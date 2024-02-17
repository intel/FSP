/** @file

  @copyright
  Copyright (C) 2023 Intel Corporation

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _SILICON_UPD_UPDATE_H_
#define _SILICON_UPD_UPDATE_H_

#include <FspEas.h>

#define MAX_IIO_PORTS_PER_SOCKET   57
#define MAX_IOU_PER_SOCKET         7
#define MAX_VMD_STACKS_PER_SOCKET  8

#pragma pack(1)

typedef struct {
  UINT8    SLOTEIP[MAX_IIO_PORTS_PER_SOCKET];          // Electromechanical Interlock Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B17)
  UINT8    SLOTHPCAP[MAX_IIO_PORTS_PER_SOCKET];        // Slot Hot Plug capable - Slot Capabilities (D0-10 / F0 / R0xA4 / B6)
  UINT8    SLOTHPSUP[MAX_IIO_PORTS_PER_SOCKET];        // Hot Plug surprise supported - Slot Capabilities (D0-10 / F0 / R0xA4 / B5)
  UINT8    SLOTPIP[MAX_IIO_PORTS_PER_SOCKET];          // Power Indicator Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B4)
  UINT8    SLOTAIP[MAX_IIO_PORTS_PER_SOCKET];          // Attention Inductor Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B3)
  UINT8    SLOTMRLSP[MAX_IIO_PORTS_PER_SOCKET];        // MRL Sensor Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B2)
  UINT8    SLOTPCP[MAX_IIO_PORTS_PER_SOCKET];          // Power Controller Present - Slot Capabilities (D0-10 / F0 / R0xA4 /B1)
  UINT8    SLOTABP[MAX_IIO_PORTS_PER_SOCKET];          // Attention Button Present - Slot Capabilities (D0-10 / F0 / R0xA4 / B0)
  UINT8    SLOTIMP[MAX_IIO_PORTS_PER_SOCKET];
  UINT8    SLOTSPLS[MAX_IIO_PORTS_PER_SOCKET];
  UINT8    SLOTSPLV[MAX_IIO_PORTS_PER_SOCKET];
  UINT16   SLOTPSP[MAX_IIO_PORTS_PER_SOCKET];
  BOOLEAN  VppEnabled[MAX_IIO_PORTS_PER_SOCKET];        // 00 -- Disable, 01 -- Enable  //no setup option defined- aj
  UINT8    VppPort[MAX_IIO_PORTS_PER_SOCKET];           // 00 -- Port 0, 01 -- Port 1   //no setup option defined- aj
  UINT8    VppAddress[MAX_IIO_PORTS_PER_SOCKET];        // 01-07 for SMBUS address of Vpp   //no setup option defined- aj
  UINT8    MuxAddress[MAX_IIO_PORTS_PER_SOCKET];        // SMBUS address of MUX              //no setup option defined
  UINT8    ChannelID[MAX_IIO_PORTS_PER_SOCKET];         // 00 -- channel 0, 01 -- channel 1  //no setup option defined

  UINT8    PciePortEnable[MAX_IIO_PORTS_PER_SOCKET];
  UINT8    PEXPHIDE[MAX_IIO_PORTS_PER_SOCKET];          // Hide any of the DMI or PCIE devices - SKT 0,1,2,3; Device 0-10 PRD
  UINT8    HidePEXPMenu[MAX_IIO_PORTS_PER_SOCKET];      // to suppress /display the PCIe port menu
  UINT8    PciePortOwnership[MAX_IIO_PORTS_PER_SOCKET];
  UINT8    RetimerConnectCount[MAX_IIO_PORTS_PER_SOCKET];
  UINT8    ConfigIOU[MAX_IOU_PER_SOCKET];               // 00-x4x4x4x4, 01-x4x4x8NA, 02-x8NAx4x4, 03-x8NAx8NA, 04-x16 (P1p2p3p4)
  UINT8    PcieHotPlugOnPort[MAX_IIO_PORTS_PER_SOCKET]; // Manual override of hotplug for port
  UINT8    VMDEnabled[MAX_VMD_STACKS_PER_SOCKET];
  UINT8    VMDPortEnable[MAX_IIO_PORTS_PER_SOCKET];
  UINT8    VMDHotPlugEnable[MAX_VMD_STACKS_PER_SOCKET];
  UINT8    PcieMaxPayload[MAX_IIO_PORTS_PER_SOCKET];
  UINT8    PciePortLinkSpeed[MAX_IIO_PORTS_PER_SOCKET]; // auto - 0(default); gen1 -1; gen2 -2; ... gen5 -5.
  UINT8    DfxDnTxPresetGen3[MAX_IIO_PORTS_PER_SOCKET]; //auto - 0xFF(default); p0 - 0; p1 -1; ... p9 - 9.
  UINT8    PcieGlobalAspm;
  UINT8    PcieMaxReadRequestSize;
} UPD_IIO_PCIE_PORT_CONFIG;

// IIO_PCIE_PORT_CONFIG:
// PciePortConfiguration - Pointer to an array of PCIe port configuration structures as declared above
// NumberOfEntries       - Number of elements in the PciePortConfiguration Array

typedef struct {
  UPD_IIO_PCIE_PORT_CONFIG  *ConfigurationTable;
  UINT16                     NumberOfEntries;
} IIO_PCIE_PORT_CONFIG;
#pragma pack()

#endif
