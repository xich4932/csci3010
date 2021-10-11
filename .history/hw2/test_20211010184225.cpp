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
  //REQUIRE( !count1.Count());
  //std::cout <<"count"<< count1<< std::endl;
  REQUIRE( !count1.Count());
  temp_struct temp1;
  temp_struct temp2;
  temp_struct temp3;
  temp1.a = 1; temp1.b = 3; temp1.c = "jhe";
  temp2.a = 2; temp2.b = 3; temp2.c = "jhdafdse";
  temp3.a = 1; temp3.b = 3; temp3.c = "jhsknfkfe";
  std::vector<temp_struct> vec1= {temp1, temp2, temp3};
  Counter<temp_struct> count2(vec2);
  REQUIRE(!count2.Count());
  
}
