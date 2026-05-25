/** @file
  CXL CEDT GUID HOB definitions

  @copyright
  INTEL CONFIDENTIAL
  Copyright 2022 Intel Corporation. <BR>

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

#ifndef _CXL_CEDT_HOB_
#define _CXL_CEDT_HOB_

#define CXL_CEDT_HOB_GUID             { 0x58F943E7, 0xBB51, 0x445F, { 0xB9, 0x81, 0xF8, 0xBE, 0xBB, 0x0A, 0x30, 0x1B } }

#define CXL_CEDT_ACPI_HOB_GUID        { 0x5CB7A12A, 0x8B2D, 0x485A, { 0xB7, 0x04, 0xC0, 0x52, 0x49, 0x56, 0x81, 0xE7 } }

#ifndef FSP_MAX
#define FSP_MAX(a,b)                  (((a) > (b)) ? (a) : (b))
#endif

#ifndef MAX_SOCKET
#define MAX_SOCKET                    1
#endif

#ifndef MAX_IIO_STACK
#define MAX_IIO_STACK              14
#endif

#ifndef MAX_IMC
#define MAX_IMC                       8                     // Maximum memory controllers per socket
#endif

#ifndef MAX_CXL_HOST_BRIDGES
#define MAX_CXL_HOST_BRIDGES              0x6   // Maximum number of CXL host bridges per socket.
#endif

#define MAX_CXL_END_DEVICES       0x10       // Maximum number of CXL end devices per socket.

#ifndef MAX_DRAM_CLUSTERS
#define MAX_DRAM_CLUSTERS                 6
#endif

#ifndef MAX_SAD_RULES
#define MAX_SAD_RULES                     16
#endif

#define MAX_CXL_MEM_INTLV_TARGETS (MAX_IMC + MAX_CXL_HOST_BRIDGES)
#define MAX_CXL_HOST_BRIDGE_ENTRIES   FSP_MAX(MAX_CXL_END_DEVICES, MAX_IIO_STACK)        // Maximum possible number of CXL host bridge entries per socket.
#define MAX_CXL_FIXED_MEM_WINDOWS     (MAX_DRAM_CLUSTERS * MAX_SAD_RULES)             // Maximum possible number of CXL fixed memory windows per socket.

#define MAX_CXL_XOR_INTLV_MATHS       7                                               // Maximum possible number of CXL XOR interleave math structures
                                                                                      // That is, the maximum number of interleave granularities supported by CXL HDM decoder.
#define MAX_XOR_BITMAP_ENTRIES        4                                               // Maximum possible number of XOR bitmap entries.
                                                                                      // That is, the number of HPA bits needed to support the maximum CXL interleave ways.
#define MAX_CXL_QTG_ID                2

//
// Ensure proper structure formats.
//
#pragma pack(1)

///
/// CEDT CXL Fixed Memory Window Structure (CFMWS) Window Restrictions
///
typedef union {
  struct {
    UINT16            CxlType2Mem:1;
    UINT16            CxlType3Mem:1;
    UINT16            Volatile:1;
    UINT16            Persistent:1;
    UINT16            FixedDevConfig:1;
    UINT16            BackInvalidate:1;  // Introduced in CXL Specification Revision 3.1, Version 0.9
    UINT16            Reserved:10;
  } Bits;
  UINT16  Data;
} CEDT_CFMWS_WINDOW_RESTRICTIONS;

typedef struct {
  UINT8    PeId;               // CXL host bridge PE index within socket.
  UINT8    CxlVersion;         // CXL specification version that the CXL host bridge complies with.
  UINT32   Uid;                // CXL host bridge unique ID.
  UINT8    ClusterId;          // CXL host bridge cluster ID.
} CXL_HOST_BRIDGE_ENTRY;

typedef struct {
  UINT32                          HpaBase;                              // Base of the HPA range this window represents in 256MB granularity.
  UINT32                          HpaSize;                              // Size of the HPA range this window represents in 256MB granularity.
  UINT8                           EncIntlvGran;                         // Encoded interleave granularity across interleave targets.
  UINT8                           EncIntlvWays;                         // Encoded interleave ways across interleave targets.
  UINT8                           Arithmetic;                           // Arithmetic used for mapping HPA to an interleave target.
  UINT8                           QtgId;                                // ID of the QoS Throttling Group associated with this window.
  UINT8                           TargetNum;                            // Number of interleave targets.
  UINT32                          IntlvList[MAX_CXL_MEM_INTLV_TARGETS]; // Unique ID list of all the interleave targets.
  CEDT_CFMWS_WINDOW_RESTRICTIONS  Restrictions;                         // Same definition as the Window Restrictions field of CEDT CFMWS.
} CXL_FIXED_MEM_WINDOW;

typedef struct {
  UINT8   EncIntlvGran;                         // Encoded interleave granularity across interleave targets
  UINT8   XorMapNum;                            // The number of entries in the XOR map list.
  UINT64  XorMapList[MAX_XOR_BITMAP_ENTRIES];   // List of XOR bitmap entries.
} CXL_XOR_INTLV_MATH;

typedef struct {
  UINT64  WriteBw; // in MB/s
} CXL_QTG_THRESHOLD;

//
// CXL CEDT socket scope data structure.
//
typedef struct {
  UINT8                   CxlHbEntryNum;
  CXL_HOST_BRIDGE_ENTRY   CxlHbEntryList[MAX_CXL_HOST_BRIDGE_ENTRIES];
  UINT8                   CxlMemWindowNum;
  CXL_FIXED_MEM_WINDOW    CxlMemWindowList[MAX_CXL_FIXED_MEM_WINDOWS];
} CXL_CEDT_SOCKET;

///
/// CXL CEDT HOB data structure.
///
typedef struct {
  CXL_CEDT_SOCKET         CxlCedtSocket[MAX_SOCKET];
  UINT8                   CxlXorIntlvMathNum;
  CXL_XOR_INTLV_MATH      CxlXorIntlvMathList[MAX_CXL_XOR_INTLV_MATHS];
  UINT8                   CxlQtgThresholdNum;
  CXL_QTG_THRESHOLD       CxlQtgThresholdList[MAX_CXL_QTG_ID];
} CXL_CEDT_HOB;

#pragma pack()

#endif  // _CXL_CEDT_HOB_