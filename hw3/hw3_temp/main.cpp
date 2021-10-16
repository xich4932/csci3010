#include<iostream>
#include"map_district.h"

int main(){
    ElectoralMap map_ = ElectoralMap::getInstanceMap();
    std::cout << map_ << std::endl;

    return 0;
}