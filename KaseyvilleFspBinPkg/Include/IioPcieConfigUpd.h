/** @file
  Header file to define the structures used for FSPM dynamic configuration.
  @copyright
  INTEL CONFIDENTIAL
  Copyright 2021 Intel Corporation. <BR>
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

#ifndef _IIO_PCIE_CONFIG_UPD_H_
#define _IIO_PCIE_CONFIG_UPD_H_

#ifndef MAX_SOCKET
#define MAX_SOCKET                  1
#endif

#ifndef MAX_LOGIC_IIO_STACK
#define MAX_LOGIC_IIO_STACK        16
#endif

/**
 * Maximum number of IIO ports per IIO stack.
 */
#ifndef MAX_IIO_PORTS_PER_STACK
#define MAX_IIO_PORTS_PER_STACK    8
#endif

#define MAX_IIO_STACK                14
#define MAX_IIO_STACKS_PER_SOCKET    MAX_IIO_STACK
#define MAX_IIO_PORTS_PER_SOCKET   (MAX_IIO_STACKS_PER_SOCKET * MAX_IIO_PORTS_PER_STACK)

#define MAX_IIO_PCIE_PER_SOCKET      3

#define MAX_IOU_PER_SOCKET           MAX_IIO_PCIE_PER_SOCKET

#define IIO_BIFURCATE_xxxxxxxx          0xFE
#define IIO_BIFURCATE_x4x4x4x4          0x0
#define IIO_BIFURCATE_x4x4xxx8          0x1
#define IIO_BIFURCATE_xxx8x4x4          0x2
#define IIO_BIFURCATE_xxx8xxx8          0x3
#define IIO_BIFURCATE_xxxxxx16          0x4
#define IIO_BIFURCATE_x2x2x4x8          0x5
#define IIO_BIFURCATE_x4x2x2x8          0x6
#define IIO_BIFURCATE_x8x2x2x4          0x7
#define IIO_BIFURCATE_x8x4x2x2          0x8
#define IIO_BIFURCATE_x2x2x4x4x4        0x9
#define IIO_BIFURCATE_x4x2x2x4x4        0xA
#define IIO_BIFURCATE_x4x4x2x2x4        0xB
#define IIO_BIFURCATE_x4x4x4x2x2        0xC
#define IIO_BIFURCATE_x2x2x2x2x8        0xD
#define IIO_BIFURCATE_x8x2x2x2x2        0xE
#define IIO_BIFURCATE_x2x2x2x2x4x4      0xF
#define IIO_BIFURCATE_x2x2x4x2x2x4      0x10
#define IIO_BIFURCATE_x2x2x4x4x2x2      0x11
#define IIO_BIFURCATE_x4x2x2x2x2x4      0x12
#define IIO_BIFURCATE_x4x2x2x4x2x2      0x13
#define IIO_BIFURCATE_x4x4x2x2x2x2      0x14
#define IIO_BIFURCATE_x2x2x2x2x2x2x4    0x15
#define IIO_BIFURCATE_x2x2x2x2x4x2x2    0x16
#define IIO_BIFURCATE_x2x2x4x2x2x2x2    0x17
#define IIO_BIFURCATE_x4x2x2x2x2x2x2    0x18
#define IIO_BIFURCATE_x2x2x2x2x2x2x2x2  0x19

#define IIO_BIFURCATE_xxxxxxx4          0x40
#define IIO_BIFURCATE_xxx2xxx2          0x41
#define IIO_BIFURCATE_x1x1xxx2          0x42
#define IIO_BIFURCATE_xxx2x1x1          0x43
#define IIO_BIFURCATE_x1x1x1x1          0x44

#define IIO_BIFURCATE_AUTO              0xFF

#define C1_UID                              2
#define C2_UID                              3

#pragma pack(1)

typedef enum {
  PE0 = 0,
  PE1,
  PE2,
  PE3,
  PE4,
  PE5,
  PEa,
  PEb,
  PEc,
  PEd,
  PE_MAX,
  PE_ = 0xFF   // temporary unknown value
} IIO_PACKAGE_PE;

typedef struct {
  struct {
    UINT8  Segment;                                  ///< Remember segment, if it changes reset everything
    UINT8  StackPciBusPoolSize[MAX_LOGIC_IIO_STACK]; ///< Number of bus numbers needed for IIO stack
  } Socket[MAX_SOCKET];
} SYSTEM_PCI_BUS_CONFIGURATION;

typedef struct {
  UINT64 Base;    ///< Base (starting) address of a range (I/O, 32 and 64-bit mmio regions)
  UINT64 Limit;   ///< Limit (last valid) address of a range
} PCIE_BASE_LIMIT;

typedef struct {
  UINT32 MmioLSize;
  UINT64 MmioHSize;
} CXL11_LIMITS;

