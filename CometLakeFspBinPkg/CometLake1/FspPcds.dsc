## @file
#  FSP description for DynamicEx PCDs.
#
# @copyright
#  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
# @par Specification
##

  ## Specifies the AP target C-state for Mwait during POST phase.
  #  The default value 0 means C1 state.
  #  The value is defined as below.<BR><BR>
  # @Prompt The specified AP target C-state for Mwait.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuApTargetCstate|0

  ## Specifies max supported number of Logical Processors.
  # @Prompt Configure max supported number of Logical Processorss
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMaxLogicalProcessorNumber | 20

  gSiPkgTokenSpaceGuid.PcdSiPciExpressBaseAddress           | 0xE0000000
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

