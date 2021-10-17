#include<iostream>
#include<map>
#include<set>
#include<time.h>
#include<stdlib.h>
#include"ElectoralMap.h"

int Candidate::id = 0;
int Candidate::party_one_acvtive = 0;
int Candidate::party_two_acvtive = 0;
int Candidate::party_three_acvtive = 0;

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

District::District(){
    srand((unsigned int)(time(NULL)));
    if(Candidate::party_one_active){
        map.insert()
    }
}
