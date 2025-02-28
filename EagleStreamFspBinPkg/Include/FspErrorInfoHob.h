/** @file
  FSP Error Information HOB to describe errors inside FSP that bootloader may
  take some actions to handle those error scenarios.

  @copyright
  Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-3-Clause
**/

#ifndef _FSP_ERROR_INFO_HOB_H_
#define _FSP_ERROR_INFO_HOB_H_

#include <Uefi/UefiMultiPhase.h>
#include <Pi/PiBootMode.h>
#include <Pi/PiHob.h>
#include <Pi/PiStatusCode.h>

#define FSP_ERROR_INFO_HOB_GUID                 { 0x611e6a88, 0xadb7, 0x4301, { 0x93, 0xff, 0xe4, 0x73, 0x04, 0xb4, 0x3d, 0xa6 }}

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

#endif //#ifndef _FSP_ERROR_INFO_HOB_H_