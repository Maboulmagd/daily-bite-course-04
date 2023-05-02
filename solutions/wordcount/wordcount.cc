#include "wordcount.h"

int64_t wordcount(std::string_view line) {
  int64_t cnt = 0;
  auto it = line.begin();
  while (it != line.end()) {
    // skip over leading spaces
    while (it != line.end() && std::isspace(*it))
      ++it;
    // if we have letters, it is a word
    if (it != line.end())
      ++cnt;
    // skip over the word
    while (it != line.end() && !std::isspace(*it))
      ++it;
  }
  return cnt;
}

int64_t wordcount(const std::vector<std::string> &text) {
  int64_t cnt = 0;
  for (const auto &line : text)
    cnt += wordcount(line);
  return cnt;
}

int64_t instances(std::string_view line, std::string_view word) {
  int64_t cnt = 0;
  size_t offset = line.find(word);
  while (offset != std::string_view::npos) {
    // a word needs to be surrounded by spaces (or at the start/end of string)
    if ((offset == 0 || std::isspace(line[offset - 1])) // before the word
        && (offset + word.length() == line.length() ||
            std::isspace(line[offset + word.length()]))) // after the word
      ++cnt;
    // find the next candidate
    offset = line.find(word, offset + word.length());
  }
  return cnt;
}

int64_t instances(const std::vector<std::string> &text, std::string_view word) {
  int64_t cnt = 0;
  for (const auto &line : text)
    cnt += instances(line, word);
  return cnt;
}