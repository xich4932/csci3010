#include <iostream>

// Name:Xiang Chen
//

// Write any functions you need here!
//passing pointeer to this func
void increment1(int * i){
    (*i) ++;
    std::cout << *i <<std::endl;
}

void increment2(int & i){
    i ++;
}

void foo3(const int &num, int * ptrr){
    (*ptrr) ++;
    std::cout << "num: "<< num <<std::endl;
    std::cout << "ptr: "<< *ptrr <<std::endl;
}

class GDP{
    public:
        GDP(){
            consumption = 0;
            investment = 0;
        }
        GDP(int c,int i){
            consumption = c;
            investment = i;
        }
        int get_con(){return consumption;} 
        int get_inv() {return investment;}
        GDP operator+ (GDP &one) {
            GDP temp(this->consumption + one.get_con(),this->investment + one.get_inv() );
            return temp; 
        }
        bool operator==(GDP &one){
            if(this->consumption == one.get_con() && this->investment == one.get_inv()) return true;
            return false;
        }
    private:
        int consumption;
        int investment;
};



int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int num = 1;
    // 2) Declare a pointer to that int
    int* ptr = &num;
    // 3) Increment the int via the pointer
    (*ptr)++;
    // 4) Declare a reference to your int
    int &ref_num = num;
    // 5) Increment the int via the reference
    ref_num++;
    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer:  both
    
    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: both pointer and reference will change

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: both pointer and reference will change

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    //void increment1(int * i);
    increment1(&num);

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: no
    //increment1(ref_num);

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)
    increment2(ref_num);
    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: no
    
    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer: yes
    increment2(ref_num);
    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    foo3(ref_num, ptr);
    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer:
    //output parameters is faster than return values because compiler don't need to create variable when passing parameters;
    //return values can return the status of function to users
    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:
    GDP year_2018(100,200);
    GDP year_2019(100,200);
    
    if(year_2018 == year_2019){
        std::cout <<"years GDP are equal"<<std::endl;
    }else{
        std::cout <<"years GDP are not equal"<<std::endl;
    }
    GDP year_2020 = year_2018 + year_2019;
    std::cout << "consumption: "<< year_2020.get_con() <<std::endl;
    std::cout << "consumption: "<< year_2020.get_inv() <<std::endl;
}
