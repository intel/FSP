/** @file
  Data format for IIO Universal Data HOB Structure

  @copyright

  Copyright 1999 - 2023 Intel Corporation. <BR>

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

#ifndef _IIO_UNIVERSAL_DATA_HOB_H_
#define _IIO_UNIVERSAL_DATA_HOB_H_

#define IIO_UNIVERSAL_DATA_GUID { 0x7FF396A1, 0xEE7D, 0x431E, { 0xBA, 0x53, 0x8F, 0xCA, 0x12, 0x7C, 0x44, 0xC0 } }

#ifndef MAX_SOCKET
#define MAX_SOCKET              1
#endif

#if (MAX_SOCKET == 1)
  #define MAX_FW_KTI_PORTS     4    // Maximum KTI PORTS to be used in structure definition.
#else
  #define MAX_FW_KTI_PORTS     6    // Maximum KTI PORTS to be used in structure definition
#endif //(MAX_SOCKET == 1)

#define MAX_LOGIC_IIO_STACK          16

#ifndef MAX_IIO_PCIROOTS_PER_STACK
#define MAX_IIO_PCIROOTS_PER_STACK   5   // PCI roots that can be created for a stack
#endif

#define MAX_COMPUTE_DIE              2
#define MAX_CHA_MAP                  (2 * MAX_COMPUTE_DIE)  //for GNR & SRF only, each compute die has its own CAPID6 & CAPID7 (i.e. 2 CAPID registers)

#ifndef MAX_MESSAGE_LENGTH
#define MAX_MESSAGE_LENGTH  500
#endif

#define DINO_UID                            0
#define PC_UID                              1
#define UB_UID                              4
#define CPM0_UID                            5
#define HQM0_UID                            6

typedef enum {
  IioStack0 = 0,
  IioStack1 = 1,
  IioStack2 = 2,
  IioStack3 = 3,
  IioStack4 = 4,
  IioStack5 = 5,
  IioStack6 = 6,
  IioStack7 = 7,
  IioStack8 = 8,
  IioStack9 = 9,
  IioStack10 = 10,
  IioStack11 = 11,
  IioStack12 = 12,
  IioStack13 = 13,
  IioStack14 = 14,
  IioStack15 = 15,
  IioStack16 = 16,
  IioStackUnknown = 0xFF
} IIO_STACK;

//--------------------------------------------------------------------------------------//
// Structure definitions for Universal Data Store (UDS)
//--------------------------------------------------------------------------------------//
#pragma pack(1)

typedef struct {
  UINT8                     Valid;         // TRUE, if the link is valid (i.e reached normal operation)
  UINT8                     PeerSocId;     // Socket ID
  UINT8                     PeerSocType;   // Socket Type (0 - CPU; 1 - IIO)
  UINT8                     PeerPort;      // Port of the peer socket
} QPI_PEER_DATA;

typedef struct {
  UINT8                     Valid;
  UINT8                     PcieSegment;
  UINT64                    SegMmcfgBase;
  UINT32                    StackPresentBitmap;
  UINT16                    Cxl1p1PresentBitmap; // Bitmap of stacks where CXL 1p1 is connected
  UINT16                    CxlCapableBitmap;    // Bitmap of stacks capable of CXL
  UINT8                     TotCha;
  UINT32                    SocId;
  QPI_PEER_DATA             PeerInfo[MAX_FW_KTI_PORTS];    // QPI LEP info
} QPI_CPU_DATA;

/**
 * PCI resources that establish one PCI hierarchy for PCI Enumerator.
 */
typedef struct {
  UINT16                  UidType;               // Type of UID for this root bridge.
  UINT8                   BusBase;               // Base of PCI bus numbers available for PCI devices
  UINT8                   BusLimit;              // Limit of PCI bus numbers available for PCI devices
  UINT16                  IoBase;                // Base of IO resources available for PCI devices
  UINT16                  IoLimit;               // Limit of IO resources available for PCI devices
  UINT32                  Mmio32Base;            // Base of low MMIO resources available for PCI devices
  UINT32                  Mmio32Limit;           // Limit of low MMIO resources available for PCI devices
  UINT64                  Mmio64Base;            // Base of high MMIO resources available for PCI devices
  UINT64                  Mmio64Limit;           // Limit of high MMIO resources available for PCI devices
} UDS_PCIROOT_RES;

/**
 * This structore keeps resources configured in Host I/O Processor (HIOP) for one stack.
 * One HIOP may produce more than one PCI hierarchy, these are in PciRoot[] table.
 */
