#ifndef __ELECTORALMAP__
#define __ELECTORALMAP__
#include"District.h"
#include<iostream>
#include<map>

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