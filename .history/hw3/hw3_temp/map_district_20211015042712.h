#ifndef __MAP_DISTRICT__
#define __MAP_DISTRICT__
#include<iostream>
#include<map>

class district{
    public:
        district();
        int get_id();
        int area();
    private:
        int id;
        int area;
};

class ElectoralMap{
    public:
        static district* getDistrict(int);
        static int count_district;
        ostream & operator<<(ostream& os, )
    private:
        ElectoralMap();
        std::map<int, district> map;
};

#endif