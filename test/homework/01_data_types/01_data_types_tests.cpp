#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "data_types.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test Multiply Numbers", "Should return 5 * num2 entered") 
{
	REQUIRE(multiply_numbers(10) == 50);
	REQUIRE(multiply_numbers(2) == 10);
}

