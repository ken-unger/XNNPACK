// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/x8-packw/kr-gio-scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.


#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/packw.h"

void xnn_qs8_to_qu8_packw_gemm_gio_ukernel_x16c8__scalar(
  size_t g,
  size_t nc,
  size_t kc,
  size_t nr,
  size_t kr,
  size_t sr,
  size_t k_stride,
  const int8_t* weights,
  const int32_t* bias,
  const void* scale,
  int8_t* packed_weights,
  size_t extra_bytes,
  const void* params)
{
  assert(g != 0);
  assert(nc != 0);
  assert(kc != 0);
  assert(nr == 16);
  assert(kr == 8);
  assert(sr == 1);
  assert(weights != NULL);
  assert(packed_weights != NULL);

  int8_t* out = (int8_t*) packed_weights;
  const int32_t* b = (const int32_t*) bias;
  const uint32_t izp = (uint32_t) (params ? (((const struct xnn_qs8_packw_params*) params)->input_zero_point + 128): 128);

  do {
    // NC main loop multiple of 16
    const int8_t* w0 = (const int8_t*) weights;
    size_t n = nc;
    for (;n >= 16; n -= 16) {
      int32_t* packed_b = (int32_t*) out;
      if XNN_LIKELY(b != NULL) {
        ((int32_t*) out)[0] = b[0];
        ((int32_t*) out)[1] = b[1];
        ((int32_t*) out)[2] = b[2];
        ((int32_t*) out)[3] = b[3];
        ((int32_t*) out)[4] = b[4];
        ((int32_t*) out)[5] = b[5];
        ((int32_t*) out)[6] = b[6];
        ((int32_t*) out)[7] = b[7];
        ((int32_t*) out)[8] = b[8];
        ((int32_t*) out)[9] = b[9];
        ((int32_t*) out)[10] = b[10];
        ((int32_t*) out)[11] = b[11];
        ((int32_t*) out)[12] = b[12];
        ((int32_t*) out)[13] = b[13];
        ((int32_t*) out)[14] = b[14];
        ((int32_t*) out)[15] = b[15];
        b += 16;
      } else {
        ((int32_t*) out)[0] = 0;
        ((int32_t*) out)[1] = 0;
        ((int32_t*) out)[2] = 0;
        ((int32_t*) out)[3] = 0;
        ((int32_t*) out)[4] = 0;
        ((int32_t*) out)[5] = 0;
        ((int32_t*) out)[6] = 0;
        ((int32_t*) out)[7] = 0;
        ((int32_t*) out)[8] = 0;
        ((int32_t*) out)[9] = 0;
        ((int32_t*) out)[10] = 0;
        ((int32_t*) out)[11] = 0;
        ((int32_t*) out)[12] = 0;
        ((int32_t*) out)[13] = 0;
        ((int32_t*) out)[14] = 0;
        ((int32_t*) out)[15] = 0;
      }
      out += 16 * sizeof(int32_t);

      const int8_t* w1 = w0 + k_stride;
      const int8_t* w2 = w1 + k_stride;
      const int8_t* w3 = w2 + k_stride;
      const int8_t* w4 = w3 + k_stride;
      const int8_t* w5 = w4 + k_stride;
      const int8_t* w6 = w5 + k_stride;
      const int8_t* w7 = w6 + k_stride;
      uint32_t ksum0 = 0;
      uint32_t ksum1 = 0;
      uint32_t ksum2 = 0;
      uint32_t ksum3 = 0;
      uint32_t ksum4 = 0;
      uint32_t ksum5 = 0;
      uint32_t ksum6 = 0;
      uint32_t ksum7 = 0;
      uint32_t ksum8 = 0;
      uint32_t ksum9 = 0;
      uint32_t ksum10 = 0;
      uint32_t ksum11 = 0;
      uint32_t ksum12 = 0;
      uint32_t ksum13 = 0;
      uint32_t ksum14 = 0;
      uint32_t ksum15 = 0;

      // KC main loop multiple of 16x8
      size_t k = kc;
      for (; k >= 8; k -= 8) {
        const int8_t v0x0 = w0[0];
        const int8_t v1x0 = w1[0];
        const int8_t v2x0 = w2[0];
        const int8_t v3x0 = w3[0];
        const int8_t v4x0 = w4[0];
        const int8_t v5x0 = w5[0];
        const int8_t v6x0 = w6[0];
        const int8_t v7x0 = w7[0];
        ksum0 += (uint32_t) v0x0;
        ksum0 += (uint32_t) v1x0;
        ksum0 += (uint32_t) v2x0;
        ksum0 += (uint32_t) v3x0;
        ksum0 += (uint32_t) v4x0;
        ksum0 += (uint32_t) v5x0;
        ksum0 += (uint32_t) v6x0;
        ksum0 += (uint32_t) v7x0;
        out[0] = v0x0;
        out[1] = v1x0;
        out[2] = v2x0;
        out[3] = v3x0;
        out[4] = v4x0;
        out[5] = v5x0;
        out[6] = v6x0;
        out[7] = v7x0;
        const int8_t v0x1 = w0[1];
        const int8_t v1x1 = w1[1];
        const int8_t v2x1 = w2[1];
        const int8_t v3x1 = w3[1];
        const int8_t v4x1 = w4[1];
        const int8_t v5x1 = w5[1];
        const int8_t v6x1 = w6[1];
        const int8_t v7x1 = w7[1];
        ksum1 += (uint32_t) v0x1;
        ksum1 += (uint32_t) v1x1;
        ksum1 += (uint32_t) v2x1;
        ksum1 += (uint32_t) v3x1;
        ksum1 += (uint32_t) v4x1;
        ksum1 += (uint32_t) v5x1;
        ksum1 += (uint32_t) v6x1;
        ksum1 += (uint32_t) v7x1;
        out[8] = v0x1;
        out[9] = v1x1;
        out[10] = v2x1;
        out[11] = v3x1;
        out[12] = v4x1;
        out[13] = v5x1;
        out[14] = v6x1;
        out[15] = v7x1;
        const int8_t v0x2 = w0[2];
        const int8_t v1x2 = w1[2];
        const int8_t v2x2 = w2[2];
        const int8_t v3x2 = w3[2];
        const int8_t v4x2 = w4[2];
        const int8_t v5x2 = w5[2];
        const int8_t v6x2 = w6[2];
        const int8_t v7x2 = w7[2];
        ksum2 += (uint32_t) v0x2;
        ksum2 += (uint32_t) v1x2;
        ksum2 += (uint32_t) v2x2;
        ksum2 += (uint32_t) v3x2;
        ksum2 += (uint32_t) v4x2;
        ksum2 += (uint32_t) v5x2;
        ksum2 += (uint32_t) v6x2;
        ksum2 += (uint32_t) v7x2;
        out[16] = v0x2;
        out[17] = v1x2;
        out[18] = v2x2;
        out[19] = v3x2;
        out[20] = v4x2;
        out[21] = v5x2;
        out[22] = v6x2;
        out[23] = v7x2;
        const int8_t v0x3 = w0[3];
        const int8_t v1x3 = w1[3];
        const int8_t v2x3 = w2[3];
        const int8_t v3x3 = w3[3];
        const int8_t v4x3 = w4[3];
        const int8_t v5x3 = w5[3];
        const int8_t v6x3 = w6[3];
        const int8_t v7x3 = w7[3];
        ksum3 += (uint32_t) v0x3;
        ksum3 += (uint32_t) v1x3;
        ksum3 += (uint32_t) v2x3;
        ksum3 += (uint32_t) v3x3;
        ksum3 += (uint32_t) v4x3;
        ksum3 += (uint32_t) v5x3;
        ksum3 += (uint32_t) v6x3;
        ksum3 += (uint32_t) v7x3;
        out[24] = v0x3;
        out[25] = v1x3;
        out[26] = v2x3;
        out[27] = v3x3;
        out[28] = v4x3;
        out[29] = v5x3;
        out[30] = v6x3;
        out[31] = v7x3;
        const int8_t v0x4 = w0[4];
        const int8_t v1x4 = w1[4];
        const int8_t v2x4 = w2[4];
        const int8_t v3x4 = w3[4];
        const int8_t v4x4 = w4[4];
        const int8_t v5x4 = w5[4];
        const int8_t v6x4 = w6[4];
        const int8_t v7x4 = w7[4];
        ksum4 += (uint32_t) v0x4;
        ksum4 += (uint32_t) v1x4;
        ksum4 += (uint32_t) v2x4;
        ksum4 += (uint32_t) v3x4;
        ksum4 += (uint32_t) v4x4;
        ksum4 += (uint32_t) v5x4;
        ksum4 += (uint32_t) v6x4;
        ksum4 += (uint32_t) v7x4;
        out[32] = v0x4;
        out[33] = v1x4;
        out[34] = v2x4;
        out[35] = v3x4;
        out[36] = v4x4;
        out[37] = v5x4;
        out[38] = v6x4;
        out[39] = v7x4;
        const int8_t v0x5 = w0[5];
        const int8_t v1x5 = w1[5];
        const int8_t v2x5 = w2[5];
        const int8_t v3x5 = w3[5];
        const int8_t v4x5 = w4[5];
        const int8_t v5x5 = w5[5];
        const int8_t v6x5 = w6[5];
        const int8_t v7x5 = w7[5];
        ksum5 += (uint32_t) v0x5;
        ksum5 += (uint32_t) v1x5;
        ksum5 += (uint32_t) v2x5;
        ksum5 += (uint32_t) v3x5;
        ksum5 += (uint32_t) v4x5;
        ksum5 += (uint32_t) v5x5;
        ksum5 += (uint32_t) v6x5;
        ksum5 += (uint32_t) v7x5;
        out[40] = v0x5;
        out[41] = v1x5;
        out[42] = v2x5;
        out[43] = v3x5;
        out[44] = v4x5;
        out[45] = v5x5;
        out[46] = v6x5;
        out[47] = v7x5;
        const int8_t v0x6 = w0[6];
        const int8_t v1x6 = w1[6];
        const int8_t v2x6 = w2[6];
        const int8_t v3x6 = w3[6];
        const int8_t v4x6 = w4[6];
        const int8_t v5x6 = w5[6];
        const int8_t v6x6 = w6[6];
        const int8_t v7x6 = w7[6];
        ksum6 += (uint32_t) v0x6;
        ksum6 += (uint32_t) v1x6;
        ksum6 += (uint32_t) v2x6;
        ksum6 += (uint32_t) v3x6;
        ksum6 += (uint32_t) v4x6;
        ksum6 += (uint32_t) v5x6;
        ksum6 += (uint32_t) v6x6;
        ksum6 += (uint32_t) v7x6;
        out[48] = v0x6;
        out[49] = v1x6;
        out[50] = v2x6;
        out[51] = v3x6;
        out[52] = v4x6;
        out[53] = v5x6;
        out[54] = v6x6;
        out[55] = v7x6;
        const int8_t v0x7 = w0[7];
        const int8_t v1x7 = w1[7];
        const int8_t v2x7 = w2[7];
        const int8_t v3x7 = w3[7];
        const int8_t v4x7 = w4[7];
        const int8_t v5x7 = w5[7];
        const int8_t v6x7 = w6[7];
        const int8_t v7x7 = w7[7];
        ksum7 += (uint32_t) v0x7;
        ksum7 += (uint32_t) v1x7;
        ksum7 += (uint32_t) v2x7;
        ksum7 += (uint32_t) v3x7;
        ksum7 += (uint32_t) v4x7;
        ksum7 += (uint32_t) v5x7;
        ksum7 += (uint32_t) v6x7;
        ksum7 += (uint32_t) v7x7;
        out[56] = v0x7;
        out[57] = v1x7;
        out[58] = v2x7;
        out[59] = v3x7;
        out[60] = v4x7;
        out[61] = v5x7;
        out[62] = v6x7;
        out[63] = v7x7;
        const int8_t v0x8 = w0[8];
        const int8_t v1x8 = w1[8];
        const int8_t v2x8 = w2[8];
        const int8_t v3x8 = w3[8];
        const int8_t v4x8 = w4[8];
        const int8_t v5x8 = w5[8];
        const int8_t v6x8 = w6[8];
        const int8_t v7x8 = w7[8];
        ksum8 += (uint32_t) v0x8;
        ksum8 += (uint32_t) v1x8;
        ksum8 += (uint32_t) v2x8;
        ksum8 += (uint32_t) v3x8;
        ksum8 += (uint32_t) v4x8;
        ksum8 += (uint32_t) v5x8;
        ksum8 += (uint32_t) v6x8;
        ksum8 += (uint32_t) v7x8;
        out[64] = v0x8;
        out[65] = v1x8;
        out[66] = v2x8;
        out[67] = v3x8;
        out[68] = v4x8;
        out[69] = v5x8;
        out[70] = v6x8;
        out[71] = v7x8;
        const int8_t v0x9 = w0[9];
        const int8_t v1x9 = w1[9];
        const int8_t v2x9 = w2[9];
        const int8_t v3x9 = w3[9];
        const int8_t v4x9 = w4[9];
        const int8_t v5x9 = w5[9];
        const int8_t v6x9 = w6[9];
        const int8_t v7x9 = w7[9];
        ksum9 += (uint32_t) v0x9;
        ksum9 += (uint32_t) v1x9;
        ksum9 += (uint32_t) v2x9;
        ksum9 += (uint32_t) v3x9;
        ksum9 += (uint32_t) v4x9;
        ksum9 += (uint32_t) v5x9;
        ksum9 += (uint32_t) v6x9;
        ksum9 += (uint32_t) v7x9;
        out[72] = v0x9;
        out[73] = v1x9;
        out[74] = v2x9;
        out[75] = v3x9;
        out[76] = v4x9;
        out[77] = v5x9;
        out[78] = v6x9;
        out[79] = v7x9;
        const int8_t v0x10 = w0[10];
        const int8_t v1x10 = w1[10];
        const int8_t v2x10 = w2[10];
        const int8_t v3x10 = w3[10];
        const int8_t v4x10 = w4[10];
        const int8_t v5x10 = w5[10];
        const int8_t v6x10 = w6[10];
        const int8_t v7x10 = w7[10];
        ksum10 += (uint32_t) v0x10;
        ksum10 += (uint32_t) v1x10;
        ksum10 += (uint32_t) v2x10;
        ksum10 += (uint32_t) v3x10;
        ksum10 += (uint32_t) v4x10;
        ksum10 += (uint32_t) v5x10;
        ksum10 += (uint32_t) v6x10;
        ksum10 += (uint32_t) v7x10;
        out[80] = v0x10;
        out[81] = v1x10;
        out[82] = v2x10;
        out[83] = v3x10;
        out[84] = v4x10;
        out[85] = v5x10;
        out[86] = v6x10;
        out[87] = v7x10;
        const int8_t v0x11 = w0[11];
        const int8_t v1x11 = w1[11];
        const int8_t v2x11 = w2[11];
        const int8_t v3x11 = w3[11];
        const int8_t v4x11 = w4[11];
        const int8_t v5x11 = w5[11];
        const int8_t v6x11 = w6[11];
        const int8_t v7x11 = w7[11];
        ksum11 += (uint32_t) v0x11;
        ksum11 += (uint32_t) v1x11;
        ksum11 += (uint32_t) v2x11;
        ksum11 += (uint32_t) v3x11;
        ksum11 += (uint32_t) v4x11;
        ksum11 += (uint32_t) v5x11;
        ksum11 += (uint32_t) v6x11;
        ksum11 += (uint32_t) v7x11;
        out[88] = v0x11;
        out[89] = v1x11;
        out[90] = v2x11;
        out[91] = v3x11;
        out[92] = v4x11;
        out[93] = v5x11;
        out[94] = v6x11;
        out[95] = v7x11;
        const int8_t v0x12 = w0[12];
        const int8_t v1x12 = w1[12];
        const int8_t v2x12 = w2[12];
        const int8_t v3x12 = w3[12];
        const int8_t v4x12 = w4[12];
        const int8_t v5x12 = w5[12];
        const int8_t v6x12 = w6[12];
        const int8_t v7x12 = w7[12];
        ksum12 += (uint32_t) v0x12;
        ksum12 += (uint32_t) v1x12;
        ksum12 += (uint32_t) v2x12;
        ksum12 += (uint32_t) v3x12;
        ksum12 += (uint32_t) v4x12;
        ksum12 += (uint32_t) v5x12;
        ksum12 += (uint32_t) v6x12;
        ksum12 += (uint32_t) v7x12;
        out[96] = v0x12;
        out[97] = v1x12;
        out[98] = v2x12;
        out[99] = v3x12;
        out[100] = v4x12;
        out[101] = v5x12;
        out[102] = v6x12;
        out[103] = v7x12;
        const int8_t v0x13 = w0[13];
        const int8_t v1x13 = w1[13];
        const int8_t v2x13 = w2[13];
        const int8_t v3x13 = w3[13];
        const int8_t v4x13 = w4[13];
        const int8_t v5x13 = w5[13];
        const int8_t v6x13 = w6[13];
        const int8_t v7x13 = w7[13];
        ksum13 += (uint32_t) v0x13;
        ksum13 += (uint32_t) v1x13;
        ksum13 += (uint32_t) v2x13;
        ksum13 += (uint32_t) v3x13;
        ksum13 += (uint32_t) v4x13;
        ksum13 += (uint32_t) v5x13;
        ksum13 += (uint32_t) v6x13;
        ksum13 += (uint32_t) v7x13;
        out[104] = v0x13;
        out[105] = v1x13;
        out[106] = v2x13;
        out[107] = v3x13;
        out[108] = v4x13;
        out[109] = v5x13;
        out[110] = v6x13;
        out[111] = v7x13;
        const int8_t v0x14 = w0[14];
        const int8_t v1x14 = w1[14];
        const int8_t v2x14 = w2[14];
        const int8_t v3x14 = w3[14];
        const int8_t v4x14 = w4[14];
        const int8_t v5x14 = w5[14];
        const int8_t v6x14 = w6[14];
        const int8_t v7x14 = w7[14];
        ksum14 += (uint32_t) v0x14;
        ksum14 += (uint32_t) v1x14;
        ksum14 += (uint32_t) v2x14;
        ksum14 += (uint32_t) v3x14;
        ksum14 += (uint32_t) v4x14;
        ksum14 += (uint32_t) v5x14;
        ksum14 += (uint32_t) v6x14;
        ksum14 += (uint32_t) v7x14;
        out[112] = v0x14;
        out[113] = v1x14;
        out[114] = v2x14;
        out[115] = v3x14;
        out[116] = v4x14;
        out[117] = v5x14;
        out[118] = v6x14;
        out[119] = v7x14;
        const int8_t v0x15 = w0[15];
        const int8_t v1x15 = w1[15];
        const int8_t v2x15 = w2[15];
        const int8_t v3x15 = w3[15];
        const int8_t v4x15 = w4[15];
        const int8_t v5x15 = w5[15];
        const int8_t v6x15 = w6[15];
        const int8_t v7x15 = w7[15];
        ksum15 += (uint32_t) v0x15;
        ksum15 += (uint32_t) v1x15;
        ksum15 += (uint32_t) v2x15;
        ksum15 += (uint32_t) v3x15;
        ksum15 += (uint32_t) v4x15;
        ksum15 += (uint32_t) v5x15;
        ksum15 += (uint32_t) v6x15;
        ksum15 += (uint32_t) v7x15;
        out[120] = v0x15;
        out[121] = v1x15;
        out[122] = v2x15;
        out[123] = v3x15;
        out[124] = v4x15;
        out[125] = v5x15;
        out[126] = v6x15;
        out[127] = v7x15;
        w0 += 8 * k_stride;
        w1 += 8 * k_stride;
        w2 += 8 * k_stride;
        w3 += 8 * k_stride;
        w4 += 8 * k_stride;
        w5 += 8 * k_stride;
        w6 += 8 * k_stride;
        w7 += 8 * k_stride;
        out += 128;
      }

      // KC remainder of 1..7
      if (k != 0) {
        assert(k >= 1 && k <= 7);
        const int8_t v0x0 = w0[0];
        ksum0 += (uint32_t) v0x0;
        out[0] = v0x0;
        if (1 < k) {
          const int8_t v1x0 = w1[0];
          ksum0 += (uint32_t) v1x0;
          out[1] = v1x0;
        }
        if (2 < k) {
          const int8_t v2x0 = w2[0];
          ksum0 += (uint32_t) v2x0;
          out[2] = v2x0;
        }
        if (3 < k) {
          const int8_t v3x0 = w3[0];
          ksum0 += (uint32_t) v3x0;
          out[3] = v3x0;
        }
        if (4 < k) {
          const int8_t v4x0 = w4[0];
          ksum0 += (uint32_t) v4x0;
          out[4] = v4x0;
        }
        if (5 < k) {
          const int8_t v5x0 = w5[0];
          ksum0 += (uint32_t) v5x0;
          out[5] = v5x0;
        }
        if (6 < k) {
          const int8_t v6x0 = w6[0];
          ksum0 += (uint32_t) v6x0;
          out[6] = v6x0;
        }
        if (7 < k) {
          const int8_t v7x0 = w7[0];
          ksum0 += (uint32_t) v7x0;
          out[7] = v7x0;
        }
        const int8_t v0x1 = w0[1];
        ksum1 += (uint32_t) v0x1;
        out[8] = v0x1;
        if (1 < k) {
          const int8_t v1x1 = w1[1];
          ksum1 += (uint32_t) v1x1;
          out[9] = v1x1;
        }
        if (2 < k) {
          const int8_t v2x1 = w2[1];
          ksum1 += (uint32_t) v2x1;
          out[10] = v2x1;
        }
        if (3 < k) {
          const int8_t v3x1 = w3[1];
          ksum1 += (uint32_t) v3x1;
          out[11] = v3x1;
        }
        if (4 < k) {
          const int8_t v4x1 = w4[1];
          ksum1 += (uint32_t) v4x1;
          out[12] = v4x1;
        }
        if (5 < k) {
          const int8_t v5x1 = w5[1];
          ksum1 += (uint32_t) v5x1;
          out[13] = v5x1;
        }
        if (6 < k) {
          const int8_t v6x1 = w6[1];
          ksum1 += (uint32_t) v6x1;
          out[14] = v6x1;
        }
        if (7 < k) {
          const int8_t v7x1 = w7[1];
          ksum1 += (uint32_t) v7x1;
          out[15] = v7x1;
        }
        const int8_t v0x2 = w0[2];
        ksum2 += (uint32_t) v0x2;
        out[16] = v0x2;
        if (1 < k) {
          const int8_t v1x2 = w1[2];
          ksum2 += (uint32_t) v1x2;
          out[17] = v1x2;
        }
        if (2 < k) {
          const int8_t v2x2 = w2[2];
          ksum2 += (uint32_t) v2x2;
          out[18] = v2x2;
        }
        if (3 < k) {
          const int8_t v3x2 = w3[2];
          ksum2 += (uint32_t) v3x2;
          out[19] = v3x2;
        }
        if (4 < k) {
          const int8_t v4x2 = w4[2];
          ksum2 += (uint32_t) v4x2;
          out[20] = v4x2;
        }
        if (5 < k) {
          const int8_t v5x2 = w5[2];
          ksum2 += (uint32_t) v5x2;
          out[21] = v5x2;
        }
        if (6 < k) {
          const int8_t v6x2 = w6[2];
          ksum2 += (uint32_t) v6x2;
          out[22] = v6x2;
        }
        if (7 < k) {
          const int8_t v7x2 = w7[2];
          ksum2 += (uint32_t) v7x2;
          out[23] = v7x2;
        }
        const int8_t v0x3 = w0[3];
        ksum3 += (uint32_t) v0x3;
        out[24] = v0x3;
        if (1 < k) {
          const int8_t v1x3 = w1[3];
          ksum3 += (uint32_t) v1x3;
          out[25] = v1x3;
        }
        if (2 < k) {
          const int8_t v2x3 = w2[3];
          ksum3 += (uint32_t) v2x3;
          out[26] = v2x3;
        }
        if (3 < k) {
          const int8_t v3x3 = w3[3];
          ksum3 += (uint32_t) v3x3;
          out[27] = v3x3;
        }
        if (4 < k) {
          const int8_t v4x3 = w4[3];
          ksum3 += (uint32_t) v4x3;
          out[28] = v4x3;
        }
        if (5 < k) {
          const int8_t v5x3 = w5[3];
          ksum3 += (uint32_t) v5x3;
          out[29] = v5x3;
        }
        if (6 < k) {
          const int8_t v6x3 = w6[3];
          ksum3 += (uint32_t) v6x3;
          out[30] = v6x3;
        }
        if (7 < k) {
          const int8_t v7x3 = w7[3];
          ksum3 += (uint32_t) v7x3;
          out[31] = v7x3;
        }
        const int8_t v0x4 = w0[4];
        ksum4 += (uint32_t) v0x4;
        out[32] = v0x4;
        if (1 < k) {
          const int8_t v1x4 = w1[4];
          ksum4 += (uint32_t) v1x4;
          out[33] = v1x4;
        }
        if (2 < k) {
          const int8_t v2x4 = w2[4];
          ksum4 += (uint32_t) v2x4;
          out[34] = v2x4;
        }
        if (3 < k) {
          const int8_t v3x4 = w3[4];
          ksum4 += (uint32_t) v3x4;
          out[35] = v3x4;
        }
        if (4 < k) {
          const int8_t v4x4 = w4[4];
          ksum4 += (uint32_t) v4x4;
          out[36] = v4x4;
        }
        if (5 < k) {
          const int8_t v5x4 = w5[4];
          ksum4 += (uint32_t) v5x4;
          out[37] = v5x4;
        }
        if (6 < k) {
          const int8_t v6x4 = w6[4];
          ksum4 += (uint32_t) v6x4;
          out[38] = v6x4;
        }
        if (7 < k) {
          const int8_t v7x4 = w7[4];
          ksum4 += (uint32_t) v7x4;
          out[39] = v7x4;
        }
        const int8_t v0x5 = w0[5];
        ksum5 += (uint32_t) v0x5;
        out[40] = v0x5;
        if (1 < k) {
          const int8_t v1x5 = w1[5];
          ksum5 += (uint32_t) v1x5;
          out[41] = v1x5;
        }
        if (2 < k) {
          const int8_t v2x5 = w2[5];
          ksum5 += (uint32_t) v2x5;
          out[42] = v2x5;
        }
        if (3 < k) {
          const int8_t v3x5 = w3[5];
          ksum5 += (uint32_t) v3x5;
          out[43] = v3x5;
        }
        if (4 < k) {
          const int8_t v4x5 = w4[5];
          ksum5 += (uint32_t) v4x5;
          out[44] = v4x5;
        }
        if (5 < k) {
          const int8_t v5x5 = w5[5];
          ksum5 += (uint32_t) v5x5;
          out[45] = v5x5;
        }
        if (6 < k) {
          const int8_t v6x5 = w6[5];
          ksum5 += (uint32_t) v6x5;
          out[46] = v6x5;
        }
        if (7 < k) {
          const int8_t v7x5 = w7[5];
          ksum5 += (uint32_t) v7x5;
          out[47] = v7x5;
        }
        const int8_t v0x6 = w0[6];
        ksum6 += (uint32_t) v0x6;
        out[48] = v0x6;
        if (1 < k) {
          const int8_t v1x6 = w1[6];
          ksum6 += (uint32_t) v1x6;
          out[49] = v1x6;
        }
        if (2 < k) {
          const int8_t v2x6 = w2[6];
          ksum6 += (uint32_t) v2x6;
          out[50] = v2x6;
        }
        if (3 < k) {
          const int8_t v3x6 = w3[6];
          ksum6 += (uint32_t) v3x6;
          out[51] = v3x6;
        }
        if (4 < k) {
          const int8_t v4x6 = w4[6];
          ksum6 += (uint32_t) v4x6;
          out[52] = v4x6;
        }
        if (5 < k) {
          const int8_t v5x6 = w5[6];
          ksum6 += (uint32_t) v5x6;
          out[53] = v5x6;
        }
        if (6 < k) {
          const int8_t v6x6 = w6[6];
          ksum6 += (uint32_t) v6x6;
          out[54] = v6x6;
        }
        if (7 < k) {
          const int8_t v7x6 = w7[6];
          ksum6 += (uint32_t) v7x6;
          out[55] = v7x6;
        }
        const int8_t v0x7 = w0[7];
        ksum7 += (uint32_t) v0x7;
        out[56] = v0x7;
        if (1 < k) {
          const int8_t v1x7 = w1[7];
          ksum7 += (uint32_t) v1x7;
          out[57] = v1x7;
        }
        if (2 < k) {
          const int8_t v2x7 = w2[7];
          ksum7 += (uint32_t) v2x7;
          out[58] = v2x7;
        }
        if (3 < k) {
          const int8_t v3x7 = w3[7];
          ksum7 += (uint32_t) v3x7;
          out[59] = v3x7;
        }
        if (4 < k) {
          const int8_t v4x7 = w4[7];
          ksum7 += (uint32_t) v4x7;
          out[60] = v4x7;
        }
        if (5 < k) {
          const int8_t v5x7 = w5[7];
          ksum7 += (uint32_t) v5x7;
          out[61] = v5x7;
        }
        if (6 < k) {
          const int8_t v6x7 = w6[7];
          ksum7 += (uint32_t) v6x7;
          out[62] = v6x7;
        }
        if (7 < k) {
          const int8_t v7x7 = w7[7];
          ksum7 += (uint32_t) v7x7;
          out[63] = v7x7;
        }
        const int8_t v0x8 = w0[8];
        ksum8 += (uint32_t) v0x8;
        out[64] = v0x8;
        if (1 < k) {
          const int8_t v1x8 = w1[8];
          ksum8 += (uint32_t) v1x8;
          out[65] = v1x8;
        }
        if (2 < k) {
          const int8_t v2x8 = w2[8];
          ksum8 += (uint32_t) v2x8;
          out[66] = v2x8;
        }
        if (3 < k) {
          const int8_t v3x8 = w3[8];
          ksum8 += (uint32_t) v3x8;
          out[67] = v3x8;
        }
        if (4 < k) {
          const int8_t v4x8 = w4[8];
          ksum8 += (uint32_t) v4x8;
          out[68] = v4x8;
        }
        if (5 < k) {
          const int8_t v5x8 = w5[8];
          ksum8 += (uint32_t) v5x8;
          out[69] = v5x8;
        }
        if (6 < k) {
          const int8_t v6x8 = w6[8];
          ksum8 += (uint32_t) v6x8;
          out[70] = v6x8;
        }
        if (7 < k) {
          const int8_t v7x8 = w7[8];
          ksum8 += (uint32_t) v7x8;
          out[71] = v7x8;
        }
        const int8_t v0x9 = w0[9];
        ksum9 += (uint32_t) v0x9;
        out[72] = v0x9;
        if (1 < k) {
          const int8_t v1x9 = w1[9];
          ksum9 += (uint32_t) v1x9;
          out[73] = v1x9;
        }
        if (2 < k) {
          const int8_t v2x9 = w2[9];
          ksum9 += (uint32_t) v2x9;
          out[74] = v2x9;
        }
        if (3 < k) {
          const int8_t v3x9 = w3[9];
          ksum9 += (uint32_t) v3x9;
          out[75] = v3x9;
        }
        if (4 < k) {
          const int8_t v4x9 = w4[9];
          ksum9 += (uint32_t) v4x9;
          out[76] = v4x9;
        }
        if (5 < k) {
          const int8_t v5x9 = w5[9];
          ksum9 += (uint32_t) v5x9;
          out[77] = v5x9;
        }
        if (6 < k) {
          const int8_t v6x9 = w6[9];
          ksum9 += (uint32_t) v6x9;
          out[78] = v6x9;
        }
        if (7 < k) {
          const int8_t v7x9 = w7[9];
          ksum9 += (uint32_t) v7x9;
          out[79] = v7x9;
        }
        const int8_t v0x10 = w0[10];
        ksum10 += (uint32_t) v0x10;
        out[80] = v0x10;
        if (1 < k) {
          const int8_t v1x10 = w1[10];
          ksum10 += (uint32_t) v1x10;
          out[81] = v1x10;
        }
        if (2 < k) {
          const int8_t v2x10 = w2[10];
          ksum10 += (uint32_t) v2x10;
          out[82] = v2x10;
        }
        if (3 < k) {
          const int8_t v3x10 = w3[10];
          ksum10 += (uint32_t) v3x10;
          out[83] = v3x10;
        }
        if (4 < k) {
          const int8_t v4x10 = w4[10];
          ksum10 += (uint32_t) v4x10;
          out[84] = v4x10;
        }
        if (5 < k) {
          const int8_t v5x10 = w5[10];
          ksum10 += (uint32_t) v5x10;
          out[85] = v5x10;
        }
        if (6 < k) {
          const int8_t v6x10 = w6[10];
          ksum10 += (uint32_t) v6x10;
          out[86] = v6x10;
        }
        if (7 < k) {
          const int8_t v7x10 = w7[10];
          ksum10 += (uint32_t) v7x10;
          out[87] = v7x10;
        }
        const int8_t v0x11 = w0[11];
        ksum11 += (uint32_t) v0x11;
        out[88] = v0x11;
        if (1 < k) {
          const int8_t v1x11 = w1[11];
          ksum11 += (uint32_t) v1x11;
          out[89] = v1x11;
        }
        if (2 < k) {
          const int8_t v2x11 = w2[11];
          ksum11 += (uint32_t) v2x11;
          out[90] = v2x11;
        }
        if (3 < k) {
          const int8_t v3x11 = w3[11];
          ksum11 += (uint32_t) v3x11;
          out[91] = v3x11;
        }
        if (4 < k) {
          const int8_t v4x11 = w4[11];
          ksum11 += (uint32_t) v4x11;
          out[92] = v4x11;
        }
        if (5 < k) {
          const int8_t v5x11 = w5[11];
          ksum11 += (uint32_t) v5x11;
          out[93] = v5x11;
        }
        if (6 < k) {
          const int8_t v6x11 = w6[11];
          ksum11 += (uint32_t) v6x11;
          out[94] = v6x11;
        }
        if (7 < k) {
          const int8_t v7x11 = w7[11];
          ksum11 += (uint32_t) v7x11;
          out[95] = v7x11;
        }
        const int8_t v0x12 = w0[12];
        ksum12 += (uint32_t) v0x12;
        out[96] = v0x12;
        if (1 < k) {
          const int8_t v1x12 = w1[12];
          ksum12 += (uint32_t) v1x12;
          out[97] = v1x12;
        }
        if (2 < k) {
          const int8_t v2x12 = w2[12];
          ksum12 += (uint32_t) v2x12;
          out[98] = v2x12;
        }
        if (3 < k) {
          const int8_t v3x12 = w3[12];
          ksum12 += (uint32_t) v3x12;
          out[99] = v3x12;
        }
        if (4 < k) {
          const int8_t v4x12 = w4[12];
          ksum12 += (uint32_t) v4x12;
          out[100] = v4x12;
        }
        if (5 < k) {
          const int8_t v5x12 = w5[12];
          ksum12 += (uint32_t) v5x12;
          out[101] = v5x12;
        }
        if (6 < k) {
          const int8_t v6x12 = w6[12];
          ksum12 += (uint32_t) v6x12;
          out[102] = v6x12;
        }
        if (7 < k) {
          const int8_t v7x12 = w7[12];
          ksum12 += (uint32_t) v7x12;
          out[103] = v7x12;
        }
        const int8_t v0x13 = w0[13];
        ksum13 += (uint32_t) v0x13;
        out[104] = v0x13;
        if (1 < k) {
          const int8_t v1x13 = w1[13];
          ksum13 += (uint32_t) v1x13;
          out[105] = v1x13;
        }
        if (2 < k) {
          const int8_t v2x13 = w2[13];
          ksum13 += (uint32_t) v2x13;
          out[106] = v2x13;
        }
        if (3 < k) {
          const int8_t v3x13 = w3[13];
          ksum13 += (uint32_t) v3x13;
          out[107] = v3x13;
        }
        if (4 < k) {
          const int8_t v4x13 = w4[13];
          ksum13 += (uint32_t) v4x13;
          out[108] = v4x13;
        }
        if (5 < k) {
          const int8_t v5x13 = w5[13];
          ksum13 += (uint32_t) v5x13;
          out[109] = v5x13;
        }
        if (6 < k) {
          const int8_t v6x13 = w6[13];
          ksum13 += (uint32_t) v6x13;
          out[110] = v6x13;
        }
        if (7 < k) {
          const int8_t v7x13 = w7[13];
          ksum13 += (uint32_t) v7x13;
          out[111] = v7x13;
        }
        const int8_t v0x14 = w0[14];
        ksum14 += (uint32_t) v0x14;
        out[112] = v0x14;
        if (1 < k) {
          const int8_t v1x14 = w1[14];
          ksum14 += (uint32_t) v1x14;
          out[113] = v1x14;
        }
        if (2 < k) {
          const int8_t v2x14 = w2[14];
          ksum14 += (uint32_t) v2x14;
          out[114] = v2x14;
        }
        if (3 < k) {
          const int8_t v3x14 = w3[14];
          ksum14 += (uint32_t) v3x14;
          out[115] = v3x14;
        }
        if (4 < k) {
          const int8_t v4x14 = w4[14];
          ksum14 += (uint32_t) v4x14;
          out[116] = v4x14;
        }
        if (5 < k) {
          const int8_t v5x14 = w5[14];
          ksum14 += (uint32_t) v5x14;
          out[117] = v5x14;
        }
        if (6 < k) {
          const int8_t v6x14 = w6[14];
          ksum14 += (uint32_t) v6x14;
          out[118] = v6x14;
        }
        if (7 < k) {
          const int8_t v7x14 = w7[14];
          ksum14 += (uint32_t) v7x14;
          out[119] = v7x14;
        }
        const int8_t v0x15 = w0[15];
        ksum15 += (uint32_t) v0x15;
        out[120] = v0x15;
        if (1 < k) {
          const int8_t v1x15 = w1[15];
          ksum15 += (uint32_t) v1x15;
          out[121] = v1x15;
        }
        if (2 < k) {
          const int8_t v2x15 = w2[15];
          ksum15 += (uint32_t) v2x15;
          out[122] = v2x15;
        }
        if (3 < k) {
          const int8_t v3x15 = w3[15];
          ksum15 += (uint32_t) v3x15;
          out[123] = v3x15;
        }
        if (4 < k) {
          const int8_t v4x15 = w4[15];
          ksum15 += (uint32_t) v4x15;
          out[124] = v4x15;
        }
        if (5 < k) {
          const int8_t v5x15 = w5[15];
          ksum15 += (uint32_t) v5x15;
          out[125] = v5x15;
        }
        if (6 < k) {
          const int8_t v6x15 = w6[15];
          ksum15 += (uint32_t) v6x15;
          out[126] = v6x15;
        }
        if (7 < k) {
          const int8_t v7x15 = w7[15];
          ksum15 += (uint32_t) v7x15;
          out[127] = v7x15;
        }
        w0 += k * k_stride;
        w1 += k * k_stride;
        w2 += k * k_stride;
        w3 += k * k_stride;
        w4 += k * k_stride;
        w5 += k * k_stride;
        w6 += k * k_stride;
        w7 += k * k_stride;
        out += 128;
      }

      packed_b[0] -= ksum0 * izp;
      packed_b[1] -= ksum1 * izp;
      packed_b[2] -= ksum2 * izp;
      packed_b[3] -= ksum3 * izp;
      packed_b[4] -= ksum4 * izp;
      packed_b[5] -= ksum5 * izp;
      packed_b[6] -= ksum6 * izp;
      packed_b[7] -= ksum7 * izp;
      packed_b[8] -= ksum8 * izp;
      packed_b[9] -= ksum9 * izp;
      packed_b[10] -= ksum10 * izp;
      packed_b[11] -= ksum11 * izp;
      packed_b[12] -= ksum12 * izp;
      packed_b[13] -= ksum13 * izp;
      packed_b[14] -= ksum14 * izp;
      packed_b[15] -= ksum15 * izp;
      out = (int8_t*) ((uintptr_t) out + extra_bytes);
      w0 = w0 - kc * k_stride + 16;
    }

    // NC remainder (1..15)
    if XNN_UNLIKELY(n != 0) {
      int32_t* packed_b = (int32_t*) out;
      if XNN_LIKELY(b != NULL) {
        size_t nb = n;
        do {
          *((int32_t*) out) = *b++;
          out += sizeof(int32_t);
        } while (--nb != 0);
      } else {
        size_t nb = n;
        do {
          *((int32_t*) out) = 0;
          out += sizeof(int32_t);
        } while (--nb != 0);
      }
      out += (16 - n) * sizeof(int32_t);

     // NR remainder has less than 16 rows so last row is not loaded
      const int8_t* w1 = w0 + k_stride;
      const int8_t* w2 = w1 + k_stride;
      const int8_t* w3 = w2 + k_stride;
      const int8_t* w4 = w3 + k_stride;
      const int8_t* w5 = w4 + k_stride;
      const int8_t* w6 = w5 + k_stride;
      const int8_t* w7 = w6 + k_stride;

      uint32_t ksum0 = 0;
      uint32_t ksum1 = 0;
      uint32_t ksum2 = 0;
      uint32_t ksum3 = 0;
      uint32_t ksum4 = 0;
      uint32_t ksum5 = 0;
      uint32_t ksum6 = 0;
      uint32_t ksum7 = 0;
      uint32_t ksum8 = 0;
      uint32_t ksum9 = 0;
      uint32_t ksum10 = 0;
      uint32_t ksum11 = 0;
      uint32_t ksum12 = 0;
      uint32_t ksum13 = 0;
      uint32_t ksum14 = 0;

      // KC main loop multiple of 16x8
      size_t k = kc;
      for (; k >= 8; k -= 8) {
        const int8_t v0x0 = w0[0];
        const int8_t v1x0 = w1[0];
        const int8_t v2x0 = w2[0];
        const int8_t v3x0 = w3[0];
        const int8_t v4x0 = w4[0];
        const int8_t v5x0 = w5[0];
        const int8_t v6x0 = w6[0];
        const int8_t v7x0 = w7[0];
        ksum0 += (uint32_t) v0x0;
        ksum0 += (uint32_t) v1x0;
        ksum0 += (uint32_t) v2x0;
        ksum0 += (uint32_t) v3x0;
        ksum0 += (uint32_t) v4x0;
        ksum0 += (uint32_t) v5x0;
        ksum0 += (uint32_t) v6x0;
        ksum0 += (uint32_t) v7x0;
        out[0] = v0x0;
        out[1] = v1x0;
        out[2] = v2x0;
        out[3] = v3x0;
        out[4] = v4x0;
        out[5] = v5x0;
        out[6] = v6x0;
        out[7] = v7x0;
        if (1 < n) {
          const int8_t v0x1 = w0[1];
          const int8_t v1x1 = w1[1];
          const int8_t v2x1 = w2[1];
          const int8_t v3x1 = w3[1];
          const int8_t v4x1 = w4[1];
          const int8_t v5x1 = w5[1];
          const int8_t v6x1 = w6[1];
          const int8_t v7x1 = w7[1];
          ksum1 += (uint32_t) v0x1;
          ksum1 += (uint32_t) v1x1;
          ksum1 += (uint32_t) v2x1;
          ksum1 += (uint32_t) v3x1;
          ksum1 += (uint32_t) v4x1;
          ksum1 += (uint32_t) v5x1;
          ksum1 += (uint32_t) v6x1;
          ksum1 += (uint32_t) v7x1;
          out[8] = v0x1;
          out[9] = v1x1;
          out[10] = v2x1;
          out[11] = v3x1;
          out[12] = v4x1;
          out[13] = v5x1;
          out[14] = v6x1;
          out[15] = v7x1;
        }
        if (2 < n) {
          const int8_t v0x2 = w0[2];
          const int8_t v1x2 = w1[2];
          const int8_t v2x2 = w2[2];
          const int8_t v3x2 = w3[2];
          const int8_t v4x2 = w4[2];
          const int8_t v5x2 = w5[2];
          const int8_t v6x2 = w6[2];
          const int8_t v7x2 = w7[2];
          ksum2 += (uint32_t) v0x2;
          ksum2 += (uint32_t) v1x2;
          ksum2 += (uint32_t) v2x2;
          ksum2 += (uint32_t) v3x2;
          ksum2 += (uint32_t) v4x2;
          ksum2 += (uint32_t) v5x2;
          ksum2 += (uint32_t) v6x2;
          ksum2 += (uint32_t) v7x2;
          out[16] = v0x2;
          out[17] = v1x2;
          out[18] = v2x2;
          out[19] = v3x2;
          out[20] = v4x2;
          out[21] = v5x2;
          out[22] = v6x2;
          out[23] = v7x2;
        }
        if (3 < n) {
          const int8_t v0x3 = w0[3];
          const int8_t v1x3 = w1[3];
          const int8_t v2x3 = w2[3];
          const int8_t v3x3 = w3[3];
          const int8_t v4x3 = w4[3];
          const int8_t v5x3 = w5[3];
          const int8_t v6x3 = w6[3];
          const int8_t v7x3 = w7[3];
          ksum3 += (uint32_t) v0x3;
          ksum3 += (uint32_t) v1x3;
          ksum3 += (uint32_t) v2x3;
          ksum3 += (uint32_t) v3x3;
          ksum3 += (uint32_t) v4x3;
          ksum3 += (uint32_t) v5x3;
          ksum3 += (uint32_t) v6x3;
          ksum3 += (uint32_t) v7x3;
          out[24] = v0x3;
          out[25] = v1x3;
          out[26] = v2x3;
          out[27] = v3x3;
          out[28] = v4x3;
          out[29] = v5x3;
          out[30] = v6x3;
          out[31] = v7x3;
        }
        if (4 < n) {
          const int8_t v0x4 = w0[4];
          const int8_t v1x4 = w1[4];
          const int8_t v2x4 = w2[4];
          const int8_t v3x4 = w3[4];
          const int8_t v4x4 = w4[4];
          const int8_t v5x4 = w5[4];
          const int8_t v6x4 = w6[4];
          const int8_t v7x4 = w7[4];
          ksum4 += (uint32_t) v0x4;
          ksum4 += (uint32_t) v1x4;
          ksum4 += (uint32_t) v2x4;
          ksum4 += (uint32_t) v3x4;
          ksum4 += (uint32_t) v4x4;
          ksum4 += (uint32_t) v5x4;
          ksum4 += (uint32_t) v6x4;
          ksum4 += (uint32_t) v7x4;
          out[32] = v0x4;
          out[33] = v1x4;
          out[34] = v2x4;
          out[35] = v3x4;
          out[36] = v4x4;
          out[37] = v5x4;
          out[38] = v6x4;
          out[39] = v7x4;
        }
        if (5 < n) {
          const int8_t v0x5 = w0[5];
          const int8_t v1x5 = w1[5];
          const int8_t v2x5 = w2[5];
          const int8_t v3x5 = w3[5];
          const int8_t v4x5 = w4[5];
          const int8_t v5x5 = w5[5];
          const int8_t v6x5 = w6[5];
          const int8_t v7x5 = w7[5];
          ksum5 += (uint32_t) v0x5;
          ksum5 += (uint32_t) v1x5;
          ksum5 += (uint32_t) v2x5;
          ksum5 += (uint32_t) v3x5;
          ksum5 += (uint32_t) v4x5;
          ksum5 += (uint32_t) v5x5;
          ksum5 += (uint32_t) v6x5;
          ksum5 += (uint32_t) v7x5;
          out[40] = v0x5;
          out[41] = v1x5;
          out[42] = v2x5;
          out[43] = v3x5;
          out[44] = v4x5;
          out[45] = v5x5;
          out[46] = v6x5;
          out[47] = v7x5;
        }
        if (6 < n) {
          const int8_t v0x6 = w0[6];
          const int8_t v1x6 = w1[6];
          const int8_t v2x6 = w2[6];
          const int8_t v3x6 = w3[6];
          const int8_t v4x6 = w4[6];
          const int8_t v5x6 = w5[6];
          const int8_t v6x6 = w6[6];
          const int8_t v7x6 = w7[6];
          ksum6 += (uint32_t) v0x6;
          ksum6 += (uint32_t) v1x6;
          ksum6 += (uint32_t) v2x6;
          ksum6 += (uint32_t) v3x6;
          ksum6 += (uint32_t) v4x6;
          ksum6 += (uint32_t) v5x6;
          ksum6 += (uint32_t) v6x6;
          ksum6 += (uint32_t) v7x6;
          out[48] = v0x6;
          out[49] = v1x6;
          out[50] = v2x6;
          out[51] = v3x6;
          out[52] = v4x6;
          out[53] = v5x6;
          out[54] = v6x6;
          out[55] = v7x6;
        }
        if (7 < n) {
          const int8_t v0x7 = w0[7];
          const int8_t v1x7 = w1[7];
          const int8_t v2x7 = w2[7];
          const int8_t v3x7 = w3[7];
          const int8_t v4x7 = w4[7];
          const int8_t v5x7 = w5[7];
          const int8_t v6x7 = w6[7];
          const int8_t v7x7 = w7[7];
          ksum7 += (uint32_t) v0x7;
          ksum7 += (uint32_t) v1x7;
          ksum7 += (uint32_t) v2x7;
          ksum7 += (uint32_t) v3x7;
          ksum7 += (uint32_t) v4x7;
          ksum7 += (uint32_t) v5x7;
          ksum7 += (uint32_t) v6x7;
          ksum7 += (uint32_t) v7x7;
          out[56] = v0x7;
          out[57] = v1x7;
          out[58] = v2x7;
          out[59] = v3x7;
          out[60] = v4x7;
          out[61] = v5x7;
          out[62] = v6x7;
          out[63] = v7x7;
        }
        if (8 < n) {
          const int8_t v0x8 = w0[8];
          const int8_t v1x8 = w1[8];
          const int8_t v2x8 = w2[8];
          const int8_t v3x8 = w3[8];
          const int8_t v4x8 = w4[8];
          const int8_t v5x8 = w5[8];
          const int8_t v6x8 = w6[8];
          const int8_t v7x8 = w7[8];
          ksum8 += (uint32_t) v0x8;
          ksum8 += (uint32_t) v1x8;
          ksum8 += (uint32_t) v2x8;
          ksum8 += (uint32_t) v3x8;
          ksum8 += (uint32_t) v4x8;
          ksum8 += (uint32_t) v5x8;
          ksum8 += (uint32_t) v6x8;
          ksum8 += (uint32_t) v7x8;
          out[64] = v0x8;
          out[65] = v1x8;
          out[66] = v2x8;
          out[67] = v3x8;
          out[68] = v4x8;
          out[69] = v5x8;
          out[70] = v6x8;
          out[71] = v7x8;
        }
        if (9 < n) {
          const int8_t v0x9 = w0[9];
          const int8_t v1x9 = w1[9];
          const int8_t v2x9 = w2[9];
          const int8_t v3x9 = w3[9];
          const int8_t v4x9 = w4[9];
          const int8_t v5x9 = w5[9];
          const int8_t v6x9 = w6[9];
          const int8_t v7x9 = w7[9];
          ksum9 += (uint32_t) v0x9;
          ksum9 += (uint32_t) v1x9;
          ksum9 += (uint32_t) v2x9;
          ksum9 += (uint32_t) v3x9;
          ksum9 += (uint32_t) v4x9;
          ksum9 += (uint32_t) v5x9;
          ksum9 += (uint32_t) v6x9;
          ksum9 += (uint32_t) v7x9;
          out[72] = v0x9;
          out[73] = v1x9;
          out[74] = v2x9;
          out[75] = v3x9;
          out[76] = v4x9;
          out[77] = v5x9;
          out[78] = v6x9;
          out[79] = v7x9;
        }
        if (10 < n) {
          const int8_t v0x10 = w0[10];
          const int8_t v1x10 = w1[10];
          const int8_t v2x10 = w2[10];
          const int8_t v3x10 = w3[10];
          const int8_t v4x10 = w4[10];
          const int8_t v5x10 = w5[10];
          const int8_t v6x10 = w6[10];
          const int8_t v7x10 = w7[10];
          ksum10 += (uint32_t) v0x10;
          ksum10 += (uint32_t) v1x10;
          ksum10 += (uint32_t) v2x10;
          ksum10 += (uint32_t) v3x10;
          ksum10 += (uint32_t) v4x10;
          ksum10 += (uint32_t) v5x10;
          ksum10 += (uint32_t) v6x10;
          ksum10 += (uint32_t) v7x10;
          out[80] = v0x10;
          out[81] = v1x10;
          out[82] = v2x10;
          out[83] = v3x10;
          out[84] = v4x10;
          out[85] = v5x10;
          out[86] = v6x10;
          out[87] = v7x10;
        }
        if (11 < n) {
          const int8_t v0x11 = w0[11];
          const int8_t v1x11 = w1[11];
          const int8_t v2x11 = w2[11];
          const int8_t v3x11 = w3[11];
          const int8_t v4x11 = w4[11];
          const int8_t v5x11 = w5[11];
          const int8_t v6x11 = w6[11];
          const int8_t v7x11 = w7[11];
          ksum11 += (uint32_t) v0x11;
          ksum11 += (uint32_t) v1x11;
          ksum11 += (uint32_t) v2x11;
          ksum11 += (uint32_t) v3x11;
          ksum11 += (uint32_t) v4x11;
          ksum11 += (uint32_t) v5x11;
          ksum11 += (uint32_t) v6x11;
          ksum11 += (uint32_t) v7x11;
          out[88] = v0x11;
          out[89] = v1x11;
          out[90] = v2x11;
          out[91] = v3x11;
          out[92] = v4x11;
          out[93] = v5x11;
          out[94] = v6x11;
          out[95] = v7x11;
        }
        if (12 < n) {
          const int8_t v0x12 = w0[12];
          const int8_t v1x12 = w1[12];
          const int8_t v2x12 = w2[12];
          const int8_t v3x12 = w3[12];
          const int8_t v4x12 = w4[12];
          const int8_t v5x12 = w5[12];
          const int8_t v6x12 = w6[12];
          const int8_t v7x12 = w7[12];
          ksum12 += (uint32_t) v0x12;
          ksum12 += (uint32_t) v1x12;
          ksum12 += (uint32_t) v2x12;
          ksum12 += (uint32_t) v3x12;
          ksum12 += (uint32_t) v4x12;
          ksum12 += (uint32_t) v5x12;
          ksum12 += (uint32_t) v6x12;
          ksum12 += (uint32_t) v7x12;
          out[96] = v0x12;
          out[97] = v1x12;
          out[98] = v2x12;
          out[99] = v3x12;
          out[100] = v4x12;
          out[101] = v5x12;
          out[102] = v6x12;
          out[103] = v7x12;
        }
        if (13 < n) {
          const int8_t v0x13 = w0[13];
          const int8_t v1x13 = w1[13];
          const int8_t v2x13 = w2[13];
          const int8_t v3x13 = w3[13];
          const int8_t v4x13 = w4[13];
          const int8_t v5x13 = w5[13];
          const int8_t v6x13 = w6[13];
          const int8_t v7x13 = w7[13];
          ksum13 += (uint32_t) v0x13;
          ksum13 += (uint32_t) v1x13;
          ksum13 += (uint32_t) v2x13;
          ksum13 += (uint32_t) v3x13;
          ksum13 += (uint32_t) v4x13;
          ksum13 += (uint32_t) v5x13;
          ksum13 += (uint32_t) v6x13;
          ksum13 += (uint32_t) v7x13;
          out[104] = v0x13;
          out[105] = v1x13;
          out[106] = v2x13;
          out[107] = v3x13;
          out[108] = v4x13;
          out[109] = v5x13;
          out[110] = v6x13;
          out[111] = v7x13;
        }
        if (14 < n) {
          const int8_t v0x14 = w0[14];
          const int8_t v1x14 = w1[14];
          const int8_t v2x14 = w2[14];
          const int8_t v3x14 = w3[14];
          const int8_t v4x14 = w4[14];
          const int8_t v5x14 = w5[14];
          const int8_t v6x14 = w6[14];
          const int8_t v7x14 = w7[14];
          ksum14 += (uint32_t) v0x14;
          ksum14 += (uint32_t) v1x14;
          ksum14 += (uint32_t) v2x14;
          ksum14 += (uint32_t) v3x14;
          ksum14 += (uint32_t) v4x14;
          ksum14 += (uint32_t) v5x14;
          ksum14 += (uint32_t) v6x14;
          ksum14 += (uint32_t) v7x14;
          out[112] = v0x14;
          out[113] = v1x14;
          out[114] = v2x14;
          out[115] = v3x14;
          out[116] = v4x14;
          out[117] = v5x14;
          out[118] = v6x14;
          out[119] = v7x14;
        }
        w0 += 8 * k_stride;
        w1 += 8 * k_stride;
        w2 += 8 * k_stride;
        w3 += 8 * k_stride;
        w4 += 8 * k_stride;
        w5 += 8 * k_stride;
        w6 += 8 * k_stride;
        w7 += 8 * k_stride;
        out += 128;
      }

      // KC remainder of 1..7
      if (k != 0) {
        assert(k >= 1 && k <= 7);
        if (0 < n) {
          const int8_t v0x0 = w0[0];
          ksum0 += (uint32_t) v0x0;
          out[0] = v0x0;
          if (1 < k) {
            const int8_t v1x0 = w1[0];
            ksum0 += (uint32_t) v1x0;
            out[1] = v1x0;
          }
          if (2 < k) {
            const int8_t v2x0 = w2[0];
            ksum0 += (uint32_t) v2x0;
            out[2] = v2x0;
          }
          if (3 < k) {
            const int8_t v3x0 = w3[0];
            ksum0 += (uint32_t) v3x0;
            out[3] = v3x0;
          }
          if (4 < k) {
            const int8_t v4x0 = w4[0];
            ksum0 += (uint32_t) v4x0;
            out[4] = v4x0;
          }
          if (5 < k) {
            const int8_t v5x0 = w5[0];
            ksum0 += (uint32_t) v5x0;
            out[5] = v5x0;
          }
          if (6 < k) {
            const int8_t v6x0 = w6[0];
            ksum0 += (uint32_t) v6x0;
            out[6] = v6x0;
          }
          if (7 < k) {
            const int8_t v7x0 = w7[0];
            ksum0 += (uint32_t) v7x0;
            out[7] = v7x0;
          }
        }
        if (1 < n) {
          const int8_t v0x1 = w0[1];
          ksum1 += (uint32_t) v0x1;
          out[8] = v0x1;
          if (1 < k) {
            const int8_t v1x1 = w1[1];
            ksum1 += (uint32_t) v1x1;
            out[9] = v1x1;
          }
          if (2 < k) {
            const int8_t v2x1 = w2[1];
            ksum1 += (uint32_t) v2x1;
            out[10] = v2x1;
          }
          if (3 < k) {
            const int8_t v3x1 = w3[1];
            ksum1 += (uint32_t) v3x1;
            out[11] = v3x1;
          }
          if (4 < k) {
            const int8_t v4x1 = w4[1];
            ksum1 += (uint32_t) v4x1;
            out[12] = v4x1;
          }
          if (5 < k) {
            const int8_t v5x1 = w5[1];
            ksum1 += (uint32_t) v5x1;
            out[13] = v5x1;
          }
          if (6 < k) {
            const int8_t v6x1 = w6[1];
            ksum1 += (uint32_t) v6x1;
            out[14] = v6x1;
          }
          if (7 < k) {
            const int8_t v7x1 = w7[1];
            ksum1 += (uint32_t) v7x1;
            out[15] = v7x1;
          }
        }
        if (2 < n) {
          const int8_t v0x2 = w0[2];
          ksum2 += (uint32_t) v0x2;
          out[16] = v0x2;
          if (1 < k) {
            const int8_t v1x2 = w1[2];
            ksum2 += (uint32_t) v1x2;
            out[17] = v1x2;
          }
          if (2 < k) {
            const int8_t v2x2 = w2[2];
            ksum2 += (uint32_t) v2x2;
            out[18] = v2x2;
          }
          if (3 < k) {
            const int8_t v3x2 = w3[2];
            ksum2 += (uint32_t) v3x2;
            out[19] = v3x2;
          }
          if (4 < k) {
            const int8_t v4x2 = w4[2];
            ksum2 += (uint32_t) v4x2;
            out[20] = v4x2;
          }
          if (5 < k) {
            const int8_t v5x2 = w5[2];
            ksum2 += (uint32_t) v5x2;
            out[21] = v5x2;
          }
          if (6 < k) {
            const int8_t v6x2 = w6[2];
            ksum2 += (uint32_t) v6x2;
            out[22] = v6x2;
          }
          if (7 < k) {
            const int8_t v7x2 = w7[2];
            ksum2 += (uint32_t) v7x2;
            out[23] = v7x2;
          }
        }
        if (3 < n) {
          const int8_t v0x3 = w0[3];
          ksum3 += (uint32_t) v0x3;
          out[24] = v0x3;
          if (1 < k) {
            const int8_t v1x3 = w1[3];
            ksum3 += (uint32_t) v1x3;
            out[25] = v1x3;
          }
          if (2 < k) {
            const int8_t v2x3 = w2[3];
            ksum3 += (uint32_t) v2x3;
            out[26] = v2x3;
          }
          if (3 < k) {
            const int8_t v3x3 = w3[3];
            ksum3 += (uint32_t) v3x3;
            out[27] = v3x3;
          }
          if (4 < k) {
            const int8_t v4x3 = w4[3];
            ksum3 += (uint32_t) v4x3;
            out[28] = v4x3;
          }
          if (5 < k) {
            const int8_t v5x3 = w5[3];
            ksum3 += (uint32_t) v5x3;
            out[29] = v5x3;
          }
          if (6 < k) {
            const int8_t v6x3 = w6[3];
            ksum3 += (uint32_t) v6x3;
            out[30] = v6x3;
          }
          if (7 < k) {
            const int8_t v7x3 = w7[3];
            ksum3 += (uint32_t) v7x3;
            out[31] = v7x3;
          }
        }
        if (4 < n) {
          const int8_t v0x4 = w0[4];
          ksum4 += (uint32_t) v0x4;
          out[32] = v0x4;
          if (1 < k) {
            const int8_t v1x4 = w1[4];
            ksum4 += (uint32_t) v1x4;
            out[33] = v1x4;
          }
          if (2 < k) {
            const int8_t v2x4 = w2[4];
            ksum4 += (uint32_t) v2x4;
            out[34] = v2x4;
          }
          if (3 < k) {
            const int8_t v3x4 = w3[4];
            ksum4 += (uint32_t) v3x4;
            out[35] = v3x4;
          }
          if (4 < k) {
            const int8_t v4x4 = w4[4];
            ksum4 += (uint32_t) v4x4;
            out[36] = v4x4;
          }
          if (5 < k) {
            const int8_t v5x4 = w5[4];
            ksum4 += (uint32_t) v5x4;
            out[37] = v5x4;
          }
          if (6 < k) {
            const int8_t v6x4 = w6[4];
            ksum4 += (uint32_t) v6x4;
            out[38] = v6x4;
          }
          if (7 < k) {
            const int8_t v7x4 = w7[4];
            ksum4 += (uint32_t) v7x4;
            out[39] = v7x4;
          }
        }
        if (5 < n) {
          const int8_t v0x5 = w0[5];
          ksum5 += (uint32_t) v0x5;
          out[40] = v0x5;
          if (1 < k) {
            const int8_t v1x5 = w1[5];
            ksum5 += (uint32_t) v1x5;
            out[41] = v1x5;
          }
          if (2 < k) {
            const int8_t v2x5 = w2[5];
            ksum5 += (uint32_t) v2x5;
            out[42] = v2x5;
          }
          if (3 < k) {
            const int8_t v3x5 = w3[5];
            ksum5 += (uint32_t) v3x5;
            out[43] = v3x5;
          }
          if (4 < k) {
            const int8_t v4x5 = w4[5];
            ksum5 += (uint32_t) v4x5;
            out[44] = v4x5;
          }
          if (5 < k) {
            const int8_t v5x5 = w5[5];
            ksum5 += (uint32_t) v5x5;
            out[45] = v5x5;
          }
          if (6 < k) {
            const int8_t v6x5 = w6[5];
            ksum5 += (uint32_t) v6x5;
            out[46] = v6x5;
          }
          if (7 < k) {
            const int8_t v7x5 = w7[5];
            ksum5 += (uint32_t) v7x5;
            out[47] = v7x5;
          }
        }
        if (6 < n) {
          const int8_t v0x6 = w0[6];
          ksum6 += (uint32_t) v0x6;
          out[48] = v0x6;
          if (1 < k) {
            const int8_t v1x6 = w1[6];
            ksum6 += (uint32_t) v1x6;
            out[49] = v1x6;
          }
          if (2 < k) {
            const int8_t v2x6 = w2[6];
            ksum6 += (uint32_t) v2x6;
            out[50] = v2x6;
          }
          if (3 < k) {
            const int8_t v3x6 = w3[6];
            ksum6 += (uint32_t) v3x6;
            out[51] = v3x6;
          }
          if (4 < k) {
            const int8_t v4x6 = w4[6];
            ksum6 += (uint32_t) v4x6;
            out[52] = v4x6;
          }
          if (5 < k) {
            const int8_t v5x6 = w5[6];
            ksum6 += (uint32_t) v5x6;
            out[53] = v5x6;
          }
          if (6 < k) {
            const int8_t v6x6 = w6[6];
            ksum6 += (uint32_t) v6x6;
            out[54] = v6x6;
          }
          if (7 < k) {
            const int8_t v7x6 = w7[6];
            ksum6 += (uint32_t) v7x6;
            out[55] = v7x6;
          }
        }
        if (7 < n) {
          const int8_t v0x7 = w0[7];
          ksum7 += (uint32_t) v0x7;
          out[56] = v0x7;
          if (1 < k) {
            const int8_t v1x7 = w1[7];
            ksum7 += (uint32_t) v1x7;
            out[57] = v1x7;
          }
          if (2 < k) {
            const int8_t v2x7 = w2[7];
            ksum7 += (uint32_t) v2x7;
            out[58] = v2x7;
          }
          if (3 < k) {
            const int8_t v3x7 = w3[7];
            ksum7 += (uint32_t) v3x7;
            out[59] = v3x7;
          }
          if (4 < k) {
            const int8_t v4x7 = w4[7];
            ksum7 += (uint32_t) v4x7;
            out[60] = v4x7;
          }
          if (5 < k) {
            const int8_t v5x7 = w5[7];
            ksum7 += (uint32_t) v5x7;
            out[61] = v5x7;
          }
          if (6 < k) {
            const int8_t v6x7 = w6[7];
            ksum7 += (uint32_t) v6x7;
            out[62] = v6x7;
          }
          if (7 < k) {
            const int8_t v7x7 = w7[7];
            ksum7 += (uint32_t) v7x7;
            out[63] = v7x7;
          }
        }
        if (8 < n) {
          const int8_t v0x8 = w0[8];
          ksum8 += (uint32_t) v0x8;
          out[64] = v0x8;
          if (1 < k) {
            const int8_t v1x8 = w1[8];
            ksum8 += (uint32_t) v1x8;
            out[65] = v1x8;
          }
          if (2 < k) {
            const int8_t v2x8 = w2[8];
            ksum8 += (uint32_t) v2x8;
            out[66] = v2x8;
          }
          if (3 < k) {
            const int8_t v3x8 = w3[8];
            ksum8 += (uint32_t) v3x8;
            out[67] = v3x8;
          }
          if (4 < k) {
            const int8_t v4x8 = w4[8];
            ksum8 += (uint32_t) v4x8;
            out[68] = v4x8;
          }
          if (5 < k) {
            const int8_t v5x8 = w5[8];
            ksum8 += (uint32_t) v5x8;
            out[69] = v5x8;
          }
          if (6 < k) {
            const int8_t v6x8 = w6[8];
            ksum8 += (uint32_t) v6x8;
            out[70] = v6x8;
          }
          if (7 < k) {
            const int8_t v7x8 = w7[8];
            ksum8 += (uint32_t) v7x8;
            out[71] = v7x8;
          }
        }
        if (9 < n) {
          const int8_t v0x9 = w0[9];
          ksum9 += (uint32_t) v0x9;
          out[72] = v0x9;
          if (1 < k) {
            const int8_t v1x9 = w1[9];
            ksum9 += (uint32_t) v1x9;
            out[73] = v1x9;
          }
          if (2 < k) {
            const int8_t v2x9 = w2[9];
            ksum9 += (uint32_t) v2x9;
            out[74] = v2x9;
          }
          if (3 < k) {
            const int8_t v3x9 = w3[9];
            ksum9 += (uint32_t) v3x9;
            out[75] = v3x9;
          }
          if (4 < k) {
            const int8_t v4x9 = w4[9];
            ksum9 += (uint32_t) v4x9;
            out[76] = v4x9;
          }
          if (5 < k) {
            const int8_t v5x9 = w5[9];
            ksum9 += (uint32_t) v5x9;
            out[77] = v5x9;
          }
          if (6 < k) {
            const int8_t v6x9 = w6[9];
            ksum9 += (uint32_t) v6x9;
            out[78] = v6x9;
          }
          if (7 < k) {
            const int8_t v7x9 = w7[9];
            ksum9 += (uint32_t) v7x9;
            out[79] = v7x9;
          }
        }
        if (10 < n) {
          const int8_t v0x10 = w0[10];
          ksum10 += (uint32_t) v0x10;
          out[80] = v0x10;
          if (1 < k) {
            const int8_t v1x10 = w1[10];
            ksum10 += (uint32_t) v1x10;
            out[81] = v1x10;
          }
          if (2 < k) {
            const int8_t v2x10 = w2[10];
            ksum10 += (uint32_t) v2x10;
            out[82] = v2x10;
          }
          if (3 < k) {
            const int8_t v3x10 = w3[10];
            ksum10 += (uint32_t) v3x10;
            out[83] = v3x10;
          }
          if (4 < k) {
            const int8_t v4x10 = w4[10];
            ksum10 += (uint32_t) v4x10;
            out[84] = v4x10;
          }
          if (5 < k) {
            const int8_t v5x10 = w5[10];
            ksum10 += (uint32_t) v5x10;
            out[85] = v5x10;
          }
          if (6 < k) {
            const int8_t v6x10 = w6[10];
            ksum10 += (uint32_t) v6x10;
            out[86] = v6x10;
          }
          if (7 < k) {
            const int8_t v7x10 = w7[10];
            ksum10 += (uint32_t) v7x10;
            out[87] = v7x10;
          }
        }
        if (11 < n) {
          const int8_t v0x11 = w0[11];
          ksum11 += (uint32_t) v0x11;
          out[88] = v0x11;
          if (1 < k) {
            const int8_t v1x11 = w1[11];
            ksum11 += (uint32_t) v1x11;
            out[89] = v1x11;
          }
          if (2 < k) {
            const int8_t v2x11 = w2[11];
            ksum11 += (uint32_t) v2x11;
            out[90] = v2x11;
          }
          if (3 < k) {
            const int8_t v3x11 = w3[11];
            ksum11 += (uint32_t) v3x11;
            out[91] = v3x11;
          }
          if (4 < k) {
            const int8_t v4x11 = w4[11];
            ksum11 += (uint32_t) v4x11;
            out[92] = v4x11;
          }
          if (5 < k) {
            const int8_t v5x11 = w5[11];
            ksum11 += (uint32_t) v5x11;
            out[93] = v5x11;
          }
          if (6 < k) {
            const int8_t v6x11 = w6[11];
            ksum11 += (uint32_t) v6x11;
            out[94] = v6x11;
          }
          if (7 < k) {
            const int8_t v7x11 = w7[11];
            ksum11 += (uint32_t) v7x11;
            out[95] = v7x11;
          }
        }
        if (12 < n) {
          const int8_t v0x12 = w0[12];
          ksum12 += (uint32_t) v0x12;
          out[96] = v0x12;
          if (1 < k) {
            const int8_t v1x12 = w1[12];
            ksum12 += (uint32_t) v1x12;
            out[97] = v1x12;
          }
          if (2 < k) {
            const int8_t v2x12 = w2[12];
            ksum12 += (uint32_t) v2x12;
            out[98] = v2x12;
          }
          if (3 < k) {
            const int8_t v3x12 = w3[12];
            ksum12 += (uint32_t) v3x12;
            out[99] = v3x12;
          }
          if (4 < k) {
            const int8_t v4x12 = w4[12];
            ksum12 += (uint32_t) v4x12;
            out[100] = v4x12;
          }
          if (5 < k) {
            const int8_t v5x12 = w5[12];
            ksum12 += (uint32_t) v5x12;
            out[101] = v5x12;
          }
          if (6 < k) {
            const int8_t v6x12 = w6[12];
            ksum12 += (uint32_t) v6x12;
            out[102] = v6x12;
          }
          if (7 < k) {
            const int8_t v7x12 = w7[12];
            ksum12 += (uint32_t) v7x12;
            out[103] = v7x12;
          }
        }
        if (13 < n) {
          const int8_t v0x13 = w0[13];
          ksum13 += (uint32_t) v0x13;
          out[104] = v0x13;
          if (1 < k) {
            const int8_t v1x13 = w1[13];
            ksum13 += (uint32_t) v1x13;
            out[105] = v1x13;
          }
          if (2 < k) {
            const int8_t v2x13 = w2[13];
            ksum13 += (uint32_t) v2x13;
            out[106] = v2x13;
          }
          if (3 < k) {
            const int8_t v3x13 = w3[13];
            ksum13 += (uint32_t) v3x13;
            out[107] = v3x13;
          }
          if (4 < k) {
            const int8_t v4x13 = w4[13];
            ksum13 += (uint32_t) v4x13;
            out[108] = v4x13;
          }
          if (5 < k) {
            const int8_t v5x13 = w5[13];
            ksum13 += (uint32_t) v5x13;
            out[109] = v5x13;
          }
          if (6 < k) {
            const int8_t v6x13 = w6[13];
            ksum13 += (uint32_t) v6x13;
            out[110] = v6x13;
          }
          if (7 < k) {
            const int8_t v7x13 = w7[13];
            ksum13 += (uint32_t) v7x13;
            out[111] = v7x13;
          }
        }
        if (14 < n) {
          const int8_t v0x14 = w0[14];
          ksum14 += (uint32_t) v0x14;
          out[112] = v0x14;
          if (1 < k) {
            const int8_t v1x14 = w1[14];
            ksum14 += (uint32_t) v1x14;
            out[113] = v1x14;
          }
          if (2 < k) {
            const int8_t v2x14 = w2[14];
            ksum14 += (uint32_t) v2x14;
            out[114] = v2x14;
          }
          if (3 < k) {
            const int8_t v3x14 = w3[14];
            ksum14 += (uint32_t) v3x14;
            out[115] = v3x14;
          }
          if (4 < k) {
            const int8_t v4x14 = w4[14];
            ksum14 += (uint32_t) v4x14;
            out[116] = v4x14;
          }
          if (5 < k) {
            const int8_t v5x14 = w5[14];
            ksum14 += (uint32_t) v5x14;
            out[117] = v5x14;
          }
          if (6 < k) {
            const int8_t v6x14 = w6[14];
            ksum14 += (uint32_t) v6x14;
            out[118] = v6x14;
          }
          if (7 < k) {
            const int8_t v7x14 = w7[14];
            ksum14 += (uint32_t) v7x14;
            out[119] = v7x14;
          }
        }
        w0 += k * k_stride;
        w1 += k * k_stride;
        w2 += k * k_stride;
        w3 += k * k_stride;
        w4 += k * k_stride;
        w5 += k * k_stride;
        w6 += k * k_stride;
        w7 += k * k_stride;
        out += 128;
      }

      packed_b[0] -= ksum0 * izp;
      packed_b[1] -= ksum1 * izp;
      packed_b[2] -= ksum2 * izp;
      packed_b[3] -= ksum3 * izp;
      packed_b[4] -= ksum4 * izp;
      packed_b[5] -= ksum5 * izp;
      packed_b[6] -= ksum6 * izp;
      packed_b[7] -= ksum7 * izp;
      packed_b[8] -= ksum8 * izp;
      packed_b[9] -= ksum9 * izp;
      packed_b[10] -= ksum10 * izp;
      packed_b[11] -= ksum11 * izp;
      packed_b[12] -= ksum12 * izp;
      packed_b[13] -= ksum13 * izp;
      packed_b[14] -= ksum14 * izp;
      out = (int8_t*) ((uintptr_t) out + extra_bytes);
    }
    weights += nc * kc;
  } while (--g != 0);
}
