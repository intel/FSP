/** @file

Copyright (C) 2013, Intel Corporation

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.
* Neither the name of Intel Corporation nor the names of its contributors may
  be used to endorse or promote products derived from this software without
  specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.

**/

#include <types.h>
#include <string.h>
#include "fsp_support.h"


/**
  Reads a 64-bit value from memory that may be unaligned.

  This function returns the 64-bit value pointed to by Buffer. The function
  guarantees that the read operation does not produce an alignment fault.

  If the Buffer is NULL, then ASSERT().

  @param  Buffer  Pointer to a 64-bit value that may be unaligned.

  @return The 64-bit value read from Buffer.

**/
STATIC
UINT64
EFIAPI
ReadUnaligned64 (
  CONST UINT64        *Buffer
)
{
  ASSERT (Buffer != NULL);

  return *Buffer;
}

/**
  Compares two GUIDs.

  This function compares Guid1 to Guid2.  If the GUIDs are identical then TRUE is returned.
  If there are any bit differences in the two GUIDs, then FALSE is returned.

  If Guid1 is NULL, then ASSERT().
  If Guid2 is NULL, then ASSERT().

  @param  Guid1     A pointer to a 128 bit GUID.
  @param  Guid2     A pointer to a 128 bit GUID.

  @retval TRUE      Guid1 and Guid2 are identical.
  @retval FALSE     Guid1 and Guid2 are not identical.

**/
STATIC
BOOLEAN
EFIAPI
CompareGuid (
  CONST EFI_GUID  *Guid1,
  CONST EFI_GUID  *Guid2
)
{
  UINT64  LowPartOfGuid1;
  UINT64  LowPartOfGuid2;
  UINT64  HighPartOfGuid1;
  UINT64  HighPartOfGuid2;

  LowPartOfGuid1  = ReadUnaligned64 ((CONST UINT64*) Guid1);
  LowPartOfGuid2  = ReadUnaligned64 ((CONST UINT64*) Guid2);
  HighPartOfGuid1 = ReadUnaligned64 ((CONST UINT64*) Guid1 + 1);
  HighPartOfGuid2 = ReadUnaligned64 ((CONST UINT64*) Guid2 + 1);

  return (BOOLEAN) (LowPartOfGuid1 == LowPartOfGuid2 && HighPartOfGuid1 == HighPartOfGuid2);
}

/**
  Returns the next instance of a HOB type from the starting HOB.

  @param  Type      HOB type to search
  @param  HobStart  A pointer to the HOB list

  @retval a HOB object with matching type; Otherwise NULL.

**/
VOID *
EFIAPI
GetNextHob (
  UINT16           Type,
  CONST VOID       *HobStart
)
{
  EFI_PEI_HOB_POINTERS  Hob;

  ASSERT (HobStart != NULL);

  Hob.Raw = (UINT8 *) HobStart;
  /*
   * Parse the HOB list until end of list or matching type is found.
   */
  while (!END_OF_HOB_LIST (Hob)) {
    if (Hob.Header->HobType == Type) {
      return Hob.Raw;
    }
    Hob.Raw = GET_NEXT_HOB (Hob);
  }
  return NULL;
}

/**
  Returns the next instance of the matched GUID HOB from the starting HOB.

  @param  Guid      GUID to search
  @param  HobStart  A pointer to the HOB list

  @retval a HOB object with matching GUID; Otherwise NULL.

**/
VOID *
EFIAPI
GetNextGuidHob (
  CONST EFI_GUID     *Guid,
  CONST VOID         *HobStart
)
{
  EFI_PEI_HOB_POINTERS  GuidHob;

  GuidHob.Raw = (UINT8 *) HobStart;
  while ((GuidHob.Raw = GetNextHob (EFI_HOB_TYPE_GUID_EXTENSION, GuidHob.Raw)) != NULL) {
    if (CompareGuid (Guid, &GuidHob.Guid->Name)) {
      break;
    }
    GuidHob.Raw = GET_NEXT_HOB (GuidHob);
  }
  return GuidHob.Raw;
}

