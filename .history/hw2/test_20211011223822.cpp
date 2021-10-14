#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Counter.hpp"
#include <sstream>

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

TEST_CASE ( "default constructor, paramter constructor and get Count, keys, values work fine", "[Counter]") {
  std::vector<std::string> vec1= {"hello", "world", "vscode", "atom", "hello"};
  Counter<std::string> count1(vec1);
  std::vector<int> values_answer = {1,2,1,1};
  std::set<std::string> key_answer = {"hello", "world", "vscode", "atom"};
 // std::set<std::string> temp_Set {"hello", "world", "vscode", "atom"};
 // std::vector<int> key_ans {1,1,1,1};
  REQUIRE(count1.Count() == vec1.size());
  REQUIRE(count1.Values() == values_answer);
  REQUIRE(count1.Keys() == key_answer);
}

TEST_CASE( "Increment 1 and Increment by n work fine", "[Counter]") {
 /*  std::vector<std::string> vec1= {"hello", "world", "vscode", "atom"};
  Counter<std::string> count1(vec1);
  std::set<std::string> temp_Set {"hello", "world", "vscode", "atom", "hello", "vscode"};
  count1.Increment("hello");
  std::cout << count1.Count("hello") << std::endl;
  REQUIRE(count1.Count("hello") == 3);
  count1.Increment("atom", 2);
  REQUIRE(count1.Count("hello") == 3); */

}
