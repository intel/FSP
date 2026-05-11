/** @file
  FSP Error Information HOB to describe errors inside FSP that bootloader may
  take some actions to handle those error scenarios.

  @copyright
  INTEL CONFIDENTIAL
  Copyright (C) 2023 Intel Corporation.

  This software and the related documents are Intel copyrighted materials,
  and your use of them is governed by the express license under which they
  were provided to you ("License"). Unless the License provides otherwise,
  you may not use, modify, copy, publish, distribute, disclose or transmit
  this software or the related documents without Intel's prior written
  permission.

  This software and the related documents are provided as is, with no
  express or implied warranties, other than those that are expressly stated
  in the License.

@par Specification Reference:
**/

#ifndef _FSP_ERROR_INFO_HOB_H_
#define _FSP_ERROR_INFO_HOB_H_

///
/// GUID value indicating the FSP error information.
///
#define FSP_ERROR_INFO_HOB_GUID { 0x611e6a88, 0xadb7, 0x4301, { 0x93, 0xff, 0xe4, 0x73, 0x04, 0xb4, 0x3d, 0xa6 } }

#define FSP_ERROR_INFO_STATUS_CODE_TYPE          (EFI_ERROR_CODE | EFI_ERROR_UNRECOVERED)
///
/// FSP Error Information Block.
///
#pragma pack(1)
typedef struct {
  ///
  /// GUID HOB header.
  ///
  EFI_HOB_GUID_TYPE     GuidHob;

  ///
  /// ReportStatusCode () type identifier.
  ///
  EFI_STATUS_CODE_TYPE  Type;

  ///
  /// ReportStatusCode () value.
  ///
  EFI_STATUS_CODE_VALUE Value;

  ///
  /// ReportStatusCode () Instance number.
  ///
  UINT32                Instance;

  ///
  /// Optional GUID which may be used to identify
  /// which internal component of the FSP was
  /// executing at the time of the error.
  ///
  EFI_GUID              CallerId;

  ///
  /// GUID identifying the nature of the fatal error.
  ///
  EFI_GUID              ErrorType;

  ///
  /// EFI_STATUS code describing the error encountered.
  ///
  UINT32                Status;
} FSP_ERROR_INFO_HOB;

#pragma pack()

#endif //_FSP_ERROR_INFO_H_
