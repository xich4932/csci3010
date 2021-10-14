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
  std::set<std::string> temp_Set {"hello", "world", "vscode", "atom"};
  std::vector<int> key_ans {1,1,1,1};
  REQUIRE(count1.Keys() == temp_Set);
  REQUIRE( count1.Count() == vec1.size());
  REQUIRE(count1.Values() == key_ans);
  //REQUIRE( count1.Count() == vec1.size());
  count1.Increment("hello");
  REQUIRE( count1.Count("hello") == 2);
  count1.Increment("hello", 5);
  REQUIRE( count1.Count("hello") == 7);
  count1.Dncrement("vscode");
  REQUIRE( count1.Count("vscode") == 0);
  count1.Dncrement("hello", 3 );
  REQUIRE( count1.Count("hello") == 4);


  std::vector<float> vec2= {3.4,6.7,44.5,900,120,5};
  Counter<float> count2(vec2);
  REQUIRE( count2.Count() == vec2.size());
  std::cout << count2.Count()<< std::endl;

  count2.Increment(3.4);
  REQUIRE( count2.Count(3.4) == 2);
  count2.Increment(3.4, 5);
  REQUIRE( count2.Count(3.4) == 7);
  count2.Dncrement(6.7);
  REQUIRE( count2.Count(6.7) == 0);
  count2.Dncrement(3.4, 3 );
  REQUIRE( count2.Count(3.4) == 4);


}
