//#include "catch.hpp"
#include<iostream>
#include<vector>
#include "Counter.h"


/* TEST_CASE ( "Factorials are computed", "[factorial]") {
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
} */

//TEST_CASE ( "default constructor, paramter constructor and get Count work fine", "[Counter]") {

  //std::vector<std::string> vec1= {"hello", "world", "vscode", "atom"};
  //Counter count1(vec1);
  //REQUIRE( !count1.Count());
  //REQUIRE( Factorial(3) == 6 );
//}
int main(){
    std::vector<int> vec1 = {1,2,3,4,5};
  Counter<int> count1(vec1);
  std::cout << count1.Count() << std::endl;
  std::cout << count1.Count(1) << std::endl;
    return 0;
}