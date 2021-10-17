#include<iostream>
#include<map>
#include<set>
#include"ElectoralMap.h"

int Candidate::id = 0;

Candidate(party affilication_, std:string name_):id_candidate(id+1),party_affiliation(affilication_), name(name_)