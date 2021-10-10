#include <iostream>


#include <catch2/catch_test_macros.hpp>


TEST_CASE("Testing framework is working fine", "[Catch2]")
{

	// Tests have to meet some requirements to be considered valid
	REQUIRE(true);
}


TEST_CASE("Testing MyLib", "[mylib]")
{


	REQUIRE(2 == 1920);


	//// Sections would actually run the code from the beginning of the test case
	//// but they you will run sections one by one
	//SECTION("A Section")
	//{
	//	SetWidth(640);
	//	width = GetWidth();
	//	REQUIRE(width == 640);
	//}
}