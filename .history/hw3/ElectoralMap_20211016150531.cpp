#include<iostream>
#include<map>
#include<set>
#include"ElectoralMap.h"

int Candidate::id = 0;

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
    
}