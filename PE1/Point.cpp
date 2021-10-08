#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;
//intilize point default
Point::Point(){
    x = 0;
    y = 0;
}
//initlize point with given parameters
Point::Point(int c,int cc){
    x = c;
    y = cc;
}

//set the x-coordinate of point
void Point::setter_x(int z){
    x = z;
}
//get the x-coordinate from outside
int Point::getter_x(void){
    return x;
}

//set the y-coordinate of point
void Point::setter_y(int z){
    y =z;
}

//get the y-coordinate of point
int Point::getter_y(void){
    return y;
}

//calculate the distance between two points
double Point::Distance(Point* temp_point){
    int temp_x = temp_point->getter_x();//get x of second point
    int temp_y = temp_point->getter_y();//get y of second point
    return sqrt(pow(abs(x-temp_x), 2)+ pow(abs(y-temp_y), 2)); //calculate the distance 
}

//move the point in given distance
void Point::Translate(int d){
    x += d;
    y += d;
}

