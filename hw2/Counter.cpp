#include<iostream>
#include<vector>
#include<map>
#include"Counter.h"

template <typename T> Counter<T>::Counter(){
    map_counter.clear();
}


template <typename T> Counter<T>::Counter(std::vector<T> vals){
    for(int i = 0; i < vals.size(); i++){
        map_counter.insert(vals[i], 0);
    }
}

template <typename T> int Counter<T>::Count(){
    int sum = 0;
    for(auto i = map_counter.begin(); i != map_counter.end(); i++){
        sum += i->second;
    }
    return sum;
}