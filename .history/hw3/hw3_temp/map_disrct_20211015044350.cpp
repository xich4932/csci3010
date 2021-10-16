#include<iostream>
#include<map>
#include"map_district.h"

int Electoral::count_district = 0;

ElectoralMap::ElectoralMap(int id, int area){
   
    district init_district(count_district, area, id);
     count_district ++;
}

