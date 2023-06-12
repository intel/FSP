## @file
#  Platform description for DynamicEx PCDs.
#
# @copyright
#  
#  Copyright 2018 - 2023 Intel Corporation.
#
#  The source code contained or described herein and all documents related to the
#  source code ("Material") are owned by Intel Corporation or its suppliers or
#  licensors. Title to the Material remains with Intel Corporation or its suppliers
#  and licensors. The Material may contain trade secrets and proprietary and
#  confidential information of Intel Corporation and its suppliers and licensors,
#  and is protected by worldwide copyright and trade secret laws and treaty
#  provisions. No part of the Material may be used, copied, reproduced, modified,
#  published, uploaded, posted, transmitted, distributed, or disclosed in any way
#  without Intel's prior express written permission.
#
#  No license under any patent, copyright, trade secret or other intellectual
#  property right is granted to or conferred upon you by disclosure or delivery
#  of the Materials, either expressly, by implication, inducement, estoppel or
#  otherwise. Any license under such intellectual property rights must be
#  express and approved by Intel in writing.
#
#  Unless otherwise agreed by Intel in writing, you may not remove or alter
#  this notice or any other notice embedded in Materials by Intel or
#  Intel's suppliers or licensors in any way.
#
#  This file contains an 'Intel Peripheral Driver' and is uniquely identified as
#  "Intel Reference Module" and is licensed for Intel CPUs and chipsets under
#  the terms of your license agreement with Intel or your vendor. This file may
#  be modified by the user, subject to additional terms of the license agreement.
#
# @par Specification
##

[PcdsDynamicExDefault]

  ## Specifies max supported number of Logical Processors.
  # @Prompt Configure max supported number of Logical Processorss
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMaxLogicalProcessorNumber | 16

  gSiPkgTokenSpaceGuid.PcdSiPciExpressBaseAddress   |0xC0000000
  gSiPkgTokenSpaceGuid.PcdPciExpressRegionLength            | 0x10000000

  ## Specifies the base address of the first microcode Patch in the microcode Region.
  # @Prompt Microcode Region base address.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMicrocodePatchAddress|0x0

  ## Specifies the size of the microcode Region.
  # @Prompt Microcode Region size.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMicrocodePatchRegionSize|0x0

  ## Specifies the AP wait loop state during POST phase.
  #  The value is defined as below.
  #  1: Place AP in the Hlt-Loop state.
  #  2: Place AP in the Mwait-Loop state.
  #  3: Place AP in the Run-Loop state.
  # @Prompt The AP wait loop state.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuApLoopMode|2

  ## Specifies the AP target C-state for Mwait during POST phase.
  #  The default value 0 means C1 state.
  #  The value is defined as below.<BR><BR>
  # @Prompt The specified AP target C-state for Mwait.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuApTargetCstate|0

  #
  # Enable ACPI S3 support in FSP by default
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiS3Enable|1

