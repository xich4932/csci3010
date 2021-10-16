#ifndef __DISTRICT__
#define __DISTRICT__
#include<iostream>
#include<vector>

extern enum party;

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
        std::vector<party> vec_party; 
        int id;
};

#endif