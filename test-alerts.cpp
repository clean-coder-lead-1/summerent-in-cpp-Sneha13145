#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
  REQUIRE(inferBreach(12, 10, 30) == NORMAL);
  REQUIRE(inferBreach(12, 10, 45) == NORMAL);
  REQUIRE(inferBreach(12, 25, 45) == TOO_LOW);
  REQUIRE(inferBreach(50, 25, 45) == TOO_HIGH);
  REQUIRE(inferBreach(20, 0, 45) == NORMAL);
  REQUIRE(inferBreach(40, 0, 35) == TOO_HIGH);
  REQUIRE(inferBreach(5, 12, 35) == TOO_LOW);
}

