/** @file
  FSP Output HOB: SystemMemoryMap

  @copyright

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

#ifndef _FSP_EXT_SYSTEM_MEMORY_MAP_HOB_H_
#define _FSP_EXT_SYSTEM_MEMORY_MAP_HOB_H_

#include "FspGlobals.h"

#define FSP_EXT_SYSTEM_MEMORY_MAP_HOB_GUID   { 0xDF310DE8, 0x579F, 0x419C, { 0xB6, 0xAB, 0x4D, 0x4B, 0xE7, 0xCA, 0xB0, 0x83 } }

#pragma pack(1)

typedef struct FspDimmDevice {
  UINT8     Present;
  BOOLEAN   Enabled;
  UINT8     DramIoWidth;                                               // Actual DRAM IO Width (4, 8, 16)
  UINT8     NumRanks;                                                  // Number of ranks on dimm
  UINT8     NumPackageRanks;                                           // Number of Package ranks on dimm
                                                                       // For DDR5 NumRanks and NumPackageRanks same
                                                                       // For MRDIMM NumRanks and NumPackageRanks may differ
  UINT8     ActKeyByte2;                                               // Actual module type reported by SPD
  UINT16    DimmSize;
  UINT16    VendorID;
  UINT16    DeviceID;
  UINT16    RevisionID;
  UINT8     SerialNumber[FSP_DIMM_MAX_SERIALNUMBER_LEN];                 // Serial Number
  UINT8     PartNumber[FSP_DIMM_MAX_PARTNUMBER_LEN];                     // Part Number
  UINT16    SubsystemVendorID;
  UINT16    SubsystemDeviceID;
  UINT16    SubsystemRevisionID;
  UINT16    FisVersion;                                                // Firmware Interface Specification version
  INT32     CommonTck;
  UINT16    SpdRegVen;                                                 // Register Vendor ID in SPD
  UINT8     DataWidth;
} FSP_EXT_DIMM_DEVICE;

typedef struct FspExtMemoryDimmDeviceInfo {
  UINT8                         Count;
  FSP_EXT_DIMM_DEVICE           Dimms[FSP_MAX_DIMM];
} FSP_EXT_DIMM_DEVICE_INFO;

typedef struct FspMemoryChannelDevice {
  UINT8                               Enabled;                            // 0 = channel disabled, 1 = channel enabled
  UINT8                               Features;                           // Bit mask of features to enable or disable
  UINT8                               MaxDimm;                            // Number of DIMM
  UINT8                               ChFailed;
  UINT8                               NgnChFailed;
  UINT8                               Is4BitEccDimmPresent;               // 4-bit Ecc dimm present indicator
  UINT8                               DdrPopulationMap;                   // Bitmap to indicate location of DDR DIMMs within the channel memory slots (BIT0: Ch.D0, BIT1: CH.D1)
  UINT8                               PmemPopulationMap;                  // Bitmap to indicate location of PMem modules within the channel memory slots (BIT0: Ch.D0, BIT1: CH.D1)
  FSP_EXT_DIMM_DEVICE_INFO            DimmInfo;
} FSP_EXT_MEMORY_CHANNEL_DEVICE;

typedef struct FspMemoryController {
  UINT8   ImcEnabled;
  UINT32  MemSize;
} FSP_EXT_MEMORY_CONTROLLER;

typedef struct FspExtMemoryChannelDeviceInfo {
  UINT8                         Count;
  FSP_EXT_MEMORY_CHANNEL_DEVICE Devices[FSP_MAX_CH];
} FSP_EXT_MEMORY_CHANNEL_DEVICE_INFO;

typedef struct FspExtMemoryControllerInfo {
  UINT8                         Count;
  UINT8                         NumChPerMC;
  FSP_EXT_MEMORY_CONTROLLER     MemControllers[FSP_MAX_IMC];
} FSP_EXT_MEMORY_CONTROLLER_INFO;

typedef struct FspMemoryMapSocket {
  UINT8                                  SocketEnabled;
  UINT32                                 IioStackBitmap;
  UINT32                                 SktTotMemMapSPA;       // Total memory mapped to SPA
  FSP_EXT_MEMORY_CONTROLLER_INFO         MemoryControllerInfo;
  FSP_EXT_MEMORY_CHANNEL_DEVICE_INFO     MemoryChannelDeviceInfo;
} FSP_EXT_MEMORY_MAP_SOCKET;

typedef struct FspExtMemMapSocketInfo {
  UINT8                         Count;
  FSP_EXT_MEMORY_MAP_SOCKET     Sockets[FSP_MAX_SOCKET];
} FSP_EXT_MEMORY_MAP_SOCKET_INFO;

typedef struct FspMemoryMapElement {
  UINT16   Type;           // Type of this memory element; Bit0: 1LM  Bit1: 2LM  Bit2: PMEM  Bit3: PMEM-cache  Bit4: BLK Window  Bit5: CSR/Mailbox/Ctrl region
  UINT8    NodeId;         // Node ID of the HA Owning the memory
  UINT8    SocketId;       // Socket Id of socket that has his memory - ONLY IN NUMA
  UINT8    ClusterId;      // Logical cluster Id of SNC cluster - only 0 in UMA clustering and all2all
  UINT32   BaseAddress;    // Base Address of the element in 64MB chunks
  UINT32   ElementSize;    // Size of this memory element in 64MB chunks
} FSP_EXT_MEMORY_MAP_ELEMENT;

typedef struct FspExtMemMapElementInfo {
  UINT8                         Count;
  FSP_EXT_MEMORY_MAP_ELEMENT    Elements[FSP_MAX_MEMORY_MAP_ELEMENTS];
} FSP_EXT_MEMORY_MAP_ELEMENT_INFO;

typedef struct FspExtRasInfo {
  UINT8    SystemRasType;
  UINT8    RasModesEnabled;                       // RAS modes that are enabled
  UINT16   ExRasModesEnabled;                     // Extended RAS modes that are enabled
} FSP_EXT_RAS_INFO;

typedef struct FspExtMemoryConfigurationInfo {
  UINT32   LowMemBase;                            // Mem base in 64MB units for below 4GB mem.
  UINT32   LowMemSize;                            // Mem size in 64MB units for below 4GB mem.
  UINT32   HighMemBase;                           // Mem base in 64MB units for above 4GB mem.
  UINT32   HighMemSize;                           // Mem size in 64MB units for above 4GB mem.
  UINT32   MmiohBase;                             // MMIOH base in 64MB granularity
  UINT32   MemSize;                               // Total physical memory size
  UINT16   MemFreq;
  UINT8    MemMode;                               // 0 - Independent, 1 - Lockstep
  UINT8    VolMemMode;                            // 0 - 1LM, 1 - 2LM
  UINT16   DramType;
  UINT8    DdrVoltage;                            // Mem Frequency
  UINT8    ErrorCorrectionType;
} FSP_EXT_MEMORY_CONFIGURATION_INFO;

typedef struct FspExtSystemMemoryMapData {
  FSP_EXT_MEMORY_CONFIGURATION_INFO      MemoryConfigurationInfo;
  FSP_EXT_RAS_INFO                       RasInfo;
  FSP_EXT_MEMORY_MAP_ELEMENT_INFO        MemoryMapElementInfo;
  FSP_EXT_MEMORY_MAP_SOCKET_INFO         MemoryMapSocketInfo;
} FSP_EXT_SYSTEM_MEMORY_MAP_DATA;

typedef struct FspExtSystemMemoryMapDataHob{
  FSP_EXT_HEADER                        Header;
  FSP_EXT_SYSTEM_MEMORY_MAP_DATA        Data;
} FSP_EXT_SYSTEM_MEMORY_MAP_HOB;

#pragma pack()

#endif // _FSP_EXT_SYSTEM_MEMORY_MAP_HOB_H_
