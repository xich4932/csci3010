#include <iostream>
#include "Earth.h"

// Names:
//
int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp
    
    // 1) Get an instance of your earth object
    Earth &firstEarth = Earth::GetInstance();
    
    // 2) Get another instance of your earth object
    Earth &secondEarth = Earth::GetInstance();
    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.
    std::cout <<"is address same? " << ((&firstEarth) == (&secondEarth)) << std::endl;
    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?
    firstEarth.IncreasePopulation();
    std::cout << secondEarth.get_population() << std::endl;
    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?
    //No
    std::cout << Earth::animal  << std::endl;
	return 0;
}
