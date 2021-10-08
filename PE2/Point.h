#ifndef _POINT_H_ // header guard
#define _POINT_H_
#include <vector>
/*
CSCI 3010, PE 1 example solution, Spring 2020
Felix Muzny
Two dimensional point with Distance and Translate methods.
*/

class Point {
public: 
    Point(const int); // 0-argument constructor
	Point(const std::vector<int>);  // constructor
	
	std::vector<int> get_x() const { return x_; }  // inline member function
	std::vector<int> get_y() const { return y_; }  // inline member function

    void set_x(const std::vector<int> &x);   // inline member function
	void set_y(const std::vector<int> &y);  // inline member function

	double Distance(const Point &other) const;  // member function

	void Translate(const int &amt);  // member function


 private:
  std::vector<int> x_;  // data member, attribute, field
  std::vector<int> y_;  // data member, attribute, field

};  // class Point

#endif  // _POINT_H_

