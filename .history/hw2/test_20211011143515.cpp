#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Counter.hpp"


/* TEST_CASE ( "Factorials are computed", "[factorial]") {
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
} */
/* struct temp_struct{
    int a, b;
    std::string c;
    bool operator <(const temp_struct& comp){
        if(this->a > comp.a) return true;
        if(this->b > comp.b) return true;
        if(this->c.compare(comp.c)) return true;
        return false;
    } 
    bool operator >(const temp_struct& comp){
        if(this->a > comp.a) return true;
        if(this->b > comp.b) return true;
        if(this->c.compare(comp.c)) return true;
        return false;
    } 
}; */

TEST_CASE ( "default constructor, paramter constructor and get Count work fine", "[Counter]") {

  std::vector<std::string> vec1= {"hello", "world", "vscode", "atom"};
  Counter<std::string> count1(vec1);
  REQUIRE( !count1.Count());

  std::vector<float> vec2= {3.4,6.7,44.5,900,120,3.4};
  Counter<float> count2(vec2);
  REQUIRE( !count2.Count());
  
  
}
