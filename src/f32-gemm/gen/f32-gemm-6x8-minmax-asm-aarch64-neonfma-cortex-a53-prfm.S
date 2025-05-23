// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-gemm/6x8-aarch64-neonfma-cortex-a53.S.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include "src/xnnpack/assembly.h"

# void xnn_f32_gemm_minmax_ukernel_6x8__asm_aarch64_neonfma_cortex_a53_prfm(
#     size_t mr,                x0
#     size_t nc,                x1
#     size_t kc,                x2 / x0
#     const float* a,           x3
#     size_t a_stride,          x4
#     const float* w,           x5
#     float* c,                 x6
#     size_t cm_stride,         x7
#     size_t cn_stride,         [sp] -> (x0)
#     const xnn_f32_minmax_params* params)  [sp + 8] -> (x8)

# d8-d15, x19-x30 need to be preserved if used. x18 is reserved by the OS.

// Register usage
// A0   x3  v0     v3
// A1   x9  v0[1]  v3[1]
// A2  x10  v1     v4
// A3  x11  v1[1]  v4[1]
// A4  x12  v2     v5
// A5   x4  v2[1]  v5[1]
// B    x5  v12 v13 v14 v15 second set of B
// B        v16 v17 v18 v19 first set
// C    x6  v20 v21
// C   x16  v22 v23
// C   x17  v24 v25
// C   x14  v26 v27
// C   x13  v28 v29
// C    x7  v30 v31
// clamp  v6 v7
// unused A   v8 v9 v10 v11
// temporary vector shadow register x8

BEGIN_FUNCTION xnn_f32_gemm_minmax_ukernel_6x8__asm_aarch64_neonfma_cortex_a53_prfm

        # Load params pointer
        LDR         x8, [sp, 8]

        # Clamp A and C pointers
        CMP         x0, 2                   // if mr < 2
        ADD         x9, x3, x4              // A1 = a0 + a_stride
        ADD         x16, x6, x7             // c1 = c0 + cm_stride
        CSEL        x9, x3, x9, LO          //   a1 = a0
        CSEL        x16, x6, x16, LO        //   c1 = c0

        ADD         x10, x9, x4             // A2 = a1 + a_stride
        ADD         x17, x16, x7            // c2 = c1 + cm_stride
                                            // if mr <= 2
        CSEL        x10, x9, x10, LS        //   a2 = a1
        CSEL        x17, x16, x17, LS       //   c2 = c1

        CMP         x0, 4                   // if mr < 4
        ADD         x11, x10, x4            // A3 = a2 + a_stride
        ADD         x14, x17, x7            // c3 = c2 + cm_stride
        CSEL        x11, x10, x11, LO       //   a3 = a2
        CSEL        x14, x17, x14, LO       //   c3 = c2

        ADD         x12, x11, x4            // A4 = a3 + a_stride
        ADD         x13, x14, x7            // c4 = c3 + cm_stride
                                            // if mr <= 4
        CSEL        x12, x11, x12, LS       //   a4 = a3
        CSEL        x13, x14, x13, LS       //   c4 = c3

        CMP         x0, 6                   // if mr < 6
        ADD         x4, x12, x4             // A5 = a4 + a_stride
        ADD         x7, x13, x7             // c5 = c4 + cm_stride
        CSEL        x4, x12, x4, LO         //   a5 = a4
        CSEL        x7, x13, x7, LO         //   c5 = c4

        # Load min/max values
        LD2R        {v6.4s, v7.4s}, [x8]

        # Save d12-d15 on stack
        STP         d12, d13, [sp, -32]!
        STP         d14, d15, [sp, 16]

