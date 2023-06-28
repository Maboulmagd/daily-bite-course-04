#include "people.h"

#include <limits>

const Person &lookup(const Db *db, int64_t id) {
  for (const Person &person : db->data) {
    if (person.id == id) {
      return person;
    }
  }
  return null_person;
}

const Person &highest_tenure(const Db *db) {
  int64_t min_id = std::numeric_limits<int64_t>::max();
  const Person *res = nullptr;
  for (const Person &person : db->data) {
    if (person.id < min_id) {
      min_id = person.id;
      res = &person;
    }
  }
  if (res == nullptr) {
    return null_person;
  }
  const Person &res_ref = *res;
  return res_ref;
  //   return res == nullptr ? null_person : *res;
}

const Person &youngest_person(const Db *db) {
  int64_t latest_year = std::numeric_limits<int64_t>::min();
  const Person *res = nullptr;
  for (const Person &person : db->data) {
    if (person.year_of_birth > latest_year) {
      latest_year = person.year_of_birth;
      res = &person;
    }
  }
  return res == nullptr ? null_person : *res;
}