#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_floating_point.hpp"
#include "reverse.h"

TEST_CASE("reverse: Empty input") {
  std::vector<int64_t> data;
  reverse(data);
  REQUIRE(data.empty());
}

TEST_CASE("reverse: Single element") {
  std::vector<int64_t> data{42};
  reverse(data);
  REQUIRE(data.size() == 1);
  REQUIRE(data[0] == 42);
}

TEST_CASE("reverse: Even number of elements") {
  std::vector<int64_t> data{1, 2, 3, 4};
  std::vector<int64_t> expected{4, 3, 2, 1};
  reverse(data);
  REQUIRE(data.size() == 4);
  REQUIRE(data == expected);
}

TEST_CASE("reverse: Odd number of elements") {
  std::vector<int64_t> data{1, 2, 3, 4, 5};
  std::vector<int64_t> expected{5, 4, 3, 2, 1};
  reverse(data);
  REQUIRE(data.size() == 5);
  REQUIRE(data == expected);
}

TEST_CASE("reverse: Bigger input") {
  std::vector<int64_t> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
                            1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  std::vector<int64_t> expected{0, 9, 8, 7, 6, 5, 4, 3, 2, 1,
                                0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  reverse(data);
  REQUIRE(data.size() == 20);
  REQUIRE(data == expected);
}
