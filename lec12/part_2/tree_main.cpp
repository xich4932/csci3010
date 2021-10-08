#include <iostream>

#include "Tree.h"

// Names: Xiang
//

int main() {
    Tree oak;
    std::cout << "Number of trees: " << oak.get_number_seeds() << std::endl;

    // 0) Attempt to directly access the number_seeds_ static field here. Can you do so? why/why not?
       
        //no, it 's in the private
    // 1) Instantiate another Tree object here
    Tree mytree;

    // 2) Call get_number_seeds() from your tree object instantiated at #1

    mytree.get_number_seeds();
    // 3) Test to see whether pointers to your two Tree objects are equal.
   // int *ptr_1 = &(mytree.get_number_seeds());
    //int *ptr_2 = &oak.get_number_seeds();
   // std::cout << "is address same? "<< ())<<std::endl;
    Tree * ptr1 = &oak;
    Tree * ptr2 = &mytree;
    std::cout << "is address same? "<< (ptr1 == ptr2 )<<std::endl;
    // 4) Call Seed() from the Tree object oak and Seed() from the Tree object instantiated at #1
    // Does changing the value of number_seeds_ from one tree object affect what you see from the
    // other Tree object by calling get_number_seeds()?
    oak.Seed();
    std::cout << mytree.get_number_seeds() <<std::endl;
    //yes
    // 5) Add a subclass of the Tree object. Your subclass should overwrite the Seed() method so that
    // when your subclass uses Seed(), the number_seeds_ should increase by two. Write adequate code
    // to experiment how the static field changes when calling Seed() with your regular Trees versus with the
    // derived class that you implemented. Don't forget the keyword virtual and remember that you shouldn't
    // add a new field to your Tree subclass to accomplish this!
    //
    sur sur1;
    sur1.Seed();
    std::cout << mytree.get_number_seeds() <<std::endl;

    // 6) Add a public static variable to your Tree class that counts how many Trees (and Tree subclasses)
    // have been instantiated. Can you access this via a Tree instance? Can you access it without an instance of Tree?
    // e.g.
    std::cout << "number_tress_" << std::endl;
    std::cout << Tree::number_trees_ << std::endl;
    std::cout << oak.number_trees_ << std::endl;
    //yes
}
