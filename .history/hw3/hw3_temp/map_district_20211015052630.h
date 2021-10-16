#ifndef __MAP_DISTRICT__
#define __MAP_DISTRICT__
#include<iostream>
#include<map>

class district{
    public:
        district(int i, int area): id_(i),area_(area){};
        int get_id(){return id_;};
        int area() {return area_;};
        friend std::ostream & operator<<(std::ostream& os, district print_district);
    private:
        int id_;
        int area_;
};

class ElectoralMap{
    public:
        //ElectoralMap();
        static ElectoralMap* getInstanceMap(){
            
        }
        static district* getDistrict(int);
        friend std::ostream & operator<<(std::ostream& os, ElectoralMap *map);
    private:
        ElectoralMap();
        static int count_district;
        std::map<int, district> map;
};
#endif