/**
  Find FSP header offset in FSP image

  If this function is called before the a stack is established, special care
  must be taken. First, it cannot declare any local variable using stack. Only
  register variable can be used here.  Secondly, some compiler version will 
  add prolog or epilog code for the C function. If so the function call may not
  work before stack is ready. GCC 4.8.1 has been verified to be working for the
  following code. 
  
  @param  None

  @retval the offset of FSP header. If signature is invalid, returns 0.

**/
UINT32
__attribute__((optimize("O0")))
FindFspHeader (
  VOID
)
{
  volatile register UINT8 *FspPtr asm ("eax");

  /* Initalize the FSP base */
  FspPtr = (UINT8 *) CONFIG_FSP_LOCATION;

  /* Check the FV signature, _FVH */
  if (((EFI_FIRMWARE_VOLUME_HEADER *)FspPtr)->Signature == 0x4856465F) {
    /* Go to the end of the FV header and align the address. */
    FspPtr += ((EFI_FIRMWARE_VOLUME_HEADER *)FspPtr)->ExtHeaderOffset;
    FspPtr += ((EFI_FIRMWARE_VOLUME_EXT_HEADER *)FspPtr)->ExtHeaderSize;
    FspPtr  = (UINT8 *)(((UINT32)FspPtr + 7) & 0xFFFFFFF8);
  } else {
    FspPtr  = 0;
  }

  /* Check the FFS GUID */
  if (FspPtr &&
      (((UINT32 *)&(((EFI_FFS_FILE_HEADER *)FspPtr)->Name))[0] == 0x912740BE) &&
      (((UINT32 *)&(((EFI_FFS_FILE_HEADER *)FspPtr)->Name))[1] == 0x47342284) &&
      (((UINT32 *)&(((EFI_FFS_FILE_HEADER *)FspPtr)->Name))[2] == 0xB08471B9) &&
      (((UINT32 *)&(((EFI_FFS_FILE_HEADER *)FspPtr)->Name))[3] == 0x0C3F3527)) {
    /* Add the FFS Header size to the base to find the Raw section Header */
    FspPtr += sizeof(EFI_FFS_FILE_HEADER);
  } else {
    FspPtr = 0;
  }

  if (FspPtr &&
      ((EFI_RAW_SECTION *)FspPtr)->Type == EFI_SECTION_RAW) {
    /* Add the Raw Header size to the base to find the FSP INFO Header */
    FspPtr += sizeof(EFI_RAW_SECTION);
  } else {
    FspPtr = 0;
  }

  return (UINT32)FspPtr;
}

/**
  Continuation function

  @param  SharedData   Shared data base before stack migration
  @param  Status       Always 0
  @param  HobListPtr   HOB list pointer

  @retval Never returns

**/
#ifdef __PRE_RAM__
VOID
BlContinuationFunc (
  SHARED_DATA *SharedData,
  EFI_STATUS   Status,
  VOID        *HobListPtr
)
{
  UINT32        StackLength;
  UINT32        OldStackBaseInMemory;
  UINT32        OldStackTopInMemory;

  ASSERT (Status == 0);

  /* Get the migrated stack in normal memory */
  OldStackBaseInMemory = (UINT32)GetBootloaderTempMemoryBuffer (HobListPtr, &StackLength);
  ASSERT (OldStackBaseInMemory != 0);
  OldStackTopInMemory  = OldStackBaseInMemory + StackLength - sizeof(UINT32);

  /*
   * Old stack base is stored at the very end of the stack top,
   * use it to calculate the migrated shared data base
   */
  SharedData = (SHARED_DATA *)(OldStackBaseInMemory + ((UINT32)SharedData - *(UINT32 *)OldStackTopInMemory));

  /*
   * The boot loader main function entry
   */
  bl_main_continue (HobListPtr, SharedData);
}

/**
  Call the FSP to do memory init. The FSP doesn't return to this function.
  The FSP returns to the romstage_main_continue().
 
  @param  BlStackTop     Bootloader stack top address
  @param  BootMode       Boot mode defined in fsp_bootmode.h
  @param  NvsBufferPtr   Non-volatile memory buffer pointer

  @retval Never returns

 */
