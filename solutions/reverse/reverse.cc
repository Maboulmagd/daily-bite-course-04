#include "reverse.h"

void reverse(std::span<int64_t> data) {
  if (data.empty())
    return;

  auto left = data.begin();
  auto right = std::prev(data.end()); // or data.end()-1
  while (left < right) {
    // same as std::swap(*left,*right)
    // or we could just do a 3-step swap:
    // int64_t tmp = *left; *left = *right; *right = tmp;
    std::iter_swap(left, right);
    ++left;  // move left right
    --right; // move right left
  }
}