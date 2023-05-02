#include "people.h"

const Person &lookup(const Db *db, int64_t id) {
  // Scan through the database
  for (const auto &person : db->data)
    if (person.id == id)
      return person;
  // We have to return something and it cannot be local variable.
  return null_person;
}

const Person &highest_tenure(const Db *db) {
  // Scan through the DB
  auto min_id = db->data.begin();
  for (auto it = db->data.begin(); it != db->data.end(); ++it)
    if (it->id < min_id->id)
      min_id = it;

  if (min_id == db->data.end()) // same as db->data.empty()
    return null_person;
  else
    return *min_id;
}

const Person &youngest_person(const Db *db) {
  // Scan through the DB
  auto max_year = db->data.begin();
  for (auto it = db->data.begin(); it != db->data.end(); ++it)
    if (it->year_of_birth > max_year->year_of_birth)
      max_year = it;

  if (max_year == db->data.end()) // same as db->data.empty()
    return null_person;
  else
    return *max_year;
}