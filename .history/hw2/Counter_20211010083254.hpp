#ifndef COUNTER_h
#define COUNTER_h

#include<iostream>
#include<vector>
#include<map>
#include<set>

//template <typename T> class Counter;

template <typename T> class Counter {
    public:
        template<typename U> Counter(){};
        template<typename U> Counter(const std::vector<U> vals){
            for(int i = 0; i < vals.size(); i++){
                map_counter[vals[i]] = 0;
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
        void Remove(const T key){
            if(map_counter.find(key) == map_counter.end()){
                ;
            }else{
                map_counter.erase(key);
            }
        }

        void Increment(const T key){
            if(map_counter.find(key) == map_counter.end()){
                ;
            }else{
                map_counter[key] += 1;
            }
        }
        void Increment(const T key, int n){
            if(map_counter.find(key) == map_counter.end()){
                ;
            }else{
                map_counter[key] += n;
            }
        }
        void Decrement(const T key){
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
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Counter<U> &b);
    private:
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