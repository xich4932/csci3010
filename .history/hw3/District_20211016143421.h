#ifndef __DISTRICT__
#define __DISTRICT__
#include<iostream>
#include<vector>


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
        std::vector<Party> 
        party constituents;
        int id;
};

#endif