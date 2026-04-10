/** @file
  FSP Output HOB: MemoryPpr

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

#ifndef _FSP_EXT_MEMORY_PPR_HOB_H_
#define _FSP_EXT_MEMORY_PPR_HOB_H_

#include "FspGlobals.h"

#define FSP_EXT_MEMORY_PPR_HOB_GUID   { 0x3956C6DA, 0x35B6, 0x4036, { 0x93, 0xE4, 0xB1, 0x51, 0x38, 0x60, 0x21, 0x1E } }

#pragma pack(1)

typedef struct FspExtPprAddr {
  UINT8               Status;
  UINT8               ErrorType;
  UINT8               Socket;
  UINT8               MemoryController;
  UINT8               Channel;
  UINT8               Dimm;
  UINT8               Bank;
  UINT32              Row;
  UINT8               Rank;
} FSP_EXT_PPR_ADDR;

typedef struct FspExtPprDdrInfo {
  UINT8               Count;
  FSP_EXT_PPR_ADDR    PprAddresses[FSP_MAX_PPR_ADDR_ENTRIES_DDR];
} FSP_EXT_DDR_PPR_INFO;

typedef struct FspExtMemoryPprData {
  FSP_EXT_DDR_PPR_INFO          DdrPprInfo;
} FSP_EXT_MEMORY_PPR_DATA;

typedef struct FspExtMemoryPprHob {
  FSP_EXT_HEADER                Header;
  FSP_EXT_MEMORY_PPR_DATA       Data;
} FSP_EXT_MEMORY_PPR_HOB;

#pragma pack()

#endif // _FSP_EXT_MEMORY_PPR_HOB_H_
