#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../ElectoralMap.h"
#include "catch.hpp"

TEST_CASE ( "GOOD", "[CONVERTING]") {
    ElectoralMap ins = ElectoralMap::getInstance();
    Election *ele = new Election(1,)
}