#include "reverse.h"

#include <algorithm>

void reverse(std::span<int64_t> data) {
  // Recall std::span is a mutable reference type
  std::reverse(data.begin(), data.end());

  // TODO Implement your own std::reverse functionality
}