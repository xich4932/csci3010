#ifndef __MAP_DISTRICT__
#define __MAP_DISTRICT__
#include<iostream>
#include<map>

class district{
    public:
        district();
        int get_id();
        int area();
        friend std::ostream & operator<<(std::ostream& os, district print_district);
    private:
        int id;
        int area;
};

class ElectoralMap{
    public:
        static district* getDistrict(int);
        static int count_district;
        friend std::ostream & operator<<(std::ostream& os, ElectoralMap *map);
    private:
        ElectoralMap();
        std::map<int, district> map;
};

#endif