VOID
FspInitWrapper (
  UINT32    BlStackTop,
  UINT32    BootMode,
  VOID*     NvsBufferPtr
)
{
  SHARED_DATA          SharedData;
  FSP_FSP_INIT         FspInitApi;
  FSP_INIT_PARAMS      FspInitParams;
  FSP_INIT_RT_BUFFER   FspRtBuffer;
  VPD_DATA_REGION     *FspVpdRgn;
  FSP_INFO_HEADER     *FspInfoHeader;
  FSP_INIT_PARAMS     *FspInitParamsPtr;
  UPD_DATA_REGION     *FspUpdRgn;

  FspInfoHeader = (FSP_INFO_HEADER *)FindFspHeader();
  if (FspInfoHeader == NULL) {
    /* No valid FSP info header was found */
    ASSERT (FALSE);
  }

  FspUpdRgn     = (UPD_DATA_REGION *)&SharedData.FspUpdRgn;
  memset((void*)&FspRtBuffer, 0, sizeof(FSP_INIT_RT_BUFFER));
  /* Reserve a gap in stack top */
  FspRtBuffer.Common.StackTop    = (UINT32 *)BlStackTop - 32;
  FspRtBuffer.Common.BootMode    = BootMode;
  FspRtBuffer.Common.UpdDataRgnPtr = (UPD_DATA_REGION *)FspUpdRgn;

  /* Get VPD region start */
  FspVpdRgn = (VPD_DATA_REGION *)(FspInfoHeader->ImageBase + FspInfoHeader->CfgRegionOffset);
  
  /* Verifify the VPD data region is valid */
  ASSERT((FspVpdRgn->PcdImageRevision == VPD_IMAGE_REV) && (FspVpdRgn->PcdVpdRegionSign == VPD_IMAGE_ID));  
  
  /* Copy default data from Flash */
  memcpy (FspUpdRgn, (void *)(FspInfoHeader->ImageBase + FspVpdRgn->PcdUpdRegionOffset), sizeof(UPD_DATA_REGION));

  /* Verifify the UPD data region is valid */
  ASSERT(FspUpdRgn->PcdRegionTerminator == 0x55AA);

  /* Override any UPD setting if required */
  UpdateFspUpdConfigs (FspUpdRgn);
  
  memset((void*)&FspInitParams, 0, sizeof(FSP_INIT_PARAMS));
  FspInitParams.NvsBufferPtr = NvsBufferPtr;
  FspInitParams.RtBufferPtr  = (FSP_INIT_RT_BUFFER *)&FspRtBuffer;
  FspInitParams.ContinuationFunc = (CONTINUATION_PROC)AsmContinuation;

  FspInitApi      = (FSP_FSP_INIT)(FspInfoHeader->ImageBase + FspInfoHeader->FspInitEntry);
  FspInitParamsPtr  = &FspInitParams;

  SharedData.FspInfoHeader = FspInfoHeader;
  SharedData.NewStackTop   = (UINT32 *)BlStackTop;

  /*
   * Use ASM code to ensure the register value in ECX & EBX will be passed
   * into BlContinuationFunc
   */
  asm volatile (
    "pushl	  %0;"
    "call	   *%%eax;"
    ".global AsmContinuation;"
    "AsmContinuation:;"
    "popl	    %%eax;" /* pop  out return address  */
    "pushl	  %%ecx;" /* push SharedData pointer  */
    "pushl	  %%eax;" /* push back return address */
    "jmp	  BlContinuationFunc;"
    :  : "m"(FspInitParamsPtr), "a"(FspInitApi), "c"(&SharedData)
  );

  /*
   * Should never get here. Control will continue from romstage_main_continue_asm
   * This line below is to prevent the compiler from optimizing structure intialization
   */
  FspInitApi(&FspInitParams);

  /* Should never return. Control will continue from ContinuationFunc */
  ASSERT (FALSE);
}

#else

/**
  FSP notification wrapper function. Calls into FSP code to perform platform 
  initialization

  @param  FspInfoHeader  Pointer to FSP information header
  @param  Phase          FSP initialization phase defined in enum FSP_INIT_PHASE

  @retval compatible status code with EFI_STATUS defined in PI spec

**/
EFI_STATUS
FspNotifyWrapper (
  FSP_INFO_HEADER *FspInfoHeader,
  UINT32           Phase
)
{
  FSP_NOTFY_PHASE       NotifyPhaseProc;
  NOTIFY_PHASE_PARAMS   NotifyPhaseParams;
  EFI_STATUS            Status;
  FSP_INFO_HEADER       *FspHeader;

  /* call FSP PEI to Notify PostPciEnumeration */
  if (!FspInfoHeader) {
    FspHeader   = (FSP_INFO_HEADER *)FindFspHeader();
  } else {
    FspHeader   = FspInfoHeader;
  }

  if (FspHeader == NULL) {
    /* No valid FSP info header */
    ASSERT (FALSE);
  }

  NotifyPhaseProc = (FSP_NOTFY_PHASE)(FspHeader->ImageBase + FspHeader->NotifyPhaseEntry);
  NotifyPhaseParams.Phase = Phase;
  Status = NotifyPhaseProc (&NotifyPhaseParams);
  return Status;
}

