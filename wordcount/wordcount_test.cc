#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_floating_point.hpp"
#include "wordcount.h"

TEST_CASE("Word count for a single line of text", "[wordcount]") {
  REQUIRE(wordcount("") == 0);
  REQUIRE(wordcount("   ") == 0);
  REQUIRE(wordcount("Hello") == 1);
  REQUIRE(wordcount("Hello, World!") == 2);
  REQUIRE(wordcount("   Leading spaces") == 2);
  REQUIRE(wordcount("Trailing spaces   ") == 2);
  REQUIRE(wordcount("Multiple    spaces   between words") == 4);
}

TEST_CASE("Word count for multiple lines of text", "[wordcount]") {
  std::vector<std::string> empty_text = {};
  std::vector<std::string> single_line_text = {"Hello, World!"};
  std::vector<std::string> multi_line_text = {
      "This is a test", "with multiple lines.", "Some lines have extra spaces.",
      "   Like this one."};

  REQUIRE(wordcount(empty_text) == 0);
  REQUIRE(wordcount(single_line_text) == 2);
  REQUIRE(wordcount(multi_line_text) == 15);
}

TEST_CASE("Instance count for a word in a single line of text", "[instances]") {
  REQUIRE(instances("", "test") == 0);
  REQUIRE(instances("Hello, World", "World") == 1);
  REQUIRE(instances("test test test test", "test") == 4);
  REQUIRE(instances("Partial match testesting", "test") == 0);
  REQUIRE(instances("Word at the end of the linetest", "test") == 0);
  REQUIRE(instances("testWord at the start of the line", "test") == 0);
}

TEST_CASE("Instance count for a word in multiple lines of text",
          "[instances]") {
  std::vector<std::string> empty_text = {};
  std::vector<std::string> single_line_text = {"Hello, World! Test World"};
  std::vector<std::string> multi_line_text = {
      "This is a test", "with multiple lines", "Some lines have the word test",
      "   Test is case-sensitive"};

  REQUIRE(instances(empty_text, "test") == 0);
  REQUIRE(instances(single_line_text, "World") == 1);
  REQUIRE(instances(multi_line_text, "test") == 2);
  REQUIRE(instances(multi_line_text, "Test") == 1);
}