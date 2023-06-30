#include "bepositive.h"

int64_t be_positive(std::span<int64_t> data) {
  int64_t inversions = 0;

  for (int64_t &num : data) {
    // Almost always 63 -> the sign bit, mask will always be either 0 or 1
    // (negative integer), move sign bit 63 positions right
    int64_t mask = num >> ((sizeof(int64_t) << 3) - 1);
    inversions += mask & 1; // Check if mask is 0 or 1 (negative integer)

    // By XORing num with 1 (mask is 1 for negative numbers), we toggle all the
    // bits of num. The result is a number where the sign bit of num is cleared
    // (turned to 0), effectively turning negative numbers into positive
    // numbers. Subsequently, the value of mask is subtracted from this result.
    // For positive numbers, mask is 0, so the value remains unchanged.
    // For negative numbers, mask is 1, so subtracting 1 from the result.
    num = (num ^ mask) - mask;
  }

  return inversions;
}