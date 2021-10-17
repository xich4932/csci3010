#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include<time.h>
#include"ElectoralMap.h"
using namespace std;


int main(){
    srand(time(NULL));
    ElectoralMap firstmap = ElectoralMap::getInstance();
    std::cout << firstmap << std::endl;
    return 0;
}