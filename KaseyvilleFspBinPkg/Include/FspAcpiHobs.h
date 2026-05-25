/** @file
  RAS ACPI GUID HOB definitions

  @copyright
  INTEL CONFIDENTIAL
  Copyright 2023 Intel Corporation. <BR>

  The source code contained or described herein and all documents related to the
  source code ("Material") are owned by Intel Corporation or its suppliers or
  licensors. Title to the Material remains with Intel Corporation or its suppliers
  and licensors. The Material may contain trade secrets and proprietary    and
  confidential information of Intel Corporation and its suppliers and licensors,
  and is protected by worldwide copyright and trade secret laws and treaty
  provisions. No part of the Material may be used, copied, reproduced, modified,
  published, uploaded, posted, transmitted, distributed, or disclosed in any way
  without Intel's prior express written permission.

  No license under any patent, copyright, trade secret or other intellectual
  property right is granted to or conferred upon you by disclosure or delivery
  of the Materials, either expressly, by implication, inducement, estoppel or
  otherwise. Any license under such intellectual property rights must be
  express and approved by Intel in writing.

  Unless otherwise agreed by Intel in writing, you may not remove or alter
  this notice or any other notice embedded in Materials by Intel or
  Intel's suppliers or licensors in any way.
**/

#ifndef __FSP_ACPI_HOBS__
#define __FSP_ACPI_HOBS__

//Typecast HOB pointer to APEI table structure of ACPI version 6.2
#define FSP_RAS_ACPI_HOB_GUID             { 0x826785ee, 0xa8e0, 0x4d8f, { 0x82, 0x6f, 0x54, 0x29, 0x2c, 0xe7, 0x6f, 0xe6 } }

//Typecast HOB pointer to ACPI CXL CEDT table structure
#define FSP_CXL_CEDT_ACPI_HOB_GUID        { 0x5CB7A12A, 0x8B2D, 0x485A, { 0xB7, 0x04, 0xC0, 0x52, 0x49, 0x56, 0x81, 0xE7 } }

// Typecast HOB pointer to MEM_TRAINING_DATA_HOB_HEADER. 
// User with NDA clearance should refer to RC code for latest structure definition.
#define FSP_MEM_TRAINING_DATA_HOB_GUID    { 0x7e8b89e2, 0x8b84, 0x4cb3, { 0x86, 0x8f, 0x10, 0xb6, 0x78, 0x71, 0xa2, 0xc0 }}

// Typecast HOB pointer to EWL_PRIVATE_DATA. 
// User with NDA clearance should refer to RC code for latest structure definition.
#define FSP_EWL_ID_HOB_GUID                   { 0xd8e05800, 0x5e, 0x4462, { 0xaa, 0x3d, 0x9c, 0x6b, 0x47, 0x4, 0x92, 0xb } };

//Typecast HOB pointer to RAS_ACPI_PARAM_HOB_DATA;
#define RAS_ACPI_PARAM_HOB_GUID           {0x594dfe5c, 0x7a87, 0x49dc, { 0x8f, 0x33, 0xea, 0x83, 0x4d, 0x6f, 0x18, 0x90 } }

#endif  // __FSP_ACPI_HOBS__
