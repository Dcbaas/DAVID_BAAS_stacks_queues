#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "functions.h"
#include <string>


TEST_CASE("Test BalancedSymbols", "[inner]"){
	std::string input = "()()(abc){}";

	CHECK(balancedSymbols(input) == true);	
}

TEST_CASE("Test Invalid Input BalSymbols", "[inner]"){
	std::string input = "{{})(((";

	CHECK_FALSE(balancedSymbols(input) == true);
}
