#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include<time.h>
#include<random>
#include"ElectoralMap.h"
using namespace std;


int main(){
   // srand(time(NULL));
    std::default_random_engine generator;
    ElectoralMap firstmap = ElectoralMap::getInstance();
    std::cout << firstmap << std::endl;
    Election first_election;
    
    while (true)
    {
        
    }
   
    
    return 0;
}