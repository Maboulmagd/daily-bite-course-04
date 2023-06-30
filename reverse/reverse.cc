#include "reverse.h"

#include <algorithm>

void reverse(std::span<int64_t> data) {
  // Recall std::span is a mutable reference type
  // std::reverse(data.begin(), data.end());

  // My own implementation of std::reverse functionality
  if (data.empty()) {
    return;
  }

  std::span<int64_t>::iterator left = data.begin();
  std::span<int64_t>::iterator right = data.end() - 1;

  while (left < right) {
    std::swap(*left, *right);
    ++left;
    --right;
  }
}