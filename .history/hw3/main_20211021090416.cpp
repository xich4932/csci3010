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
    char direct_ans = 'a';
    while(direct_ans != 'd' || direct_ans != 'r'){
        std::cout << "What kind of election should we have (direct(d) or representative(r), 0 to stop)?" <<std::endl;
        std::com(std::cin, direct_ans);
        if(std::stoi(direct_ans) == 'd'){
            auto start_eletion = Election();
        }else if(std::stoi(direct_ans) == 'r'){
            auto start_eletion = RepresentativeELection();
        }else{
            return 0;
        }
    }
    
    while(start)

    return 0;
}