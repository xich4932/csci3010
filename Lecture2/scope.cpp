#include <iostream>
#include <vector>

// scope: "what can we see right here"
// - what variables/functions/other can we access from inside x, where x is a function, method, etc.

// 1) what happens in c++ if you try to acces a variable out of scope?
//it cause compiler time error
// 2) what happens if we make everything global?
//it might change the value even progammer didn't realize

// Summary:
// pass-by-value vs. pass-by-reference
// pass-by-value: give the function a copy of the value
// pass-by-reference: give the address of the location of the value


// *************************************************


// When you are done: turn in your file on canvas

// Names (be sure to include the initial of your last name(s)!):
//xiang chen xc

// 1) Write a function that demonstrates whether ints are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
int square(int n ){
    n *= n;
    return n;
}


// 2) Write a function that tests demonstrates whether strings (std::string) are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
std::string addSymbol(std::string s){
    s += "!";
    return s;
}

// 3) Write a function that demonstrates whether arrays are pass-by-value or pass-by-reference
// recall: to initialize an array-- type name[] = {comma separated elements};
// (do not use pointers or c++ references in this function)
// Answer:

void toTwo(int arr[], int size){
    for(int i = 0; i < size; i++)
        arr[i] = 2;
    
}

// 4) Write a function that demonstrates whether vectors are pass-by-value or pass-by-reference
// Answer:

void addToBack(std::vector<int> vec){
    vec.push_back(999);

}


int main() {
    // code to call your functions goes here.

    // you may find it useful to print out values in main as well as inside your functions
    // to appropriately demonstrate whether the given type is pass-by-value or 
    // pass-by-reference
    int num1 = 2;
    if(num1 == square(num1)){
        std::cout <<"ints are passed by value"  << std::endl;
    }else{
        std::cout <<"ints are not passed by value"  << std::endl;
    }
    std::string s1 = "hello";
    if(s1 == addSymbol(s1)){
        std::cout <<"strings are passed by value"  << std::endl;
    }else{
        std::cout <<"string are not passed by value"  << std::endl;
    }
    int arr1[] = {0,0,0};
    toTwo(arr1,3);
    if(arr1[0] == 2){
        std::cout <<"arrays are passed by value"  << std::endl;
    }else{
        std::cout <<"arrays are not passed by value"  << std::endl;
    }
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    addToBack(vec1);
    if(vec1.back() == 999){
        std::cout <<"arrays are passed by value"  << std::endl;
    }else{
        std::cout <<"arrays are not passed by value"  << std::endl;
    }
}   
