#include <iostream>


#include <catch2/catch_test_macros.hpp>


TEST_CASE("Testing framework is working fine", "[Catch2]")
{

	REQUIRE(true);
}


TEST_CASE("Testing MyLib", "[mylib]")
{

	REQUIRE(2 == 1920);
}