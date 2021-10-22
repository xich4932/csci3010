#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include<time.h>
#include<random>
#include"ElectoralMap.h"
using namespace std;


int direct_election(){
    std::map<int, District*> main_map = ElectoralMap::getInstance().get_map();
    auto start_election = new Election("do_nothing");
    Candidate *now_candidate = start_election->who_campaigning();
    std::cout << ElectoralMap::getInstance() << std::endl;
    while(now_candidate != nullptr){
        //if(now_candidate == nullptr) break;
        int disrict_num = start_election->where_campaigning();
        if(disrict_num == -1 ){
            now_candidate = start_election->who_campaigning();
            continue;
        }
        start_election->converting(main_map[disrict_num], now_candidate);
        std::cout << ElectoralMap::getInstance() << std::endl;
        
        //std::cout << ElectoralMap::getInstance() << std::endl;
    }
    start_election->voting();
    start_election->report_win();
    start_election->clear();
    return 1;
}

int representative_election(){
    std::map<int, District*> main_map = ElectoralMap::getInstance().get_map();
    auto start_election = new RepresentativeELection();
    Candidate *now_candidate = start_election->who_campaigning();
    std::cout << ElectoralMap::getInstance() << std::endl;
    while(now_candidate != nullptr){
        //if(now_candidate == nullptr) break;
        int disrict_num = start_election->where_campaigning();
        if(disrict_num == -1 ){
            now_candidate = start_election->who_campaigning();
            continue;
        }
        start_election->converting(main_map[disrict_num], now_candidate);
        std::cout << ElectoralMap::getInstance() << std::endl;
        
        //std::cout << ElectoralMap::getInstance() << std::endl;
    }
    start_election->voting();
    start_election->report_win();
    start_election->clear();
    return 1;
}


int main(){
    int is_direct;
    char direct_ans = 'a';
    //auto start_election = Election;
    int turn = 0;
    int end = 0;
    while((direct_ans != 'd' || direct_ans != 'r') || end ){
        std::cout << "What kind of election should we have (direct(d) or representative(r), 0 to stop)?" <<std::endl;
        std::cin.get(direct_ans);
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(direct_ans == 'd'){
            end = direct_election();
        }else if(direct_ans == 'r'){
            end = representative_election();
        }else if(direct_ans == '0'){
            break;
        }else{
            std::cout <<"invalid input" << std::endl;
        }
    }
    

    return 0;
}