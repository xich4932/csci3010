#include <iostream>
#include <vector>

#include "Emotion.h"
#include "Creature.h"

// Names:Xiang Chen
//
//

void ScienceLab(Creature * original){
    Creature * test_one = original->Clone();
    if(test_one->get_emotions().size() == original->get_emotions().size()){
        std::cout <<"the emotion of this creature all can be heredity" << std::endl;
    }else{
         std::cout <<"some emotion of this creature can be heredity" << std::endl;
    }
}


int main() {
    // Part 1 (factory) 
    // ---------------
    // 4) get pointers to one of each type of your Emotion objects via your EmotionFactory. Then,
    // call the Emotion's get_count method to see how many Emotion objects have been instantiated.
    Emotion *happy =  EmotionFactory::GetHappy();
    Emotion *angry =  EmotionFactory::GetAngry();
    Emotion *sad =  EmotionFactory::GetSad();
    // 5) are your EmotionFactory's Get____() methods static or non-static? Do you think that they should
    // be one or the other? Justify your answer. If your methods are static, what would change if they were
    // non-static? If they are non-static, what would change if they were static?
    // method is static, they should be one
    // 
    // 6) Feel free to create more creatures here
   // Creature original_creature(14);
    Creature first_creature(14);
    Creature second_creature(10);
    first_creature.AddEmotion(happy);
    //second_creature.AddEmotion(sad);
    //second_creature.AddEmotion(angry);
    first_creature.Spread(&second_creature);
    // 7) Infect your creatures with your emotions. Test out the Creature Spread method.
    Creature *cloned = first_creature.Clone();

   for (Emotion * d : second_creature.get_emotions() ) {
        std::cout << *(d) << std::endl;     
    }


    // STOP! Turn in Emotion.h, Emotion.cpp, and main.cpp on canvas

 
    // Part 2 (prototype) 
    // ---------------
    // 3) Create some new Creature * objects by using the Creature's Clone() method. Does this method use dynamic dispatch?
    // Answer: yes
    // How did you test this? print out
    first_creature.AddEmotion(angry);
    Creature * clone_one = first_creature.Clone();
    std::cout <<"emotion of clone creature"<<std::endl;
    for (Emotion * d : clone_one->get_emotions() ) {
        std::cout << *(d) << std::endl;     
    }
    ScienceLab(*first_creature);

    // If you finish:
    // -------------
    // 4) Write a new function in this file void ScienceLab(Creature * original) (not associated with any classes)
    // that takes an original creature and conducts experiments by cloning it and measuring the spread of emotion.
    // You have complete creative freedom here. Feel free to add methods to the Emotion/Creature classes.
    // (The only requirements are the function definition and that you must call Clone() within that function).
    //
    // Call your ScienceLab function as many times as is necessary for your experiments.
}

