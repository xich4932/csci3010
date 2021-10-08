#include <iostream>

#include "Animal.h"

// Name(s): 

int main() {

  Reptile ralph("alligator");
  std::cout << ralph.MakeSound() << std::endl;

  // 1) Instantiate another animal 
  Animal elepha("elephant");
  // 2) Call the Fight method of animal
  elepha.Fight(ralph);
  // 3) Go to the Animal.h file and define some new subclasses of animal
  // Define one class that inherits from Animal and
  // one class that inherits from a child class of Animal
 
  // 4) Instantiate at least one object of each class you defined for #3
  shark shark_1("sh");
  fish fish_1("fi"); 
  // 5) Have a tournament between the animals that you have instantiated 
  shark_1.Fight(fish_1);
  // 6) turn in Animal.h and main.cpp on canvas
    
	return 0;
}
