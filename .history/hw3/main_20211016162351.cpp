#include<iostream>
#include<vector>
#include<map>
#include"ElectoralMap.h"
using namespace std;


int main(){
    ElectoralMap *firstmap = ElectoralMap::getDistrict();
    std::cout << firstmap << std::endl;
    return 0;
}