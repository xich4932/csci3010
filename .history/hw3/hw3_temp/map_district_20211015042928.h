#ifndef __MAP_DISTRICT__
#define __MAP_DISTRICT__
#include<iostream>
#include<map>

class district{
    public:
        district();
        int get_id();
        int area();
        friend ostream & operator<<(ostream& os, district print_district);
    private:
        int id;
        int area;
};

class ElectoralMap{
    public:
        static district* getDistrict(int);
        static int count_district;
        friend ostream& operator<<(ostreamm & os, ElectoralMap *map);
    private:
        ElectoralMap();
        std::map<int, district> map;
};

#endif