typedef struct {
  PCIE_BASE_LIMIT Io;        ///< Base and limit of I/O range assigned to entity
  PCIE_BASE_LIMIT LowMmio;   ///< Base and limit of low MMIO region for entity
  PCIE_BASE_LIMIT HighMmio;  ///< Base and limit of high (64-bit) MMIO region for entity
} PCI_BASE_LIMITS;

typedef struct {
  PCI_BASE_LIMITS StackLimits[MAX_LOGIC_IIO_STACK]; ///< Base and Limit of all PCIe resources for each stack of the socket
  CXL11_LIMITS    CxlStackReq[MAX_LOGIC_IIO_STACK]; ///< Base and Limit of CXL11 resources for each stack of the socket
} SOCKET_PCI_BASE_LIMITS;

typedef struct {
  //
  // Save basic system configuration parameters along with the resource map to detect a change.
  // Remember low and high I/O memory range when saving recource configuration. It is used to verify
  // whether system memory map changed. Remember also stacks configured when creating the map.
  // If anything changed reset the system PCI resource configuration.
  //
  UINT64                 MmioHBase;
  UINT64                 MmioHGranularity;
  UINT32                 MmioLBase;
  UINT32                 MmioLLimit;
  UINT32                 MmioLGranularity;
  UINT16                 IoBase;
  UINT16                 IoLimit;
  UINT16                 IoGranularity;
  UINT32                 StackPresentBitmap[MAX_SOCKET];
  //
  // Used by the PciHostBridge DXE driver, these variables don't need to be exposed through setup options
  // The variables are used as a communication vehicle from the PciHostBridge DXE driver to an OEM hook
  // which updates the KTI resource map.
  //
  SOCKET_PCI_BASE_LIMITS Socket[MAX_SOCKET];        ///< Base and limit of all PCIe resources for each socket
} SYSTEM_PCI_BASE_LIMITS;

typedef struct {
  UINT8    Address;     // SMBUS address of IO expander which provides VPP register
  UINT8    Port;        // Port or bank on IoExpander which provides VPP register
  UINT8    MuxAddress;  // SMBUS address of MUX used to access VPP
  UINT8    MuxChannel;  // Channel of the MUX used to access VPP
} IIO_VPP_CFG;

typedef struct {
  UINT8    Address;     // SMBUS address of IO expander which provides NPEM
  UINT8    Bank;        // Port or bank on IoExpander which provides NPEM
  UINT8    MuxAddress;  // SMBUS address of MUX used to access NPEM
  UINT8    MuxChannel;  // Channel of the MUX used to access NPEM
} IIO_NPEM_CFG;

typedef struct {
  UINT8    Eip             : 1;  // Electromechanical Interlock Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B17)
  UINT8    HotPlugSurprise : 1;  // Hot Plug surprise supported - Slot Capabilities (D0-10 / F0 / R0xA4 / B5)
  UINT8    PowerInd        : 1;  // Power Indicator Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B4)
  UINT8    AttentionInd    : 1;  // Attention Inductor Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B3)
  UINT8    PowerCtrl       : 1;  // Power Controller Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B1)
  UINT8    AttentionBtn    : 1;  // Attention Button Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B0)

  UINT8    Reserved        : 2;
} IIO_SLOT_CFG;

typedef struct {
  //
  // Below is an excerpt from structure PCIE_PORT_ENTERPRISE_CONFIG
  //
  IIO_VPP_CFG             Vpp;
  IIO_NPEM_CFG            Npem;
  IIO_SLOT_CFG            Slot;

  UINT8                   VppEnabled      :1;     // If VPP is supported on given port
  UINT8                   VppExpType      :1;     // IO Expander type used for VPP (see IIO_VPP_EXPANDER_TYPE for values definitions)
  UINT8                   NpemSupported   :1;     // If NPEM is supported on given port

  //
  // Below is an excerpt IIO_PCIE_PORT_CONFIG
  //
  UINT8                   SlotImplemented :1;
  UINT8                   Retimer1Present :1;
  UINT8                   Retimer2Present :1;
  UINT8                   CommonClock     :1;
  UINT8                   SRIS            :1;

  //
  // Below is an excerpt from structure PCIE_PORT_COMMON_CONFIG
  //
  UINT16                  HotPlug             :  1;  // If hotplug is supported on slot connected to this port
  UINT16                  MrlSensorPresent    :  1;  // If MRL is present on slot connected to this port
  UINT16                  SlotPowerLimitScale :  2;  // Slot Power Scale for slot connected to this port
  UINT16                  SlotPowerLimitValue : 12;  // Slot Power Value for slot connected to this port

  UINT16                  PhysicalSlotNumber;          // Slot number for slot connected to this port
} IIO_BOARD_SETTINGS_PER_PORT;

