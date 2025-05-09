// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-dwconv/unipass-avx512.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include "src/xnnpack/dwconv.h"
#include "src/xnnpack/intrinsics-polyfill.h"


void xnn_f32_dwconv_minmax_ukernel_25p16c__avx512f_acc2(
    size_t channels,
    size_t output_width,
    const float** input,
    const float* weights,
    float* output,
    intptr_t input_stride,
    size_t output_increment,
    size_t input_offset,
    size_t input_pixel_stride,
    const float* zero,
    const struct xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(channels != 0);
  assert(output_width != 0);

  const __m512 vmin = _mm512_set1_ps(params->scalar.min);
  const __m512 vmax = _mm512_set1_ps(params->scalar.max);
  do {
    const float* i0 = input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != zero) {
      i0 = (const float*) ((uintptr_t) i0 + input_offset);
    }
    const float* i1 = input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != zero) {
      i1 = (const float*) ((uintptr_t) i1 + input_offset);
    }
    const float* i2 = input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != zero) {
      i2 = (const float*) ((uintptr_t) i2 + input_offset);
    }
    const float* i3 = input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != zero) {
      i3 = (const float*) ((uintptr_t) i3 + input_offset);
    }
    const float* i4 = input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != zero) {
      i4 = (const float*) ((uintptr_t) i4 + input_offset);
    }
    const float* i5 = input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != zero) {
      i5 = (const float*) ((uintptr_t) i5 + input_offset);
    }
    const float* i6 = input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != zero) {
      i6 = (const float*) ((uintptr_t) i6 + input_offset);
    }
    const float* i7 = input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != zero) {
      i7 = (const float*) ((uintptr_t) i7 + input_offset);
    }
    const float* i8 = input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != zero) {
      i8 = (const float*) ((uintptr_t) i8 + input_offset);
    }
    const float* i9 = input[9];
    assert(i9 != NULL);
    if XNN_UNPREDICTABLE(i9 != zero) {
      i9 = (const float*) ((uintptr_t) i9 + input_offset);
    }
    const float* i10 = input[10];
    assert(i10 != NULL);
    if XNN_UNPREDICTABLE(i10 != zero) {
      i10 = (const float*) ((uintptr_t) i10 + input_offset);
    }
    const float* i11 = input[11];
    assert(i11 != NULL);
    if XNN_UNPREDICTABLE(i11 != zero) {
      i11 = (const float*) ((uintptr_t) i11 + input_offset);
    }
    const float* i12 = input[12];
    assert(i12 != NULL);
    if XNN_UNPREDICTABLE(i12 != zero) {
      i12 = (const float*) ((uintptr_t) i12 + input_offset);
    }
    const float* i13 = input[13];
    assert(i13 != NULL);
    if XNN_UNPREDICTABLE(i13 != zero) {
      i13 = (const float*) ((uintptr_t) i13 + input_offset);
    }
    const float* i14 = input[14];
    assert(i14 != NULL);
    if XNN_UNPREDICTABLE(i14 != zero) {
      i14 = (const float*) ((uintptr_t) i14 + input_offset);
    }
    const float* i15 = input[15];
    assert(i15 != NULL);
    if XNN_UNPREDICTABLE(i15 != zero) {
      i15 = (const float*) ((uintptr_t) i15 + input_offset);
    }
    const float* i16 = input[16];
    assert(i16 != NULL);
    if XNN_UNPREDICTABLE(i16 != zero) {
      i16 = (const float*) ((uintptr_t) i16 + input_offset);
    }
    const float* i17 = input[17];
    assert(i17 != NULL);
    if XNN_UNPREDICTABLE(i17 != zero) {
      i17 = (const float*) ((uintptr_t) i17 + input_offset);
    }
    const float* i18 = input[18];
    assert(i18 != NULL);
    if XNN_UNPREDICTABLE(i18 != zero) {
      i18 = (const float*) ((uintptr_t) i18 + input_offset);
    }
    const float* i19 = input[19];
    assert(i19 != NULL);
    if XNN_UNPREDICTABLE(i19 != zero) {
      i19 = (const float*) ((uintptr_t) i19 + input_offset);
    }
    const float* i20 = input[20];
    assert(i20 != NULL);
    if XNN_UNPREDICTABLE(i20 != zero) {
      i20 = (const float*) ((uintptr_t) i20 + input_offset);
    }
    const float* i21 = input[21];
    assert(i21 != NULL);
    if XNN_UNPREDICTABLE(i21 != zero) {
      i21 = (const float*) ((uintptr_t) i21 + input_offset);
    }
    const float* i22 = input[22];
    assert(i22 != NULL);
    if XNN_UNPREDICTABLE(i22 != zero) {
      i22 = (const float*) ((uintptr_t) i22 + input_offset);
    }
    const float* i23 = input[23];
    assert(i23 != NULL);
    if XNN_UNPREDICTABLE(i23 != zero) {
      i23 = (const float*) ((uintptr_t) i23 + input_offset);
    }
    const float* i24 = input[24];
    assert(i24 != NULL);
    if XNN_UNPREDICTABLE(i24 != zero) {
      i24 = (const float*) ((uintptr_t) i24 + input_offset);
    }
    input = (const float**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const float* w = weights;
    for (; c >= 16; c -= 16) {
      __m512 vacc0123456789ABCDEFp0 = _mm512_load_ps(w);


      const __m512 vi0x0123456789ABCDEF = _mm512_loadu_ps(i0);
      i0 += 16;

      const __m512 vk0x0123456789ABCDEF = _mm512_load_ps(w + 16);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi0x0123456789ABCDEF, vk0x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi1x0123456789ABCDEF = _mm512_loadu_ps(i1);
      i1 += 16;

      const __m512 vk1x0123456789ABCDEF = _mm512_load_ps(w + 32);
      __m512 vacc0123456789ABCDEFp1 = _mm512_mul_ps(vi1x0123456789ABCDEF, vk1x0123456789ABCDEF);

      const __m512 vi2x0123456789ABCDEF = _mm512_loadu_ps(i2);
      i2 += 16;

      const __m512 vk2x0123456789ABCDEF = _mm512_load_ps(w + 48);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi2x0123456789ABCDEF, vk2x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi3x0123456789ABCDEF = _mm512_loadu_ps(i3);
      i3 += 16;

      const __m512 vk3x0123456789ABCDEF = _mm512_load_ps(w + 64);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi3x0123456789ABCDEF, vk3x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi4x0123456789ABCDEF = _mm512_loadu_ps(i4);
      i4 += 16;

      const __m512 vk4x0123456789ABCDEF = _mm512_load_ps(w + 80);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi4x0123456789ABCDEF, vk4x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi5x0123456789ABCDEF = _mm512_loadu_ps(i5);
      i5 += 16;

      const __m512 vk5x0123456789ABCDEF = _mm512_load_ps(w + 96);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi5x0123456789ABCDEF, vk5x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi6x0123456789ABCDEF = _mm512_loadu_ps(i6);
      i6 += 16;

      const __m512 vk6x0123456789ABCDEF = _mm512_load_ps(w + 112);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi6x0123456789ABCDEF, vk6x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi7x0123456789ABCDEF = _mm512_loadu_ps(i7);
      i7 += 16;

      const __m512 vk7x0123456789ABCDEF = _mm512_load_ps(w + 128);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi7x0123456789ABCDEF, vk7x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi8x0123456789ABCDEF = _mm512_loadu_ps(i8);
      i8 += 16;

      const __m512 vk8x0123456789ABCDEF = _mm512_load_ps(w + 144);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi8x0123456789ABCDEF, vk8x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi9x0123456789ABCDEF = _mm512_loadu_ps(i9);
      i9 += 16;

      const __m512 vk9x0123456789ABCDEF = _mm512_load_ps(w + 160);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi9x0123456789ABCDEF, vk9x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi10x0123456789ABCDEF = _mm512_loadu_ps(i10);
      i10 += 16;

      const __m512 vk10x0123456789ABCDEF = _mm512_load_ps(w + 176);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi10x0123456789ABCDEF, vk10x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi11x0123456789ABCDEF = _mm512_loadu_ps(i11);
      i11 += 16;

      const __m512 vk11x0123456789ABCDEF = _mm512_load_ps(w + 192);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi11x0123456789ABCDEF, vk11x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi12x0123456789ABCDEF = _mm512_loadu_ps(i12);
      i12 += 16;

      const __m512 vk12x0123456789ABCDEF = _mm512_load_ps(w + 208);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi12x0123456789ABCDEF, vk12x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi13x0123456789ABCDEF = _mm512_loadu_ps(i13);
      i13 += 16;

      const __m512 vk13x0123456789ABCDEF = _mm512_load_ps(w + 224);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi13x0123456789ABCDEF, vk13x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi14x0123456789ABCDEF = _mm512_loadu_ps(i14);
      i14 += 16;

      const __m512 vk14x0123456789ABCDEF = _mm512_load_ps(w + 240);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi14x0123456789ABCDEF, vk14x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi15x0123456789ABCDEF = _mm512_loadu_ps(i15);
      i15 += 16;

      const __m512 vk15x0123456789ABCDEF = _mm512_load_ps(w + 256);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi15x0123456789ABCDEF, vk15x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi16x0123456789ABCDEF = _mm512_loadu_ps(i16);
      i16 += 16;

      const __m512 vk16x0123456789ABCDEF = _mm512_load_ps(w + 272);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi16x0123456789ABCDEF, vk16x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi17x0123456789ABCDEF = _mm512_loadu_ps(i17);
      i17 += 16;

      const __m512 vk17x0123456789ABCDEF = _mm512_load_ps(w + 288);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi17x0123456789ABCDEF, vk17x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi18x0123456789ABCDEF = _mm512_loadu_ps(i18);
      i18 += 16;

      const __m512 vk18x0123456789ABCDEF = _mm512_load_ps(w + 304);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi18x0123456789ABCDEF, vk18x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi19x0123456789ABCDEF = _mm512_loadu_ps(i19);
      i19 += 16;

      const __m512 vk19x0123456789ABCDEF = _mm512_load_ps(w + 320);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi19x0123456789ABCDEF, vk19x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi20x0123456789ABCDEF = _mm512_loadu_ps(i20);
      i20 += 16;

      const __m512 vk20x0123456789ABCDEF = _mm512_load_ps(w + 336);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi20x0123456789ABCDEF, vk20x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi21x0123456789ABCDEF = _mm512_loadu_ps(i21);
      i21 += 16;

      const __m512 vk21x0123456789ABCDEF = _mm512_load_ps(w + 352);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi21x0123456789ABCDEF, vk21x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi22x0123456789ABCDEF = _mm512_loadu_ps(i22);
      i22 += 16;

      const __m512 vk22x0123456789ABCDEF = _mm512_load_ps(w + 368);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi22x0123456789ABCDEF, vk22x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi23x0123456789ABCDEF = _mm512_loadu_ps(i23);
      i23 += 16;

      const __m512 vk23x0123456789ABCDEF = _mm512_load_ps(w + 384);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi23x0123456789ABCDEF, vk23x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi24x0123456789ABCDEF = _mm512_loadu_ps(i24);
      i24 += 16;

      const __m512 vk24x0123456789ABCDEF = _mm512_load_ps(w + 400);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi24x0123456789ABCDEF, vk24x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      w += 416;

      // Add up all accumulators to vacc0123456789ABCDEFp0
      vacc0123456789ABCDEFp0 = _mm512_add_ps(vacc0123456789ABCDEFp0, vacc0123456789ABCDEFp1);

      __m512 vacc0123456789ABCDEF = _mm512_max_ps(vmin, vacc0123456789ABCDEFp0);
      vacc0123456789ABCDEF = _mm512_min_ps(vmax, vacc0123456789ABCDEF);

      _mm512_storeu_ps(output, vacc0123456789ABCDEF);
      output += 16;
    }
    if XNN_UNLIKELY(c != 0) {
      assert(c >= 1);
      assert(c <= 16);
      // Prepare mask for valid 32-bit elements (depends on nc).
      const __mmask16 vmask = _cvtu32_mask16((uint32_t) ((UINT32_C(1) << c) - UINT32_C(1)));

      __m512 vacc0123456789ABCDEFp0 = _mm512_maskz_loadu_ps(vmask, w);

      const __m512 vi0x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i0);
      const __m512 vk0x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 16);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi0x0123456789ABCDEF, vk0x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi1x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i1);
      const __m512 vk1x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 32);
      __m512 vacc0123456789ABCDEFp1 = _mm512_mul_ps(vi1x0123456789ABCDEF, vk1x0123456789ABCDEF);

      const __m512 vi2x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i2);
      const __m512 vk2x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 48);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi2x0123456789ABCDEF, vk2x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi3x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i3);
      const __m512 vk3x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 64);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi3x0123456789ABCDEF, vk3x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi4x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i4);
      const __m512 vk4x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 80);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi4x0123456789ABCDEF, vk4x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi5x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i5);
      const __m512 vk5x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 96);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi5x0123456789ABCDEF, vk5x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi6x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i6);
      const __m512 vk6x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 112);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi6x0123456789ABCDEF, vk6x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi7x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i7);
      const __m512 vk7x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 128);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi7x0123456789ABCDEF, vk7x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi8x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i8);
      const __m512 vk8x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 144);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi8x0123456789ABCDEF, vk8x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi9x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i9);
      const __m512 vk9x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 160);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi9x0123456789ABCDEF, vk9x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi10x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i10);
      const __m512 vk10x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 176);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi10x0123456789ABCDEF, vk10x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi11x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i11);
      const __m512 vk11x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 192);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi11x0123456789ABCDEF, vk11x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi12x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i12);
      const __m512 vk12x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 208);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi12x0123456789ABCDEF, vk12x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi13x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i13);
      const __m512 vk13x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 224);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi13x0123456789ABCDEF, vk13x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi14x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i14);
      const __m512 vk14x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 240);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi14x0123456789ABCDEF, vk14x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi15x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i15);
      const __m512 vk15x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 256);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi15x0123456789ABCDEF, vk15x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi16x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i16);
      const __m512 vk16x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 272);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi16x0123456789ABCDEF, vk16x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi17x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i17);
      const __m512 vk17x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 288);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi17x0123456789ABCDEF, vk17x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi18x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i18);
      const __m512 vk18x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 304);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi18x0123456789ABCDEF, vk18x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi19x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i19);
      const __m512 vk19x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 320);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi19x0123456789ABCDEF, vk19x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi20x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i20);
      const __m512 vk20x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 336);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi20x0123456789ABCDEF, vk20x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi21x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i21);
      const __m512 vk21x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 352);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi21x0123456789ABCDEF, vk21x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi22x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i22);
      const __m512 vk22x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 368);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi22x0123456789ABCDEF, vk22x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      const __m512 vi23x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i23);
      const __m512 vk23x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 384);
      vacc0123456789ABCDEFp1 = _mm512_fmadd_ps(vi23x0123456789ABCDEF, vk23x0123456789ABCDEF, vacc0123456789ABCDEFp1);

      const __m512 vi24x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, i24);
      const __m512 vk24x0123456789ABCDEF = _mm512_maskz_loadu_ps(vmask, w + 400);
      vacc0123456789ABCDEFp0 = _mm512_fmadd_ps(vi24x0123456789ABCDEF, vk24x0123456789ABCDEF, vacc0123456789ABCDEFp0);

      // Add up all accumulators to vacc0123456789ABCDEFp0
      vacc0123456789ABCDEFp0 = _mm512_add_ps(vacc0123456789ABCDEFp0, vacc0123456789ABCDEFp1);

      __m512 vacc0123456789ABCDEF = _mm512_max_ps(vmin, vacc0123456789ABCDEFp0);
      vacc0123456789ABCDEF = _mm512_min_ps(vmax, vacc0123456789ABCDEF);

      _mm512_mask_storeu_ps(output, vmask, vacc0123456789ABCDEF);
      output += c;
    }

    input_offset += input_pixel_stride;
    output = (float*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
