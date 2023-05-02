#pragma once

#include <cstdint>
#include <span>

/* \brief Changes all negative elements to their absolute value.

 \returns The number of changed elements.
*/
int64_t be_positive(std::span<int64_t> data);