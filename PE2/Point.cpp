#include <cmath>
#include <iostream>
#include "Point.h"

/*
CSCI 3010, PE 1 example solution, Spring 2020
Felix Muzny
Two dimensional point with Distance and Translate methods.
*/

/**
  Creates a new Point object with coordinates (0, 0)
*/
Point::Point(int n) {
  for(int i = 0; i < n; i++){
    x_.push_back(0); //assume that x and y are same size
    y_.push_back(0);
  }
}

/**
  Creates a new Point object with coordinates x and y
  @param x int x coordinate
  @param y int y coordinate
  let x and y have same size
*/

Point::Point(std::vector<int> vec) {
  for(unsigned int i = 0; i < vec.size(); i++){
    x_.push_back(vec[i]); //let x and y share same value
    y_.push_back(vec[i]);
  }
}


/* set vector of x */
/* allow reset all the value of x coordinate */
void Point::set_x(const std::vector<int> &x) { 
    for(unsigned int i = 0; i < x.size(); i++){
      x_.push_back(x[i]);
    }
}


/* set vector of y */
/* allow reset all the value of y coordinate */
void Point::set_y(const std::vector<int> &y) { 
    for(unsigned int i = 0; i < y.size(); i++){
      y_.push_back(y[i]);
    }
}

/**
  Calculates the distance between this point and another Point.
  @param other Point object to calculate the distance to
*/
double Point::Distance(const Point &other) const {
  // We can access p's x_ and y_ variables either through the
  // get_x(), get_y() accessor functions, or the x_, y_ private
  // member variables directly, since we're in a member function of
  // the same class.
  double distance = 0;
  std::vector<int> vec_x = other.get_x(); // store all x value
  std::vector<int> vec_y = other.get_y(); //store all y value
  if(vec_y.size() != y_.size()){ // if given point is not same dimention, quit
    std::cout <<"points are not same dimention, can't calculate distance"<< std::endl;
    return -1;
  }
  //double distance2 = 0;
  for(unsigned int i = 0; i < x_.size(); i++){
    distance += (x_[i] - vec_x[i]) * (x_[i] - vec_x[i]);
    distance += (y_[i] - vec_y[i]) * (y_[i] - vec_y[i]);
  }
  ;
  
  return sqrt(distance);
}

/**
  Moves this Point's coordinates by the amount given.
  @param amt int amount by which to move the coordinates of this Point.
*/
void Point::Translate(const int &amt) {
  for(unsigned int i = 0; i < x_.size(); i++){
    x_[i] += amt; 
    y_[i] += amt;
  }
}
