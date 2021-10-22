#ifndef __ELECTORALMAP__
#define __ELECTORALMAP__
//#include"District.h"
#include<iostream>
#include<map>
#include<vector>

enum party{one, two, three, none};


class District{
    public:
        District();
        District(int);
        void change_party(party,party, int);
        //void get_constituent(party);
        double get_square_mile(){return square_mile;};
        int get_id() const {return id;};
        int get_constituent(party party_name){return map_party[party_name];};
        void convert_constituent(party, party, int);
        party get_max();
        int get_sum_constitutent();
        party get_max_party();
        int get_sum_constitutent_exclude_none(party);
        friend std::ostream & operator<<(std::ostream& os, District print_district);
        /* bool operator <(const District& less)const{
            if(this->id < less.get_id()) return true;
            return false;
        };
        bool operator >(const District& less)const{
            if(this->id > less.get_id()) return true;
            return false;
        };
        bool operator ==(const District& less)const{
            if(this->id == less.get_id()) return true;
            return false;
        }; */
    private:
        double square_mile;
        std::map<party, int> map_party; 
        int id;
};

class Candidate{
    public:
    Candidate();
    Candidate(int, party, std::string);
    int get_ids();
    std::string get_name(){return name;};
    int get_vote(int dis){return votes[dis];};
    party get_party(){return party_affiliation;};
    void plus_vote(const int, int);
    std::map<int,int> get_all_votes() {return votes;}
    static int party_one_candidate;
    static int party_two_candidate;
    static int party_three_candidate;
    int get_total_vote(){return total_vote;};
   // static int party_none;
    void print_vote(); //debug
    public:
    int id_candidate;
    party party_affiliation;
    std::string name;
    std::map<int ,int> votes;
    int total_vote;
};

class Election{
    public:
        Election();
        Election(std::string);
        bool check_win();
        virtual void report_win();
        virtual void voting();
        void register_candidate(party, std::string);
        virtual Candidate* who_campaigning();
        virtual int where_campaigning();
        bool check_end();
        virtual void print_each_Vote();
        virtual void election_process();
        virtual void test(){std::cout <<"from base"<<std::endl;};
        void converting(District*, Candidate* );
        virtual Candidate* get_candidate(int );
        static int ids;
        static std::vector<int> party_one_active;
        static std::vector<int> party_two_active;
        static std::vector<int> party_three_active;
        static std::vector<int> party_none;
        static int active_party[3];
        void clear();
    private:
        std::map<int, Candidate*> candidate_;
};

class RepresentativeELection : public Election{
    public:
        RepresentativeELection();
        void calculate_vote();
        void voting();
        void test(){std::cout <<"from derivative"<<std::endl;};
        void report_win();
        Candidate* who_campaigning();
    private:
        std::vector<int> vote_per_district;
        std::map<int, Candidate*> rep_candidate_ ;
    
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
        std::map<int, District*> get_map(){return map;};
    private:
        ElectoralMap();
        std::map<int, District*> map;
};

#endif