#include<iostream>
#include<map>
#include"map_district.h"
#include<time.h>
#include <utility>

int ElectoralMap::count_district = 0;

ElectoralMap& ElectoralMap::getInstanceMap(){
    static ElectoralMap my_map;
    return my_map;
}

ElectoralMap::ElectoralMap(){
    district init_district(count_district, rand()%25+5);
    map.insert(std::pair<int, district>(count_district, init_district));
    count_district ++;
}

std::ostream & operator<<(std::ostream& os, ElectoralMap *print_map){
    for(auto i = print_map->map.begin();  i != print_map->map.end(); i++){
        std::cout << i->second << std::endl;
    }
    return os;
}

std::ostream & operator<<(std::ostream& os, district print_district){
    std::cout << "id: "<< print_district.id_ <<std::endl;
    std::cout << "area: "<< print_district.area_ <<std::endl;
    return os;
}

