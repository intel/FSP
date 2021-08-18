/** @file UpiConfig.h

  @copyright
  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _UPI_CONFIG_H_
#define _UPI_CONFIG_H_

#include <FspEas.h>

#pragma pack(1)

/**
  Per Lane PHY Configuration

  These PHY settings are system dependent. Every socket/link/freq requires an instance of this structure.
**/
typedef struct {
  UINT8  SocketID;              ///< Socket ID
  UINT8  AllLanesUseSameTxeq;   ///< Use same TXEQ on all lanes
  UINT8  Freq;                  ///< The Link Speed these TXEQ settings should be used for
  UINT32 Link;                  ///< Port Number
  UINT32 TXEQL[20];             ///< TXEQ Settings
  UINT32 CTLEPEAK[5];           ///< CTLE Peaking Settings
} PER_LANE_EPARAM_LINK_INFO;

/**
  All Lanes PHY Configuration

  This is for full speed mode, all lanes have the same TXEQ setting
**/
typedef struct {
  UINT8  SocketID;              ///< Socket ID
  UINT8  Freq;                  ///< The Link Speed these TXEQ settings should be used for
  UINT32 Link;                  ///< Port Number
  UINT32 AllLanesTXEQ;          ///< TXEQ Setting
  UINT8  CTLEPEAK;              ///< CTLE Peaking Setting
} ALL_LANES_EPARAM_LINK_INFO;

#pragma pack()

#endif // _UPI_CONFIG_H_