#endif  /* __PRE_RAM__ */

/**
  This function retrieves the top of usable low memory.

  @param    HobListPtr   A HOB list pointer.

  @retval                Usable low memory top.

**/
UINT32
GetUsableLowMemTop (
  CONST VOID       *HobStart
)
{
  EFI_PEI_HOB_POINTERS  Hob;
  UINT32          MemLen;
  /*
   * Get the HOB list for processing
   */
  Hob.Raw = (VOID *)HobStart;

  /*
   * Collect memory ranges
   */
  MemLen = 0x100000;
  while (!END_OF_HOB_LIST (Hob)) {
    if (Hob.Header->HobType == EFI_HOB_TYPE_RESOURCE_DESCRIPTOR) {
      if (Hob.ResourceDescriptor->ResourceType == EFI_RESOURCE_SYSTEM_MEMORY) {
        /*
         * Need memory above 1MB to be collected here
         */
        if (Hob.ResourceDescriptor->PhysicalStart >= 0x100000 &&
            Hob.ResourceDescriptor->PhysicalStart < (EFI_PHYSICAL_ADDRESS) 0x100000000) {
          MemLen += (UINT32) (Hob.ResourceDescriptor->ResourceLength);
        }
      }
    }
    Hob.Raw = GET_NEXT_HOB (Hob);
  }

  return MemLen;
}

/**
  This function retrieves the top of usable high memory.

  @param  HobListPtr   A HOB list pointer.

  @retval              Usable high memory top.

**/
UINT64
GetUsableHighMemTop (
  CONST VOID       *HobStart
)
{
  EFI_PEI_HOB_POINTERS  Hob;
  UINT64                MemTop;
  /*
   * Get the HOB list for processing
   */
  Hob.Raw = (VOID *)HobStart;

  /*
   * Collect memory ranges
   */
  MemTop = 0x100000000;
  while (!END_OF_HOB_LIST (Hob)) {
    if (Hob.Header->HobType == EFI_HOB_TYPE_RESOURCE_DESCRIPTOR) {
      if (Hob.ResourceDescriptor->ResourceType == EFI_RESOURCE_SYSTEM_MEMORY) {
        /*
         * Need memory above 1MB to be collected here
         */
        if (Hob.ResourceDescriptor->PhysicalStart >= (EFI_PHYSICAL_ADDRESS) 0x100000000) {
          MemTop += (UINT32) (Hob.ResourceDescriptor->ResourceLength);
        }
      }
    }
    Hob.Raw = GET_NEXT_HOB (Hob);
  }

  return MemTop;
}

/**
  This function retrieves a special reserved memory region.

  @param  HobListPtr   A HOB list pointer.
  @param  Length       A pointer to the GUID HOB data buffer length.  If the GUID HOB is
                       located, the length will be updated.
  @param  OwnerGuid    A pointer to the owner guild.
  @retval              Reserved region start address.  0 if this region does not exist.

**/
UINT64
GetFspReservedMemoryFromGuid (
  CONST VOID     *HobListPtr,
  UINT64         *Length,
  EFI_GUID       *OwnerGuid
)
{
  EFI_PEI_HOB_POINTERS    Hob;

  /*
   * Get the HOB list for processing
   */
  Hob.Raw = (VOID *)HobListPtr;

  /*
   * Collect memory ranges
   */
  while (!END_OF_HOB_LIST (Hob)) {
    if (Hob.Header->HobType == EFI_HOB_TYPE_RESOURCE_DESCRIPTOR) {
      if (Hob.ResourceDescriptor->ResourceType == EFI_RESOURCE_MEMORY_RESERVED) {
        if (CompareGuid(&Hob.ResourceDescriptor->Owner, OwnerGuid)) {
          if (Length) {
            *Length = (UINT32) (Hob.ResourceDescriptor->ResourceLength);
          }
          return (UINT64)(Hob.ResourceDescriptor->PhysicalStart);
        }
      }
    }
    Hob.Raw = GET_NEXT_HOB (Hob);
  }

  return 0;
}

