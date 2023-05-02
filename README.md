# Modern-Only C++ Course - Homework

This repository contains the homework for Lesson 4.

## Be Positive

Implement a function `be_positive` (in the file `bepositive/bepositive.cc`) that changes elements with negative values to their absolute values and returns the number of changed elements.

The goal is to have the following commands pass without any errors:

```
bazel test //bepositive/...
bazel test --config=addrsan //bepositive/...
bazel test --config=ubsan //bepositive/...
```

## Reverse

Implement a function `reverse` (in the file `reverse/reverse.cc`) that reverses the order of elements in a `std::span`.

The goal is to have the following commands pass without any errors:

```
bazel test //reverse/...
bazel test --config=addrsan //reverse/...
bazel test --config=ubsan //reverse/...
```

## People DB

Given a database of people, implement functions `lookup`, `highest_tenure`, and `youngest_person` (in the file `people/people.cc`) that do the following:

- `lookup`: Look up a person in the database by ID
- `highest_tenure`: Return the person with the lowest ID
- `youngest_person`: Return the person with the highest year_of_birth

Hint: You will find the global variable `null_person` useful.

The goal is to have the following commands pass without any errors:

```
bazel test //people/...
bazel test --config=addrsan //people/...
bazel test --config=ubsan //people/...
```

## Word Count

Implement the single-line and multi-line versions of functions `wordcount` and `instances` (in the file `wordcount/wordcount.cc`) that count the number of words in a line/text and count the number of instances of a word in a line/text.

The goal is to have the following commands pass without any errors:

```
bazel test //wordcount/...
bazel test --config=addrsan //wordcount/...
bazel test --config=ubsan //wordcount/...
```

## Solutions

If you wish to have a look at the solutions, you can find the commented code in the `solutions` directory.