typedef struct {
  UINT8                   Personality;
  UINT8                   PciRootBridgeNum;      // Number of valid entries in PciRoot[] table
  UINT8                   Segment;               // Segment for this stack
  UINT8                   BusBase;               // Base of Bus configured for this stack
  UINT8                   BusLimit;              // Limit of Bus configured for this stack
  UINT8                   Reserved[3];           // Reserved for alignment
  UINT16                  IoBase;                // Base of IO configured for this stack
  UINT16                  IoLimit;               // Limit of IO configured for this stack
  UINT16                  IoMinSize;             // The size of IO that must be preserved in rebalance
  UINT32                  Mmio32Base;            // Base of low MMIO configured for this stack in memory map
  UINT32                  Mmio32Limit;           // Limit of low MMIO configured for this stack in memory map
  UINT32                  Mmio32MinSize;         // The size of MMIO32 that must be preserved in rebalance
  UINT64                  Mmio64Base;            // Base of high MMIO configured for this stack in memory map
  UINT64                  Mmio64Limit;           // Limit of high MMIO configured for this stack in memory map
  UINT64                  Mmio64MinSize;         // The size of MMIO64 that must be preserved in rebalance
  UINT64                  VtbarAddress;          // VT-d Base Address
  UINT64                  ChbcrBarAddress;       // CXL Host Bridge Component Registers (CHBCR) region
  UDS_PCIROOT_RES         PciRoot[MAX_IIO_PCIROOTS_PER_STACK];
} UDS_STACK_RES;

/**
 * This structore keeps resource ranges configured in one socket. It contains a table of IO stacks provided by
 // the socket. The stacks are also groupded by IO dies, but dies are not reflected in UDS.
 */
typedef struct {
  UINT8                   Valid;
  UINT8                   SocketID;               // Socket ID of the IIO (0..3)
  UINT16                  IoBase;
  UINT16                  IoLimit;
  UINT32                  Mmio32Base;             // Base of low MMIO configured for this socket in memory map
  UINT32                  Mmio32Limit;            // Limit of low MMIO configured for this socket in memory map
  UINT64                  Mmio64Base;             // Base of high MMIO configured for this socket in memory map
  UINT64                  Mmio64Limit;            // Limit of high MMIO configured for this socket in memory map
  UDS_STACK_RES           StackRes[MAX_LOGIC_IIO_STACK];
} UDS_SOCKET_RES;

/**
 * This structore keeps resource ranges configured in whole system.
 */
typedef struct {
  UINT16                  SystemIoBase;           // System IO Base
  UINT16                  SystemIoLimit;          // System IO Limit
  UINT32                  SystemIoApicBase;       // Legacy IOAPIC base address, one in the system
  UINT32                  SystemIoApicLimit;
  UINT32                  SystemMmio32Base;       // System low MMIO base
  UINT32                  SystemMmio32Limit;      // System low MMIO limit
  UINT64                  SystemMmio64Base;       // System high MMIO Base
  UINT64                  SystemMmio64Limit;      // System high MMIO Limit
  QPI_CPU_DATA            CpuQpiInfo[MAX_SOCKET]; // QPI related info per CPU
  UINT64                  PciExpressBase;         // PCI Config Space base address
  UINT64                  PciExpressSize;         // PCI Config Space size
  UDS_SOCKET_RES          IIO_resource[MAX_SOCKET];
  UINT32                  packageBspApicID[MAX_SOCKET]; // This data array is valid only for SBSP, not for non-SBSP CPUs. <AS> for CpuSv
  UINT16                  IoGranularity;
  UINT32                  Mmio32Granularity;
  UINT64                  Mmio64Granularity;
  UINT32                  UboxMmioSize;
  UINT32                  MemTolm;
  UINT32                  MemTsegSize;
  UINT32                  MaxAddressBits;
} PLATFORM_DATA;

typedef struct {
    BOOLEAN                 FailFlag;
    CHAR16                  Message[MAX_MESSAGE_LENGTH];
} REBALANCE_FAIL_INFO;

typedef struct {
    UINT8                   CurrentUpiiLinkSpeed;    // Current programmed UPI Link speed (Slow/Full speed mode)
    UINT8                   CurrentUpiLinkFrequency; // Current requested UPI Link frequency (in GT)
    UINT8                   OutKtiCpuSktHotPlugEn;            // 0 - Disabled, 1 - Enabled for PM X2APIC
    UINT32                  meRequestedSize;        // Size of the memory range requested by ME FW, in MB
    UINT8                   SystemRasType;
    UINT8                   numCpus;           // 1,..4. Total number of CPU packages installed and detected (1..4)by QPI RC
    UINT8                   OutSncEn;
    UINT8                   OutNumOfCluster;
    UINT8                   BitsUsed;    //For 5 Level Paging
    REBALANCE_FAIL_INFO     RebalanceFailInfo;
} SYSTEM_STATUS;

typedef struct {
    PLATFORM_DATA           PlatformData;
    SYSTEM_STATUS           SystemStatus;
    UINT32                  OemValue;
} IIO_UDS;

#pragma pack()

#endif  // _IIO_UNIVERSAL_DATA_HOB_H_

