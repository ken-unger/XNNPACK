// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f16-raddstoreexpminusmax/rvvfp16arith-rr2-p2.c.in
//   Generator: tools/xngen
//
// Copyright 2026 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <riscv_vector.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/raddstoreexpminusmax.h"


void xnn_f16_raddstoreexpminusmax_ukernel__rvvfp16arith_rr2_p2_u2v(
    size_t batch,
    const xnn_float16* input,
    const xnn_float16* max,
    xnn_float16* output,
    xnn_float16* sum,
    const void* params) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(xnn_float16) == 0);
  assert(input != NULL);
  assert(max != NULL);
  assert(output != NULL);
  assert(sum != NULL);

  const xnn_float16 vlog2e = (xnn_float16) UINT16_C(0x3DC5);  // 0x1.714p+0h 0x1.714p+0h;
  const xnn_float16 vmagic_bias = (xnn_float16) UINT16_C(0x660F);  //0x1.83Cp+10h;
  const xnn_float16 vminus_ln2_hi = (xnn_float16) UINT16_C(0xB98C);  // -0x1.630p-1h;
  const xnn_float16 vminus_ln2_lo = (xnn_float16) UINT16_C(0x0AF4);  // 0x1.BD0p-13h;
  const xnn_float16 vc2 = (xnn_float16) UINT16_C(0x37F9);  // 0x1.FE4p-2h;
  const xnn_float16 vc1 = (xnn_float16) UINT16_C(0x3C0E);  // 0x1.038p+0h;
  const xnn_float16 vdenorm_cutoff = (xnn_float16) UINT16_C(0xC8DA);  // -0x1.368p+3h;

  const xnn_float16* i = input;
  xnn_float16* o = output;

  batch >>= XNN_LOG2_SIZEOF_FLOAT16;

  size_t vlmax = __riscv_vsetvl_e16m2(batch);
  vfloat16m2_t vacc = __riscv_vfmv_v_f_f16m2(0.0f, vlmax);

  do {
    size_t vl = __riscv_vsetvl_e16m2(batch);
    batch -= vl;

    vfloat16m2_t vi = __riscv_vle16_v_f16m2(i, vl); i += vl;

    const vfloat16m2_t vx = __riscv_vfsub_vf_f16m2(vi, *max, vl);

    vfloat16m2_t vn = __riscv_vfmv_v_f_f16m2(vmagic_bias, vl);
    vn = __riscv_vfmacc_vf_f16m2(vn, vlog2e, vx, vl);

    const vfloat16m2_t vs = __riscv_vreinterpret_v_i16m2_f16m2(__riscv_vsll_vx_i16m2(__riscv_vreinterpret_v_f16m2_i16m2(vn), 10, vl));

    vn = __riscv_vfsub_vf_f16m2(vn, vmagic_bias, vl);

    vfloat16m2_t vt = __riscv_vmv_v_v_f16m2(vx, vl);
    vt = __riscv_vfmacc_vf_f16m2(vt, vminus_ln2_hi, vn, vl);
    vt = __riscv_vfmacc_vf_f16m2(vt, vminus_ln2_lo, vn, vl);

    vfloat16m2_t vp = __riscv_vfmv_v_f_f16m2(vc1, vl);
    vp = __riscv_vfmacc_vf_f16m2(vp, vc2, vt, vl);

    vt = __riscv_vfmul_vv_f16m2(vt, vs, vl);

    vfloat16m2_t vf = __riscv_vmv_v_v_f16m2(vs, vl);
    vf = __riscv_vfmacc_vv_f16m2(vf, vp, vt, vl);

    const vbool8_t vmask = __riscv_vmflt_vf_f16m2_b8(vx, vdenorm_cutoff, vl);
    vf = __riscv_vreinterpret_v_u16m2_f16m2(__riscv_vand_vx_u16m2_m(vmask, __riscv_vreinterpret_v_f16m2_u16m2(vf), UINT16_C(0x0000), vl));

    __riscv_vse16_v_f16m2(o, vf, vl); o += vl;

    vacc = __riscv_vfadd_vv_f16m2(vacc, vf, vl);
  } while (batch > 0);

   vfloat16m1_t v0 = __riscv_vfmv_s_f_f16m1(0.0f, 1);
  *sum = __riscv_vfmv_f_s_f16m1_f16(__riscv_vfredusum_vs_f16m2_f16m1(vacc, v0, vlmax));
}
