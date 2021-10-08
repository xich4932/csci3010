#include <iostream>
#include <vector>
#include "Point.h"

/*
CSCI 3010, PE 1 example solution, Spring 2020
Felix Muzny
Two dimensional point with Distance and Translate methods.

Use Makefile to compile. "make" will produce executable "main". Run (on unix systems) with "./main"
*/

void print_points(Point & poi){
	for(unsigned int i = 0; i < poi.get_x().size(); i++){
		std::cout << poi.get_x()[i] << " ";
	} 
	std::cout << " , ";
	for(unsigned int i = 0; i < poi.get_y().size(); i++){
		std::cout << poi.get_y()[i] << " ";
	}
}


int main(int argc, char **argv){
	std::vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);

	Point p1(4);
	Point p2(vec1);

	std::cout << "p1 is: ( ";
	print_points(p1);
	std::cout  <<  ")" << std::endl;

	std::cout << "p2 is: ( ";
	print_points(p2);
	std::cout  <<  ")" << std::endl;
	
	std::vector<int> vec2;
	vec2.push_back(5);
	vec2.push_back(6);
	vec2.push_back(7);
	vec2.push_back(8);
	Point p3(vec2);

	std::cout << "p3 is: ( ";
	print_points(p3);
	std::cout  <<  ")" << std::endl;
/* 
	Point p3(1, 2);
	std::cout << "p3 is: (" << p3.get_x() << ", ";
	std::cout << p3.get_y() << ")" << std::endl;
	*/
	std::cout << "dist p1 & p2: " << p1.Distance(p2) << std::endl;
	std::cout << "dist p1 & p3: " << p1.Distance(p3) << std::endl;
	std::cout << "dist p2 & p3: " << p2.Distance(p3) << std::endl;

    p1.Translate(10);
	std::cout << "p1 after +10 translation is: ( " ;
	//<< p1.get_x() << ", ";
	print_points(p1);
	std::cout <<   ")" << std::endl;
	std::cout << "dist p1 & p2: " << p1.Distance(p2) << std::endl;
	std::cout << "dist p1 & p3: " << p1.Distance(p3) << std::endl;
    p1.Translate(-73);
	std::cout << "p1 after -73 translation is: ( " ;
	//<< p1.get_x() << ", ";
	print_points(p1);
	std::cout <<   ")" << std::endl;
	std::cout << "dist p1 & p2: " << p1.Distance(p2) << std::endl;
	std::cout << "dist p1 & p3: " << p1.Distance(p3) << std::endl;

	return 0;
}
