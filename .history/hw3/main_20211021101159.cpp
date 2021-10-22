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
    auto start_election = Election;
    while(direct_ans != 'd' || direct_ans != 'r'){
        std::cout << "What kind of election should we have (direct(d) or representative(r), 0 to stop)?" <<std::endl;
        std::cin.get(direct_ans);
        if(direct_ans == 'd'){
            auto start_election = new Election();
        }else if(direct_ans == 'r'){
            start_election = new RepresentativeELection();
        }else{
            return 0;
        }
    }
    while(true){
        
        int turn = 0;
        while(!start_election->check_end() && turn < 10){
            turn ++;
        }
    }
    

    return 0;
}