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
int Election::party_one_active = 0;
int Election::party_two_active = 0;
int Election::party_three_active = 0;
int Candidate::party_one_candidate = 0;
int Candidate::party_two_candidate = 0;
int Candidate::party_three_candidate = 0;
int Election::active_party[3] = {0};

Candidate::Candidate(){
    ;
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
                //if(stringifyEnum(party_name) == "party one") party_one_active ++;
                //if(stringifyEnum(party_name) == "party two") party_two_active ++;
                //if(stringifyEnum(party_name) == "party three") party_three_active ++;
                active_party[party_name] ++;
                continue;
            }
            if(choice == "n") break;
            continue; //when user input other choice, keep asking
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

/* void Election::voting(){
    int sum_party_one = 0;
    int sum_party_two = 0;
    int sum_party_three = 0;
    ElectoralMap vote_map = ElectoralMap::getInstance();
    std::map<int, District> vote_district = vote_map.get_map();
    for(int d = 0; d < num_district; d++){
        for(enum party party_name = party::one; party_name <= party::none; party_name = (party)(party_name+1)){
            if(Candidate::party_one_candidate){
                sum_party_one += vote_district[d].get_map_party(party_name);
                
            }else{

            }
        }
    }
} */

