/** @file
  Header file for FSP Information HOB.

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

#ifndef _FSP_INFO_HOB_H_
#define _FSP_INFO_HOB_H_

extern EFI_GUID gFspInfoGuid;

#pragma pack (push, 1)

typedef struct {
UINT8              SiliconInitVersionMajor;
UINT8              SiliconInitVersionMinor;
UINT8              SiliconInitVersionRevision;
UINT8              SiliconInitVersionBuild;
UINT8              FspVersionRevision;
UINT8              FspVersionBuild;
UINT8              TimeStamp [12];
} FSP_INFO_HOB;

#pragma pack (pop)

#endif // _FSP_INFO_HOB_H_
