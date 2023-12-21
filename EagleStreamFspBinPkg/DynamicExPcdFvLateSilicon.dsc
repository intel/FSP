## @file
# FSP DynamicEx PCDs used for FvLateSilicon build.
# When adding PCD, they should also be added to FspPcdListLibNullFvLateSilicon.inf
#
# @copyright
# Copyright (C) 2023 Intel Corporation
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

[PcdsDynamicExDefault]
  gCpuPkgTokenSpaceGuid.PcdCpuConfigContextBuffer
  gCpuPkgTokenSpaceGuid.PcdCpuEnergyPolicy
  gCpuPkgTokenSpaceGuid.PcdCpuSmmMsrSaveStateEnable
  gCpuPkgTokenSpaceGuid.PcdCpuSmmProtectedModeEnable
  gCpuPkgTokenSpaceGuid.PcdCpuSmmRuntimeCtlHooks
  gCpuPkgTokenSpaceGuid.PcdCpuSmmUseBlockIndication
  gCpuPkgTokenSpaceGuid.PcdCpuSmmUseDelayIndication
  gCpuPkgTokenSpaceGuid.PcdPlatformCpuSocketCount

  gEfiCpRcPkgTokenSpaceGuid.PcdDprMemSize
  gEfiCpRcPkgTokenSpaceGuid.PcdImonAddr
  gEfiCpRcPkgTokenSpaceGuid.PcdImr2Enable
  gEfiCpRcPkgTokenSpaceGuid.PcdImr2Size
  gEfiCpRcPkgTokenSpaceGuid.PcdLtMemSize
  gEfiCpRcPkgTokenSpaceGuid.PcdMemMapHostMemoryAddress
  gEfiCpRcPkgTokenSpaceGuid.PcdMemSrvidMap
  gEfiCpRcPkgTokenSpaceGuid.PcdPcieMmcfgTablePtr
  gEfiCpRcPkgTokenSpaceGuid.PcdPeiSyshostMemorySize
  gEfiCpRcPkgTokenSpaceGuid.PcdSyshostMemoryAddress

  gEfiMdeModulePkgTokenSpaceGuid.PcdAriSupport
  gEfiMdeModulePkgTokenSpaceGuid.PcdGhcbBase
  gEfiMdeModulePkgTokenSpaceGuid.PcdGhcbSize
  gEfiMdeModulePkgTokenSpaceGuid.PcdS3BootScriptTablePrivateDataPtr
  gEfiMdeModulePkgTokenSpaceGuid.PcdS3BootScriptTablePrivateSmmDataPtr
  gEfiMdeModulePkgTokenSpaceGuid.PcdSrIovSupport
  gEfiMdeModulePkgTokenSpaceGuid.PcdStatusCodeUseSerial
  gEfiMdeModulePkgTokenSpaceGuid.PcdUse5LevelPageTable

  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultBaudRate
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultDataBits
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultParity
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultStopBits

  gIntelSiliconPkgTokenSpaceGuid.PcdVTdPolicyPropertyMask

  gOemSkuTokenSpaceGuid.PcdOemSkuBmcPciePortNumber
  gOemSkuTokenSpaceGuid.PcdOemSkuBoardSocketCount
  gOemSkuTokenSpaceGuid.PcdOemSkuMaxChannel
  gOemSkuTokenSpaceGuid.PcdOemSkuMaxDimmPerChannel
  gOemSkuTokenSpaceGuid.PcdOemSkuMaxDimmSize
  gOemSkuTokenSpaceGuid.PcdOemSkuPlatformFeatureFlag
  gOemSkuTokenSpaceGuid.PcdOemSkuSubBoardID
  gOemSkuTokenSpaceGuid.PcdOemSkuUplinkPortIndex
  gOemSkuTokenSpaceGuid.PcdOemSku_GPIO_TABLE_SIZE

  gOobMsmTokenSpaceGuid.PcdPciBmcVendorDeviceId
  gOobMsmTokenSpaceGuid.PcdPciPmtBDF

  gPlatformModuleTokenSpaceGuid.PcdProcessorLtsxEnable

  gPlatformTokenSpaceGuid.PcdBoardTypeBitmask
  gPlatformTokenSpaceGuid.PcdDfxAdvDebugJumper
  gPlatformTokenSpaceGuid.PcdImr3Enable
  gPlatformTokenSpaceGuid.PcdPlatformType

  gReferenceCodePolicyTokenSpaceGuid.PcdDfxB2PErrAssertAtCommand
  gReferenceCodePolicyTokenSpaceGuid.PcdDfxRstCplBitsEn
  gReferenceCodePolicyTokenSpaceGuid.PcdEvMode

  gSecurityPkgPcdSpaceGuid.PcdSgxAddPackageSupport
  gSecurityPkgPcdSpaceGuid.PcdSgxPrivacy

  gSiPkgTokenSpaceGuid.PcdBiosGuardHobPtrModuleAddr
  gSiPkgTokenSpaceGuid.PcdEmuBiosSkipS3MAccess
  gSiPkgTokenSpaceGuid.PcdHvmModeEnabled
  gSiPkgTokenSpaceGuid.PcdMaxCxlMemExpNum
  gSiPkgTokenSpaceGuid.PcdNumaAcpiDataStaticPointer
  gSiPkgTokenSpaceGuid.PcdRasIerrPresent
  gSiPkgTokenSpaceGuid.PcdWarmResetEliminationEn

  gUefiCpuPkgTokenSpaceGuid.PcdCpuApLoopMode
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesCapability
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesSetting
  gUefiCpuPkgTokenSpaceGuid.PcdCpuHotPlugDataAddress
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMicrocodePatchAddress
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMicrocodePatchRegionSize
  gUefiCpuPkgTokenSpaceGuid.PcdCpuS3DataAddress
  gUefiCpuPkgTokenSpaceGuid.PcdIsPowerOnReset
  gUefiCpuPkgTokenSpaceGuid.PcdSevEsIsEnabled

[PcdsDynamicExHii]
  gEfiMdeModulePkgTokenSpaceGuid.PcdUse1GPageTable|L"1GPageTable"|gEfiGenericVariableGuid|0x0|TRUE
  gPlatformModuleTokenSpaceGuid.PcdBootState|L"BootState"|gEfiGenericVariableGuid|0x0|TRUE

#
# When adding PCD, they should also be added to FspPcdListLibNullFvLateSilicon.inf
#
