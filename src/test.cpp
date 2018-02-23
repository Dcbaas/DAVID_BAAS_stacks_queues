#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"
#include <string>
#include <fstream>
#include <iostream>

TEST_CASE("Test BalancedSymbols", "[inner]"){
	std::string input = "()()(abc){}";

	CHECK(balancedSymbols(input) == true);	
}

TEST_CASE("Test Invalid Input BalSymbols", "[inner]"){
	std::string input = "{{})(((";

	CHECK_FALSE(balancedSymbols(input) == true);

}
//Test a java src file.
TEST_CASE("Test a file", "[inner]"){
	std::ifstream in{"TestText.txt"};
	std::string input = "Test";
	CHECK(input == "Test");		
	if(not in)
		std::perror("TestText.txt");
	else{
		in >> input;
	}

	CHECK_FALSE(input == "Test" );
	CHECK(balancedSymbols(input) == true);
}

TEST_CASE("Test iToP", "[inner]"){
	std::string input = "a+b*c+(d*e+f)*g";

	std::string output = iToP(input);
	CHECK(output == "abc*+de*f+g*+");

}

TEST_CASE("Test iTOP", "[inner]"){
  std::string input = "a/b+c+t";

  std::string output = iToP(input);
  std::cout << output << std::endl;
}
