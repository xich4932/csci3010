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
                map_counter.insert({vals[i], 0});
        }
        }
        int Count(){
            int sum = 0;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
                sum += i->second;
            }
            return sum;
        }
        int Count(T key){
            auto ans = map_counter.find(key); 
            if(ans != map_counter.end()){
                return ans->second;
            }
            return -1;
           // return -1;
        }
        void Remove(T key){
            
        }

        void Increment(T key){
            if(map_counter.find(key) == map_counter.end()){
                ;
            }else{
                map_counter[key] += 1;
            }
        }
        void Increment(T key, int n){
            if(map_counter.find(key) == map_counter.end()){
                ;
            }else{
                map_counter[key] += n;
            }
        }
        void Decrement(T key){
            if(map_counter.find(key) == map_counter.end()){
                ;
            }else{
                map_counter[key] --;
            }
        }
        void Decrement(T key, int n){
            if(map_counter.find(key) == map_counter.end()){
                ;
            }else{
                map_counter[key] -= n;
            }
        }

        
       
    private:
        std::map<T, int> map_counter;
};

#endif 