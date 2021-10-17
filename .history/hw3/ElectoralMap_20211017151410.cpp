#include<iostream>
#include<map>
#include<set>
#include<random>
#include<time.h>
#include<stdlib.h>
#include"ElectoralMap.h"

#define num_district 3
#define num_enum 4

//int Candidate::id = 0;

int ElectoralMap::count_district = 0;

int Election::ids = 0;
std::vector<int> Election::party_one_active = {};
std::vector<int> Election::party_two_active = {};
std::vector<int> Election::party_three_active = {};
//std::vector<int> Election::stored_idx_each;
int Candidate::party_one_candidate = 0;
int Candidate::party_two_candidate = 0;
int Candidate::party_three_candidate = 0;
int Election::active_party[3] = {0};

Candidate::Candidate(){
    ;
}
void Candidate::plus_vote(int count){
    vote += count;
}

Candidate::Candidate(int given_id, party party_name, std::string candidate_name){
    id_candidate = given_id;
    party_affiliation = party_name;
    name = candidate_name;
}

int Candidate::get_ids(){
    return id_candidate;
}

District::District(int given_id){
  // std::default_random_engine engine;
  //  std::uniform_int_distribution<unsigned> range_random(0,9);
    for(enum party temp = party::one; temp <= party::none ; temp =  (party)(temp + 1)){
        map_party.insert(std::pair<party,int>(temp, rand()%9));
        //map_party.insert(std::pair<party,int>(temp, range_random(engine)));
    }
    std::uniform_int_distribution<unsigned> range_random1(5,29);
    square_mile = rand()%25+5;
    id = given_id;
}

party District::get_max(){
    enum party ret;
    int max = 0;
    int old_ = max;
    for(auto i = map_party.begin(); i != map_party.end(); i++){
        max = std::max(max, i->second);
        if(old_ != max){
            old_ = max;
            ret = i->first;
        }
    }
    return ret;
}

void District::change_party(party cur_party, int num){
    //debug: assume changing number is always smaller than the actual number
    int sum_in_party = 0;
    for(auto i = map_party.begin(); i != map_party.end(); i++){
        if(i->first != party::none) sum_in_party += i->second;
    }
    double success = ((map_party[cur_party]+1)*2/sum_in_party)*(((map_party[cur_party]+1)*2)/(square_mile));
    success = std::min(100.00, success);
    double extra_success = success * 0.1;

};

ElectoralMap::ElectoralMap(){
    for(int i = 0; i < num_district; i++){
        District *temp = new District(count_district+1);
        map.insert(std::pair<int, District>(count_district+1, *temp));
        count_district ++;
    }

}

std::string stringifyEnum(party one){
    const std::string str[4] = {"party one", "party two", "party three", "party none"};
    for(enum party temp = party::one; temp <= party::none; temp = (party)(temp+1)){
        if(temp == one) return str[(int)temp];
    }
    return "";
}


std::ostream & operator<<(std::ostream& os, District print_district){
    std::cout << "district: "<< print_district.id <<":"<< std::endl;
    std::cout << "area: "<< print_district.square_mile << std::endl;
    for(enum party print_enum = party::one; print_enum <= party::none; print_enum = (party)(print_enum+1)){
        std::cout << stringifyEnum(print_enum) <<": "<< print_district.map_party[print_enum] <<" ";
    }
    std::cout << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream& os, ElectoralMap print_map){
    for(auto i = print_map.map.begin(); i != print_map.map.end(); i++){
        std::cout << i->second << std::endl;
    }
    return os;
}

void ask_name(std::string &name){
    std::cout << "What is their name?"<<std::endl;
    getline(std::cin, name);
}

void Election::register_candidate(){
    std::string choice;
    for(enum party party_name; party_name <= party::none; party_name = (party)(party_name+1)){
        while(1){
            std::cout <<"Do you want to register a candidate for "<< stringifyEnum(party_name) <<" (y or n)?"<<std::endl;
            getline(std::cin, choice);
            if(choice == "y"){
                std::string candidate_name;
                ask_name(candidate_name);
                Candidate temp(ids+1, party_name, candidate_name);
                candidate_.push_back(temp);
                ids ++;
                if(party_name == 0){
                    party_one_active.push_back(ids);
                }else if(party_name == 1){
                    party_two_active.push_back(ids);
                }else if(party_name == 2){
                    party_three_active.push_back(ids);
                }
                active_party[party_name] ++;
                continue;
            }
            if(choice == "n") break;
            //continue; //when user input other choice, keep asking
        }
    }
}

Candidate* Election::go_campaigning(){
    std::string choice;
    while ((1))
    {
        std::cout << "Which candidate is campaigning (id) (0 to stop) ?" <<std::endl;
        getline(std::cin, choice);
        if(choice == "0") break;
        if(stoi(choice) >= ids) std::cout << "index out of range"<< std::endl;
        break; //jump out of loop if id is availble
    }
    int campaign_id = stoi(choice);
    std::cout << ElectoralMap::getInstance << std::endl;
    while ((1))
    {
        std::cout << "Where is this candidate campaigning (id) (0 to stop) ?" <<std::endl;
        getline(std::cin, choice);
        if(choice == "0") break;
        if(stoi(choice) >= num_district) std::cout << "index out of range"<< std::endl;
        break; //jump out of loop if id is availble
    }
    int campaign_district = stoi(choice);
    std::cout << candidate_[campaign_id].get_name() << " is campaigning in district "<< campaign_district << std::endl;
}

void Election::voting(){
    std::map<party, int> sum_each_party;
    sum_each_party.insert(std::pair<party, int> (party::one, 0));
    sum_each_party.insert(std::pair<party, int> (party::two, 0));
    sum_each_party.insert(std::pair<party, int> (party::three,0));
    std::vector<std::vector<int>> store_id_each = {party_one_active, party_two_active, party_three_active};
    ElectoralMap vote_map = ElectoralMap::getInstance();
    std::map<int, District> vote_district = vote_map.get_map();
    for(int d = 0; d < num_district; d++){
        for(enum party party_name = party::one; party_name <= party::none; party_name = (party)(party_name+1)){
            if(active_party[party_name]){
                int get_voted = rand()%store_id_each[party_name].size();
                candidate_[party_one_active[get_voted]].plus_vote(vote_district[d].get_constituent(party_name));
                //sum_each_party[party_name] += vote_district[d].get_constituent(party_name);
            }else if(party_name == party::none){
                party none_cantitutent = vote_district[d].get_max();
                //if none constitutent is 9, should i count them as one or do random choice for each person
                if(party_name == party::none){ //the majority constituent is still none
                    ;
                }else if(!active_party[none_cantitutent] || (!active_party[party_name] && party_name != party::none)){ // when the majority constituent has no candidate
                    int sum = 0;
                    for(int i = 0; i < 3; i++) sum += active_party[i];
                    int get_voted = rand()%sum;
                    candidate_[get_voted].plus_vote(vote_district[d].get_constituent(party_name));
                }
            }else{
                int sum = 0;
                for(int i = 0; i < 3; i++) sum += active_party[i];
                int get_voted = rand()%sum;
                candidate_[get_voted].plus_vote(vote_district[d].get_constituent(party_name));
            }
        }
    }
}

void Representative::voting(){
    
}

