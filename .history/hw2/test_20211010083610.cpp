#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Counter.hpp"


/* TEST_CASE ( "Factorials are computed", "[factorial]") {
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
} */
struct temp_struct{
    int a, b;
    std::string c;
};

TEST_CASE ( "default constructor, paramter constructor and get Count work fine", "[Counter]") {

  std::vector<std::string> vec1= {"hello", "world", "vscode", "atom"};
  Counter<std::string> count1(vec1);
  REQUIRE( !count1.Count());
  
  
  temp_struct temp1;
  temp1.a = 1; temp1.b = 1; temp1.c="hh";
  temp_struct temp2;
  temp1.a = 2; temp1.b = 2; temp2.c="sda";
  std::vector<temp_struct> vec2 = {temp1, temp2};
 // vec2.push_back(temp1);
  //vec2.push_back(temp2);
  Counter<temp_struct> count2(vec2);
  std::cout << count2.Count() << std::endl;
  //REQUIRE( !count2.Count());
  //REQUIRE( Factorial(3) == 6 );
}
