#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include<time.h>
#include<random>
#include"ElectoralMap.h"
using namespace std;



int main(){
    int is_direct;
    std::string direct_ans;
    std::cout << "What kind of election should we have (direct(d) or representative(r), 0 to stop)?" <<std::endl;
    getline(std::cin, direct_ans);
    if(std::stoi(direct_ans) == 'd'){
        auto start_eletion = Election();
    }else{
        auto start_eletion = RepresentativeELection();
    }else{
        return;
    }

    return 0;
}