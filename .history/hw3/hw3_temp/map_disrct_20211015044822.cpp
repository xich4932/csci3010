#include<iostream>
#include<map>
#include"map_district.h"
#include<time.h>
#include <utility>

int ElectoralMap::count_district = 0;

ElectoralMap::ElectoralMap(){\
    district init_district(count_district, rand()%25+5);
    map.insert(make_pair<int, district>(count_district, init_district));
    count_district ++;
}

