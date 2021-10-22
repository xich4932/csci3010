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
    //auto start_election = Election;
    int turn = 0;
    std::map<int, District*> main_map = ElectoralMap::getInstance().get_map();
    while(direct_ans != 'd' || direct_ans != 'r'){
        std::cout << "What kind of election should we have (direct(d) or representative(r), 0 to stop)?" <<std::endl;
        std::cin.get(direct_ans);
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(direct_ans == 'd'){
            auto start_election = new Election();
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
            break;
        }else if(direct_ans == 'r'){
            auto start_election = new RepresentativeELection();

        }else{
            return 0;
        }
    }
    

    return 0;
}