0:
        # Load initial bias from w into accumulators
        LDP         q20, q21, [x5], 32
        MOV         v22.16b, v20.16b
        PRFM        PLDL1KEEP,  [x3,  0]    // Prefetch A
        PRFM        PLDL1KEEP,  [x3, 64]
        MOV         v23.16b, v21.16b
        PRFM        PLDL1KEEP,  [x9,  0]
        PRFM        PLDL1KEEP,  [x9, 64]
        MOV         v24.16b, v20.16b
        PRFM        PLDL1KEEP, [x10,  0]
        PRFM        PLDL1KEEP, [x10, 64]
        MOV         v25.16b, v21.16b
        PRFM        PLDL1KEEP, [x11,  0]
        PRFM        PLDL1KEEP, [x11, 64]
        MOV         v26.16b, v20.16b
        PRFM        PLDL1KEEP, [x12,  0]
        PRFM        PLDL1KEEP, [x12, 64]
        MOV         v27.16b, v21.16b
        PRFM        PLDL1KEEP,  [x4,  0]
        PRFM        PLDL1KEEP,  [x4, 64]
        MOV         v28.16b, v20.16b
        PRFM        PLDL1KEEP, [x5,   0]    // Prefetch B
        MOV         v29.16b, v21.16b
        PRFM        PLDL1KEEP, [x5,  64]
        MOV         v30.16b, v20.16b
        PRFM        PLDL1KEEP, [x5, 128]
        MOV         v31.16b, v21.16b
        PRFM        PLDL1KEEP, [x5, 192]

        # Is there at least 4 floats (16 bytes) for prologue + epilogue?
        SUBS        x0, x2, 16              // k = kc - 16
        B.LO        4f

        # Prologue - First group loads, no FMA
        LDR         d0, [x3], 8                 // A0
        LDP         q16, q17, [x5], 32          // B
        LDR         d1, [x10], 8                // A2
        LDR         d2, [x12], 8                // A4
        LD1         {v0.d}[1],  [x9], 8         // A1
        LD1         {v1.d}[1], [x11], 8         // A3
        LD1         {v2.d}[1],  [x4], 8         // A5
        SUBS        x0, x0, 16
        LDR         q18, [x5], 16
        LDR         d19, [x5], 8
        LDR         x8, [x5], 8                 // ins is in BLOCK 0

        # Is there at least 4 floats (16 bytes) for main loop?
        B.LO        2f

        # Main loop - 4 floats of A (16 bytes)
        # 48 FMA + 12 LD64 A + 8 LDR B
