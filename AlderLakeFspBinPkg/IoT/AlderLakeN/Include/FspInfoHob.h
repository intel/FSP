/** @file
  Header file for FSP Information HOB.

@copyright

  Copyright 2017 - 2019 Intel Corporation.

  No license under any patent, copyright, trade secret or other intellectual
  property right is granted to or conferred upon you by disclosure or delivery
  of the Materials, either expressly, by implication, inducement, estoppel or
  otherwise. Any license under such intellectual property rights must be
  express and approved by Intel in writing.

  Unless otherwise agreed by Intel in writing, you may not remove or alter
  this notice or any other notice embedded in Materials by Intel or
  Intel's suppliers or licensors in any way.

  This file contains an 'Intel Peripheral Driver' and is uniquely identified as
  "Intel Reference Module" and is licensed for Intel CPUs and chipsets under
  the terms of your license agreement with Intel or your vendor. This file may
  be modified by the user, subject to additional terms of the license agreement.

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
UINT8              FspVersionMinor;
} FSP_INFO_HOB;

#pragma pack (pop)

#endif // _FSP_INFO_HOB_H_
