#include "wordcount.h"

int64_t wordcount(std::string_view line) {
  int64_t word_count = 0;

  bool constructing_word = false;

  for (const char &c : line) {
    if (c != ' ') {
      constructing_word = true;
    } else if (c == ' ' && constructing_word) {
      constructing_word = false;
      ++word_count;
    }
  }
  if (constructing_word) {
    ++word_count;
  }

  return word_count;
}

int64_t wordcount(const std::vector<std::string> &text) {
  int64_t word_count = 0;

  for (const std::string &line : text) {
    word_count += wordcount(line);
  }

  return word_count;
}

int64_t instances(std::string_view line, std::string_view word) {
  int64_t instances = 0;

  std::string curr_word;
  for (const char &c : line) {
    if (c == ' ') {
      if (!curr_word.empty()) {
        if (curr_word == word) {
          ++instances;
        }
      }

      curr_word.clear();
    } else if (c != ' ') {
      curr_word += c;
    }
  }
  if (curr_word == word) {
    ++instances;
  }

  return instances;
}

int64_t instances(const std::vector<std::string> &text, std::string_view word) {
  int64_t num_instances = 0;

  for (const std::string &line : text) {
    num_instances += instances(line, word);
  }

  return num_instances;
}