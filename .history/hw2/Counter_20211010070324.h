#ifndef COUNTER_h
#define COUNTER_h

#include<iostream>
#include<vector>
#include<map>
#include<set>

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
            if(map_counter.find(key) == map_counter.end()){
                ;
            }else{
                map_counter.erase(key);
            }
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
        std::set<T> Keys(){
            std::set<T> ans;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
                ans.insert(i->first);
            }
            return ans;
        }
        std::vector<int> Values(){
            std::vector<T> ans;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
                ans.push_back(i->second);
            }
            return ans;
        }
        std::ostream& operator<<(std::ostream& os, const Counter<T> &b){
           std::cout << "{";
           for(auto i = map_counter.begin(); i != map_counter.end()-1; i++){
                std::cout << i->first <<": "<< i->second <<", ";
            }
            std::cout << "}";
            return os;
       }
    private:
        std::map<T, int> map_counter;
};

#endif 