#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"


/* TEST_CASE ( "Factorials are computed", "[factorial]") {
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
} */

 TEST_CASE ( "Constructor and getter functions are fine", "[Recangle]") {
  Point p1;
  p1.x = 1; p1.y = 1;
  Point p2;
  p2.x = 2; p2.y = 2;
  Point p3;
  p3.x = -1; p3.y = -1;
  Point p4;
  p4.x = -2; p4.y= 4;
  Rectangle rec0(p1,p1);
  Rectangle rec1(p1, p2);
  Rectangle rec2(p1, p3);
  Rectangle rec4(p4, p1);
  //constructor work
  //allow one point to create a rectangle
  REQUIRE( rec0.get_p1().x == p1.x); REQUIRE( rec0.get_p1().y == p1.y );
  REQUIRE( rec0.get_p2().x == p1.x); REQUIRE( rec0.get_p2().y == p1.y );
  //normal points
  REQUIRE( rec1.get_p1().x == p1.x); REQUIRE( rec1.get_p1().y == p1.y );
  REQUIRE( rec1.get_p2().x == p2.x); REQUIRE( rec1.get_p2().y == p2.y );
  //reverse order of poinr
  REQUIRE( rec2.get_p1().x == p3.x); REQUIRE( rec2.get_p1().y == p3.y );
  REQUIRE( rec2.get_p2().x == p1.x); REQUIRE( rec2.get_p2().y == p1.y );
} 

TEST_CASE("overlap function is fine") {
  Point p1;
  p1.x = 1;
  p1.y = 1;
  Point p2;
  p2.x = 2;
  p2.y = 2;
  Rectangle rec0(p1,p1);
  Rectangle rec1(p1, p2);
  //calculate width and height with positive number
  REQUIRE( rec1.GetWidth() == 1 );
  REQUIRE( rec1.GetHeight() == 1 );
  Point p3;
  p3.x = -1;
  p3.y = -1;
  Point p4;
  p4.x = 0;
  p4.y = -3;
  Rectangle *rec2 = new Rectangle(p3,p1);
  //calculate width and height for positive and negative
  REQUIRE( rec2->GetHeight() == 2 );
  REQUIRE( rec2->GetWidth() == 2 );
  Rectangle rec3(p4, p1);
  //calculate width and height mixed with 0
  REQUIRE(rec3.GetHeight() == 4);
  REQUIRE(rec3.GetWidth() == 1);
  Point p5;
  p5.x = -3;
  p5.y = -3;
  Rectangle rec4(p5,p3);
  REQUIRE(rec4.GetHeight() == 2);
  REQUIRE(rec4.GetWidth() == 2);
}

TEST_CASE("get width and height is fine") {
  Point p1;
  p1.x = 1; p1.y = 1;
  Point p2;
  p2.x = 2; p2.y = 2;
  Rectangle rec0(p1,p1);
  Rectangle rec1(p1, p2);
  Point p4;
  p4.x = 3; p4.y=3;
  Rectangle rec3(p1,p4);
  Point p5;
  p5.x = 0; p5.y=0;
  Rectangle rec4(p5,p1);
  Point p6;
  p6.x =8; p6.y = 8;
  Point p7;
  p6.x =9; p6.y = 9;
  Rectangle rec5(p6,p7);
  REQUIRE(rec3.Overlaps(rec1)); //two rectangle overlap
  REQUIRE(rec4.Overlaps(rec1)); //two rectangle overlap on one point
  REQUIRE(!rec5.Overlaps(rec1)); //no overlap
}

TEST_CASE ("calculate area is fine") {
  Point p1;
  p1.x = -1; p1.y = -1;
  Point p2;
  p2.x = 3; p2.y = 5;
  Rectangle rec1(p1,p2);
  REQUIRE(rec1.CalculateArea() == 24);
  p2.x = 0; p2.y = 0;
  Rectangle rec2(p1,p2);
  REQUIRE(rec2.CalculateArea() == 1);
}

TEST_CASE ("expand is fine") {
  Point p1;
  p1.x = -1; p1.y = -1;
  Point p2;
  p2.x = 3; p2.y = 5;
  Rectangle rec1(p1,p2);
  rec1.Expand();
  REQUIRE(rec1.GetWidth() == 6);
  REQUIRE(rec1.GetHeight() == 8);
  REQUIRE(rec1.CalculateArea() == 48);
}

TEST_CASE ("shrink is fine") {
  Point p1;
  p1.x = -1; p1.y = -1;
  Point p2;
  p2.x = 3; p2.y = 5;
  Rectangle rec1(p1,p2);
  rec1.Shrink();
  REQUIRE(rec1.GetWidth() == 2);
  REQUIRE(rec1.GetHeight() == 4);
  Rectangle rec2(p1,p1);
  rec1.Shrink();
  REQUIRE(rec1.CalculateArea() == 0);
}