typedef enum {
  IioBifurcation_UNKNOWN = IIO_BIFURCATE_xxxxxxxx,
  IioBifurcation_x4x4x4x4 = IIO_BIFURCATE_x4x4x4x4,
  IioBifurcation_x4x4xxx8 = IIO_BIFURCATE_x4x4xxx8,
  IioBifurcation_xxx8x4x4 = IIO_BIFURCATE_xxx8x4x4,
  IioBifurcation_xxx8xxx8 = IIO_BIFURCATE_xxx8xxx8,
  IioBifurcation_xxxxxx16 = IIO_BIFURCATE_xxxxxx16,
  IioBifurcation_x2x2x4x8 = IIO_BIFURCATE_x2x2x4x8,
  IioBifurcation_x4x2x2x8 = IIO_BIFURCATE_x4x2x2x8,
  IioBifurcation_x8x2x2x4 = IIO_BIFURCATE_x8x2x2x4,
  IioBifurcation_x8x4x2x2 = IIO_BIFURCATE_x8x4x2x2,
  IioBifurcation_x2x2x4x4x4 = IIO_BIFURCATE_x2x2x4x4x4,
  IioBifurcation_x4x2x2x4x4 = IIO_BIFURCATE_x4x2x2x4x4,
  IioBifurcation_x4x4x2x2x4 = IIO_BIFURCATE_x4x4x2x2x4,
  IioBifurcation_x4x4x4x2x2 = IIO_BIFURCATE_x4x4x4x2x2,
  IioBifurcation_x2x2x2x2x8 = IIO_BIFURCATE_x2x2x2x2x8,
  IioBifurcation_x8x2x2x2x2 = IIO_BIFURCATE_x8x2x2x2x2,
  IioBifurcation_x2x2x2x2x4x4 = IIO_BIFURCATE_x2x2x2x2x4x4,
  IioBifurcation_x2x2x4x2x2x4 = IIO_BIFURCATE_x2x2x4x2x2x4,
  IioBifurcation_x2x2x4x4x2x2 = IIO_BIFURCATE_x2x2x4x4x2x2,
  IioBifurcation_x4x2x2x2x2x4 = IIO_BIFURCATE_x4x2x2x2x2x4,
  IioBifurcation_x4x2x2x4x2x2 = IIO_BIFURCATE_x4x2x2x4x2x2,
  IioBifurcation_x4x4x2x2x2x2 = IIO_BIFURCATE_x4x4x2x2x2x2,
  IioBifurcation_x2x2x2x2x2x2x4 = IIO_BIFURCATE_x2x2x2x2x2x2x4,
  IioBifurcation_x2x2x2x2x4x2x2 = IIO_BIFURCATE_x2x2x2x2x4x2x2,
  IioBifurcation_x2x2x4x2x2x2x2 = IIO_BIFURCATE_x2x2x4x2x2x2x2,
  IioBifurcation_x4x2x2x2x2x2x2 = IIO_BIFURCATE_x4x2x2x2x2x2x2,
  IioBifurcation_x2x2x2x2x2x2x2x2 = IIO_BIFURCATE_x2x2x2x2x2x2x2x2,

  // Specific values for DMR pcie4p4 controller for infrastructure lanes
  IioBifurcation_xxxxxxx4 = IIO_BIFURCATE_xxxxxxx4,
  IioBifurcation_xxx2xxx2 = IIO_BIFURCATE_xxx2xxx2,
  IioBifurcation_x1x1xxx2 = IIO_BIFURCATE_x1x1xxx2,
  IioBifurcation_xxx2x1x1 = IIO_BIFURCATE_xxx2x1x1,
  IioBifurcation_x1x1x1x1 = IIO_BIFURCATE_x1x1x1x1,

  IioBifurcation_Auto = IIO_BIFURCATE_AUTO
} IIO_BIFURCATION;

typedef struct {
  IIO_BIFURCATION         Bifurcation;
  UINT8                   CxlSupportInUba  :1;
  UINT8                   Reserved         :7;

  IIO_BOARD_SETTINGS_PER_PORT Port[MAX_IIO_PORTS_PER_STACK];
} IIO_BOARD_SETTINGS_PER_PE;

typedef struct {
  IIO_BOARD_SETTINGS_PER_PE   Pe[MAX_IIO_PCIE_PER_SOCKET];
} IIO_BOARD_SETTINGS_PER_SOCKET;

//
// HOB to store board settings data created based on UBA data
//
typedef struct {
  IIO_BOARD_SETTINGS_PER_SOCKET Socket[MAX_SOCKET];
} IIO_BOARD_SETTINGS_HOB;

#pragma pack()

#endif // _IIO_PCIE_CONFIG_UPD_H_