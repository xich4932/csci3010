#ifndef __ELECTORALMAP__
#define __ELECTORALMAP__
//#include"District.h"
#include<iostream>
#include<map>
#include<vector>

const enum party{one, two, three};

class Candidate{
    public:
    Candidate();
    Candidate(party, std::string);
    int get_ids();
    static int id;
    static int party_one_active;
    static int party_two_active;
    static int party_three_active;
    private:
    int id_candidate;
    party party_affiliation;
    std::string name;
};

class District{
    public:
        District();
        void change_party();
        void get_constituent(int id);
        double get_sqaure_mile(){return square_mile;};
        int get_id() {return id;};
        friend std::ostream & operator<<(std::ostream& os, District print_district);
    private:
        double square_mile;
        std::vector<party, int> vec_party; 
        int id;
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
        RepresentativeELection();
        int counting();
    private:
        party party_representative;
    
};

class ElectoralMap{
    public:
        static ElectoralMap& getInstance(){
            static ElectoralMap instance;
            return instance;
        }
        static District* getDistrict(int);
        friend std::ostream & operator<<(std::ostream& os, ElectoralMap map);
    private:
        ElectoralMap();
        static int count_district;
        std::map<int, District> map;
};



#endif