1:
        # First group of 24 FMA, Second group loads
        # BLOCK 0
        LDR         d3, [x3], 8                 // A0
        INS         v19.d[1], x8                // B from second group
        FMLA        v20.4s, v16.4s,  v0.s[0]
        LDR         x8, [x9], 8                 // A1
        FMLA        v22.4s, v16.4s,  v0.s[2]
        FMLA        v24.4s, v16.4s,  v1.s[0]

        # BLOCK 1
        LDR         d12, [x5]
        INS         v3.d[1], x8                 // A1 ins
        FMLA        v26.4s, v16.4s,  v1.s[2]
        LDR         x8, [x5, 8]                 // B
        FMLA        v28.4s, v16.4s,  v2.s[0]
        FMLA        v30.4s, v16.4s,  v2.s[2]

        # BLOCK 2
        LDR         d4, [x10], 8                // A2
        INS         v12.d[1], x8                // B  ins
        FMLA        v21.4s, v17.4s,  v0.s[0]
        LDR         x8, [x11], 8                // A3
        FMLA        v23.4s, v17.4s,  v0.s[2]
        FMLA        v25.4s, v17.4s,  v1.s[0]

        # BLOCK 3
        LDR         d5, [x12], 8                // A4
        INS         v4.d[1], x8                 // A3 ins
        FMLA        v27.4s, v17.4s,  v1.s[2]
        LDR         x8, [x4], 8                 // A5
        FMLA        v29.4s, v17.4s,  v2.s[0]
        FMLA        v31.4s, v17.4s,  v2.s[2]

        # BLOCK 4
        LDR         d13, [x5, 16]
        INS         v5.d[1], x8                 // A5 ins
        FMLA        v20.4s, v18.4s,  v0.s[1]
        LDR         x8, [x5, 24]
        FMLA        v22.4s, v18.4s,  v0.s[3]
        FMLA        v24.4s, v18.4s,  v1.s[1]

        # BLOCK 5
        LDR         d14, [x5, 32]
        INS         v13.d[1], x8                // B
        FMLA        v26.4s, v18.4s,  v1.s[3]
        LDR         x8, [x5, 40]
        FMLA        v28.4s, v18.4s,  v2.s[1]
        FMLA        v30.4s, v18.4s,  v2.s[3]

        # BLOCK 6
        LDR         d15, [x5, 48]
        INS         v14.d[1], x8                // B
        FMLA        v21.4s, v19.4s,  v0.s[1]
        LDR         x8, [x5, 56]
        FMLA        v23.4s, v19.4s,  v0.s[3]
        FMLA        v25.4s, v19.4s,  v1.s[1]

        # BLOCK 7
        INS         v15.d[1], x8
        FMLA        v27.4s, v19.4s,  v1.s[3]
        FMLA        v29.4s, v19.4s,  v2.s[1]
        FMLA        v31.4s, v19.4s,  v2.s[3]

        # Second group of 24 FMA, First group of loads
        # BLOCK 0
        LDR         d0, [x3], 8                 // A0
        FMLA        v20.4s, v12.4s,  v3.s[0]
        LDR         x8, [x9], 8                 // A1
        FMLA        v22.4s, v12.4s,  v3.s[2]
        FMLA        v24.4s, v12.4s,  v4.s[0]
        PRFM        PLDL1KEEP, [x3, 128]        // Prefetch A0

        # BLOCK 1
        LDR         d16, [x5, 64]
        INS         v0.d[1], x8                 // A1 ins
        FMLA        v26.4s, v12.4s,  v4.s[2]
        LDR         x8, [x5, 72]                // B
        FMLA        v28.4s, v12.4s,  v5.s[0]
        FMLA        v30.4s, v12.4s,  v5.s[2]
        PRFM        PLDL1KEEP, [x9, 128]        // Prefetch A1

        # BLOCK 2
        LDR         d1, [x10], 8                // A2
        INS         v16.d[1], x8                // B
        FMLA        v21.4s, v13.4s,  v3.s[0]
        LDR         x8, [x11], 8                // A3
        FMLA        v23.4s, v13.4s,  v3.s[2]
        FMLA        v25.4s, v13.4s,  v4.s[0]
        PRFM        PLDL1KEEP, [x10, 128]       // Prefetch A2

        # BLOCK 3
        LDR         d2, [x12], 8                // A4
        INS         v1.d[1], x8                 // A3 ins
        FMLA        v27.4s, v13.4s,  v4.s[2]
        LDR         x8,  [x4], 8                // A5
        FMLA        v29.4s, v13.4s,  v5.s[0]
        FMLA        v31.4s, v13.4s,  v5.s[2]
        PRFM        PLDL1KEEP, [x11, 128]       // Prefetch A3

        # BLOCK 4
        LDR         d17, [x5, 80]
        INS         v2.d[1], x8                 // A5 ins
        FMLA        v20.4s, v14.4s,  v3.s[1]
        LDR         x8, [x5, 88]
        FMLA        v22.4s, v14.4s,  v3.s[3]
        FMLA        v24.4s, v14.4s,  v4.s[1]
        PRFM        PLDL1KEEP, [x12, 128]       // Prefetch A4

        # BLOCK 5
        LDR         d18, [x5, 96]
        INS         v17.d[1], x8                // B
        FMLA        v26.4s, v14.4s,  v4.s[3]
        LDR         x8, [x5, 104]
        FMLA        v28.4s, v14.4s,  v5.s[1]
        FMLA        v30.4s, v14.4s,  v5.s[3]
        PRFM        PLDL1KEEP, [x4, 128]        // Prefetch A5

        # BLOCK 6
        LDR         d19, [x5, 112]
        INS         v18.d[1], x8                // B
        FMLA        v21.4s, v15.4s,  v3.s[1]
        LDR         x8, [x5, 120]
        FMLA        v23.4s, v15.4s,  v3.s[3]
        PRFM        PLDL1KEEP, [x5, 192]        // Prefetch B
        FMLA        v25.4s, v15.4s,  v4.s[1]
        PRFM        PLDL1KEEP, [x5, 256]        // Prefetch B

        # BLOCK 7
        SUBS        x0, x0, 16                  // LDR lands here
        FMLA        v27.4s, v15.4s,  v4.s[3]
        FMLA        v29.4s, v15.4s,  v5.s[1]
        ADD         x5, x5, 128
        FMLA        v31.4s, v15.4s,  v5.s[3]
        B.HS        1b

        # Epilogue - 4 floats of A (16 bytes)
        # 48 FMA + 12 LD64 A + 8 LDR B
