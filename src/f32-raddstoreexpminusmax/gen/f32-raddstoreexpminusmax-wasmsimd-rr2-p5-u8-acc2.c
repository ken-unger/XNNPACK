// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-raddstoreexpminusmax/wasmsimd-rr2-p5.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/raddstoreexpminusmax.h"


void xnn_f32_raddstoreexpminusmax_ukernel__wasmsimd_rr2_p5_u8_acc2(
    size_t batch,
    const float* input,
    const float* max,
    float* output,
    float* sum,
    const void* params) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(max != NULL);
  assert(output != NULL);
  assert(sum != NULL);

  const v128_t vlog2e = wasm_f32x4_const_splat(0x1.715476p+0f);
  const v128_t vmagic_bias = wasm_f32x4_const_splat(0x1.8000FEp23f);
  const v128_t vminus_ln2_hi = wasm_f32x4_const_splat(-0x1.62E400p-1f);
  const v128_t vminus_ln2_lo = wasm_f32x4_const_splat(-0x1.7F7D1Cp-20f);
  const v128_t vc5 = wasm_f32x4_const_splat(0x1.0F9F9Cp-7f);
  const v128_t vc4 = wasm_f32x4_const_splat(0x1.573A1Ap-5f);
  const v128_t vc3 = wasm_f32x4_const_splat(0x1.555A80p-3f);
  const v128_t vc2 = wasm_f32x4_const_splat(0x1.FFFDC6p-2f);
  const v128_t vc1 = wasm_f32x4_const_splat(0x1.FFFFF6p-1f);
  const v128_t vdenorm_cutoff = wasm_f32x4_const_splat(-0x1.5D589Ep6f);

  XNN_FORCE_REALIZATION(vlog2e);
  XNN_FORCE_REALIZATION(vmagic_bias);
  XNN_FORCE_REALIZATION(vminus_ln2_hi);
  XNN_FORCE_REALIZATION(vminus_ln2_lo);
  XNN_FORCE_REALIZATION(vc5);
  XNN_FORCE_REALIZATION(vc4);
  XNN_FORCE_REALIZATION(vc3);
  XNN_FORCE_REALIZATION(vc2);
  XNN_FORCE_REALIZATION(vc1);
  XNN_FORCE_REALIZATION(vdenorm_cutoff);

  const v128_t vi_max = wasm_v128_load32_splat(max);

  v128_t vacc0 = wasm_f32x4_const_splat(0.0f);
  v128_t vacc1 = vacc0;
  for (; batch >= 8 * sizeof(float); batch -= 8 * sizeof(float)) {
    // Load 8 (2x4) inputs at a time.
    const v128_t vi0123 = wasm_v128_load(input);
    const v128_t vi4567 = wasm_v128_load(input + 4);
    input += 8;

    const v128_t vx0123 = wasm_f32x4_sub(vi0123, vi_max);
    const v128_t vx4567 = wasm_f32x4_sub(vi4567, vi_max);

    v128_t vn0123 = wasm_f32x4_add(wasm_f32x4_mul(vx0123, vlog2e), vmagic_bias);
    v128_t vn4567 = wasm_f32x4_add(wasm_f32x4_mul(vx4567, vlog2e), vmagic_bias);

    const v128_t vs0123 = wasm_i32x4_shl(vn0123, 23);
    const v128_t vs4567 = wasm_i32x4_shl(vn4567, 23);

    vn0123 = wasm_f32x4_sub(vn0123, vmagic_bias);
    vn4567 = wasm_f32x4_sub(vn4567, vmagic_bias);

    v128_t vt0123 = wasm_f32x4_add(wasm_f32x4_mul(vn0123, vminus_ln2_hi), vx0123);
    v128_t vt4567 = wasm_f32x4_add(wasm_f32x4_mul(vn4567, vminus_ln2_hi), vx4567);

    vt0123 = wasm_f32x4_add(wasm_f32x4_mul(vn0123, vminus_ln2_lo), vt0123);
    vt4567 = wasm_f32x4_add(wasm_f32x4_mul(vn4567, vminus_ln2_lo), vt4567);

    v128_t vp0123 = wasm_f32x4_add(wasm_f32x4_mul(vc5, vt0123), vc4);
    v128_t vp4567 = wasm_f32x4_add(wasm_f32x4_mul(vc5, vt4567), vc4);

    vp0123 = wasm_f32x4_add(wasm_f32x4_mul(vp0123, vt0123), vc3);
    vp4567 = wasm_f32x4_add(wasm_f32x4_mul(vp4567, vt4567), vc3);

    vp0123 = wasm_f32x4_add(wasm_f32x4_mul(vp0123, vt0123), vc2);
    vp4567 = wasm_f32x4_add(wasm_f32x4_mul(vp4567, vt4567), vc2);

    vp0123 = wasm_f32x4_add(wasm_f32x4_mul(vp0123, vt0123), vc1);
    vp4567 = wasm_f32x4_add(wasm_f32x4_mul(vp4567, vt4567), vc1);

    vt0123 = wasm_f32x4_mul(vt0123, vs0123);
    vt4567 = wasm_f32x4_mul(vt4567, vs4567);

    v128_t vf0123 = wasm_f32x4_add(wasm_f32x4_mul(vt0123, vp0123), vs0123);
    v128_t vf4567 = wasm_f32x4_add(wasm_f32x4_mul(vt4567, vp4567), vs4567);

    vf0123 = wasm_v128_andnot(vf0123, wasm_f32x4_lt(vx0123, vdenorm_cutoff));
    vf4567 = wasm_v128_andnot(vf4567, wasm_f32x4_lt(vx4567, vdenorm_cutoff));

    wasm_v128_store(output, vf0123);
    wasm_v128_store(output + 4, vf4567);
    output += 8;

    vacc0 = wasm_f32x4_add(vacc0, vf0123);
    vacc0 = wasm_f32x4_add(vacc0, vf4567);
  }
  // Add up all accumulators to vacc0
  vacc0 = wasm_f32x4_add(vacc0, vacc1);

  v128_t vacc = vacc0;
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const v128_t vi = wasm_v128_load(input);
    input += 4;

    const v128_t vx = wasm_f32x4_sub(vi, vi_max);

    v128_t vn = wasm_f32x4_add(wasm_f32x4_mul(vx, vlog2e), vmagic_bias);

    const v128_t vs = wasm_i32x4_shl(vn, 23);

    vn = wasm_f32x4_sub(vn, vmagic_bias);

    v128_t vt = wasm_f32x4_add(wasm_f32x4_mul(vn, vminus_ln2_hi), vx);
    vt = wasm_f32x4_add(wasm_f32x4_mul(vn, vminus_ln2_lo), vt);

    v128_t vp = wasm_f32x4_add(wasm_f32x4_mul(vc5, vt), vc4);
    vp = wasm_f32x4_add(wasm_f32x4_mul(vp, vt), vc3);
    vp = wasm_f32x4_add(wasm_f32x4_mul(vp, vt), vc2);
    vp = wasm_f32x4_add(wasm_f32x4_mul(vp, vt), vc1);

    vt = wasm_f32x4_mul(vt, vs);
    v128_t vf = wasm_f32x4_add(wasm_f32x4_mul(vt, vp), vs);

    vf = wasm_v128_andnot(vf, wasm_f32x4_lt(vx, vdenorm_cutoff));

    wasm_v128_store(output, vf);
    output += 4;

    vacc = wasm_f32x4_add(vacc, vf);
  }
  vacc = wasm_f32x4_add(vacc, wasm_v64x2_shuffle(vacc, vacc, 1, 1));
  float vsum = wasm_f32x4_extract_lane(vacc, 0) + wasm_f32x4_extract_lane(vacc, 1);
  if (batch != 0) {
    assert(batch >= 1 * sizeof(float));
    assert(batch <= 3 * sizeof(float));

    const v128_t vi = wasm_v128_load(input);

    const v128_t vx = wasm_f32x4_sub(vi, vi_max);

    v128_t vn = wasm_f32x4_add(wasm_f32x4_mul(vx, vlog2e), vmagic_bias);

    const v128_t vs = wasm_i32x4_shl(vn, 23);

    vn = wasm_f32x4_sub(vn, vmagic_bias);

    v128_t vt = wasm_f32x4_add(wasm_f32x4_mul(vn, vminus_ln2_hi), vx);
    vt = wasm_f32x4_add(wasm_f32x4_mul(vn, vminus_ln2_lo), vt);

    v128_t vp = wasm_f32x4_add(wasm_f32x4_mul(vc5, vt), vc4);
    vp = wasm_f32x4_add(wasm_f32x4_mul(vp, vt), vc3);
    vp = wasm_f32x4_add(wasm_f32x4_mul(vp, vt), vc2);
    vp = wasm_f32x4_add(wasm_f32x4_mul(vp, vt), vc1);

    vt = wasm_f32x4_mul(vt, vs);
    v128_t vf = wasm_f32x4_add(wasm_f32x4_mul(vt, vp), vs);

    vf = wasm_v128_andnot(vf, wasm_f32x4_lt(vx, vdenorm_cutoff));

    if (batch & (2 * sizeof(float))) {
      wasm_v128_store64_lane(output, vf, 0);
      output += 2;

      vsum += wasm_f32x4_extract_lane(vf, 0) + wasm_f32x4_extract_lane(vf, 1);
      vf = wasm_v64x2_shuffle(vf, vf, 1, 1);
    }
    if (batch & (1 * sizeof(float))) {
      wasm_v128_store32_lane(output, vf, 0);
      vsum += wasm_f32x4_extract_lane(vf, 0);
    }
  }
  *sum = vsum;
}
