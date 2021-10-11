#ifndef COUNTER_h
#define COUNTER_h

#include<iostream>
#include<vector>
#include<map>

//template <typename T> class Counter;

template <typename T> class Counter {
    public:
        Counter(){};
        Counter(std::vector<T> vals){
            for(int i = 0; i < vals.size(); i++){
                map_countervals.insert({vals[i], 0});
        }
        }
        int Count();
        //int Count(T key);
       
    private:
        std::map<T, int> map_counter;
};

#endif 