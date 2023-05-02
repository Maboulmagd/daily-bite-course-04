#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_floating_point.hpp"
#include "people.h"

TEST_CASE("Lookup tests") {
  Db db;
  Person person1{1, "Alice", 1990};
  Person person2{2, "Bob", 1985};
  Person person3{3, "Charlie", 2000};
  db.data.push_back(person1);
  db.data.push_back(person2);
  db.data.push_back(person3);

  SECTION("Lookup person with valid ID") {
    const Person &result1 = lookup(&db, 1);
    REQUIRE(result1.id == 1);
    REQUIRE(result1.name == "Alice");
    REQUIRE(result1.year_of_birth == 1990);

    const Person &result2 = lookup(&db, 2);
    REQUIRE(result2.id == 2);
    REQUIRE(result2.name == "Bob");
    REQUIRE(result2.year_of_birth == 1985);

    const Person &result3 = lookup(&db, 3);
    REQUIRE(result3.id == 3);
    REQUIRE(result3.name == "Charlie");
    REQUIRE(result3.year_of_birth == 2000);
  }

  SECTION("Lookup person with invalid ID") {
    const Person &result = lookup(&db, 999);
    REQUIRE(result.id == 0);
    REQUIRE(result.name == "");
    REQUIRE(result.year_of_birth == 0);
  }

  SECTION("Lookup person with an empty database") {
    Db empty_db;
    const Person &result = lookup(&empty_db, 1);
    REQUIRE(result.id == 0);
    REQUIRE(result.name == "");
    REQUIRE(result.year_of_birth == 0);
  }
}

TEST_CASE("Highest tenure tests") {
  Db db;
  Person person1{1, "Alice", 1990};
  Person person2{2, "Bob", 1985};
  Person person3{3, "Charlie", 2000};
  db.data.push_back(person1);
  db.data.push_back(person2);
  db.data.push_back(person3);

  SECTION("Find person with the highest tenure (lowest ID)") {
    const Person &result = highest_tenure(&db);
    REQUIRE(result.id == 1);
    REQUIRE(result.name == "Alice");
    REQUIRE(result.year_of_birth == 1990);
  }

  SECTION("Empty database returns null_person") {
    Db empty_db;
    const Person &result = highest_tenure(&empty_db);
    REQUIRE(result.id == 0);
    REQUIRE(result.name == "");
    REQUIRE(result.year_of_birth == 0);
  }

  SECTION("Database with only one person") {
    Db single_db;
    single_db.data.push_back(person2);
    const Person &result = highest_tenure(&single_db);
    REQUIRE(result.id == 2);
    REQUIRE(result.name == "Bob");
    REQUIRE(result.year_of_birth == 1985);
  }
}

TEST_CASE("Youngest person tests") {
  Db db;
  Person person1{1, "Alice", 1990};
  Person person2{2, "Bob", 1985};
  Person person3{3, "Charlie", 2000};
  db.data.push_back(person1);
  db.data.push_back(person2);
  db.data.push_back(person3);

  SECTION("Find the youngest person") {
    const Person &result = youngest_person(&db);
    REQUIRE(result.id == 3);
    REQUIRE(result.name == "Charlie");
    REQUIRE(result.year_of_birth == 2000);
  }

  SECTION("Empty database returns null_person") {
    Db empty_db;
    const Person &result = youngest_person(&empty_db);
    REQUIRE(result.id == 0);
    REQUIRE(result.name == "");
    REQUIRE(result.year_of_birth == 0);
  }

  SECTION("Database with only one person") {
    Db single_db;
    single_db.data.push_back(person2);
    const Person &result = youngest_person(&single_db);
    REQUIRE(result.id == 2);
    REQUIRE(result.name == "Bob");
    REQUIRE(result.year_of_birth == 1985);
  }
}