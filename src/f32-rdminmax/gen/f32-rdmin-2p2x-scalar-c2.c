// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-rdminmax/simd.c.in
//   Generator: tools/xngen
//
// Copyright 2025 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/reduce.h"

#include "src/xnnpack/simd/f32-scalar.h"


void xnn_f32_rdmin_ukernel_2p2x__scalar_c2(
    size_t rows,
    size_t channels,
    const float* input,
    size_t input_stride,
    float* output,
    const void* params)
{
  assert(rows != 0);
  assert(channels != 0);
  assert(input != NULL);
  assert(output != NULL);

  size_t input_increment = 2 * input_stride;
  for (; channels >= 2; channels -= 2) {
    const float* i0 = input;
    const float* i1 = (const float*) ((uintptr_t) input + 1 * input_stride);

    xnn_simd_f32_t vmin0 = xnn_loadu_f32(output);
    xnn_simd_f32_t vmin1 = xnn_loadu_f32((float*)((uintptr_t) output + 1 * sizeof(float)));

    for (int r = rows; r > 0; r -= 2) {
      if XNN_UNPREDICTABLE(r < 2) {
        i1 = i0;
      }
      xnn_simd_f32_t vin_0_0 = xnn_loadu_f32(&i0[0]);
      xnn_simd_f32_t vin_0_1 = xnn_loadu_f32(&i0[1]);
      xnn_simd_f32_t vin_1_0 = xnn_loadu_f32(&i1[0]);
      xnn_simd_f32_t vin_1_1 = xnn_loadu_f32(&i1[1]);
      vmin0 = xnn_min_f32(vmin0, vin_0_0);
      vmin1 = xnn_min_f32(vmin1, vin_0_1);
      vmin0 = xnn_min_f32(vmin0, vin_1_0);
      vmin1 = xnn_min_f32(vmin1, vin_1_1);

      i0 = (float*) ((uintptr_t) i0 + input_increment);
      i1 = (float*) ((uintptr_t) i1 + input_increment);
    }

    xnn_storeu_f32(output, vmin0);
    output = (float*) ((uintptr_t) output + xnn_simd_bytes_f32);
    xnn_storeu_f32(output, vmin1);
    output = (float*) ((uintptr_t) output + xnn_simd_bytes_f32);

    input = (float*) ((uintptr_t) input + 2 * sizeof(float));
  }
  if (channels != 0) {
    input_increment = 2 * input_stride;
    do {
      const float* i0 = input;
      const float* i1 = (const float*) ((uintptr_t) input + 1 * input_stride);

      xnn_simd_f32_t vmin;

      if (channels >= xnn_simd_size_f32) {
        vmin = xnn_loadu_f32(output);
      } else {
        vmin = xnn_load_tail_safe_f32(output, channels);
      }

      for (int r = rows; r > 0; r -= 2) {
        if XNN_UNPREDICTABLE(r < 2) {
          i1 = i0;
        }
        xnn_simd_f32_t vin0;
        xnn_simd_f32_t vin1;
        if (channels >= xnn_simd_size_f32) {
          vin0 = xnn_loadu_f32(&i0[0]);
        } else {
          vin0 = xnn_load_tail_safe_f32(&i0[0], channels);
        }
        if (channels >= xnn_simd_size_f32) {
          vin1 = xnn_loadu_f32(&i1[0]);
        } else {
          vin1 = xnn_load_tail_safe_f32(&i1[0], channels);
        }
        vmin = xnn_min_f32(vmin, vin0);
        vmin = xnn_min_f32(vmin, vin1);
        i0 = (float*) ((uintptr_t) i0 + input_increment);
        i1 = (float*) ((uintptr_t) i1 + input_increment);
      }

      if (channels >= xnn_simd_size_f32) {
        xnn_storeu_f32(output, vmin);
        output = (float*) ((uintptr_t) output + xnn_simd_bytes_f32);
        input = (float*) ((uintptr_t) input + xnn_simd_bytes_f32);
        channels -= xnn_simd_size_f32;
      } else {
        xnn_store_tail_f32(output, vmin, channels);

        channels = 0;
      }
    } while (channels != 0);
  }
}
