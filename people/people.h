#pragma once

#include <cstdint>
#include <string>
#include <vector>

struct Person {
  int64_t id;
  std::string name;
  int64_t year_of_birth;
};

struct Db {
  std::vector<Person> data;
};

inline constexpr Person null_person{0, "", 0};

/* \brief Lookup a person record by id.
 */
const Person &lookup(const Db *db, int64_t id);

/* \brief Lookup a person with the longest tenure (lowest id).
 */
const Person &highest_tenure(const Db *db);

/* \brief Lookup a person with lowest age (highest year_of_birth).
 */
const Person &youngest_person(const Db *db);