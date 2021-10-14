#ifndef COUNTER_h
#define COUNTER_h

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
#include<set>

//template <typename T> class Counter;


template <typename T> class Counter {
    public:
        Counter(){};
        Counter(const std::vector<T> vals){
            /* for(auto i = vals.begin(); i != vals.end(); i++){
                map_counter.insert(std::pair<T,int>(&vals[i],1));
            } */
            for(auto i: vals){
                map_counter[i] = 1;
            }
        }
        int Count(){
            int sum = 0;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
                sum += i->second;
            }
            return sum;
        }
        int Count(const T key){
            auto ans = map_counter.find(key); 
            if(ans != map_counter.end()){
                return ans->second;
            }
            return -1;
           // return -1;
        }
        void increment(){
            
        }
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Counter<U> &b);
        bool operator<(const Counter<T> & c){
            return true;
        }
    private:
       // std::list<std::pair<T,int>> map_counter;
       std::map<T, int> map_counter;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Counter<T> &b){
   int comma = b.map_counter.size() - 1;
    std::cout << "{";
    for(auto i = b.map_counter.begin(); i != b.map_counter.end(); i++){
        std::cout << i->first <<": "<< i->second;
        if(comma) std::cout <<", ";
        comma --;
        
    }
    std::cout << "}";
    return os;
}

#endif 