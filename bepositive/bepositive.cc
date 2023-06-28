#include "bepositive.h"

#include <cmath>

int64_t be_positive(std::span<int64_t> data) {
  int64_t inversions = 0;

  for (int64_t &num : data) {
    if (num < 0) { // TODO see if I can get rid of this if condition
      num = std::abs(num);
      ++inversions;
    }
  }

  return inversions;
}