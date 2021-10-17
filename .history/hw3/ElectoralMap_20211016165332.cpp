#include<iostream>
#include<map>
#include<set>
#include<random>
#include"ElectoralMap.h"

#define num_district 3
#define num_enum 4

int Candidate::id = 0;

int ElectoralMap::count_district = 0;

Candidate::Candidate(){
    ;
}

Candidate::Candidate(party party_name, std::string candidate_name){
    id_candidate = id + 1;
    party_affiliation = party_name;
    name = candidate_name;
    id ++;
}

int Candidate::get_ids(){
    return id_candidate;
}

District::District(int given_id){
    default_random_engine engine;
    uniform_int_distribute<unsigned> range_random(0,9);
    for(enum party temp = party::one; temp <= party::none ; temp =  (party)(temp + 1)){
        map_party.insert(std::pair<party,int>(temp, range_random(engine)));
    }
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
        District *temp = new District(count_district);
        map.insert(std::pair<int, District>(count_district, *temp));
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