2:
        # First group of 24 FMA, Second group loads
        # BLOCK 0
        LDR         d3, [x3], 8                 // A0
        INS         v19.d[1], x8                // B from second group
        FMLA        v20.4s, v16.4s,  v0.s[0]
        LDR         x8, [x9], 8                 // A1
        FMLA        v22.4s, v16.4s,  v0.s[2]
        FMLA        v24.4s, v16.4s,  v1.s[0]
        PRFM        PSTL1KEEP,  [x6]            // Prefetch C0

        # BLOCK 1
        LDR         d12, [x5]
        INS         v3.d[1], x8                 // A1 ins
        FMLA        v26.4s, v16.4s,  v1.s[2]
        LDR         x8, [x5, 8]                 // B
        FMLA        v28.4s, v16.4s,  v2.s[0]
        FMLA        v30.4s, v16.4s,  v2.s[2]
        PRFM        PSTL1KEEP, [x16]            // Prefetch C1

        # BLOCK 2
        LDR         d4, [x10], 8                // A2
        INS         v12.d[1], x8                // B  ins
        FMLA        v21.4s, v17.4s,  v0.s[0]
        LDR         x8, [x11], 8                // A3
        FMLA        v23.4s, v17.4s,  v0.s[2]
        FMLA        v25.4s, v17.4s,  v1.s[0]
        PRFM        PSTL1KEEP, [x17]            // Prefetch C2

        # BLOCK 3
        LDR         d5, [x12], 8                // A4
        INS         v4.d[1], x8                 // A3 ins
        FMLA        v27.4s, v17.4s,  v1.s[2]
        LDR         x8, [x4], 8                 // A5
        FMLA        v29.4s, v17.4s,  v2.s[0]
        FMLA        v31.4s, v17.4s,  v2.s[2]
        PRFM        PSTL1KEEP, [x14]            // Prefetch C3

        # BLOCK 4
        LDR         d13, [x5, 16]
        INS         v5.d[1], x8                 // A5 ins
        FMLA        v20.4s, v18.4s,  v0.s[1]
        LDR         x8, [x5, 24]
        FMLA        v22.4s, v18.4s,  v0.s[3]
        FMLA        v24.4s, v18.4s,  v1.s[1]
        PRFM        PSTL1KEEP, [x13]            // Prefetch C4

        # BLOCK 5
        LDR         d14, [x5, 32]
        INS         v13.d[1], x8                // B
        FMLA        v26.4s, v18.4s,  v1.s[3]
        LDR         x8, [x5, 40]
        FMLA        v28.4s, v18.4s,  v2.s[1]
        FMLA        v30.4s, v18.4s,  v2.s[3]
        PRFM        PSTL1KEEP, [x7]             // Prefetch C5

        # BLOCK 6
        LDR         d15, [x5, 48]
        INS         v14.d[1], x8                // B
        FMLA        v21.4s, v19.4s,  v0.s[1]
        LDR         x8, [x5, 56]
        FMLA        v23.4s, v19.4s,  v0.s[3]
        FMLA        v25.4s, v19.4s,  v1.s[1]

        # BLOCK 7
        INS         v15.d[1], x8                // B
        FMLA        v27.4s, v19.4s,  v1.s[3]
        FMLA        v29.4s, v19.4s,  v2.s[1]
        FMLA        v31.4s, v19.4s,  v2.s[3]

        # Second group of 24 FMA, First group of loads
        # BLOCK 0
        FMLA        v20.4s, v12.4s,  v3.s[0]
        FMLA        v22.4s, v12.4s,  v3.s[2]
        FMLA        v24.4s, v12.4s,  v4.s[0]

        # BLOCK 1
        FMLA        v26.4s, v12.4s,  v4.s[2]
        FMLA        v28.4s, v12.4s,  v5.s[0]
        FMLA        v30.4s, v12.4s,  v5.s[2]

        # BLOCK 2
        FMLA        v21.4s, v13.4s,  v3.s[0]
        FMLA        v23.4s, v13.4s,  v3.s[2]
        FMLA        v25.4s, v13.4s,  v4.s[0]

        # BLOCK 3
        FMLA        v27.4s, v13.4s,  v4.s[2]
        FMLA        v29.4s, v13.4s,  v5.s[0]
        FMLA        v31.4s, v13.4s,  v5.s[2]

        # BLOCK 4
        FMLA        v20.4s, v14.4s,  v3.s[1]
        FMLA        v22.4s, v14.4s,  v3.s[3]
        FMLA        v24.4s, v14.4s,  v4.s[1]

        # BLOCK 5
        FMLA        v26.4s, v14.4s,  v4.s[3]
        FMLA        v28.4s, v14.4s,  v5.s[1]
        FMLA        v30.4s, v14.4s,  v5.s[3]
        TST         x0, 15

        # BLOCK 6
        FMLA        v21.4s, v15.4s,  v3.s[1]
        FMLA        v23.4s, v15.4s,  v3.s[3]
        FMLA        v25.4s, v15.4s,  v4.s[1]
        ADD         x5, x5, 64

        # BLOCK 7
        FMLA        v27.4s, v15.4s,  v4.s[3]
        FMLA        v29.4s, v15.4s,  v5.s[1]
        FMLA        v31.4s, v15.4s,  v5.s[3]

        # Is there a remainder?- 2 floats of A (8 bytes) or less
        B.NE        4f