/**
  This function retrieves the TSEG reserved normal memory.

  @param  HobListPtr   A HOB list pointer.
  @param  Length       A pointer to the TSEG reserved memory length buffer.  If the GUID HOB is
                       located, the length will be updated.
  @param  Guid         A pointer to owner HOB GUID.
  @retval NULL         Failed to find the TSEG reserved memory.
  @retval others       TSEG reserved memory base.

**/
UINT32
GetTsegReservedMemory (
  CONST VOID       *HobListPtr,
  UINT32           *Length
)
{
  const EFI_GUID    TsegOwnerHobGuid = FSP_HOB_RESOURCE_OWNER_TSEG_GUID;
  UINT64            Length64;
  UINT32            Base;

  Base = (UINT32)GetFspReservedMemoryFromGuid (HobListPtr, &Length64, (EFI_GUID *)&TsegOwnerHobGuid);
  if ((Length != 0) && (Base != 0)) {
    *Length = (UINT32)Length64;
  }
  return Base;
}

/**
  This function retrieves the FSP reserved normal memory.

  @param  HobListPtr   A HOB list pointer.
  @param  Length       A pointer to the FSP reserved memory length buffer.  If the GUID HOB is
                       located, the length will be updated.
  @param  Guid         A pointer to owner HOB GUID.
  @retval NULL         Failed to find the FSP reserved memory.
  @retval others       FSP reserved memory base.

**/
UINT32
GetFspReservedMemory (
  CONST VOID       *HobListPtr,
  UINT32           *Length
)
{
  const EFI_GUID    FspOwnerHobGuid = FSP_HOB_RESOURCE_OWNER_FSP_GUID;
  UINT64            Length64;
  UINT32            Base;

  Base = (UINT32)GetFspReservedMemoryFromGuid (HobListPtr, &Length64, (EFI_GUID *)&FspOwnerHobGuid);
  if ((Length != 0) && (Base != 0)) {
    *Length = (UINT32)Length64;
  }
  return Base;
}


/**
  This function retrieves a GUIDed HOB data buffer and size.

  @param  HobListPtr   A HOB list pointer.
  @param  Length       A pointer to the GUID HOB data buffer length.  If the 
                       GUID HOB is located, the length will be updated.
  @param  Guid         A pointer to HOB GUID.
  @retval NULL         Failed to find the GUID HOB.
  @retval others       GUID HOB data buffer pointer.

**/
VOID *
GetGuidHobDataBuffer (
  CONST VOID       *HobListPtr,
  UINT32           *Length,
  EFI_GUID         *Guid
)
{
  UINT8        *GuidHob;

  /* FSP NVS DATA HOB */
  GuidHob = GetNextGuidHob(Guid, HobListPtr);
  if (GuidHob == NULL) {
    return NULL;
  } else {
    if (Length) {
      *Length = GET_GUID_HOB_DATA_SIZE (GuidHob);
    }
    return GET_GUID_HOB_DATA (GuidHob);
  }
}

/**
  This function retrieves FSP Non-volatile Storage HOB buffer and size.

  @param  HobListPtr   A HOB list pointer.
  @param  Length       A pointer to the NVS data buffer length.  If the FSP NVS 
                       HOB is located, the length will be updated.
  @retval NULL         Failed to find the NVS HOB.
  @retval others       FSP NVS data buffer pointer.

**/
VOID *
GetFspNvsDataBuffer (
  CONST VOID       *HobListPtr,
  UINT32           *Length
)
{
  const EFI_GUID    FspNvsHobGuid = FSP_NON_VOLATILE_STORAGE_HOB_GUID;
  return GetGuidHobDataBuffer (HobListPtr, Length, (EFI_GUID *)&FspNvsHobGuid);
}


/**
  This function retrieves Bootloader temporary stack buffer and size.

  @param  HobListPtr   A HOB list pointer.
  @param  Length       A pointer to the Bootloader temporary stack length.
                       If the HOB is located, the length will be updated.
  @retval NULL         Failed to find the Bootloader temporary stack HOB.
  @retval others       Bootloader temporary stackbuffer pointer.

**/
VOID *
GetBootloaderTempMemoryBuffer (
  CONST VOID       *HobListPtr,
  UINT32           *Length
)
{
  const EFI_GUID    FspBootloaderTemporaryMemoryHobGuid = FSP_BOOTLOADER_TEMPORARY_MEMORY_HOB_GUID;
  return GetGuidHobDataBuffer (HobListPtr, Length, (EFI_GUID *)&FspBootloaderTemporaryMemoryHobGuid);
}
