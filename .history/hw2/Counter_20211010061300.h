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
               // map_counter.insert({vals[i], 0});
        }
        }
        int Count(){
            int sum = 0;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
                sum += i->second;
            }
            return sum;
        }
        void Increa
        int Count(T key){
            if(map_counter.find(key) == map_counter.end()){
                return -1;
            }else{
                return map_counter[key];
            }
           // return -1;
        }
       
    private:
        std::map<T, int> map_counter;
};

#endif 