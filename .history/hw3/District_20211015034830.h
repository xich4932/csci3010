#ifndef __DISTRICT__
#define __DISTRICT__
#include<iostream>
const enum party{one, two, three};

class Candidate{
    public:
    Candidate();
    int get_ids();
    private:
    int id;
    party party_affiliation;
    std::string name;
};

class Election{
    public:
        Election();
        void clear();
        void report();
        void report_winnder();
        int counting();
        void register_candicate();
        void go_campaigning();
        void call_votes();
        
    private:

        
};

class RepresentativeElection : public Election{
    public:
    private:
};

class District{
    public:

    private:

};

#endif