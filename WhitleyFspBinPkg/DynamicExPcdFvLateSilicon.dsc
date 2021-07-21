## @file DynamicExPcdFvLateSilicon.dsc
# FSP DynamicEx PCDs used for FvLateSilicon build.
# Requires that DynamicExPcd.dsc for FSP PCD is also included.
#
# When adding PCD, they should also be added to FspPcdListLibNullFvLateSilicon.inf
#
# @copyright
#  Copyright 2018 - 2021 Intel Corporation.
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

[PcdsDynamicExDefault]
  gCpuPkgTokenSpaceGuid.PcdCpuConfigContextBuffer
  gCpuPkgTokenSpaceGuid.PcdPlatformCpuSocketCount

  gOemSkuTokenSpaceGuid.PcdOemSkuBoardSocketCount
  gOemSkuTokenSpaceGuid.PcdOemSkuMaxChannel
  gOemSkuTokenSpaceGuid.PcdOemSkuMaxDimmPerChannel
  gOemSkuTokenSpaceGuid.PcdOemSkuMaxDimmSize
  gOemSkuTokenSpaceGuid.PcdOemSkuUplinkPortIndex

  gPlatformTokenSpaceGuid.PcdFpgaSwSmiInputValue

  gStructPcdTokenSpaceGuid.PcdFpgaSocketConfig
  gStructPcdTokenSpaceGuid.PcdMemBootHealthConfig
  gStructPcdTokenSpaceGuid.PcdPchSetup
  gStructPcdTokenSpaceGuid.PcdSetup
  gStructPcdTokenSpaceGuid.PcdSocketCommonRcConfig
  gStructPcdTokenSpaceGuid.PcdSocketIioConfig
  gStructPcdTokenSpaceGuid.PcdSocketMemoryConfig
  gStructPcdTokenSpaceGuid.PcdSocketMpLinkConfig
  gStructPcdTokenSpaceGuid.PcdSocketPowerManagementConfig

  gEfiMdeModulePkgTokenSpaceGuid.PcdS3BootScriptTablePrivateDataPtr
  gEfiMdeModulePkgTokenSpaceGuid.PcdS3BootScriptTablePrivateSmmDataPtr

  gOemSkuTokenSpaceGuid.PcdAcpiGnvsAddress
  gMinPlatformPkgTokenSpaceGuid.PcdPcIoApicEnable

  gEfiCpRcPkgTokenSpaceGuid.PcdPcieMmcfgTablePtr
  gReferenceCodePolicyTokenSpaceGuid.ReservedD
  gSiPkgTokenSpaceGuid.PcdHvmModeEnabled
  gEfiCpRcPkgTokenSpaceGuid.PcdSyshostMemoryAddress
  gReferenceCodePolicyTokenSpaceGuid.ReservedC

  gUefiCpuPkgTokenSpaceGuid.PcdCpuHotPlugDataAddress
  gUefiCpuPkgTokenSpaceGuid.PcdCpuProcTraceMemSize
  gUefiCpuPkgTokenSpaceGuid.PcdCpuProcTraceOutputScheme

  gCpuPkgTokenSpaceGuid.PcdCpuSmmMsrSaveStateEnable
  gCpuPkgTokenSpaceGuid.PcdCpuSmmProtectedModeEnable
  gCpuPkgTokenSpaceGuid.PcdCpuSmmUseDelayIndication
  gCpuPkgTokenSpaceGuid.PcdCpuSmmUseBlockIndication
  gCpuPkgTokenSpaceGuid.PcdCpuSmmRuntimeCtlHooks

  gUefiCpuPkgTokenSpaceGuid.PcdCpuS3DataAddress
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesCapability
  gUefiCpuPkgTokenSpaceGuid.PcdCpuFeaturesSetting

[PcdsDynamicExHii]
  gCpPlatTokenSpaceGuid.PcdUefiOptimizedBoot|L"UefiOptimizedBoot"|gCpPlatTokenSpaceGuid|0x0|TRUE

#
# When adding PCD, they should also be added to FspPcdListLibNullFvLateSilicon.inf
#
