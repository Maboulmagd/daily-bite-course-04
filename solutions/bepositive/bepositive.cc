#include "bepositive.h"

int64_t be_positive(std::span<int64_t> data) {
  int64_t cnt = 0;
  // iterate over all elements
  for (auto &el : data)
    if (el < 0) {
      ++cnt;    // count
      el *= -1; // and change to a positive
    }
  return cnt;
}