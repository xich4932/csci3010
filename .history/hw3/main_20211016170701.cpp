#include<iostream>
#include<vector>
#include<map>
#include"ElectoralMap.h"
using namespace std;


int main(){
    srand((unsigned int)TIME(NULL));
    ElectoralMap firstmap = ElectoralMap::getInstance();
    std::cout << firstmap << std::endl;
    return 0;
}