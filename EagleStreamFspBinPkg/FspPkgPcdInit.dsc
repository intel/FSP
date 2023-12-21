## @file
# EagleStreamFspBinPkg Init PCDs
#
# @copyright
# Copyright (C) 2023 Intel Corporation
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

[PcdsFixedAtBuild]
  ##@note PcdFspImageIdString and PcdVpdRegionSign must be identical. Don't change one without the other.
  gEagleStreamFspPkgTokenSpaceGuid.PcdFspImageIdString         | 0x2450532d52505324  #$SPR-SP$
  gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask               | 0x2F
  gEfiMdePkgTokenSpaceGuid.PcdReportStatusCodePropertyMask    | 0x07
  gIntelFsp2PkgTokenSpaceGuid.PcdTemporaryRamBase             | 0xFE800000
  gIntelFsp2PkgTokenSpaceGuid.PcdTemporaryRamSize             | 0x00200000
  gIntelFsp2PkgTokenSpaceGuid.PcdFspTemporaryRamSize          | 0x00060000
  gIntelFsp2PkgTokenSpaceGuid.PcdFspReservedBufferSize        | 0x00000100
  gIntelFsp2PkgTokenSpaceGuid.PcdFspAreaBaseAddress           | 0xFFDE5000
  gIntelFsp2PkgTokenSpaceGuid.PcdFspAreaSize                  | 0x00212000
  gPlatformTokenSpaceGuid.PcdSecInFsp                         | 1
  gEfiCpRcPkgTokenSpaceGuid.PcdPeiTemporaryRamRcHeapBase      | 0xFE800000

  gUefiCpuPkgTokenSpaceGuid.PcdCpuApInitTimeOutInMicroSeconds|200000
  gUefiCpuPkgTokenSpaceGuid.PcdCpuMaxLogicalProcessorNumber|1024

  ## Specifies delay value in microseconds after sending out an INIT IPI.
  # @Prompt Configure delay value after send an INIT IPI
  gUefiCpuPkgTokenSpaceGuid.PcdCpuInitIpiDelayInMicroSeconds|10
  ## Specifies max supported number of Logical Processors.
  # @Prompt Configure max supported number of Logical Processorss
  gUefiCpuPkgTokenSpaceGuid.PcdCpuApStackSize|0x2000

  # x % of FSP temporary memory will be used for heap
  # (100 - x) % of FSP temporary memory will be used for stack
  gIntelFsp2PkgTokenSpaceGuid.PcdFspHeapSizePercentage        | 0

  # This is a platform specific global pointer used by FSP
  # For 10nmSoc it points to HPET comparison register
  gIntelFsp2PkgTokenSpaceGuid.PcdGlobalDataPointerAddress     | 0xFED00148

  # Set FSP Reserved Memory to 32MB.
  gIntelFsp2PkgTokenSpaceGuid.PcdFspReservedMemoryLength    | 0x14000000

# gEfiMdeModulePkgTokenSpaceGuid.PcdSerialPciDeviceInfo PCD defines the data members of the PCI_UART_DEVICE_INFO structure in the following format:
# {Device, Function, PowerManagementStatusAndControlRegister[7:0], PowerManagementStatusAndControlRegister[15:8], 0xFF (terminator)}
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialPciDeviceInfo|{0x1A,0x00,0x00,0x00,0xFF}
  gEfiMdeModulePkgTokenSpaceGuid.PcdPeiCoreMaxPeiStackSize|0x100000
  gPlatformTokenSpaceGuid.PcdBiosGuardPlatIdStr|$(PLATFORM_ID_STR)

!if $(PREMEM_PAGE_ALLOC_SUPPORT) == FALSE
  gEfiCpRcPkgTokenSpaceGuid.PcdPeiTemporaryRamRcHeapSize|0x150000
!endif

  gEfiCpRcPkgTokenSpaceGuid.PcdEnforcePopulationPorDefault|1

  #CLTT settings
  gEfiCpRcPkgTokenSpaceGuid.PcdClttTempMinLimit                   |0
  gEfiCpRcPkgTokenSpaceGuid.PcdClttTempMaxLimit                   |100
  gEfiCpRcPkgTokenSpaceGuid.PcdClttTempLoSingleRefreshDefault     |82
  gEfiCpRcPkgTokenSpaceGuid.PcdClttTempMidSingleRefreshDefault    |83
  gEfiCpRcPkgTokenSpaceGuid.PcdClttTempHiSingleRefreshDefault     |85

  gEfiCpRcPkgTokenSpaceGuid.PcdClttTempLoDoubleRefreshDefault     |83
  gEfiCpRcPkgTokenSpaceGuid.PcdClttTempMidDoubleRefreshDefault    |93
  gEfiCpRcPkgTokenSpaceGuid.PcdClttTempHiDoubleRefreshDefault     |95

  gSiPkgTokenSpaceGuid.PcdTwoxRefreshValue|83

  gEfiCpRcPkgTokenSpaceGuid.PcdMrcQosLowTimerLim |0x200
  gEfiCpRcPkgTokenSpaceGuid.PcdMrcQosMedTimerLim |0x200
  gEfiCpRcPkgTokenSpaceGuid.PcdMrcQosHighTimerLim|0x200

  gIntelFsp2PkgTokenSpaceGuid.PcdFspHeaderSpecVersion|0x23

  gSiPkgTokenSpaceGuid.PcdFspBinaryEnable                  |FALSE
  gSiPkgTokenSpaceGuid.PcdSmbusBaseAddress                 |0x0780
  gSiPkgTokenSpaceGuid.PcdTcoBaseAddress                   |0x0400
  gSiPkgTokenSpaceGuid.PcdAcpiBaseAddress                  |0x500
  gSiPkgTokenSpaceGuid.PcdPostedCsrAccessAllowedDefault    |TRUE
  gSiPkgTokenSpaceGuid.PcdMaxDdrioIpChannels               |0x02
  gSiPkgTokenSpaceGuid.PcdMaxMcIpChannels                  |0x02
  gSiPkgTokenSpaceGuid.PcdSenseAmpCalibHwFsmSupported      |TRUE
  gSiPkgTokenSpaceGuid.PcdHwSweepSupported                 |FALSE

!if $(PERFORMANCE_ENABLE) == TRUE
  gEfiMdePkgTokenSpaceGuid.PcdPerformanceLibraryPropertyMask|0x1
  gEfiMdeModulePkgTokenSpaceGuid.PcdEdkiiFpdtStringRecordEnableOnly|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdMaxPeiPerformanceLogEntries|100
  gEfiMdeModulePkgTokenSpaceGuid.PcdExtFpdtBootRecordPadSize|0x20000
!endif

[PcdsPatchableInModule]
  gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel            | (0x80000000 + 0x00000040 + 0x00000002)

  gEfiMdePkgTokenSpaceGuid.PcdPciExpressBaseAddress           | 0x80000000
  #
  # This entry will be patched during the build process
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdVpdBaseAddress            | 0x12345678
  gUefiCpuPkgTokenSpaceGuid.PcdCpuNumberOfReservedVariableMtrrs|0
