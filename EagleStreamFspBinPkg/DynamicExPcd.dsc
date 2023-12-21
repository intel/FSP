## @file
# FSP DynamicEx PCDs used for FSP build.
# When adding PCD, they should also be added to FspPcdListLibNull.inf
#
# @copyright
# Copyright (C) 2023 Intel Corporation
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

[PcdsDynamicExDefault]
#
# Note: PCD list here should match FspPcdListLibNull.inf
#
##SVID Mapping starts ##
  # Map VR ID Address to Memory controller
  #The mailbox command can support up to 4 DDR VR ID's, 0x10, 0x12, 0x14, and 0x16.
  #EagleStream PHAS indicates that EagleStream (like Purley) only connects 2 VRs (VR ID's 0x10 and 0x12).
  #Those are typically shared such that MC0/MC2 share the same DDR VR (as they are on the same side of the CPU)
  #and MC1/MC3 share the other. Depending on motherboard layout and other design constraints, this could change
  #BIT   4 => 0 or 1, SVID BUS\Interface 0 or 1 respectively
  #BIT 0:3 => SVID ADDRESS
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[0]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[1]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[2]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[0].Mc[3]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[0]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[1]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[2]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[1].Mc[3]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[2].Mc[0]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[2].Mc[1]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[2].Mc[2]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[2].Mc[3]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[3].Mc[0]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[3].Mc[1]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[3].Mc[2]  |0x10  #SVID BUS 1, ADDR 0
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap.Socket[3].Mc[3]  |0x10  #SVID BUS 1, ADDR 0

##SVID Mapping Ends ##
  gEfiCpRcPkgTokenSpaceGuid.PcdImonAddr
  gEfiCpRcPkgTokenSpaceGuid.PcdPcieMmcfgTablePtr
  gOemSkuTokenSpaceGuid.PcdOemSkuBmcPciePortNumber
  gOemSkuTokenSpaceGuid.PcdOemSkuPlatformFeatureFlag
  gOemSkuTokenSpaceGuid.PcdOemSkuSubBoardID
  gOemSkuTokenSpaceGuid.PcdOemSkuUplinkPortIndex
  gOemSkuTokenSpaceGuid.PcdOemSku_GPIO_TABLE_SIZE
  gPlatformModuleTokenSpaceGuid.PcdProcessorLtsxEnable
  gPlatformTokenSpaceGuid.PcdBoardTypeBitmask
  gPlatformTokenSpaceGuid.PcdDfxAdvDebugJumper
  gEfiCpRcPkgTokenSpaceGuid.PcdDprMemSize
  gEfiCpRcPkgTokenSpaceGuid.PcdImr2Enable
  gEfiCpRcPkgTokenSpaceGuid.PcdImr2Size
  gPlatformTokenSpaceGuid.PcdImr3Enable
  gEfiCpRcPkgTokenSpaceGuid.PcdLtMemSize
  gEfiCpRcPkgTokenSpaceGuid.PcdMemMapHostMemoryAddress
  gPlatformTokenSpaceGuid.PcdPlatformType
  gEfiCpRcPkgTokenSpaceGuid.PcdSyshostMemoryAddress
  gEfiCpRcPkgTokenSpaceGuid.PcdPeiSyshostMemorySize
  gReferenceCodePolicyTokenSpaceGuid.PcdDfxB2PErrAssertAtCommand
  gReferenceCodePolicyTokenSpaceGuid.PcdDfxRstCplBitsEn
  gReferenceCodePolicyTokenSpaceGuid.PcdEvMode
  gSiPkgTokenSpaceGuid.PcdWarmResetEliminationEn|FALSE
  gSiPkgTokenSpaceGuid.PcdMaxCxlMemExpNum|0x2
  gEfiMdeModulePkgTokenSpaceGuid.PcdUse5LevelPageTable|FALSE
  gUefiCpuPkgTokenSpaceGuid.PcdCpuS3DataAddress
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesCapability
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesSetting
  gUefiCpuPkgTokenSpaceGuid.PcdIsPowerOnReset
  gCpuPkgTokenSpaceGuid.PcdCpuEnergyPolicy
  ## Specifies the AP wait loop state during POST phase.
  #  The value is defined as below.
  #  1: Place AP in the Hlt-Loop state.
  #  2: Place AP in the Mwait-Loop state.
  #  3: Place AP in the Run-Loop state.
  # @Prompt The AP wait loop state.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuApLoopMode|1

  ## This PCD specifies whether or not StatusCode should use serial
  gEfiMdeModulePkgTokenSpaceGuid.PcdStatusCodeUseSerial|FALSE

  # Set SEV-ES defaults
  gEfiMdeModulePkgTokenSpaceGuid.PcdGhcbBase|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdGhcbSize|0
  gUefiCpuPkgTokenSpaceGuid.PcdSevEsIsEnabled|0
  gSiPkgTokenSpaceGuid.PcdEmuBiosSkipS3MAccess
  gIntelSiliconPkgTokenSpaceGuid.PcdVTdPolicyPropertyMask|0x00000000
  gSecurityPkgPcdSpaceGuid.PcdSgxPrivacy|TRUE
  gSecurityPkgPcdSpaceGuid.PcdSgxAddPackageSupport|TRUE
  #
  # Same FSP may be used by different platforms thus the default value may not fit to all platforms.
  # Bootloader should always update below PCD to match flash map without relying on default value.
  #
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMicrocodePatchAddress|0xFF880090
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMicrocodePatchRegionSize|0x2FFF70

[PcdsDynamicExHii]
  gEfiMdeModulePkgTokenSpaceGuid.PcdUse1GPageTable|L"1GPageTable"|gEfiGenericVariableGuid|0x0|TRUE
  gPlatformModuleTokenSpaceGuid.PcdBootState|L"BootState"|gEfiGenericVariableGuid|0x0|TRUE

