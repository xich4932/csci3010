#include<iostream>
#include<map>
#include<set>
#include<time.h>
#include<stdlib.h>
#include"ElectoralMap.h"

#define num_district 3

int Candidate::id = 0;
int Candidate::arr_party_active = {0,0,0,0};

int ElectoralMap::count_district = 0;

Candidate::Candidate(){
    ;
}

Candidate::Candidate(party party_name, std::string candidate_name){
    id_candidate = id + 1;
    party_affiliation = party_name;
    name = candidate_name;
    id ++;
    if(party_name == party::one) party_one_active++;
    if(party_name == party::two) party_two_active++;
    if(party_name == party::three) party_three_active++;
}

int Candidate::get_ids(){
    return id_candidate;
}

District::District(int given_id){
    srand((unsigned int)(time(NULL)));
    for(enum party temp = party::one; temp < party::none ; (enum)(temp++)){
        if()
    }
    if(Candidate::party_one_active){
        map_party.insert(std::pair<party, int>(party::one, rand()%10));
    }
    if(Candidate::party_two_active){
        map_party.insert(std::pair<party, int>(party::two, rand()%10));
    }
    if(Candidate::party_three_active){
        map_party.insert(std::pair<party, int>(party::three, rand()%10));
    }
    map_party.insert(std::pair<party, int>(party::none, rand()%10));
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
        District temp(count_district);
        map.insert(std::pair<int, District>(count_district, temp));
        count_district ++;
    }

}

std::ostream & operator<<(std::ostream& os, District print_district){
    std::cout << "district: "<< print_district.id <<":"<< std::endl;
    std::cout << "area: "<< print_district.square_mile << std::endl;


}

