// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <cstddef>
#include <cstdint>
#include <random>
#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "xnnpack.h"
#include "xnnpack/buffer.h"
#include "xnnpack/datatype.h"
#include "xnnpack/math.h"
#include "replicable_random_device.h"
#include "subgraph-tester.h"

namespace xnnpack {

template <typename T>
void TestImpl(size_t rank) {
  xnnpack::ReplicableRandomDevice rng;

  ASSERT_EQ(xnn_status_success, xnn_initialize(nullptr /* allocator */));

  for (int iters = 0; iters < 100; ++iters) {
    std::vector<size_t> dims = random_shape(rng, rank);

    std::vector<int64_t> begins(dims.size());
    std::vector<int64_t> ends(dims.size());
    for (size_t i = 0; i < dims.size(); i++) {
      const int64_t range = dims[i];
      auto begin_dist =
          std::uniform_int_distribution<int64_t>(-range, range - 1);
      begins[i] = begin_dist(rng);
      std::uniform_int_distribution<int64_t> end_dist;
      if (begins[i] < 0) {
        // Negative begin, negative end
        end_dist = std::uniform_int_distribution<int64_t>(begins[i] + 1, 0);
      } else if (rng() % 2 == 0) {
        // Positive begin, negative end
        end_dist =
            std::uniform_int_distribution<int64_t>(begins[i] + 1 - range, 0);
      } else {
        // Positive begin, positive end
        end_dist = std::uniform_int_distribution<int64_t>(begins[i] + 1, range);
      }
      ends[i] = end_dist(rng);
    }

    xnn_quantization_params quantization =
        random_quantization(xnn_datatype_of<T>(), rng);

    std::vector<int64_t> strides(dims.size(), 1);
    // Define subgraph
    xnnpack::SubgraphTester subgraph(2);
    subgraph.AddInputTensor(rank, xnn_datatype_of<T>(), quantization, 0)
        .AddOutputTensor(rank, xnn_datatype_of<T>(), quantization, 1)
        .AddSlice(begins, ends, strides, 0, 1)
        .CreateRuntime();

    for (int reshape = 0; reshape < 2; ++reshape) {
      std::vector<size_t> shape = random_shape(rng, rank);
      for (size_t i = 0; i < rank; ++i) {
        shape[i] += dims[i];
      }

      xnnpack::Tensor<T> input(shape, xnnpack::PaddingBytes{XNN_EXTRA_BYTES});
      DatatypeGenerator<T> generator(quantization);
      input.generate([&]() { return generator(rng); });

      // Make a deep copy so the expected result is contiguous.
      xnnpack::Tensor<T> expected = input.slice(begins, ends).deep_copy();
      xnnpack::Tensor<T> output(expected.extents());

      // Use the input prior to slicing in the subgraph.
      subgraph.ReshapeExternalTensor(shape, input.data(), 0)
          .ReshapeExternalTensor(expected.extents(), output.data(), 1)
          .ReshapeRuntime()
          .SetupRuntime()
          .InvokeRuntime();

      // Verify results.
      ASSERT_THAT(output, testing::ElementsAreArray(expected));
    }
  }
}

template <typename T>
class Slice : public ::testing::TestWithParam<int> {};

using SliceQS8 = Slice<quantized<int8_t>>;
using SliceQU8 = Slice<quantized<uint8_t>>;
using SliceF16 = Slice<xnn_float16>;
using SliceF32 = Slice<float>;

TEST_P(SliceQS8, test) { TestImpl<quantized<int8_t>>(GetParam()); }
TEST_P(SliceQU8, test) { TestImpl<quantized<uint8_t>>(GetParam()); }
TEST_P(SliceF16, test) { TestImpl<xnn_float16>(GetParam()); }
TEST_P(SliceF32, test) { TestImpl<float>(GetParam()); }

auto rank_params = testing::Range(1, XNN_MAX_TENSOR_DIMS);
INSTANTIATE_TEST_SUITE_P(Slice, SliceQS8, rank_params);
INSTANTIATE_TEST_SUITE_P(Slice, SliceQU8, rank_params);
INSTANTIATE_TEST_SUITE_P(Slice, SliceF16, rank_params);
INSTANTIATE_TEST_SUITE_P(Slice, SliceF32, rank_params);

}  // namespace xnnpack
