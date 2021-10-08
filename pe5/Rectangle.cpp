//name: Xiang Chen
//bugs:
//    p1 is not necessary be the left lower Point
//    overlap on one point is not recognized
//    a poing can still shrink
//


#include<iostream>
#include "Rectangle.h"

// p1 is the lower left corner
  // p2 is the upper right corner
  // if you find that not following this guidelines breaks this class, that
  // would be considered a bug
  Rectangle::Rectangle(Point p1, Point p2){
      if(p1.x <= p2.x){
          p1_ = p1;
          p2_ = p2;
      }else{
          p1_ = p2;
          p2_ = p1;
      }
  }

  // get the width of the rectangle  
  // between p1.x and p2.x
  int Rectangle::GetWidth(){
      return p2_.x - p1_.x;
  }
  // get the height of the rectangle
  // between p2.y and p2.y
  int Rectangle::GetHeight(){
      return p2_.y - p1_.y;
  }

  // returns true iff this rectangle shares any points with the other one
  bool Rectangle::Overlaps(Rectangle& other){
      if(this->p1_.x > other.get_p2().x || other.get_p1().x > this->p2_.x) return false;
      if(this->p1_.y > other.get_p2().y || other.get_p1().y > this->p2_.y) return false;
      return true;
  }

  // returns the area of this rectangle
  int Rectangle::CalculateArea(){
     // int area = 
      return this->GetHeight() * this->GetWidth();
     // return area;
  }

  // moves the bottom left coordinate down one and to the left one
  // moves the upper right coordinate up one and to the right one
  void Rectangle::Expand(){
    p1_.x --;
    p1_.y --;
    p2_.x ++;
    p2_.y ++;
     
  }

  // moves the bottom left coordinate up one and to the right one
  // moves the upper right coordinate down one and to the left one
  void Rectangle::Shrink(){
      //when rectangle is a point, do nothing
       if(p1_.x == p2_.x){
          return;
      }else{
          p1_.x ++;
          p1_.y ++;
          p2_.x --;
          p2_.y --;
      }
  }