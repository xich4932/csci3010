#include <iostream>
#include <string>
#include <vector>

// Names:Xiang Chen
//
//


// we'd like to write a function that is applicable to many types but
// we don't want to copy paste everything

// For example, here is a templated Add function
template <typename T>
T Add(T v1, T v2) {
    return v1 + v2;
}

// 6) implement a templated version of AddToValues, "AddToValues2".
template <typename U, typename R>
//template <typename R>
U AddToValues2(U t1, R t2){
    t1.push_back(t2);
    return t1;
}

class myclass{
    public:
        int a = 8;
       /*  myclass operator={
            
        } */
};


int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
    std::vector<int> vec = {1 ,2 ,3};
    vec = AddToValues2(vec, 4);

    // 8) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
        //    1
    //0000000000000140 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<std::__1::vector<int, std::__1::allocator<int> >, int>(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements
    std::vector<double> vec2 = {1.1, 2.2, 3.3};
    vec2 = AddToValues2(vec2, 4.0);
    //vec2 = AddToValues2(vec2, "hello");
    
    // 10) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    /*
    0000000000000360 T std::__1::vector<double, std::__1::allocator<double> > AddToValues2<std::__1::vector<double, std::__1::allocator<double> >, double>(std::__1::vector<double, std::__1::allocator<double> >, double)
    0000000000000260 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<std::__1::vector<int, std::__1::allocator<int> >, int>(std::__1::vector<int, std::__1::allocator<int> >, int)
    */
    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of 
    // error is produced.

    std::vector<float> vec3 = {1,1, 2.2, 3.3};
    //string
    //error: no matching member function for call to 'push_back'
    //vec3 = AddToValues2(vec3, "string");
    //int type
    vec3 = AddToValues2(vec3, 5);
    vec3 = AddToValues2(vec3, -5);
    //boolean
    vec3 = AddToValues2(vec3, true);
    //std::vector<std::string> vec5 = {"hello", "world", "nohello"};
    //error: no matching member function for call to 'push_back'
    //vec5 = AddToValues2(vec5, 1231);
    //vec5 = AddToValues2(vec5, 't');
    //vec5 = AddToValues2(vec5, false);

    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    myclass temp_class2;
    myclass temp_class1;
    myclass temp_class3;
    std::vector<myclass> vec4 = { temp_class1, temp_class2, temp_class3 };
    myclass temp_class4;

    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer:no
    vec4 = AddToValues2(vec4, temp_class4);
    //yes  error: expected unqualified-id
    // 14) If there was an error, attempt to fix it.

}
