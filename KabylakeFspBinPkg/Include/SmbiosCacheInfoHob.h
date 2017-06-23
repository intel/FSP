/** @file
  Header file for SMBIOS Cache Info HOB

 Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>

 This program and the accompanying materials are licensed and made available under
 the terms and conditions of the BSD License which accompanies this distribution.
 The full text of the license may be found at
 http://opensource.org/licenses/bsd-license.php

 THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

@par Specification Reference:
  System Management BIOS (SMBIOS) Reference Specification v3.0.0
  dated 2015-Feb-12 (DSP0134)
  http://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.0.0.pdf
**/

#ifndef _SMBIOS_CACHE_INFO_HOB_H_
#define _SMBIOS_CACHE_INFO_HOB_H_

#include <Uefi.h>
#include <Pi/PiHob.h>

extern EFI_GUID gSmbiosCacheInfoHobGuid;

#pragma pack(1)
///
/// SMBIOS Cache Info HOB Structure
///
typedef struct {
  UINT16     ProcessorSocketNumber;
  UINT16     NumberOfCacheLevels;         ///< Based on Number of Cache Types L1/L2/L3
  UINT8      SocketDesignationStrIndex;   ///< String Index in the string Buffer. Example "L1-CACHE"
  UINT16     CacheConfiguration;          ///< Format defined in SMBIOS Spec v3.0 Section7.8 Table36
  UINT16     MaxCacheSize;                ///< Format defined in SMBIOS Spec v3.0 Section7.8.1
  UINT16     InstalledSize;               ///< Format defined in SMBIOS Spec v3.0 Section7.8.1
  UINT16     SupportedSramType;           ///< Format defined in SMBIOS Spec v3.0 Section7.8.2
  UINT16     CurrentSramType;             ///< Format defined in SMBIOS Spec v3.0 Section7.8.2
  UINT8      CacheSpeed;                  ///< Cache Speed in nanoseconds. 0 if speed is unknown.
  UINT8      ErrorCorrectionType;         ///< ENUM Format defined in SMBIOS Spec v3.0 Section 7.8.3
  UINT8      SystemCacheType;             ///< ENUM Format defined in SMBIOS Spec v3.0 Section 7.8.4
  UINT8      Associativity;               ///< ENUM Format defined in SMBIOS Spec v3.0 Section 7.8.5
  /**
  String Buffer - each string terminated by NULL "0x00"
  String buffer terminated by double NULL "0x0000"
  **/
} SMBIOS_CACHE_INFO;
#pragma pack()

#endif // _SMBIOS_CACHE_INFO_HOB_H_
