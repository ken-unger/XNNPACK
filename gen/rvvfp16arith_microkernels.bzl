#
# Microkernel filenames lists for rvvfp16arith.
#
# Auto-generated file. Do not edit!
#   Generator: tools/update-microkernels.py
#

PROD_RVVFP16ARITH_MICROKERNEL_SRCS = [
    "src/f16-dwconv/gen/f16-dwconv-3p8vc-minmax-rvvfp16arith.c",
    "src/f16-dwconv/gen/f16-dwconv-4p8vc-minmax-rvvfp16arith.c",
    "src/f16-dwconv/gen/f16-dwconv-9p8vc-minmax-rvvfp16arith.c",
    "src/f16-dwconv/gen/f16-dwconv-25p8vc-minmax-rvvfp16arith.c",
    "src/f16-gemm/gen/f16-gemm-1x4v-minmax-rvvfp16arith.c",
    "src/f16-gemm/gen/f16-gemm-7x4v-minmax-rvvfp16arith.c",
    "src/f16-igemm/gen/f16-igemm-1x4v-minmax-rvvfp16arith.c",
    "src/f16-igemm/gen/f16-igemm-7x4v-minmax-rvvfp16arith.c",
]

NON_PROD_RVVFP16ARITH_MICROKERNEL_SRCS = [
    "src/f16-dwconv/gen/f16-dwconv-3p4vc-minmax-rvvfp16arith.c",
    "src/f16-dwconv/gen/f16-dwconv-4p4vc-minmax-rvvfp16arith.c",
    "src/f16-dwconv/gen/f16-dwconv-9p4vc-minmax-rvvfp16arith.c",
    "src/f16-dwconv/gen/f16-dwconv-25p4vc-minmax-rvvfp16arith.c",
    "src/f16-f32-vcvt/gen/f16-f32-vcvt-rvvfp16arith-u1v.c",
    "src/f16-f32-vcvt/gen/f16-f32-vcvt-rvvfp16arith-u2v.c",
    "src/f16-f32-vcvt/gen/f16-f32-vcvt-rvvfp16arith-u4v.c",
    "src/f16-gemm/gen/f16-gemm-4x4v-minmax-rvvfp16arith.c",
    "src/f16-igemm/gen/f16-igemm-4x4v-minmax-rvvfp16arith.c",
    "src/f16-vclamp/gen/f16-vclamp-rvvfp16arith-u1v.c",
    "src/f16-vclamp/gen/f16-vclamp-rvvfp16arith-u2v.c",
    "src/f16-vclamp/gen/f16-vclamp-rvvfp16arith-u4v.c",
    "src/f16-vclamp/gen/f16-vclamp-rvvfp16arith-u8v.c",
    "src/f32-f16-vcvt/gen/f32-f16-vcvt-rvvfp16arith-u1v.c",
    "src/f32-f16-vcvt/gen/f32-f16-vcvt-rvvfp16arith-u2v.c",
    "src/f32-f16-vcvt/gen/f32-f16-vcvt-rvvfp16arith-u4v.c",
    "src/f32-f16-vcvt/gen/f32-f16-vcvt-rvvfp16arith-u8v.c",
    "src/qd8-f16-qc4w-gemm/gen/qd8-f16-qc4w-gemm-1x4v-minmax-rvvfp16arith.c",
    "src/qd8-f16-qc4w-gemm/gen/qd8-f16-qc4w-gemm-4x4v-minmax-rvvfp16arith.c",
    "src/qd8-f16-qc4w-gemm/gen/qd8-f16-qc4w-gemm-7x4v-minmax-rvvfp16arith.c",
    "src/qd8-f16-qc8w-gemm/gen/qd8-f16-qc8w-gemm-1x4v-minmax-rvvfp16arith.c",
    "src/qd8-f16-qc8w-gemm/gen/qd8-f16-qc8w-gemm-4x4v-minmax-rvvfp16arith.c",
    "src/qd8-f16-qc8w-gemm/gen/qd8-f16-qc8w-gemm-7x4v-minmax-rvvfp16arith.c",
]

ALL_RVVFP16ARITH_MICROKERNEL_SRCS = PROD_RVVFP16ARITH_MICROKERNEL_SRCS + NON_PROD_RVVFP16ARITH_MICROKERNEL_SRCS