3:
        # Clamp
        FMAX        v20.4s, v20.4s, v6.4s
        # Load cn_stride
        LDR         x0, [sp, 32]
        FMAX        v21.4s, v21.4s, v6.4s
        FMAX        v22.4s, v22.4s, v6.4s
        FMAX        v23.4s, v23.4s, v6.4s
        FMAX        v24.4s, v24.4s, v6.4s
        FMAX        v25.4s, v25.4s, v6.4s
        FMAX        v26.4s, v26.4s, v6.4s
        FMAX        v27.4s, v27.4s, v6.4s
        FMAX        v28.4s, v28.4s, v6.4s
        FMAX        v29.4s, v29.4s, v6.4s
        FMAX        v30.4s, v30.4s, v6.4s
        FMAX        v31.4s, v31.4s, v6.4s
        SUBS        x1, x1, 8
        FMIN        v20.4s, v20.4s, v7.4s
        FMIN        v21.4s, v21.4s, v7.4s
        FMIN        v22.4s, v22.4s, v7.4s
        FMIN        v23.4s, v23.4s, v7.4s
        FMIN        v24.4s, v24.4s, v7.4s
        FMIN        v25.4s, v25.4s, v7.4s
        FMIN        v26.4s, v26.4s, v7.4s
        FMIN        v27.4s, v27.4s, v7.4s
        FMIN        v28.4s, v28.4s, v7.4s
        FMIN        v29.4s, v29.4s, v7.4s
        FMIN        v30.4s, v30.4s, v7.4s
        FMIN        v31.4s, v31.4s, v7.4s

        # Store full 6 x 8
        B.LO        6f

        ST1         {v20.16b, v21.16b},  [x6], x0
        SUB         x3,  x3, x2             // A0 -= kc
        ST1         {v22.16b, v23.16b}, [x16], x0
        SUB         x9,  x9, x2             // A1 -= kc
        ST1         {v24.16b, v25.16b}, [x17], x0
        SUB         x10, x10, x2            // A2 -= kc
        ST1         {v26.16b, v27.16b}, [x14], x0
        SUB         x11, x11, x2            // A3 -= kc
        ST1         {v28.16b, v29.16b}, [x13], x0
        SUB         x12, x12, x2            // A4 -= kc
        ST1         {v30.16b, v31.16b},  [x7], x0
        SUB         x4,  x4, x2             // A5 -= kc

        B.HI        0b

        # Restore d12-d15 from stack
        LDP         d14, d15, [sp, 16]
        LDP         d12, d13, [sp], 32
        RET

