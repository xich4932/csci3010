#ifndef __ELECTORALMAP__
#define __ELECTORALMAP__
//#include"District.h"
#include<iostream>
#include<map>
#include<vector>

enum party{one, two, three, none};


class Candidate{
    public:
    Candidate();
    Candidate(int, party, std::string);
    int get_ids();
    std::string get_name(){return name;};
    int get_vote(){return vote;};
    void plus_vote(int);
    static int party_one_candidate;
    static int party_two_candidate;
    static int party_three_candidate;
    private:
    int id_candidate;
    party party_affiliation;
    std::string name;
    int vote;
};

class District{
    public:
        District(int);
        void change_party(party, int);
        //void get_constituent(party);
        double get_sqaure_mile(){return square_mile;};
        int get_id() {return id;};
        int get_constituent(party party_name){return map_party[party_name];};
        party get_max();
        friend std::ostream & operator<<(std::ostream& os, District print_district);
    private:
        double square_mile;
        std::map<party, int> map_party; 
        int id;
};

class Election{
    public:
        Election();
       // void register_candidate(party, std::string);
        void report_win();
        void voting();
        void register_candidate();
        Candidate* go_campaigning();
        void call_votes();
        Candidate getCandidate(int );
        std::vector<Candidate> get_all_candidate();
        static int ids;
        static std::vector<int> party_one_active;
        static std::vector<int> party_two_active;
        static std::vector<int> party_three_active;
        static int active_party[3];
    private:
        std::vector<Candidate> candidate_;
};

class RepresentativeELection : public Election{
    public:
        RepresentativeELection();
        void voting();
    private:
        party party_representative;
    
};


class ElectoralMap{
    public:
        static ElectoralMap& getInstance(){
            static ElectoralMap instance;
            return instance;
        }
        //static District* getDistrict(int);
        friend std::ostream & operator<<(std::ostream& os, ElectoralMap map);
        static int count_district;
        std::map<int, District> get_map(){return map;};
    private:
        ElectoralMap();
        std::map<int, District> map;
};



#endif