// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-rminmax/neon.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/reduce.h"


void xnn_f32_rmax_ukernel__neon_u4(
    size_t batch,
    const float* input,
    float* output,
    const struct xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input != NULL);
  assert(output != NULL);

  float32x4_t vmax0 = vld1q_dup_f32(output);
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const float32x4_t vt = vld1q_f32(input); input += 4;
    vmax0 = vmaxq_f32(vmax0, vt);
  }
  float32x2_t vmax = vmax_f32(vget_low_f32(vmax0), vget_high_f32(vmax0));
  if XNN_UNLIKELY(batch & (2 * sizeof(float))) {
    const float32x2_t vt = vld1_f32(input); input += 2;
    vmax = vmax_f32(vmax, vt);
  }
  vmax = vpmax_f32(vmax, vmax);
  if XNN_UNLIKELY(batch & (1 * sizeof(float))) {
    const float32x2_t vt = vld1_dup_f32(input);
    vmax = vmax_f32(vmax, vt);
  }
  vst1_lane_f32(output, vmax, 0);
}
