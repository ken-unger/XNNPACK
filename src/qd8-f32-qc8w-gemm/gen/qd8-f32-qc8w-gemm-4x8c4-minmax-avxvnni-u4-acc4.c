// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/MRx8c4-avxvnni.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stdint.h>

#include <immintrin.h>

#include "xnnpack/common.h"
#include "xnnpack/gemm.h"
#include "xnnpack/intrinsics-polyfill.h"
#include "xnnpack/math.h"
#include "xnnpack/unaligned.h"
#include "xnnpack/prefetch.h"


void xnn_qd8_f32_qc8w_gemm_minmax_ukernel_4x8c4__avxvnni_u4_acc4(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const struct xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)],
    const struct xnn_qd8_quantization_params quantization_params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 4);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 4 * sizeof(int8_t));
  const int8_t* a0 = a;
  float* c0 = c;
  const int8_t* a1 = (const int8_t*) ((uintptr_t) a0 + a_stride);
  float* c1 = (float*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    a1 = a0;
    c1 = c0;
  }
  const int8_t* a2 = (const int8_t*) ((uintptr_t) a1 + a_stride);
  float* c2 = (float*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    a2 = a1;
    c2 = c1;
  }
  const int8_t* a3 = (const int8_t*) ((uintptr_t) a2 + a_stride);
  float* c3 = (float*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 4) {
    a3 = a2;
    c3 = c2;
  }

  const __m256i vinput_zero_point0 = _mm256_set1_epi32((int) quantization_params[0].zero_point);
  const __m256i vinput_zero_point1 = _mm256_set1_epi32((int) quantization_params[1].zero_point);
  const __m256i vinput_zero_point2 = _mm256_set1_epi32((int) quantization_params[2].zero_point);
  const __m256i vinput_zero_point3 = _mm256_set1_epi32((int) quantization_params[3].zero_point);
  const __m256 voutput_min = _mm256_set1_ps(params->scalar.min);
  const __m256 voutput_max = _mm256_set1_ps(params->scalar.max);
  // XNN_FORCE_REALIZATION(voutput_min);
  // XNN_FORCE_REALIZATION(voutput_max);
  do {
    const __m256i vksum01234567 = _mm256_load_si256(w);
    __m256i vacc0x0x01234567 = _mm256_mullo_epi32(vksum01234567, vinput_zero_point0);
    __m256i vacc0x1x01234567 = _mm256_setzero_si256();
    __m256i vacc0x2x01234567 = _mm256_setzero_si256();
    __m256i vacc0x3x01234567 = _mm256_setzero_si256();
    __m256i vacc1x0x01234567 = _mm256_mullo_epi32(vksum01234567, vinput_zero_point1);
    __m256i vacc1x1x01234567 = _mm256_setzero_si256();
    __m256i vacc1x2x01234567 = _mm256_setzero_si256();
    __m256i vacc1x3x01234567 = _mm256_setzero_si256();
    __m256i vacc2x0x01234567 = _mm256_mullo_epi32(vksum01234567, vinput_zero_point2);
    __m256i vacc2x1x01234567 = _mm256_setzero_si256();
    __m256i vacc2x2x01234567 = _mm256_setzero_si256();
    __m256i vacc2x3x01234567 = _mm256_setzero_si256();
    __m256i vacc3x0x01234567 = _mm256_mullo_epi32(vksum01234567, vinput_zero_point3);
    __m256i vacc3x1x01234567 = _mm256_setzero_si256();
    __m256i vacc3x2x01234567 = _mm256_setzero_si256();
    __m256i vacc3x3x01234567 = _mm256_setzero_si256();
    w = (const int32_t*) w + 8;

    size_t k = kc;
    while (k >= 16 * sizeof(int8_t)) {
      __m256i va0x0x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a0 + 0));
      __m256i va0x1x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a0 + 4));
      __m256i va0x2x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a0 + 8));
      __m256i va0x3x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a0 + 12));
      a0 += 16;
      __m256i va1x0x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a1 + 0));
      __m256i va1x1x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a1 + 4));
      __m256i va1x2x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a1 + 8));
      __m256i va1x3x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a1 + 12));
      a1 += 16;
      __m256i va2x0x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a2 + 0));
      __m256i va2x1x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a2 + 4));
      __m256i va2x2x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a2 + 8));
      __m256i va2x3x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a2 + 12));
      a2 += 16;
      __m256i va3x0x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a3 + 0));
      __m256i va3x1x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a3 + 4));
      __m256i va3x2x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a3 + 8));
      __m256i va3x3x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a3 + 12));
      a3 += 16;

      const __m256i vb0x01234567 = _mm256_load_si256((const __m256i*) ((const int8_t*) w + 0));
      const __m256i vb1x01234567 = _mm256_load_si256((const __m256i*) ((const int8_t*) w + 32));
      const __m256i vb2x01234567 = _mm256_load_si256((const __m256i*) ((const int8_t*) w + 64));
      const __m256i vb3x01234567 = _mm256_load_si256((const __m256i*) ((const int8_t*) w + 96));
      w = (const int8_t*) w + 128;

      vacc0x0x01234567 = _mm256_dpbusd_avx_epi32(vacc0x0x01234567, va0x0x0123, vb0x01234567);
      vacc0x1x01234567 = _mm256_dpbusd_avx_epi32(vacc0x1x01234567, va0x1x0123, vb1x01234567);
      vacc0x2x01234567 = _mm256_dpbusd_avx_epi32(vacc0x2x01234567, va0x2x0123, vb2x01234567);
      vacc0x3x01234567 = _mm256_dpbusd_avx_epi32(vacc0x3x01234567, va0x3x0123, vb3x01234567);
      vacc1x0x01234567 = _mm256_dpbusd_avx_epi32(vacc1x0x01234567, va1x0x0123, vb0x01234567);
      vacc1x1x01234567 = _mm256_dpbusd_avx_epi32(vacc1x1x01234567, va1x1x0123, vb1x01234567);
      vacc1x2x01234567 = _mm256_dpbusd_avx_epi32(vacc1x2x01234567, va1x2x0123, vb2x01234567);
      vacc1x3x01234567 = _mm256_dpbusd_avx_epi32(vacc1x3x01234567, va1x3x0123, vb3x01234567);
      vacc2x0x01234567 = _mm256_dpbusd_avx_epi32(vacc2x0x01234567, va2x0x0123, vb0x01234567);
      vacc2x1x01234567 = _mm256_dpbusd_avx_epi32(vacc2x1x01234567, va2x1x0123, vb1x01234567);
      vacc2x2x01234567 = _mm256_dpbusd_avx_epi32(vacc2x2x01234567, va2x2x0123, vb2x01234567);
      vacc2x3x01234567 = _mm256_dpbusd_avx_epi32(vacc2x3x01234567, va2x3x0123, vb3x01234567);
      vacc3x0x01234567 = _mm256_dpbusd_avx_epi32(vacc3x0x01234567, va3x0x0123, vb0x01234567);
      vacc3x1x01234567 = _mm256_dpbusd_avx_epi32(vacc3x1x01234567, va3x1x0123, vb1x01234567);
      vacc3x2x01234567 = _mm256_dpbusd_avx_epi32(vacc3x2x01234567, va3x2x0123, vb2x01234567);
      vacc3x3x01234567 = _mm256_dpbusd_avx_epi32(vacc3x3x01234567, va3x3x0123, vb3x01234567);

      k -= 16 * sizeof(int8_t);
    }
    vacc0x0x01234567 = _mm256_add_epi32(vacc0x0x01234567, vacc0x1x01234567);
    vacc1x0x01234567 = _mm256_add_epi32(vacc1x0x01234567, vacc1x1x01234567);
    vacc2x0x01234567 = _mm256_add_epi32(vacc2x0x01234567, vacc2x1x01234567);
    vacc3x0x01234567 = _mm256_add_epi32(vacc3x0x01234567, vacc3x1x01234567);
    vacc0x2x01234567 = _mm256_add_epi32(vacc0x2x01234567, vacc0x3x01234567);
    vacc1x2x01234567 = _mm256_add_epi32(vacc1x2x01234567, vacc1x3x01234567);
    vacc2x2x01234567 = _mm256_add_epi32(vacc2x2x01234567, vacc2x3x01234567);
    vacc3x2x01234567 = _mm256_add_epi32(vacc3x2x01234567, vacc3x3x01234567);
    vacc0x0x01234567 = _mm256_add_epi32(vacc0x0x01234567, vacc0x2x01234567);
    vacc1x0x01234567 = _mm256_add_epi32(vacc1x0x01234567, vacc1x2x01234567);
    vacc2x0x01234567 = _mm256_add_epi32(vacc2x0x01234567, vacc2x2x01234567);
    vacc3x0x01234567 = _mm256_add_epi32(vacc3x0x01234567, vacc3x2x01234567);
    while (k != 0) {
      __m256i va0x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a0));
      a0 += 4;
      __m256i va1x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a1));
      a1 += 4;
      __m256i va2x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a2));
      a2 += 4;
      __m256i va3x0123 = _mm256_set1_epi32((int) unaligned_load_u32(a3));
      a3 += 4;

      const __m256i vb01234567 = _mm256_load_si256(w);

      vacc0x0x01234567 = _mm256_dpbusd_avx_epi32(vacc0x0x01234567, va0x0123, vb01234567);
      vacc1x0x01234567 = _mm256_dpbusd_avx_epi32(vacc1x0x01234567, va1x0123, vb01234567);
      vacc2x0x01234567 = _mm256_dpbusd_avx_epi32(vacc2x0x01234567, va2x0123, vb01234567);
      vacc3x0x01234567 = _mm256_dpbusd_avx_epi32(vacc3x0x01234567, va3x0123, vb01234567);

      w = (const int8_t*) w + 32;
      k -= 4 * sizeof(int8_t);
    }

    __m256 vout0x01234567 = _mm256_cvtepi32_ps(vacc0x0x01234567);
    __m256 vout1x01234567 = _mm256_cvtepi32_ps(vacc1x0x01234567);
    __m256 vout2x01234567 = _mm256_cvtepi32_ps(vacc2x0x01234567);
    __m256 vout3x01234567 = _mm256_cvtepi32_ps(vacc3x0x01234567);

    vout0x01234567 = _mm256_mul_ps(vout0x01234567, _mm256_set1_ps(quantization_params[0].inv_scale));
    vout1x01234567 = _mm256_mul_ps(vout1x01234567, _mm256_set1_ps(quantization_params[1].inv_scale));
    vout2x01234567 = _mm256_mul_ps(vout2x01234567, _mm256_set1_ps(quantization_params[2].inv_scale));
    vout3x01234567 = _mm256_mul_ps(vout3x01234567, _mm256_set1_ps(quantization_params[3].inv_scale));

    const __m256 vfilter_output_scale01234567 = _mm256_load_ps((const float*) w);
    const __m256 vbias01234567 = _mm256_load_ps((const float*) w + 8);
    w = (const float*) w + 16;

    vout0x01234567 = _mm256_fmadd_ps(vout0x01234567, vfilter_output_scale01234567, vbias01234567);
    vout1x01234567 = _mm256_fmadd_ps(vout1x01234567, vfilter_output_scale01234567, vbias01234567);
    vout2x01234567 = _mm256_fmadd_ps(vout2x01234567, vfilter_output_scale01234567, vbias01234567);
    vout3x01234567 = _mm256_fmadd_ps(vout3x01234567, vfilter_output_scale01234567, vbias01234567);

    vout0x01234567 = _mm256_max_ps(vout0x01234567, voutput_min);
    vout1x01234567 = _mm256_max_ps(vout1x01234567, voutput_min);
    vout2x01234567 = _mm256_max_ps(vout2x01234567, voutput_min);
    vout3x01234567 = _mm256_max_ps(vout3x01234567, voutput_min);

    vout0x01234567 = _mm256_min_ps(vout0x01234567, voutput_max);
    vout1x01234567 = _mm256_min_ps(vout1x01234567, voutput_max);
    vout2x01234567 = _mm256_min_ps(vout2x01234567, voutput_max);
    vout3x01234567 = _mm256_min_ps(vout3x01234567, voutput_max);

    if XNN_LIKELY(nc >= 8) {
      _mm256_storeu_ps(c0, vout0x01234567);
      a0 = (const int8_t*) ((uintptr_t) a0 - kc);
      c0 = (float*) ((uintptr_t) c0 + cn_stride);
      _mm256_storeu_ps(c1, vout1x01234567);
      a1 = (const int8_t*) ((uintptr_t) a1 - kc);
      c1 = (float*) ((uintptr_t) c1 + cn_stride);
      _mm256_storeu_ps(c2, vout2x01234567);
      a2 = (const int8_t*) ((uintptr_t) a2 - kc);
      c2 = (float*) ((uintptr_t) c2 + cn_stride);
      _mm256_storeu_ps(c3, vout3x01234567);
      a3 = (const int8_t*) ((uintptr_t) a3 - kc);
      c3 = (float*) ((uintptr_t) c3 + cn_stride);
      nc -= 8;
    } else {
      __m128 vout0x0123 = _mm256_castps256_ps128(vout0x01234567);
      __m128 vout1x0123 = _mm256_castps256_ps128(vout1x01234567);
      __m128 vout2x0123 = _mm256_castps256_ps128(vout2x01234567);
      __m128 vout3x0123 = _mm256_castps256_ps128(vout3x01234567);
      if (nc & 4) {
        _mm_storeu_ps(c0, vout0x0123);
        c0 += 4;
        _mm_storeu_ps(c1, vout1x0123);
        c1 += 4;
        _mm_storeu_ps(c2, vout2x0123);
        c2 += 4;
        _mm_storeu_ps(c3, vout3x0123);
        c3 += 4;
        vout0x0123 = _mm256_extractf128_ps(vout0x01234567, 1);
        vout1x0123 = _mm256_extractf128_ps(vout1x01234567, 1);
        vout2x0123 = _mm256_extractf128_ps(vout2x01234567, 1);
        vout3x0123 = _mm256_extractf128_ps(vout3x01234567, 1);
      }
      if (nc & 2) {
        _mm_storel_pi((__m64*) c0, vout0x0123);
        c0 += 2;
        _mm_storel_pi((__m64*) c1, vout1x0123);
        c1 += 2;
        _mm_storel_pi((__m64*) c2, vout2x0123);
        c2 += 2;
        _mm_storel_pi((__m64*) c3, vout3x0123);
        c3 += 2;
        vout0x0123 = _mm_movehl_ps(vout0x0123, vout0x0123);
        vout1x0123 = _mm_movehl_ps(vout1x0123, vout1x0123);
        vout2x0123 = _mm_movehl_ps(vout2x0123, vout2x0123);
        vout3x0123 = _mm_movehl_ps(vout3x0123, vout3x0123);
      }
      if (nc & 1) {
        _mm_store_ss(c0, vout0x0123);
        _mm_store_ss(c1, vout1x0123);
        _mm_store_ss(c2, vout2x0123);
        _mm_store_ss(c3, vout3x0123);
      }
      nc = 0;
    }
  } while (nc != 0);
}
