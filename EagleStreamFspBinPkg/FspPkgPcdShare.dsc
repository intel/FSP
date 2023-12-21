## @file
# FSP RP Common PCDs
#
# @copyright
# Copyright (C) 2023 Intel Corporation
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

#
# MRC common configuration options defined here
#

!include EaglestreamSiliconPkg/MrcCommonConfig.dsc

!include EaglestreamFspBinPkg/DynamicExPcd.dsc

[PcdsFixedAtBuild]
  gCpuUncoreTokenSpaceGuid.PcdWaSerializationEn|FALSE
  gEfiCpRcPkgTokenSpaceGuid.PcdDimmIsolationDefault|0
!if $(AMT_ENABLE) == TRUE
  gSiPkgTokenSpaceGuid.PcdAmtEnable|TRUE
!endif
  gEfiMdeModulePkgTokenSpaceGuid.PcdMigrateTemporaryRamFirmwareVolumes|TRUE

  # disable Variable Driver access NVStorage
  gEfiMdeModulePkgTokenSpaceGuid.PcdEmuVariableNvModeEnable|FALSE

  gSiPkgTokenSpaceGuid.PcdMaxCxlAccMemRangeSize|0x800

[PcdsFixedAtBuild]

  # Indicates whether it needs to clear temp bus assignment in PCIE common init library
  gEfiCpRcPkgTokenSpaceGuid.PcdCleanTempBusAssignment|TRUE

  # Reset DDRIO
  gEfiCpRcPkgTokenSpaceGuid.PcdIoResetDdrio|FALSE

  # Socket count used to indicate maximum number of CPU sockets supported by the platform.
  gEfiCpRcPkgTokenSpaceGuid.PcdMaxCpuSocketCount|$(MAX_SOCKET)
  gEfiCpRcPkgTokenSpaceGuid.PcdMaxCpuCoreCount|$(MAX_CORE)
  gEfiCpRcPkgTokenSpaceGuid.PcdMaxCpuThreadCount|$(MAX_THREAD)

  # Indicates the max nested level
  gEfiCpRcPkgTokenSpaceGuid.PcdMaxNestedLevel|0x00000010

  # DDDR5 LAI support
  gEfiCpRcPkgTokenSpaceGuid.PcdMrcDdr5ActvInterposerSupport|TRUE

  # Memory Training phase
  gEfiCpRcPkgTokenSpaceGuid.PcdMrcTcoCompTrainingEnable|TRUE

  # Turnaround Optimization
  gEfiCpRcPkgTokenSpaceGuid.PcdMrcTurnaroundOptimizations|FALSE
  gEfiCpRcPkgTokenSpaceGuid.PcdMrcTurnaroundOptimizationsDdrt|TRUE

  # Enable NVDIMM support
  gEfiCpRcPkgTokenSpaceGuid.PcdNvDimmEn|TRUE

  # disable Optimized Cs Clk Sw Sweep
  gEfiCpRcPkgTokenSpaceGuid.PcdOptimizedCsClkSwSweep|FALSE

  # disable Optimized Ca Clk Sw Sweep
  gEfiCpRcPkgTokenSpaceGuid.PcdOptimizedCaClkSwSweep|FALSE

  # disable Optimized Bs Cs Clk Sw Sweep
  gEfiCpRcPkgTokenSpaceGuid.PcdOptimizedBsCsClkSwSweep|FALSE

  # disable Optimized Bs Ca Clk Sw Sweep
  gEfiCpRcPkgTokenSpaceGuid.PcdOptimizedBsCaClkSwSweep|FALSE

  # PPR type - soft PPR
  gEfiCpRcPkgTokenSpaceGuid.PcdPprTypeDefault|1

  # Additional Buffer Delay for Roundtrip
  gEfiCpRcPkgTokenSpaceGuid.PcdRoundTripBufferDelayDclk|10

  # BSSA RMT
  # Disable BSSA RMT as default setting value. User can change it in setup menu.
  gEfiCpRcPkgTokenSpaceGuid.PcdSsaBuiltInRmtEnable|0

  # Prints Tx Retraining verification information
  gEfiCpRcPkgTokenSpaceGuid.PcdTxRetrainVerification|FALSE

  # Memhot In defaults
  # 0 Disable
  # 1 Enable
  # Disable for SPR except Aurora platform
  # Enabled for all platforms except SPR
  gEfiCpRcPkgTokenSpaceGuid.PcdMemhotIn|0

  # Vendor MemTest
  gEfiCpRcPkgTokenSpaceGuid.PcdVendorMemtestEnable                |TRUE

  # Enable the non-executable DXE stack. (This gets set up by DxeIpl)
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetNxForStack|TRUE

  gEfiMdeModulePkgTokenSpaceGuid.PcdShadowPeimOnS3Boot|TRUE

  gSiPkgTokenSpaceGuid.PcdBiosDfxKnobEnabled|FALSE

[PcdsFixedAtBuild.X64]
# Per Security recommendation, PcdCpuSmmRestrictedMemoryAccess should only be false in non-production environments.
  gUefiCpuPkgTokenSpaceGuid.PcdCpuSmmRestrictedMemoryAccess|TRUE

[PcdsFeatureFlag]
  gCpuPkgTokenSpaceGuid.PcdCpuSapphireRapidsFamilyFlag|TRUE
  gCpuPkgTokenSpaceGuid.PcdCpuEmeraldRapidsFamilyFlag|FALSE
  gEfiCpRcPkgTokenSpaceGuid.PcdSsaFeatureSupported|TRUE

!if gEfiCpRcPkgTokenSpaceGuid.PcdSsaFeatureSupported == TRUE
  gEfiCpRcPkgTokenSpaceGuid.PcdSsaBuiltInRmtFeatureSupported|TRUE

  gEfiCpRcPkgTokenSpaceGuid.PcdSsaLoaderMethodFeatureSupported|FALSE

  gEfiCpRcPkgTokenSpaceGuid.PcdMemIOHealthCheckFeatureSupported|TRUE
!else
  gEfiCpRcPkgTokenSpaceGuid.PcdSsaBuiltInRmtFeatureSupported|FALSE
  gEfiCpRcPkgTokenSpaceGuid.PcdSsaLoaderMethodFeatureSupported|FALSE
  gEfiCpRcPkgTokenSpaceGuid.PcdMemIOHealthCheckFeatureSupported|FALSE
!endif

[PcdsDynamicExDefault]
  gEfiMdeModulePkgTokenSpaceGuid.PcdUse5LevelPageTable|FALSE