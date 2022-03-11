## @file
# FSP DynamicEx PCDs used for FSP build.
#
# When adding PCD, they should also be added to FspPcdListLibNull.inf
#
# @copyright
#  Copyright 2018 - 2021 Intel Corporation.
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

[PcdsDynamicExDefault]
  gCpuPkgTokenSpaceGuid.PcdCpuEnergyPolicy

  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesCapability
  gUefiCpuPkgTokenSpaceGuid.PcdCpuS3DataAddress
  gUefiCpuPkgTokenSpaceGuid.PcdIsPowerOnReset

  gEfiCpRcPkgTokenSpaceGuid.PcdDprMemSize
  gEfiCpRcPkgTokenSpaceGuid.PcdImonAddr
  gEfiCpRcPkgTokenSpaceGuid.PcdImr2Enable
  gEfiCpRcPkgTokenSpaceGuid.PcdImr2Size
  gEfiCpRcPkgTokenSpaceGuid.PcdLtMemSize
  gEfiCpRcPkgTokenSpaceGuid.PcdMemMapHostMemoryAddress
##SVID Mapping starts ##
  # Map VR ID Address to Memory controller
  #The mailbox command can support up to 4 DDR VR ID's, 0x10, 0x12, 0x14, and 0x16.
  #Whitley PHAS indicates that Whitley (like Purley) only connects 2 VRs (VR ID's 0x10 and 0x12).
  #Those are typically shared such that MC0/MC1 share the same DDR VR (as they are on the same side of the CPU)
  #and MC2/MC3 share the other. Depending on motherboard layout and other design constraints, this could change
  #BIT   4 => 0 or 1, SVID BUS\Interface 0 or 1 respectively
  #BIT 0:3 => SVID ADDRESS
!if $(CPUTARGET) == "ICX"
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[0]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[1]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[2]  |0x12  #SVID BUS 1, ADDR 2
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[3]  |0x12  #SVID BUS 1, ADDR 2
!if $(MAX_SOCKET) > 1
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[0]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[1]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[2]  |0x12  #SVID BUS 1, ADDR 2
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[3]  |0x12  #SVID BUS 1, ADDR 2
!endif
!else
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[0]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[1]  |0x12  #SVID BUS 1, ADDR 2
!if $(MAX_SOCKET) > 1
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[0]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[1]  |0x12  #SVID BUS 1, ADDR 2
!endif
!endif
##SVID Mapping Ends ##
  gEfiCpRcPkgTokenSpaceGuid.PcdPcieMmcfgTablePtr
  gEfiCpRcPkgTokenSpaceGuid.PcdPeiSyshostMemorySize
  gEfiCpRcPkgTokenSpaceGuid.PcdSyshostMemoryAddress

  gEfiMdeModulePkgTokenSpaceGuid.PcdGhcbBase
  gEfiMdeModulePkgTokenSpaceGuid.PcdGhcbSize
  gEfiMdeModulePkgTokenSpaceGuid.PcdNvStoreDefaultValueBuffer
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetNvStoreDefaultId
!if $(DEBUG_FLAGS_ENABLE) == FALSE
  ## This PCD specifies whether or not StatusCode should use serial
  gEfiMdeModulePkgTokenSpaceGuid.PcdStatusCodeUseSerial|FALSE
!else
  gEfiMdeModulePkgTokenSpaceGuid.PcdStatusCodeUseSerial|TRUE
!endif
  gEfiMdeModulePkgTokenSpaceGuid.PcdUse5LevelPageTable
  gEfiMdeModulePkgTokenSpaceGuid.PcdVpdBaseAddress64

  gPlatformTokenSpaceGuid.ReservedB
  gPlatformTokenSpaceGuid.PcdPlatformType

  gReferenceCodePolicyTokenSpaceGuid.ReservedC
  gReferenceCodePolicyTokenSpaceGuid.ReservedD
  gReferenceCodePolicyTokenSpaceGuid.PcdEvMode

  gSiPkgTokenSpaceGuid.PcdEmuBiosSkipS3MAccess
  gSiPkgTokenSpaceGuid.PcdHvmModeEnabled
  gSiPkgTokenSpaceGuid.PcdNumaAcpiDataStaticPointer
  gSiPkgTokenSpaceGuid.PcdWarmResetEliminationEn

  gUefiCpuPkgTokenSpaceGuid.PcdCpuClockModulationDutyCycle
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesSetting
  gUefiCpuPkgTokenSpaceGuid.PcdSevEsIsEnabled

[PcdsDynamicExHii]
  gEfiMdeModulePkgTokenSpaceGuid.PcdUse1GPageTable|L"1GPageTable"|gEfiGenericVariableGuid|0x0|TRUE

#
# When adding PCD, they should also be added to FspPcdListLibNull.inf
#
