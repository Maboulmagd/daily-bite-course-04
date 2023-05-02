#pragma once

#include <cstdint>
#include <string>
#include <vector>

/* Count the number of words in a line of text.

A word is a non-space sequence of consecutive characters.
*/
int64_t wordcount(std::string_view line);

/* Count the number of words in a text.

A word is a non-space sequence of consecutive characters.
*/
int64_t wordcount(const std::vector<std::string> &text);

/* Count the number of instances of a word in a line of text.

An instance of a word is a matching sequence of characters surrounded by space
or start/end of line.
*/
int64_t instances(std::string_view line, std::string_view word);

/* Count the number of instances of a word in a text.

An instance of a word is a matching sequence of characters surrounded by space
or start/end of line.
*/
int64_t instances(const std::vector<std::string> &text, std::string_view word);