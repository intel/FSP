/** @file
  Definitions for Hob Usage data HOB

  @copyright
  Copyright (c) 2017 - 2018, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials are licensed and made available under
  the terms and conditions of the BSD License that accompanies this distribution.
  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.
  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,

  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

@par Specification Reference:
**/

#ifndef _HOB_USAGE_DATA_HOB_H_
#define _HOB_USAGE_DATA_HOB_H_

extern EFI_GUID gHobUsageDataGuid;

#pragma pack (push, 1)

/**
  Hob Usage Data Hob

  <b>Revision 1:</b>
  - Initial version.
**/
typedef struct {
  EFI_PHYSICAL_ADDRESS EfiMemoryTop;
  EFI_PHYSICAL_ADDRESS EfiMemoryBottom;
  EFI_PHYSICAL_ADDRESS EfiFreeMemoryTop;
  EFI_PHYSICAL_ADDRESS EfiFreeMemoryBottom;
  UINTN                FreeMemory;
} HOB_USAGE_DATA_HOB;

#pragma pack (pop)

#endif // _HOB_USAGE_DATA_HOB_H_
