#include "bepositive.h"
#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_floating_point.hpp"

TEST_CASE("Changing negative elements to their absolute value",
          "[be_positive]") {
  std::vector<int64_t> empty_data;
  std::vector<int64_t> all_positive_data = {1, 2, 3, 4, 5};
  std::vector<int64_t> mixed_data = {-1, 2, -3, 4, -5};
  std::array<int64_t, 5> mixed_array_data = {-1, 2, -3, 4, -5};

  REQUIRE(be_positive(empty_data) == 0);
  REQUIRE(be_positive(all_positive_data) == 0);
  REQUIRE(be_positive(mixed_data) == 3);
  REQUIRE(be_positive(mixed_array_data) == 3);

  // Verify if the elements are actually changed
  std::vector<int64_t> expected_mixed_data = {1, 2, 3, 4, 5};
  std::array<int64_t, 5> expected_mixed_array_data = {1, 2, 3, 4, 5};

  REQUIRE(mixed_data == expected_mixed_data);
  REQUIRE(mixed_array_data == expected_mixed_array_data);
}