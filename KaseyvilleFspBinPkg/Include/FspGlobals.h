/** @file
  FSP Output HOB: SystemMemoryMap

  @copyright
  INTEL CONFIDENTIAL
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

#ifndef _FSP_EXT_GLOBALS_
#define _FSP_EXT_GLOBALS_

#define FSP_MAX_SOCKET                      MAX_SOCKET
#define FSP_MAX_IMC                         MAX_IMC
#define FSP_MAX_MC_CH                       MAX_MC_CH
#define FSP_MAX_DIMM                        MAX_DIMM
#define FSP_DIMM_MAX_SERIALNUMBER_LEN       NGN_MAX_SERIALNUMBER_STRLEN
#define FSP_DIMM_MAX_PARTNUMBER_LEN         NGN_MAX_PARTNUMBER_STRLEN
#define FSP_MAX_CH                          ((FSP_MAX_IMC)*(FSP_MAX_MC_CH))
#define FSP_MAX_MEMORY_MAP_ELEMENTS         150

#define MEM_64MB_TO_BYTES(Size64M)          ((UINT64)(Size64M) << 26)
#define MEM_64MB_TO_KBYTES(Size64M)         ((UINT64)(Size64M) << 16)
#define MEM_64MB_TO_MBYTES(Size64M)         ((UINT64)(Size64M) << 6)
#define MEM_64MB_TO_GBYTES(Size64M)         ((Size64M) >> 4)
#define MEM_BYTES_TO_64MB(SizeB)            ((SizeB) >> 26)
#define MEM_KBYTES_TO_64MB(SizeKB)          ((SizeKB) >> 16)
#define MEM_MBYTES_TO_64MB(SizeMB)          ((SizeMB) >> 6)

#define FSP_MAX_PPR_ADDR_ENTRIES_DDR        MAX_PPR_ADDR_ENTRIES_DDR

typedef struct FspExtHeader {
  UINT64 Magic;
  UINT32 DataLength;
  UINT32 CheckSum;
} FSP_EXT_HEADER;

#endif // _FSP_EXT_GLOBALS_
