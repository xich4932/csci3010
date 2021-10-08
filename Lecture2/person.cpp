#include <iostream>

// primarily about structure for data
struct Person {
    std::string name;
    int age;
};

// data + functionality
class Family {
    public:
        Family(int num) {
            num_ = num;
        }

        void Grow(int num_persons) {num_ += num_persons;}; // method
        int getNum(){
            return num_;
        }
    private:
        // fields/attributes
        int num_;
};

int main() {
    Person p;
    p.name = "Alice";
    p.age = 12;


    Family f1(4);
    f1.Grow(4);


    Family * f2 = new Family(10);
    f2->Grow(8);

    // Exercises: find out if two different structs containing the same data are ==
    // What happens if you try to << a struct to cout? why?
    Family *f3 = new Family(12);
    if(f3->getNum() == p.age){
        std::cout <<"we can use =="<<std::endl;
    }else{
        std::cout <<"we can't use =="<< std::endl;
    }
    std::cout << "f2 has num " << f2->getNum() <<std::endl;

}
