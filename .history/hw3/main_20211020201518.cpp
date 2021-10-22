#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include<time.h>
#include<random>
#include"ElectoralMap.h"
using namespace std;


template<typename T>
std::vector<T> Election_way;

int main(){
   // srand((unsigned int)time(NULL));
   // std::default_random_engine generator;
   // ElectoralMap firstmap = ElectoralMap::getInstance();
   // std::cout << firstmap << std::endl;
   // Election first_election;
    auto ele = new Election();
    ele->test();

    //ele.begin()->test();
   //ele1.begin()->test();

    return 0;
}