#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../ElectoralMap.h"
#include "catch.hpp"

TEST_CASE ( "GOOD", "[CONVERTING]") {
    ElectoralMap ins = ElectoralMap::getInstance();
    std::map<int, District> temp_map = ins.get_map();
    Candidate *can = new Candidate(1, party::one,"xiang");
    Election * ele = new Election();
    ele->converting(&temp_map[1], can);
}