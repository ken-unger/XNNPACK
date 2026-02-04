// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f16-dwconv/unipass-rvvfp16arith.c.in
//   Generator: tools/xngen
//
// Copyright 2026 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <riscv_vector.h>
#include "src/xnnpack/dwconv.h"

void xnn_f16_dwconv_minmax_ukernel_25p4vc__rvvfp16arith(
    size_t channels,
    size_t output_width,
    const xnn_float16** input,
    const xnn_float16* weights,
    xnn_float16* output,
    intptr_t input_stride,
    size_t output_increment,
    size_t input_offset,
    size_t input_pixel_stride,
    const xnn_float16* zero,
    const struct xnn_f16_minmax_params* restrict params) XNN_OOB_READS
{
  assert(channels != 0);
  assert(output_width != 0);

  _Float16 vmin = *(const _Float16*) &params->scalar.min;
  _Float16 vmax = *(const _Float16*) &params->scalar.max;
  _Float16* o = (_Float16*) output;

  do {
    const _Float16* i0 = (const _Float16*) input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != (const _Float16*) zero) {
      i0 = (const _Float16*) ((uintptr_t) i0 + input_offset);
    }
    const _Float16* i1 = (const _Float16*) input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != (const _Float16*) zero) {
      i1 = (const _Float16*) ((uintptr_t) i1 + input_offset);
    }
    const _Float16* i2 = (const _Float16*) input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != (const _Float16*) zero) {
      i2 = (const _Float16*) ((uintptr_t) i2 + input_offset);
    }
    const _Float16* i3 = (const _Float16*) input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != (const _Float16*) zero) {
      i3 = (const _Float16*) ((uintptr_t) i3 + input_offset);
    }
    const _Float16* i4 = (const _Float16*) input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != (const _Float16*) zero) {
      i4 = (const _Float16*) ((uintptr_t) i4 + input_offset);
    }
    const _Float16* i5 = (const _Float16*) input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != (const _Float16*) zero) {
      i5 = (const _Float16*) ((uintptr_t) i5 + input_offset);
    }
    const _Float16* i6 = (const _Float16*) input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != (const _Float16*) zero) {
      i6 = (const _Float16*) ((uintptr_t) i6 + input_offset);
    }
    const _Float16* i7 = (const _Float16*) input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != (const _Float16*) zero) {
      i7 = (const _Float16*) ((uintptr_t) i7 + input_offset);
    }
    const _Float16* i8 = (const _Float16*) input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != (const _Float16*) zero) {
      i8 = (const _Float16*) ((uintptr_t) i8 + input_offset);
    }
    const _Float16* i9 = (const _Float16*) input[9];
    assert(i9 != NULL);
    if XNN_UNPREDICTABLE(i9 != (const _Float16*) zero) {
      i9 = (const _Float16*) ((uintptr_t) i9 + input_offset);
    }
    const _Float16* i10 = (const _Float16*) input[10];
    assert(i10 != NULL);
    if XNN_UNPREDICTABLE(i10 != (const _Float16*) zero) {
      i10 = (const _Float16*) ((uintptr_t) i10 + input_offset);
    }
    const _Float16* i11 = (const _Float16*) input[11];
    assert(i11 != NULL);
    if XNN_UNPREDICTABLE(i11 != (const _Float16*) zero) {
      i11 = (const _Float16*) ((uintptr_t) i11 + input_offset);
    }
    const _Float16* i12 = (const _Float16*) input[12];
    assert(i12 != NULL);
    if XNN_UNPREDICTABLE(i12 != (const _Float16*) zero) {
      i12 = (const _Float16*) ((uintptr_t) i12 + input_offset);
    }
    const _Float16* i13 = (const _Float16*) input[13];
    assert(i13 != NULL);
    if XNN_UNPREDICTABLE(i13 != (const _Float16*) zero) {
      i13 = (const _Float16*) ((uintptr_t) i13 + input_offset);
    }
    const _Float16* i14 = (const _Float16*) input[14];
    assert(i14 != NULL);
    if XNN_UNPREDICTABLE(i14 != (const _Float16*) zero) {
      i14 = (const _Float16*) ((uintptr_t) i14 + input_offset);
    }
    const _Float16* i15 = (const _Float16*) input[15];
    assert(i15 != NULL);
    if XNN_UNPREDICTABLE(i15 != (const _Float16*) zero) {
      i15 = (const _Float16*) ((uintptr_t) i15 + input_offset);
    }
    const _Float16* i16 = (const _Float16*) input[16];
    assert(i16 != NULL);
    if XNN_UNPREDICTABLE(i16 != (const _Float16*) zero) {
      i16 = (const _Float16*) ((uintptr_t) i16 + input_offset);
    }
    const _Float16* i17 = (const _Float16*) input[17];
    assert(i17 != NULL);
    if XNN_UNPREDICTABLE(i17 != (const _Float16*) zero) {
      i17 = (const _Float16*) ((uintptr_t) i17 + input_offset);
    }
    const _Float16* i18 = (const _Float16*) input[18];
    assert(i18 != NULL);
    if XNN_UNPREDICTABLE(i18 != (const _Float16*) zero) {
      i18 = (const _Float16*) ((uintptr_t) i18 + input_offset);
    }
    const _Float16* i19 = (const _Float16*) input[19];
    assert(i19 != NULL);
    if XNN_UNPREDICTABLE(i19 != (const _Float16*) zero) {
      i19 = (const _Float16*) ((uintptr_t) i19 + input_offset);
    }
    const _Float16* i20 = (const _Float16*) input[20];
    assert(i20 != NULL);
    if XNN_UNPREDICTABLE(i20 != (const _Float16*) zero) {
      i20 = (const _Float16*) ((uintptr_t) i20 + input_offset);
    }
    const _Float16* i21 = (const _Float16*) input[21];
    assert(i21 != NULL);
    if XNN_UNPREDICTABLE(i21 != (const _Float16*) zero) {
      i21 = (const _Float16*) ((uintptr_t) i21 + input_offset);
    }
    const _Float16* i22 = (const _Float16*) input[22];
    assert(i22 != NULL);
    if XNN_UNPREDICTABLE(i22 != (const _Float16*) zero) {
      i22 = (const _Float16*) ((uintptr_t) i22 + input_offset);
    }
    const _Float16* i23 = (const _Float16*) input[23];
    assert(i23 != NULL);
    if XNN_UNPREDICTABLE(i23 != (const _Float16*) zero) {
      i23 = (const _Float16*) ((uintptr_t) i23 + input_offset);
    }
    const _Float16* i24 = (const _Float16*) input[24];
    assert(i24 != NULL);
    if XNN_UNPREDICTABLE(i24 != (const _Float16*) zero) {
      i24 = (const _Float16*) ((uintptr_t) i24 + input_offset);
    }

    input = (const xnn_float16**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const _Float16* w = (const _Float16*) weights;
    const size_t vlmax = __riscv_vsetvlmax_e16m4();

    do {
      size_t vl = __riscv_vsetvl_e16m4(c);
      vfloat16m4_t vacc = __riscv_vle16_v_f16m4(w, vl);
      w += vlmax;

      vfloat16m4_t va = __riscv_vundefined_f16m4();
      vfloat16m4_t vb = __riscv_vundefined_f16m4();
      va = __riscv_vle16_v_f16m4(i0, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i0 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i1, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i1 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i2, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i2 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i3, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i3 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i4, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i4 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i5, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i5 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i6, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i6 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i7, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i7 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i8, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i8 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i9, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i9 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i10, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i10 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i11, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i11 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i12, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i12 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i13, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i13 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i14, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i14 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i15, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i15 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i16, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i16 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i17, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i17 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i18, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i18 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i19, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i19 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i20, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i20 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i21, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i21 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i22, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i22 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i23, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i23 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);
      va = __riscv_vle16_v_f16m4(i24, vl);
      vb = __riscv_vle16_v_f16m4(w, vl);
      w  += vlmax;
      i24 += vlmax;
      vacc = __riscv_vfmacc_vv_f16m4(vacc, va, vb, vl);

      vacc = __riscv_vfmax_vf_f16m4(vacc, vmin, vl);
      vacc = __riscv_vfmin_vf_f16m4(vacc, vmax, vl);
      __riscv_vse16_v_f16m4(o, vacc, vl);
      o += vl;
      c -= vl;
    } while(c != 0);
    input_offset += input_pixel_stride;
    o = (_Float16*) ((uintptr_t) o + output_increment);
  } while (--output_width != 0);
}
