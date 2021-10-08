#include <iostream>
#include "Point.h"
using namespace std;


void printer(Point *arr[]){
    cout << "the current coordination of all 3 points is "<<endl;
    cout << "point1 x: " << arr[0]->getter_x() << " y: " << arr[0]->getter_y() << endl;
    cout << "point2 x: " << arr[1]->getter_x() << " y: " << arr[1]->getter_y() << endl;
    cout << "point3 x: " << arr[2]->getter_x() << " y: " << arr[2]->getter_y() << endl;

    cout << "the distance between poin1 and point2 is " << arr[0]->Distance(arr[1]) << endl;
    cout << "the distance between poin1 and point3 is " << arr[0]->Distance(arr[2]) << endl;
    cout << "the distance between poin2 and point3 is " << arr[1]->Distance(arr[2]) << endl;
}


int main(void){
    Point *point1 = new Point();
    Point *point2 = new Point(3,3);
    Point *point3 = new Point(10,10);
    Point *arr[] = {point1, point2, point3};
    //print the initial 3 points info
    printer(arr);
    cout << "---------------------------------------------"<<endl;
    //let point1 move +11, print updated info
    point1->Translate(11);
    printer(arr);
    cout << "---------------------------------------------"<<endl;
    //let point1 move -4, print updated info
    point1->Translate(-4);
    printer(arr);
    delete point3;
    delete point2;
    delete point1;
}