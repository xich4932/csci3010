#include<iostream>
#include<map>
#include"map_district.h"
#include<time.h>

int ElectoralMap::count_district = 0;

ElectoralMap::ElectoralMap(){\
    district init_district(count_district, rand() );
     count_district ++;
}

