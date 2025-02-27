// Auto-generated file. Do not edit!
//   Template: src/f32-igemm/neon-ld128.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.


#include <assert.h>

#include <arm_neon.h>

#include "xnnpack/igemm.h"


void xnn_f32_igemm_minmax_ukernel_6x16__neon_lane_ld128(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const float** restrict a,
    const float* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const float* zero,
    const struct xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(mr != 0);
  assert(mr <= 6);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(float) == 0);
  assert(ks != 0);
  assert(ks % (6 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(float) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  float* c0 = c;
  float* c1 = (float*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    c1 = c0;
  }
  float* c2 = (float*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    c2 = c1;
  }
  float* c3 = (float*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 4) {
    c3 = c2;
  }
  float* c4 = (float*) ((uintptr_t) c3 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 4) {
    c4 = c3;
  }
  float* c5 = (float*) ((uintptr_t) c4 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 6) {
    c5 = c4;
  }

  do {
    float32x4_t vacc0x0 = vld1q_f32(w); w += 4;
    float32x4_t vacc0x1 = vld1q_f32(w); w += 4;
    float32x4_t vacc0x2 = vld1q_f32(w); w += 4;
    float32x4_t vacc0x3 = vld1q_f32(w); w += 4;
    float32x4_t vacc1x0 = vacc0x0;
    float32x4_t vacc1x1 = vacc0x1;
    float32x4_t vacc1x2 = vacc0x2;
    float32x4_t vacc1x3 = vacc0x3;
    float32x4_t vacc2x0 = vacc0x0;
    float32x4_t vacc2x1 = vacc0x1;
    float32x4_t vacc2x2 = vacc0x2;
    float32x4_t vacc2x3 = vacc0x3;
    float32x4_t vacc3x0 = vacc0x0;
    float32x4_t vacc3x1 = vacc0x1;
    float32x4_t vacc3x2 = vacc0x2;
    float32x4_t vacc3x3 = vacc0x3;
    float32x4_t vacc4x0 = vacc0x0;
    float32x4_t vacc4x1 = vacc0x1;
    float32x4_t vacc4x2 = vacc0x2;
    float32x4_t vacc4x3 = vacc0x3;
    float32x4_t vacc5x0 = vacc0x0;
    float32x4_t vacc5x1 = vacc0x1;
    float32x4_t vacc5x2 = vacc0x2;
    float32x4_t vacc5x3 = vacc0x3;

    size_t p = ks;
    do {
      const float* restrict a0 = a[0];
      assert(a0 != NULL);
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const float*) ((uintptr_t) a0 + a_offset);
      }
      const float* restrict a1 = a[1];
      assert(a1 != NULL);
      if XNN_UNPREDICTABLE(a1 != zero) {
        a1 = (const float*) ((uintptr_t) a1 + a_offset);
      }
      const float* restrict a2 = a[2];
      assert(a2 != NULL);
      if XNN_UNPREDICTABLE(a2 != zero) {
        a2 = (const float*) ((uintptr_t) a2 + a_offset);
      }
      const float* restrict a3 = a[3];
      assert(a3 != NULL);
      if XNN_UNPREDICTABLE(a3 != zero) {
        a3 = (const float*) ((uintptr_t) a3 + a_offset);
      }
      const float* restrict a4 = a[4];
      assert(a4 != NULL);
      if XNN_UNPREDICTABLE(a4 != zero) {
        a4 = (const float*) ((uintptr_t) a4 + a_offset);
      }
      const float* restrict a5 = a[5];
      assert(a5 != NULL);
      if XNN_UNPREDICTABLE(a5 != zero) {
        a5 = (const float*) ((uintptr_t) a5 + a_offset);
      }
      a += 6;

      size_t k = kc;
      for (; k >= 4 * sizeof(float); k -= 4 * sizeof(float)) {
        const float32x4_t va0 = vld1q_f32(a0); a0 += 4;
        const float32x4_t va1 = vld1q_f32(a1); a1 += 4;
        const float32x4_t va2 = vld1q_f32(a2); a2 += 4;
        const float32x4_t va3 = vld1q_f32(a3); a3 += 4;
        const float32x4_t va4 = vld1q_f32(a4); a4 += 4;
        const float32x4_t va5 = vld1q_f32(a5); a5 += 4;


        const float32x4_t vb0123c0 = vld1q_f32(w); w += 4;
        const float32x4_t vb4567c0 = vld1q_f32(w); w += 4;
        const float32x4_t vb89ABc0 = vld1q_f32(w); w += 4;
        const float32x4_t vbCDEFc0 = vld1q_f32(w); w += 4;

        vacc0x0 = vmlaq_lane_f32(vacc0x0, vb0123c0, vget_low_f32(va0), 0);
        vacc1x0 = vmlaq_lane_f32(vacc1x0, vb0123c0, vget_low_f32(va1), 0);
        vacc2x0 = vmlaq_lane_f32(vacc2x0, vb0123c0, vget_low_f32(va2), 0);
        vacc3x0 = vmlaq_lane_f32(vacc3x0, vb0123c0, vget_low_f32(va3), 0);
        vacc4x0 = vmlaq_lane_f32(vacc4x0, vb0123c0, vget_low_f32(va4), 0);
        vacc5x0 = vmlaq_lane_f32(vacc5x0, vb0123c0, vget_low_f32(va5), 0);
        vacc0x1 = vmlaq_lane_f32(vacc0x1, vb4567c0, vget_low_f32(va0), 0);
        vacc1x1 = vmlaq_lane_f32(vacc1x1, vb4567c0, vget_low_f32(va1), 0);
        vacc2x1 = vmlaq_lane_f32(vacc2x1, vb4567c0, vget_low_f32(va2), 0);
        vacc3x1 = vmlaq_lane_f32(vacc3x1, vb4567c0, vget_low_f32(va3), 0);
        vacc4x1 = vmlaq_lane_f32(vacc4x1, vb4567c0, vget_low_f32(va4), 0);
        vacc5x1 = vmlaq_lane_f32(vacc5x1, vb4567c0, vget_low_f32(va5), 0);
        vacc0x2 = vmlaq_lane_f32(vacc0x2, vb89ABc0, vget_low_f32(va0), 0);
        vacc1x2 = vmlaq_lane_f32(vacc1x2, vb89ABc0, vget_low_f32(va1), 0);
        vacc2x2 = vmlaq_lane_f32(vacc2x2, vb89ABc0, vget_low_f32(va2), 0);
        vacc3x2 = vmlaq_lane_f32(vacc3x2, vb89ABc0, vget_low_f32(va3), 0);
        vacc4x2 = vmlaq_lane_f32(vacc4x2, vb89ABc0, vget_low_f32(va4), 0);
        vacc5x2 = vmlaq_lane_f32(vacc5x2, vb89ABc0, vget_low_f32(va5), 0);
        vacc0x3 = vmlaq_lane_f32(vacc0x3, vbCDEFc0, vget_low_f32(va0), 0);
        vacc1x3 = vmlaq_lane_f32(vacc1x3, vbCDEFc0, vget_low_f32(va1), 0);
        vacc2x3 = vmlaq_lane_f32(vacc2x3, vbCDEFc0, vget_low_f32(va2), 0);
        vacc3x3 = vmlaq_lane_f32(vacc3x3, vbCDEFc0, vget_low_f32(va3), 0);
        vacc4x3 = vmlaq_lane_f32(vacc4x3, vbCDEFc0, vget_low_f32(va4), 0);
        vacc5x3 = vmlaq_lane_f32(vacc5x3, vbCDEFc0, vget_low_f32(va5), 0);

        const float32x4_t vb0123c1 = vld1q_f32(w); w += 4;
        const float32x4_t vb4567c1 = vld1q_f32(w); w += 4;
        const float32x4_t vb89ABc1 = vld1q_f32(w); w += 4;
        const float32x4_t vbCDEFc1 = vld1q_f32(w); w += 4;

        vacc0x0 = vmlaq_lane_f32(vacc0x0, vb0123c1, vget_low_f32(va0), 1);
        vacc1x0 = vmlaq_lane_f32(vacc1x0, vb0123c1, vget_low_f32(va1), 1);
        vacc2x0 = vmlaq_lane_f32(vacc2x0, vb0123c1, vget_low_f32(va2), 1);
        vacc3x0 = vmlaq_lane_f32(vacc3x0, vb0123c1, vget_low_f32(va3), 1);
        vacc4x0 = vmlaq_lane_f32(vacc4x0, vb0123c1, vget_low_f32(va4), 1);
        vacc5x0 = vmlaq_lane_f32(vacc5x0, vb0123c1, vget_low_f32(va5), 1);
        vacc0x1 = vmlaq_lane_f32(vacc0x1, vb4567c1, vget_low_f32(va0), 1);
        vacc1x1 = vmlaq_lane_f32(vacc1x1, vb4567c1, vget_low_f32(va1), 1);
        vacc2x1 = vmlaq_lane_f32(vacc2x1, vb4567c1, vget_low_f32(va2), 1);
        vacc3x1 = vmlaq_lane_f32(vacc3x1, vb4567c1, vget_low_f32(va3), 1);
        vacc4x1 = vmlaq_lane_f32(vacc4x1, vb4567c1, vget_low_f32(va4), 1);
        vacc5x1 = vmlaq_lane_f32(vacc5x1, vb4567c1, vget_low_f32(va5), 1);
        vacc0x2 = vmlaq_lane_f32(vacc0x2, vb89ABc1, vget_low_f32(va0), 1);
        vacc1x2 = vmlaq_lane_f32(vacc1x2, vb89ABc1, vget_low_f32(va1), 1);
        vacc2x2 = vmlaq_lane_f32(vacc2x2, vb89ABc1, vget_low_f32(va2), 1);
        vacc3x2 = vmlaq_lane_f32(vacc3x2, vb89ABc1, vget_low_f32(va3), 1);
        vacc4x2 = vmlaq_lane_f32(vacc4x2, vb89ABc1, vget_low_f32(va4), 1);
        vacc5x2 = vmlaq_lane_f32(vacc5x2, vb89ABc1, vget_low_f32(va5), 1);
        vacc0x3 = vmlaq_lane_f32(vacc0x3, vbCDEFc1, vget_low_f32(va0), 1);
        vacc1x3 = vmlaq_lane_f32(vacc1x3, vbCDEFc1, vget_low_f32(va1), 1);
        vacc2x3 = vmlaq_lane_f32(vacc2x3, vbCDEFc1, vget_low_f32(va2), 1);
        vacc3x3 = vmlaq_lane_f32(vacc3x3, vbCDEFc1, vget_low_f32(va3), 1);
        vacc4x3 = vmlaq_lane_f32(vacc4x3, vbCDEFc1, vget_low_f32(va4), 1);
        vacc5x3 = vmlaq_lane_f32(vacc5x3, vbCDEFc1, vget_low_f32(va5), 1);

        const float32x4_t vb0123c2 = vld1q_f32(w); w += 4;
        const float32x4_t vb4567c2 = vld1q_f32(w); w += 4;
        const float32x4_t vb89ABc2 = vld1q_f32(w); w += 4;
        const float32x4_t vbCDEFc2 = vld1q_f32(w); w += 4;

        vacc0x0 = vmlaq_lane_f32(vacc0x0, vb0123c2, vget_high_f32(va0), 0);
        vacc1x0 = vmlaq_lane_f32(vacc1x0, vb0123c2, vget_high_f32(va1), 0);
        vacc2x0 = vmlaq_lane_f32(vacc2x0, vb0123c2, vget_high_f32(va2), 0);
        vacc3x0 = vmlaq_lane_f32(vacc3x0, vb0123c2, vget_high_f32(va3), 0);
        vacc4x0 = vmlaq_lane_f32(vacc4x0, vb0123c2, vget_high_f32(va4), 0);
        vacc5x0 = vmlaq_lane_f32(vacc5x0, vb0123c2, vget_high_f32(va5), 0);
        vacc0x1 = vmlaq_lane_f32(vacc0x1, vb4567c2, vget_high_f32(va0), 0);
        vacc1x1 = vmlaq_lane_f32(vacc1x1, vb4567c2, vget_high_f32(va1), 0);
        vacc2x1 = vmlaq_lane_f32(vacc2x1, vb4567c2, vget_high_f32(va2), 0);
        vacc3x1 = vmlaq_lane_f32(vacc3x1, vb4567c2, vget_high_f32(va3), 0);
        vacc4x1 = vmlaq_lane_f32(vacc4x1, vb4567c2, vget_high_f32(va4), 0);
        vacc5x1 = vmlaq_lane_f32(vacc5x1, vb4567c2, vget_high_f32(va5), 0);
        vacc0x2 = vmlaq_lane_f32(vacc0x2, vb89ABc2, vget_high_f32(va0), 0);
        vacc1x2 = vmlaq_lane_f32(vacc1x2, vb89ABc2, vget_high_f32(va1), 0);
        vacc2x2 = vmlaq_lane_f32(vacc2x2, vb89ABc2, vget_high_f32(va2), 0);
        vacc3x2 = vmlaq_lane_f32(vacc3x2, vb89ABc2, vget_high_f32(va3), 0);
        vacc4x2 = vmlaq_lane_f32(vacc4x2, vb89ABc2, vget_high_f32(va4), 0);
        vacc5x2 = vmlaq_lane_f32(vacc5x2, vb89ABc2, vget_high_f32(va5), 0);
        vacc0x3 = vmlaq_lane_f32(vacc0x3, vbCDEFc2, vget_high_f32(va0), 0);
        vacc1x3 = vmlaq_lane_f32(vacc1x3, vbCDEFc2, vget_high_f32(va1), 0);
        vacc2x3 = vmlaq_lane_f32(vacc2x3, vbCDEFc2, vget_high_f32(va2), 0);
        vacc3x3 = vmlaq_lane_f32(vacc3x3, vbCDEFc2, vget_high_f32(va3), 0);
        vacc4x3 = vmlaq_lane_f32(vacc4x3, vbCDEFc2, vget_high_f32(va4), 0);
        vacc5x3 = vmlaq_lane_f32(vacc5x3, vbCDEFc2, vget_high_f32(va5), 0);

        const float32x4_t vb0123c3 = vld1q_f32(w); w += 4;
        const float32x4_t vb4567c3 = vld1q_f32(w); w += 4;
        const float32x4_t vb89ABc3 = vld1q_f32(w); w += 4;
        const float32x4_t vbCDEFc3 = vld1q_f32(w); w += 4;

        vacc0x0 = vmlaq_lane_f32(vacc0x0, vb0123c3, vget_high_f32(va0), 1);
        vacc1x0 = vmlaq_lane_f32(vacc1x0, vb0123c3, vget_high_f32(va1), 1);
        vacc2x0 = vmlaq_lane_f32(vacc2x0, vb0123c3, vget_high_f32(va2), 1);
        vacc3x0 = vmlaq_lane_f32(vacc3x0, vb0123c3, vget_high_f32(va3), 1);
        vacc4x0 = vmlaq_lane_f32(vacc4x0, vb0123c3, vget_high_f32(va4), 1);
        vacc5x0 = vmlaq_lane_f32(vacc5x0, vb0123c3, vget_high_f32(va5), 1);
        vacc0x1 = vmlaq_lane_f32(vacc0x1, vb4567c3, vget_high_f32(va0), 1);
        vacc1x1 = vmlaq_lane_f32(vacc1x1, vb4567c3, vget_high_f32(va1), 1);
        vacc2x1 = vmlaq_lane_f32(vacc2x1, vb4567c3, vget_high_f32(va2), 1);
        vacc3x1 = vmlaq_lane_f32(vacc3x1, vb4567c3, vget_high_f32(va3), 1);
        vacc4x1 = vmlaq_lane_f32(vacc4x1, vb4567c3, vget_high_f32(va4), 1);
        vacc5x1 = vmlaq_lane_f32(vacc5x1, vb4567c3, vget_high_f32(va5), 1);
        vacc0x2 = vmlaq_lane_f32(vacc0x2, vb89ABc3, vget_high_f32(va0), 1);
        vacc1x2 = vmlaq_lane_f32(vacc1x2, vb89ABc3, vget_high_f32(va1), 1);
        vacc2x2 = vmlaq_lane_f32(vacc2x2, vb89ABc3, vget_high_f32(va2), 1);
        vacc3x2 = vmlaq_lane_f32(vacc3x2, vb89ABc3, vget_high_f32(va3), 1);
        vacc4x2 = vmlaq_lane_f32(vacc4x2, vb89ABc3, vget_high_f32(va4), 1);
        vacc5x2 = vmlaq_lane_f32(vacc5x2, vb89ABc3, vget_high_f32(va5), 1);
        vacc0x3 = vmlaq_lane_f32(vacc0x3, vbCDEFc3, vget_high_f32(va0), 1);
        vacc1x3 = vmlaq_lane_f32(vacc1x3, vbCDEFc3, vget_high_f32(va1), 1);
        vacc2x3 = vmlaq_lane_f32(vacc2x3, vbCDEFc3, vget_high_f32(va2), 1);
        vacc3x3 = vmlaq_lane_f32(vacc3x3, vbCDEFc3, vget_high_f32(va3), 1);
        vacc4x3 = vmlaq_lane_f32(vacc4x3, vbCDEFc3, vget_high_f32(va4), 1);
        vacc5x3 = vmlaq_lane_f32(vacc5x3, vbCDEFc3, vget_high_f32(va5), 1);
      }
      if XNN_UNLIKELY(k != 0) {
        do {
          const float32x4_t va0 = vld1q_dup_f32(a0); a0 += 1;
          const float32x4_t va1 = vld1q_dup_f32(a1); a1 += 1;
          const float32x4_t va2 = vld1q_dup_f32(a2); a2 += 1;
          const float32x4_t va3 = vld1q_dup_f32(a3); a3 += 1;
          const float32x4_t va4 = vld1q_dup_f32(a4); a4 += 1;
          const float32x4_t va5 = vld1q_dup_f32(a5); a5 += 1;

          const float32x4_t vb0123 = vld1q_f32(w); w += 4;
          const float32x4_t vb4567 = vld1q_f32(w); w += 4;
          const float32x4_t vb89AB = vld1q_f32(w); w += 4;
          const float32x4_t vbCDEF = vld1q_f32(w); w += 4;

          vacc0x0 = vmlaq_f32(vacc0x0, va0, vb0123);
          vacc1x0 = vmlaq_f32(vacc1x0, va1, vb0123);
          vacc2x0 = vmlaq_f32(vacc2x0, va2, vb0123);
          vacc3x0 = vmlaq_f32(vacc3x0, va3, vb0123);
          vacc4x0 = vmlaq_f32(vacc4x0, va4, vb0123);
          vacc5x0 = vmlaq_f32(vacc5x0, va5, vb0123);
          vacc0x1 = vmlaq_f32(vacc0x1, va0, vb4567);
          vacc1x1 = vmlaq_f32(vacc1x1, va1, vb4567);
          vacc2x1 = vmlaq_f32(vacc2x1, va2, vb4567);
          vacc3x1 = vmlaq_f32(vacc3x1, va3, vb4567);
          vacc4x1 = vmlaq_f32(vacc4x1, va4, vb4567);
          vacc5x1 = vmlaq_f32(vacc5x1, va5, vb4567);
          vacc0x2 = vmlaq_f32(vacc0x2, va0, vb89AB);
          vacc1x2 = vmlaq_f32(vacc1x2, va1, vb89AB);
          vacc2x2 = vmlaq_f32(vacc2x2, va2, vb89AB);
          vacc3x2 = vmlaq_f32(vacc3x2, va3, vb89AB);
          vacc4x2 = vmlaq_f32(vacc4x2, va4, vb89AB);
          vacc5x2 = vmlaq_f32(vacc5x2, va5, vb89AB);
          vacc0x3 = vmlaq_f32(vacc0x3, va0, vbCDEF);
          vacc1x3 = vmlaq_f32(vacc1x3, va1, vbCDEF);
          vacc2x3 = vmlaq_f32(vacc2x3, va2, vbCDEF);
          vacc3x3 = vmlaq_f32(vacc3x3, va3, vbCDEF);
          vacc4x3 = vmlaq_f32(vacc4x3, va4, vbCDEF);
          vacc5x3 = vmlaq_f32(vacc5x3, va5, vbCDEF);

          k -= sizeof(float);
        } while (k != 0);
      }

      p -= 6 * sizeof(void*);
    } while (p != 0);

    const float32x4_t vmax = vdupq_n_f32(params->scalar.max);
    vacc0x0 = vminq_f32(vacc0x0, vmax);
    vacc1x0 = vminq_f32(vacc1x0, vmax);
    vacc2x0 = vminq_f32(vacc2x0, vmax);
    vacc3x0 = vminq_f32(vacc3x0, vmax);
    vacc4x0 = vminq_f32(vacc4x0, vmax);
    vacc5x0 = vminq_f32(vacc5x0, vmax);
    vacc0x1 = vminq_f32(vacc0x1, vmax);
    vacc1x1 = vminq_f32(vacc1x1, vmax);
    vacc2x1 = vminq_f32(vacc2x1, vmax);
    vacc3x1 = vminq_f32(vacc3x1, vmax);
    vacc4x1 = vminq_f32(vacc4x1, vmax);
    vacc5x1 = vminq_f32(vacc5x1, vmax);
    vacc0x2 = vminq_f32(vacc0x2, vmax);
    vacc1x2 = vminq_f32(vacc1x2, vmax);
    vacc2x2 = vminq_f32(vacc2x2, vmax);
    vacc3x2 = vminq_f32(vacc3x2, vmax);
    vacc4x2 = vminq_f32(vacc4x2, vmax);
    vacc5x2 = vminq_f32(vacc5x2, vmax);
    vacc0x3 = vminq_f32(vacc0x3, vmax);
    vacc1x3 = vminq_f32(vacc1x3, vmax);
    vacc2x3 = vminq_f32(vacc2x3, vmax);
    vacc3x3 = vminq_f32(vacc3x3, vmax);
    vacc4x3 = vminq_f32(vacc4x3, vmax);
    vacc5x3 = vminq_f32(vacc5x3, vmax);

    const float32x4_t vmin = vdupq_n_f32(params->scalar.min);
    vacc0x0 = vmaxq_f32(vacc0x0, vmin);
    vacc1x0 = vmaxq_f32(vacc1x0, vmin);
    vacc2x0 = vmaxq_f32(vacc2x0, vmin);
    vacc3x0 = vmaxq_f32(vacc3x0, vmin);
    vacc4x0 = vmaxq_f32(vacc4x0, vmin);
    vacc5x0 = vmaxq_f32(vacc5x0, vmin);
    vacc0x1 = vmaxq_f32(vacc0x1, vmin);
    vacc1x1 = vmaxq_f32(vacc1x1, vmin);
    vacc2x1 = vmaxq_f32(vacc2x1, vmin);
    vacc3x1 = vmaxq_f32(vacc3x1, vmin);
    vacc4x1 = vmaxq_f32(vacc4x1, vmin);
    vacc5x1 = vmaxq_f32(vacc5x1, vmin);
    vacc0x2 = vmaxq_f32(vacc0x2, vmin);
    vacc1x2 = vmaxq_f32(vacc1x2, vmin);
    vacc2x2 = vmaxq_f32(vacc2x2, vmin);
    vacc3x2 = vmaxq_f32(vacc3x2, vmin);
    vacc4x2 = vmaxq_f32(vacc4x2, vmin);
    vacc5x2 = vmaxq_f32(vacc5x2, vmin);
    vacc0x3 = vmaxq_f32(vacc0x3, vmin);
    vacc1x3 = vmaxq_f32(vacc1x3, vmin);
    vacc2x3 = vmaxq_f32(vacc2x3, vmin);
    vacc3x3 = vmaxq_f32(vacc3x3, vmin);
    vacc4x3 = vmaxq_f32(vacc4x3, vmin);
    vacc5x3 = vmaxq_f32(vacc5x3, vmin);

    if XNN_LIKELY(nc >= 16) {
      vst1q_f32(c5, vacc5x0);
      vst1q_f32(c5 + 4, vacc5x1);
      vst1q_f32(c5 + 8, vacc5x2);
      vst1q_f32(c5 + 12, vacc5x3);
      c5 = (float*) ((uintptr_t) c5 + cn_stride);
      vst1q_f32(c4, vacc4x0);
      vst1q_f32(c4 + 4, vacc4x1);
      vst1q_f32(c4 + 8, vacc4x2);
      vst1q_f32(c4 + 12, vacc4x3);
      c4 = (float*) ((uintptr_t) c4 + cn_stride);
      vst1q_f32(c3, vacc3x0);
      vst1q_f32(c3 + 4, vacc3x1);
      vst1q_f32(c3 + 8, vacc3x2);
      vst1q_f32(c3 + 12, vacc3x3);
      c3 = (float*) ((uintptr_t) c3 + cn_stride);
      vst1q_f32(c2, vacc2x0);
      vst1q_f32(c2 + 4, vacc2x1);
      vst1q_f32(c2 + 8, vacc2x2);
      vst1q_f32(c2 + 12, vacc2x3);
      c2 = (float*) ((uintptr_t) c2 + cn_stride);
      vst1q_f32(c1, vacc1x0);
      vst1q_f32(c1 + 4, vacc1x1);
      vst1q_f32(c1 + 8, vacc1x2);
      vst1q_f32(c1 + 12, vacc1x3);
      c1 = (float*) ((uintptr_t) c1 + cn_stride);
      vst1q_f32(c0, vacc0x0);
      vst1q_f32(c0 + 4, vacc0x1);
      vst1q_f32(c0 + 8, vacc0x2);
      vst1q_f32(c0 + 12, vacc0x3);
      c0 = (float*) ((uintptr_t) c0 + cn_stride);

      a = (const float**restrict) ((uintptr_t) a - ks);
      nc -= 16;
    } else {
      if (nc & 8) {
        vst1q_f32(c5, vacc5x0); c5 += 4;
        vst1q_f32(c4, vacc4x0); c4 += 4;
        vst1q_f32(c3, vacc3x0); c3 += 4;
        vst1q_f32(c2, vacc2x0); c2 += 4;
        vst1q_f32(c1, vacc1x0); c1 += 4;
        vst1q_f32(c0, vacc0x0); c0 += 4;
        vst1q_f32(c5, vacc5x1); c5 += 4;
        vst1q_f32(c4, vacc4x1); c4 += 4;
        vst1q_f32(c3, vacc3x1); c3 += 4;
        vst1q_f32(c2, vacc2x1); c2 += 4;
        vst1q_f32(c1, vacc1x1); c1 += 4;
        vst1q_f32(c0, vacc0x1); c0 += 4;

        vacc5x0 = vacc5x2;
        vacc5x1 = vacc5x3;
        vacc4x0 = vacc4x2;
        vacc4x1 = vacc4x3;
        vacc3x0 = vacc3x2;
        vacc3x1 = vacc3x3;
        vacc2x0 = vacc2x2;
        vacc2x1 = vacc2x3;
        vacc1x0 = vacc1x2;
        vacc1x1 = vacc1x3;
        vacc0x0 = vacc0x2;
        vacc0x1 = vacc0x3;
      }
      if (nc & 4) {
        vst1q_f32(c5, vacc5x0); c5 += 4;
        vst1q_f32(c4, vacc4x0); c4 += 4;
        vst1q_f32(c3, vacc3x0); c3 += 4;
        vst1q_f32(c2, vacc2x0); c2 += 4;
        vst1q_f32(c1, vacc1x0); c1 += 4;
        vst1q_f32(c0, vacc0x0); c0 += 4;

        vacc5x0 = vacc5x1;
        vacc5x1 = vacc5x2;
        vacc5x2 = vacc5x3;
        vacc4x0 = vacc4x1;
        vacc4x1 = vacc4x2;
        vacc4x2 = vacc4x3;
        vacc3x0 = vacc3x1;
        vacc3x1 = vacc3x2;
        vacc3x2 = vacc3x3;
        vacc2x0 = vacc2x1;
        vacc2x1 = vacc2x2;
        vacc2x2 = vacc2x3;
        vacc1x0 = vacc1x1;
        vacc1x1 = vacc1x2;
        vacc1x2 = vacc1x3;
        vacc0x0 = vacc0x1;
        vacc0x1 = vacc0x2;
        vacc0x2 = vacc0x3;
      }
      float32x2_t vacc5 = vget_low_f32(vacc5x0);
      float32x2_t vacc4 = vget_low_f32(vacc4x0);
      float32x2_t vacc3 = vget_low_f32(vacc3x0);
      float32x2_t vacc2 = vget_low_f32(vacc2x0);
      float32x2_t vacc1 = vget_low_f32(vacc1x0);
      float32x2_t vacc0 = vget_low_f32(vacc0x0);
      if (nc & 2) {
        vst1_f32(c5, vacc5); c5 += 2;
        vst1_f32(c4, vacc4); c4 += 2;
        vst1_f32(c3, vacc3); c3 += 2;
        vst1_f32(c2, vacc2); c2 += 2;
        vst1_f32(c1, vacc1); c1 += 2;
        vst1_f32(c0, vacc0); c0 += 2;

        vacc5 = vget_high_f32(vacc5x0);
        vacc4 = vget_high_f32(vacc4x0);
        vacc3 = vget_high_f32(vacc3x0);
        vacc2 = vget_high_f32(vacc2x0);
        vacc1 = vget_high_f32(vacc1x0);
        vacc0 = vget_high_f32(vacc0x0);
      }
      if (nc & 1) {
        vst1_lane_f32(c5, vacc5, 0);
        vst1_lane_f32(c4, vacc4, 0);
        vst1_lane_f32(c3, vacc3, 0);
        vst1_lane_f32(c2, vacc2, 0);
        vst1_lane_f32(c1, vacc1, 0);
        vst1_lane_f32(c0, vacc0, 0);
      }

      nc = 0;
    }
  } while (nc != 0);
}
