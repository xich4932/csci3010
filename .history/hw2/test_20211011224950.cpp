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

TEST_CASE ( "default constructor, paramter constructor and Keys,Values work fine", "[Counter]") {
  std::vector<std::string> vec1= {"hello", "world", "vscode", "atom", "hello"};
  Counter<std::string> count1(vec1);
  std::vector<int> values_answer1 = {1,2,1,1};
  std::set<std::string> key_answer1 = {"hello", "world", "vscode", "atom"};
 // REQUIRE(count1.Count() == vec1.size());
  REQUIRE(count1.Values() == values_answer1);
  REQUIRE(count1.Keys() == key_answer1);
  
  std::vector<int> vec2= {1,2,3,4,4,4};
  Counter<int> count2(vec2);
  std::vector<int> values_answer2 = {1,1,1,3};
  std::set<int> key_answer2 = {1,2,3,4};
//  REQUIRE(count2.Count() == vec2.size());
  REQUIRE(count2.Values() == values_answer2);
  REQUIRE(count2.Keys() == key_answer2);
}

TEST_CASE ( "count, count by key work fine", "[Counter]") {
  std::vector<std::string> vec1= {"hello", "world", "vscode", "atom", "hello"};
  Counter<std::string> count1(vec1);
  
  REQUIRE(count1.Count() == vec1.size());
  REQUIRE(count1.Count("hello") == 2);
  
  std::vector<int> vec2= {1,2,3,4,4,4};
  Counter<int> count2(vec2);

  REQUIRE(count2.Count(4) == 3);
  REQUIRE(count2.Count() == vec2.size());
}


TEST_CASE( "Increment 1 and Increment by n work fine", "[Counter]") {
 std::vector<std::string> vec1= {"hello", "world", "vscode", "atom", "hello"};
  Counter<std::string> count1(vec1);
  count1.Increment("atom");
  REQUIRE(count1.Count("atom") == 2);
  count1.Increment("atom" ,2);
  REQUIRE(count1.Count("atom") == 4);
  
  std::vector<int> vec2= {1,2,3,4,4,4};
  Counter<int> count2(vec2);

  count2.Increment(1);
  REQUIRE(count2.Count(1) == 2);
  count2.Increment(3,2);
  REQUIRE(count2.Count(3) == 3);
}

TEST_CASE( "Decrement 1 and Decrement by n work fine", "[Counter]") {
 std::vector<std::string> vec1= {"hello", "world", "vscode", "atom", "hello"};
  Counter<std::string> count1(vec1);
  count1.Decrement("atom");
  REQUIRE(count1.Count("atom") == 0);
  count1.Decrement("hello" ,2);
  REQUIRE(count1.Count("hello") == 0);
  
  std::vector<int> vec2= {1,2,3,4,4,4};
  Counter<int> count2(vec2);

  count2.Decrement(4);
  REQUIRE(count2.Count(4) == 2);
  count2.Decrement(4,2);
  REQUIRE(count2.Count(4) == 0);
}

TEST_CASE( "overload ostream<< ", "[Counter]") {
 std::vector<std::string> vec1= {"hello", "world", "vscode", "atom", "hello"};
  Counter<std::string> count1(vec1);
  stringstream ss;
  ss << count1;
  std::string = str1;
  ss >> str1;
  REQUIRE(str1 == "{hello:2,world:1,vscode:1,atom:1,}\n");
  
  std::vector<int> vec2= {1,2,3,4,4,4};
  Counter<int> count2(vec2);
  ss << count2;
  std::string = str2;
  ss >> str2;
  REQUIRE(str2 == "{1:1,2:1,3:1,4:3,}\n");
}
