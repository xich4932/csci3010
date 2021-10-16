#ifndef __MAP_DISTRICT__
#define __MAP_DISTRICT__

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

    private:
        std::map<int, district> map;
};

#endif