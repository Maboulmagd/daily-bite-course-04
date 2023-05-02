#pragma once

#include <cstdint>
#include <span>

/* \brief Reverse the order of elements in the provided std::span.
 */
void reverse(std::span<int64_t> data);