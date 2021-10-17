#include <iostream>
#include <random>
#include<map>
using namespace std;
 
int main( ){
    map<char,int> temp;
    temp['a'] = 4;
    temp['c'] = 9;
    temp['r'] = 7;
    temp['e'] = 1;
    cout << temp.rbegin()->second << endl;
    return 0;
}