4:
        # Is there a remainder?- 2 floats of A (8 bytes)
        TBZ         x0, 3, 5f

        # Remainder- 2 floats of A (8 bytes)
        LDR         d0,  [x3], 8
        LDR         q16, [x5], 16
        LD1         {v0.d}[1], [x9], 8
        LDR         d1, [x10], 8
        LD1         {v1.d}[1], [x11], 8
        LDR         d2, [x12], 8
        LD1         {v2.d}[1], [x4], 8
        LDR         q17, [x5], 16
        LDR         q18, [x5], 16
        LDR         q19, [x5], 16

        FMLA        v20.4s, v16.4s,  v0.s[0]
        FMLA        v22.4s, v16.4s,  v0.s[2]
        FMLA        v24.4s, v16.4s,  v1.s[0]
        FMLA        v26.4s, v16.4s,  v1.s[2]
        FMLA        v28.4s, v16.4s,  v2.s[0]
        FMLA        v30.4s, v16.4s,  v2.s[2]
        FMLA        v21.4s, v17.4s,  v0.s[0]
        FMLA        v23.4s, v17.4s,  v0.s[2]
        FMLA        v25.4s, v17.4s,  v1.s[0]
        FMLA        v27.4s, v17.4s,  v1.s[2]
        FMLA        v29.4s, v17.4s,  v2.s[0]
        FMLA        v31.4s, v17.4s,  v2.s[2]

        FMLA        v20.4s, v18.4s,  v0.s[1]
        FMLA        v22.4s, v18.4s,  v0.s[3]
        FMLA        v24.4s, v18.4s,  v1.s[1]
        FMLA        v26.4s, v18.4s,  v1.s[3]
        FMLA        v28.4s, v18.4s,  v2.s[1]
        FMLA        v30.4s, v18.4s,  v2.s[3]
        FMLA        v21.4s, v19.4s,  v0.s[1]
        FMLA        v23.4s, v19.4s,  v0.s[3]
        FMLA        v25.4s, v19.4s,  v1.s[1]
        FMLA        v27.4s, v19.4s,  v1.s[3]
        FMLA        v29.4s, v19.4s,  v2.s[1]
        FMLA        v31.4s, v19.4s,  v2.s[3]

        # Is there a remainder?- 1 float of A (4 bytes)
        TBZ         x0, 2, 3b
5:
        # Remainder- 1 float of A (4 bytes)
        LDR         s0,  [x3], 4
        LDR         q16, [x5], 16
        LD1         {v0.s}[2], [x9], 4
        LDR         s1, [x10], 4
        LD1         {v1.s}[2], [x11], 4
        LDR         s2, [x12], 4
        LD1         {v2.s}[2], [x4], 4
        LDR         q17, [x5], 16

        FMLA        v20.4s, v16.4s,  v0.s[0]
        FMLA        v22.4s, v16.4s,  v0.s[2]
        FMLA        v24.4s, v16.4s,  v1.s[0]
        FMLA        v26.4s, v16.4s,  v1.s[2]
        FMLA        v28.4s, v16.4s,  v2.s[0]
        FMLA        v30.4s, v16.4s,  v2.s[2]
        FMLA        v21.4s, v17.4s,  v0.s[0]
        FMLA        v23.4s, v17.4s,  v0.s[2]
        FMLA        v25.4s, v17.4s,  v1.s[0]
        FMLA        v27.4s, v17.4s,  v1.s[2]
        FMLA        v29.4s, v17.4s,  v2.s[0]
        FMLA        v31.4s, v17.4s,  v2.s[2]
        B           3b

        # Store odd width
6:
        TBZ         x1, 2, 7f
        STR         q20,  [x6], 16
        MOV         v20.16b, v21.16b
        STR         q22, [x16], 16
        MOV         v22.16b, v23.16b
        STR         q24, [x17], 16
        MOV         v24.16b, v25.16b
        STR         q26, [x14], 16
        MOV         v26.16b, v27.16b
        STR         q28, [x13], 16
        MOV         v28.16b, v29.16b
        STR         q30,  [x7], 16
        MOV         v30.16b, v31.16b

7:
        TBZ         x1, 1, 8f
        STR         d20,  [x6], 8
        STR         d22, [x16], 8
        DUP         d20, v20.d[1]
        DUP         d22, v22.d[1]
        STR         d24, [x17], 8
        STR         d26, [x14], 8
        DUP         d24, v24.d[1]
        DUP         d26, v26.d[1]
        STR         d28, [x13], 8
        STR         d30,  [x7], 8
        DUP         d28, v28.d[1]
        DUP         d30, v30.d[1]

8:
        TBZ         x1, 0, 9f
        STR         s20,  [x6]
        STR         s22, [x16]
        STR         s24, [x17]
        STR         s26, [x14]
        STR         s28, [x13]
        STR         s30,  [x7]
9:
        # Restore d12-d15 from stack
        LDP         d14, d15, [sp, 16]
        LDP         d12, d13, [sp], 32
        RET

END_FUNCTION xnn_f32_gemm_minmax_ukernel_6x8__asm_aarch64_neonfma_cortex_a53_prfm

#ifdef __ELF__
.section ".note.GNU-stack","",%progbits
#endif
