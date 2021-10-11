#include<iostream>
#include<vector>
#include<map>
#include"Counter.h"


template <typename T> int Counter<T>::Count(){
    int sum = 0;
    for(auto i = map_counter.begin(); i != map_counter.end(); i++){
        sum += i->second;
    }
    return sum;
}