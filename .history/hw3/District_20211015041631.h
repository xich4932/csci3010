#ifndef __DISTRICT__
#define __DISTRICT__
#include<iostream>
#include<vector>
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
        void report_win();
        int counting();
        void register_candicate();
        void go_campaigning();
        void call_votes();
        Candidate getCandidate(int );
        std::vector<Candidate> get_all_candidate();

    private:
        std::vector<Candidate> candidate_;
};

class RepresentativeELection : public Election{
    public:
        RepresentativeElection();
        int counting();
    private:
        party party_representative;
    c
};

class District{
    public:
        District();
        void change_party();
        void get_constituent(int id);
        double get_sqaure_mile();
        
    private:
        double square_mile;
        party party_;
        std::vector<Candidate> candidate_district;
        party constituents;

};

#endif