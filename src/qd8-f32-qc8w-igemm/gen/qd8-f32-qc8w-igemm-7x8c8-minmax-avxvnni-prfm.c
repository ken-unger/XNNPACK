// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/MRx8c8-avxvnni.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include "xnnpack/common.h"
#include "xnnpack/gemm.h"
#include "xnnpack/intrinsics-polyfill.h"
#include "xnnpack/math.h"
#include "xnnpack/unaligned.h"
#include "xnnpack/prefetch.h"


void xnn_qd8_f32_qc8w_igemm_minmax_ukernel_7x8c8__avxvnni_prfm(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const int8_t** restrict a,
    const void* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const int8_t* zero,
    const int8_t* zero_data,
    const struct xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)],
    const struct xnn_qd8_quantization_params quantization_params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 7);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 8 * sizeof(int8_t));
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
  if XNN_UNPREDICTABLE(mr < 6) {
    c5 = c4;
  }
  float* c6 = (float*) ((uintptr_t) c5 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 6) {
    c6 = c5;
  }

  const __m256i vinput_zero_point = _mm256_set1_epi32((int) quantization_params->zero_point);
  const __m256 vinput_inv_scale = _mm256_set1_ps(quantization_params->inv_scale);
  const __m256 voutput_min = _mm256_set1_ps(params->scalar.min);
  const __m256 voutput_max = _mm256_set1_ps(params->scalar.max);
  // XNN_FORCE_REALIZATION(vinput_zero_point);
  // XNN_FORCE_REALIZATION(vinput_inv_scale);
  // XNN_FORCE_REALIZATION(voutput_min);
  // XNN_FORCE_REALIZATION(voutput_max);
  do {
    const __m256i vksum01234567 = _mm256_load_si256(w);
    const __m256i vsum0x01234567 = _mm256_mullo_epi32(vksum01234567, vinput_zero_point);
    __m256i vacc0x0123 = _mm256_cvtepu32_epi64(_mm256_extracti128_si256(vsum0x01234567, 0));
    __m256i vacc0x4567 = _mm256_cvtepu32_epi64(_mm256_extracti128_si256(vsum0x01234567, 1));
    __m256i vacc1x0123 = vacc0x0123;
    __m256i vacc1x4567 = vacc0x4567;
    __m256i vacc2x0123 = vacc0x0123;
    __m256i vacc2x4567 = vacc0x4567;
    __m256i vacc3x0123 = vacc0x0123;
    __m256i vacc3x4567 = vacc0x4567;
    __m256i vacc4x0123 = vacc0x0123;
    __m256i vacc4x4567 = vacc0x4567;
    __m256i vacc5x0123 = vacc0x0123;
    __m256i vacc5x4567 = vacc0x4567;
    __m256i vacc6x0123 = vacc0x0123;
    __m256i vacc6x4567 = vacc0x4567;
    w = (const int32_t*) w + 8;

    size_t p = ks;
    do {
      const int8_t* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const int8_t*) ((uintptr_t) a0 + a_offset);
      } else {
        a0 = zero_data;
      }
      const int8_t* restrict a1 = a[1];
      if XNN_UNPREDICTABLE(a1 != zero) {
        a1 = (const int8_t*) ((uintptr_t) a1 + a_offset);
      } else {
        a1 = zero_data;
      }
      const int8_t* restrict a2 = a[2];
      if XNN_UNPREDICTABLE(a2 != zero) {
        a2 = (const int8_t*) ((uintptr_t) a2 + a_offset);
      } else {
        a2 = zero_data;
      }
      const int8_t* restrict a3 = a[3];
      if XNN_UNPREDICTABLE(a3 != zero) {
        a3 = (const int8_t*) ((uintptr_t) a3 + a_offset);
      } else {
        a3 = zero_data;
      }
      const int8_t* restrict a4 = a[4];
      if XNN_UNPREDICTABLE(a4 != zero) {
        a4 = (const int8_t*) ((uintptr_t) a4 + a_offset);
      } else {
        a4 = zero_data;
      }
      const int8_t* restrict a5 = a[5];
      if XNN_UNPREDICTABLE(a5 != zero) {
        a5 = (const int8_t*) ((uintptr_t) a5 + a_offset);
      } else {
        a5 = zero_data;
      }
      const int8_t* restrict a6 = a[6];
      if XNN_UNPREDICTABLE(a6 != zero) {
        a6 = (const int8_t*) ((uintptr_t) a6 + a_offset);
      } else {
        a6 = zero_data;
      }
      a += 7;

      size_t k = kc;
      while (k >= 16 * sizeof(int8_t)) {
        const __m256i va0x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a0));
        const __m256i va0x89ABCDEF = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a0 + 8));
        a0 += 16;
        const __m256i va1x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a1));
        const __m256i va1x89ABCDEF = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a1 + 8));
        a1 += 16;
        const __m256i va2x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a2));
        const __m256i va2x89ABCDEF = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a2 + 8));
        a2 += 16;
        const __m256i va3x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a3));
        const __m256i va3x89ABCDEF = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a3 + 8));
        a3 += 16;
        const __m256i va4x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a4));
        const __m256i va4x89ABCDEF = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a4 + 8));
        a4 += 16;
        const __m256i va5x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a5));
        const __m256i va5x89ABCDEF = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a5 + 8));
        a5 += 16;
        const __m256i va6x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a6));
        const __m256i va6x89ABCDEF = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a6 + 8));
        a6 += 16;

        const __m256i vb01234567x0123 = _mm256_load_si256(w);
        const __m256i vb89ABCDEFx0123 = _mm256_load_si256((const __m256i*) ((const int8_t*) w + 32));
        const __m256i vb01234567x4567 = _mm256_load_si256((const __m256i*) ((const int8_t*) w + 64));
        const __m256i vb89ABCDEFx4567 = _mm256_load_si256((const __m256i*) ((const int8_t*) w + 96));
        xnn_prefetch_to_l1((const int8_t*) w + 896);

        vacc0x0123 = _mm256_dpbusd_avx_epi32(vacc0x0123, va0x01234567, vb01234567x0123);
        vacc0x4567 = _mm256_dpbusd_avx_epi32(vacc0x4567, va0x01234567, vb89ABCDEFx0123);
        vacc1x0123 = _mm256_dpbusd_avx_epi32(vacc1x0123, va1x01234567, vb01234567x0123);
        vacc1x4567 = _mm256_dpbusd_avx_epi32(vacc1x4567, va1x01234567, vb89ABCDEFx0123);
        vacc2x0123 = _mm256_dpbusd_avx_epi32(vacc2x0123, va2x01234567, vb01234567x0123);
        vacc2x4567 = _mm256_dpbusd_avx_epi32(vacc2x4567, va2x01234567, vb89ABCDEFx0123);
        vacc3x0123 = _mm256_dpbusd_avx_epi32(vacc3x0123, va3x01234567, vb01234567x0123);
        vacc3x4567 = _mm256_dpbusd_avx_epi32(vacc3x4567, va3x01234567, vb89ABCDEFx0123);
        vacc4x0123 = _mm256_dpbusd_avx_epi32(vacc4x0123, va4x01234567, vb01234567x0123);
        vacc4x4567 = _mm256_dpbusd_avx_epi32(vacc4x4567, va4x01234567, vb89ABCDEFx0123);
        vacc5x0123 = _mm256_dpbusd_avx_epi32(vacc5x0123, va5x01234567, vb01234567x0123);
        vacc5x4567 = _mm256_dpbusd_avx_epi32(vacc5x4567, va5x01234567, vb89ABCDEFx0123);
        vacc6x0123 = _mm256_dpbusd_avx_epi32(vacc6x0123, va6x01234567, vb01234567x0123);
        vacc6x4567 = _mm256_dpbusd_avx_epi32(vacc6x4567, va6x01234567, vb89ABCDEFx0123);
        xnn_prefetch_to_l1((const int8_t*) w + 960);
        vacc0x0123 = _mm256_dpbusd_avx_epi32(vacc0x0123, va0x89ABCDEF, vb01234567x4567);
        vacc0x4567 = _mm256_dpbusd_avx_epi32(vacc0x4567, va0x89ABCDEF, vb89ABCDEFx4567);
        vacc1x0123 = _mm256_dpbusd_avx_epi32(vacc1x0123, va1x89ABCDEF, vb01234567x4567);
        vacc1x4567 = _mm256_dpbusd_avx_epi32(vacc1x4567, va1x89ABCDEF, vb89ABCDEFx4567);
        vacc2x0123 = _mm256_dpbusd_avx_epi32(vacc2x0123, va2x89ABCDEF, vb01234567x4567);
        vacc2x4567 = _mm256_dpbusd_avx_epi32(vacc2x4567, va2x89ABCDEF, vb89ABCDEFx4567);
        vacc3x0123 = _mm256_dpbusd_avx_epi32(vacc3x0123, va3x89ABCDEF, vb01234567x4567);
        vacc3x4567 = _mm256_dpbusd_avx_epi32(vacc3x4567, va3x89ABCDEF, vb89ABCDEFx4567);
        vacc4x0123 = _mm256_dpbusd_avx_epi32(vacc4x0123, va4x89ABCDEF, vb01234567x4567);
        vacc4x4567 = _mm256_dpbusd_avx_epi32(vacc4x4567, va4x89ABCDEF, vb89ABCDEFx4567);
        vacc5x0123 = _mm256_dpbusd_avx_epi32(vacc5x0123, va5x89ABCDEF, vb01234567x4567);
        vacc5x4567 = _mm256_dpbusd_avx_epi32(vacc5x4567, va5x89ABCDEF, vb89ABCDEFx4567);
        vacc6x0123 = _mm256_dpbusd_avx_epi32(vacc6x0123, va6x89ABCDEF, vb01234567x4567);
        vacc6x4567 = _mm256_dpbusd_avx_epi32(vacc6x4567, va6x89ABCDEF, vb89ABCDEFx4567);

        w = (const int8_t*) w + 128;
        k -= 16 * sizeof(int8_t);
      }

      if (k != 0) {
        const __m256i va0x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a0));
        a0 += 8;
        const __m256i va1x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a1));
        a1 += 8;
        const __m256i va2x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a2));
        a2 += 8;
        const __m256i va3x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a3));
        a3 += 8;
        const __m256i va4x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a4));
        a4 += 8;
        const __m256i va5x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a5));
        a5 += 8;
        const __m256i va6x01234567 = _mm256_set1_epi64x((int64_t) unaligned_load_u64(a6));
        a6 += 8;

        const __m256i vb01234567x0123 = _mm256_load_si256(w);
        const __m256i vb89ABCDEFx0123 = _mm256_load_si256((const __m256i*) ((const int8_t*) w + 32));

        vacc0x0123 = _mm256_dpbusd_avx_epi32(vacc0x0123, va0x01234567, vb01234567x0123);
        vacc0x4567 = _mm256_dpbusd_avx_epi32(vacc0x4567, va0x01234567, vb89ABCDEFx0123);
        vacc1x0123 = _mm256_dpbusd_avx_epi32(vacc1x0123, va1x01234567, vb01234567x0123);
        vacc1x4567 = _mm256_dpbusd_avx_epi32(vacc1x4567, va1x01234567, vb89ABCDEFx0123);
        vacc2x0123 = _mm256_dpbusd_avx_epi32(vacc2x0123, va2x01234567, vb01234567x0123);
        vacc2x4567 = _mm256_dpbusd_avx_epi32(vacc2x4567, va2x01234567, vb89ABCDEFx0123);
        vacc3x0123 = _mm256_dpbusd_avx_epi32(vacc3x0123, va3x01234567, vb01234567x0123);
        vacc3x4567 = _mm256_dpbusd_avx_epi32(vacc3x4567, va3x01234567, vb89ABCDEFx0123);
        vacc4x0123 = _mm256_dpbusd_avx_epi32(vacc4x0123, va4x01234567, vb01234567x0123);
        vacc4x4567 = _mm256_dpbusd_avx_epi32(vacc4x4567, va4x01234567, vb89ABCDEFx0123);
        vacc5x0123 = _mm256_dpbusd_avx_epi32(vacc5x0123, va5x01234567, vb01234567x0123);
        vacc5x4567 = _mm256_dpbusd_avx_epi32(vacc5x4567, va5x01234567, vb89ABCDEFx0123);
        vacc6x0123 = _mm256_dpbusd_avx_epi32(vacc6x0123, va6x01234567, vb01234567x0123);
        vacc6x4567 = _mm256_dpbusd_avx_epi32(vacc6x4567, va6x01234567, vb89ABCDEFx0123);
        xnn_prefetch_to_l1((const int8_t*) w + 960);

        w = (const int8_t*) w + 64;
        k -= 8 * sizeof(int8_t);
      }

      p -= 7 * sizeof(void*);
    } while (p != 0);


    // Add adjacent pairs
    const __m256i vsum0x02134657 = _mm256_hadd_epi32(vacc0x0123, vacc0x4567);
    __m256i vacc0x01234567 = _mm256_permute4x64_epi64(vsum0x02134657, _MM_SHUFFLE(3, 1, 2, 0));
    const __m256i vsum1x02134657 = _mm256_hadd_epi32(vacc1x0123, vacc1x4567);
    __m256i vacc1x01234567 = _mm256_permute4x64_epi64(vsum1x02134657, _MM_SHUFFLE(3, 1, 2, 0));
    const __m256i vsum2x02134657 = _mm256_hadd_epi32(vacc2x0123, vacc2x4567);
    __m256i vacc2x01234567 = _mm256_permute4x64_epi64(vsum2x02134657, _MM_SHUFFLE(3, 1, 2, 0));
    const __m256i vsum3x02134657 = _mm256_hadd_epi32(vacc3x0123, vacc3x4567);
    __m256i vacc3x01234567 = _mm256_permute4x64_epi64(vsum3x02134657, _MM_SHUFFLE(3, 1, 2, 0));
    const __m256i vsum4x02134657 = _mm256_hadd_epi32(vacc4x0123, vacc4x4567);
    __m256i vacc4x01234567 = _mm256_permute4x64_epi64(vsum4x02134657, _MM_SHUFFLE(3, 1, 2, 0));
    const __m256i vsum5x02134657 = _mm256_hadd_epi32(vacc5x0123, vacc5x4567);
    __m256i vacc5x01234567 = _mm256_permute4x64_epi64(vsum5x02134657, _MM_SHUFFLE(3, 1, 2, 0));
    const __m256i vsum6x02134657 = _mm256_hadd_epi32(vacc6x0123, vacc6x4567);
    __m256i vacc6x01234567 = _mm256_permute4x64_epi64(vsum6x02134657, _MM_SHUFFLE(3, 1, 2, 0));

    __m256 vout0x01234567 = _mm256_cvtepi32_ps(vacc0x01234567);
    __m256 vout1x01234567 = _mm256_cvtepi32_ps(vacc1x01234567);
    __m256 vout2x01234567 = _mm256_cvtepi32_ps(vacc2x01234567);
    __m256 vout3x01234567 = _mm256_cvtepi32_ps(vacc3x01234567);
    __m256 vout4x01234567 = _mm256_cvtepi32_ps(vacc4x01234567);
    __m256 vout5x01234567 = _mm256_cvtepi32_ps(vacc5x01234567);
    __m256 vout6x01234567 = _mm256_cvtepi32_ps(vacc6x01234567);

    vout0x01234567 = _mm256_mul_ps(vout0x01234567, vinput_inv_scale);
    vout1x01234567 = _mm256_mul_ps(vout1x01234567, vinput_inv_scale);
    vout2x01234567 = _mm256_mul_ps(vout2x01234567, vinput_inv_scale);
    vout3x01234567 = _mm256_mul_ps(vout3x01234567, vinput_inv_scale);
    vout4x01234567 = _mm256_mul_ps(vout4x01234567, vinput_inv_scale);
    vout5x01234567 = _mm256_mul_ps(vout5x01234567, vinput_inv_scale);
    vout6x01234567 = _mm256_mul_ps(vout6x01234567, vinput_inv_scale);

    const __m256 vfilter_output_scale01234567 = _mm256_load_ps((const float*) w);
    const __m256 vbias01234567 = _mm256_load_ps((const float*) w + 8);
    w = (const float*) w + 16;
    vout0x01234567 = _mm256_fmadd_ps(vout0x01234567, vfilter_output_scale01234567, vbias01234567);
    vout1x01234567 = _mm256_fmadd_ps(vout1x01234567, vfilter_output_scale01234567, vbias01234567);
    vout2x01234567 = _mm256_fmadd_ps(vout2x01234567, vfilter_output_scale01234567, vbias01234567);
    vout3x01234567 = _mm256_fmadd_ps(vout3x01234567, vfilter_output_scale01234567, vbias01234567);
    vout4x01234567 = _mm256_fmadd_ps(vout4x01234567, vfilter_output_scale01234567, vbias01234567);
    vout5x01234567 = _mm256_fmadd_ps(vout5x01234567, vfilter_output_scale01234567, vbias01234567);
    vout6x01234567 = _mm256_fmadd_ps(vout6x01234567, vfilter_output_scale01234567, vbias01234567);

    vout0x01234567 = _mm256_max_ps(vout0x01234567, voutput_min);
    vout1x01234567 = _mm256_max_ps(vout1x01234567, voutput_min);
    vout2x01234567 = _mm256_max_ps(vout2x01234567, voutput_min);
    vout3x01234567 = _mm256_max_ps(vout3x01234567, voutput_min);
    vout4x01234567 = _mm256_max_ps(vout4x01234567, voutput_min);
    vout5x01234567 = _mm256_max_ps(vout5x01234567, voutput_min);
    vout6x01234567 = _mm256_max_ps(vout6x01234567, voutput_min);

    vout0x01234567 = _mm256_min_ps(vout0x01234567, voutput_max);
    vout1x01234567 = _mm256_min_ps(vout1x01234567, voutput_max);
    vout2x01234567 = _mm256_min_ps(vout2x01234567, voutput_max);
    vout3x01234567 = _mm256_min_ps(vout3x01234567, voutput_max);
    vout4x01234567 = _mm256_min_ps(vout4x01234567, voutput_max);
    vout5x01234567 = _mm256_min_ps(vout5x01234567, voutput_max);
    vout6x01234567 = _mm256_min_ps(vout6x01234567, voutput_max);

    if XNN_LIKELY(nc >= 8) {
      _mm256_storeu_ps(c6, vout6x01234567);
      c6 = (float*) ((uintptr_t) c6 + cn_stride);
      _mm256_storeu_ps(c5, vout5x01234567);
      c5 = (float*) ((uintptr_t) c5 + cn_stride);
      _mm256_storeu_ps(c4, vout4x01234567);
      c4 = (float*) ((uintptr_t) c4 + cn_stride);
      _mm256_storeu_ps(c3, vout3x01234567);
      c3 = (float*) ((uintptr_t) c3 + cn_stride);
      _mm256_storeu_ps(c2, vout2x01234567);
      c2 = (float*) ((uintptr_t) c2 + cn_stride);
      _mm256_storeu_ps(c1, vout1x01234567);
      c1 = (float*) ((uintptr_t) c1 + cn_stride);
      _mm256_storeu_ps(c0, vout0x01234567);
      c0 = (float*) ((uintptr_t) c0 + cn_stride);

      a = (const int8_t**restrict) ((uintptr_t) a - ks);
      nc -= 8;
    } else {
      __m128 vout6x0123 = _mm256_castps256_ps128(vout6x01234567);
      __m128 vout5x0123 = _mm256_castps256_ps128(vout5x01234567);
      __m128 vout4x0123 = _mm256_castps256_ps128(vout4x01234567);
      __m128 vout3x0123 = _mm256_castps256_ps128(vout3x01234567);
      __m128 vout2x0123 = _mm256_castps256_ps128(vout2x01234567);
      __m128 vout1x0123 = _mm256_castps256_ps128(vout1x01234567);
      __m128 vout0x0123 = _mm256_castps256_ps128(vout0x01234567);
      if (nc & 4) {
        _mm_storeu_ps(c6, vout6x0123);
        c6 += 4;
        vout6x0123 = _mm256_extractf128_ps(vout6x01234567, 1);
        _mm_storeu_ps(c5, vout5x0123);
        c5 += 4;
        vout5x0123 = _mm256_extractf128_ps(vout5x01234567, 1);
        _mm_storeu_ps(c4, vout4x0123);
        c4 += 4;
        vout4x0123 = _mm256_extractf128_ps(vout4x01234567, 1);
        _mm_storeu_ps(c3, vout3x0123);
        c3 += 4;
        vout3x0123 = _mm256_extractf128_ps(vout3x01234567, 1);
        _mm_storeu_ps(c2, vout2x0123);
        c2 += 4;
        vout2x0123 = _mm256_extractf128_ps(vout2x01234567, 1);
        _mm_storeu_ps(c1, vout1x0123);
        c1 += 4;
        vout1x0123 = _mm256_extractf128_ps(vout1x01234567, 1);
        _mm_storeu_ps(c0, vout0x0123);
        c0 += 4;
        vout0x0123 = _mm256_extractf128_ps(vout0x01234567, 1);
      }
      if (nc & 2) {
        _mm_storel_pi((__m64*) c6, vout6x0123);
        c6 += 2;
        vout6x0123 = _mm_movehl_ps(vout6x0123, vout6x0123);
        _mm_storel_pi((__m64*) c5, vout5x0123);
        c5 += 2;
        vout5x0123 = _mm_movehl_ps(vout5x0123, vout5x0123);
        _mm_storel_pi((__m64*) c4, vout4x0123);
        c4 += 2;
        vout4x0123 = _mm_movehl_ps(vout4x0123, vout4x0123);
        _mm_storel_pi((__m64*) c3, vout3x0123);
        c3 += 2;
        vout3x0123 = _mm_movehl_ps(vout3x0123, vout3x0123);
        _mm_storel_pi((__m64*) c2, vout2x0123);
        c2 += 2;
        vout2x0123 = _mm_movehl_ps(vout2x0123, vout2x0123);
        _mm_storel_pi((__m64*) c1, vout1x0123);
        c1 += 2;
        vout1x0123 = _mm_movehl_ps(vout1x0123, vout1x0123);
        _mm_storel_pi((__m64*) c0, vout0x0123);
        c0 += 2;
        vout0x0123 = _mm_movehl_ps(vout0x0123, vout0x0123);
      }
      if (nc & 1) {
        _mm_store_ss(c6, vout6x0123);
        _mm_store_ss(c5, vout5x0123);
        _mm_store_ss(c4, vout4x0123);
        _mm_store_ss(c3, vout3x0123);
        _mm_store_ss(c2, vout2x0123);
        _mm_store_ss(c1, vout1x0123);
        _mm_store_ss(c0, vout0x0123);
      }
      nc = 0;
    }
  } while (nc != 0);
}
