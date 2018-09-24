// According to Mozilla's calculator test suite
// https://mozilla.github.io/calculator/test/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cmath>

#include "reverse_polish.h"

TEST_CASE("Addition", "[addition]") {
    REQUIRE(ReversePolish::evaluate("1500 + 2000") == 3500);
    REQUIRE(ReversePolish::evaluate("-1 + 1.0000") == 0);
    REQUIRE(ReversePolish::evaluate("10.1 + 2") == 12.1);
    REQUIRE(ReversePolish::evaluate("10 + 9.9999") == 19.9999);
    REQUIRE(ReversePolish::evaluate("34.999 + 1.0") == 35.999);
    REQUIRE(ReversePolish::evaluate("-5 + 0") == -5);
    REQUIRE(ReversePolish::evaluate("0 + 5") == 5);
    REQUIRE(ReversePolish::evaluate("-5 + 5") == 0);
    REQUIRE(ReversePolish::evaluate("300000000 + 900000000") == 1.2 * pow(10, 9));
    REQUIRE(ReversePolish::evaluate("900000000 + 900000000") == 1.8 * pow(10, 9));
    REQUIRE(ReversePolish::evaluate("999999999 + 1 ") == 1.0 * pow(10, 9));
    REQUIRE(ReversePolish::evaluate("-1987.50 + 1987") == -0.5);
    REQUIRE(ReversePolish::evaluate("-1987.50 + 1987") == -0.5);
    REQUIRE(ReversePolish::evaluate(std::to_string(ReversePolish::evaluate("1500 - 2000")) + " + 500") == 0);
    REQUIRE(ReversePolish::evaluate(std::to_string(ReversePolish::evaluate("6 * 2")) + " + 8") == 20);
    REQUIRE(ReversePolish::evaluate(std::to_string(ReversePolish::evaluate("1500 - 2000")) + " + 0.25") == -499.75);
    REQUIRE(ReversePolish::evaluate(std::to_string(ReversePolish::evaluate("1500 - 2000")) + " + 1.23456789") == (1500 - 2000) + 1.23456789);
    REQUIRE(ReversePolish::evaluate(std::to_string(ReversePolish::evaluate("1500 - 2000")) + " + 123456789") == 123456289);
}
