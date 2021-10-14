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
            for(int i = 0 ; i < vals.size(); i++){
                //map_counter[vals[i]] = 1;
                auto search = map_counter.find(vals[i]);
                if(search != map_counter.end()){
                    search->second += 1;
                }else{
                    map_counter.insert(std::pair<T, int>(vals[i], 1));
                }
            }
           
        }
         T MostCommon(){return map_counter.begin()->first;};
         std::vector<T> MostCommon(int n){
             std::vector<T> ans;
             return ans;
         };
         T LeastCommon(){return map_counter.begin()->first;};
         std::vector<T> LeastCommon(int n){
             std::vector<T> ans;
             return ans;
         };
         std::map<T, double> Normalized(){
             std::map<T, double> ans;
             return ans;
         }
        /*
         T MostCommon(){
            return map_counter.rbegin();
        };
        std::vector<T> MostCommon(int n){
            std::vector<T> vec;
            for(auto i = map_counter.rbegin(); i != map_counter.rend(); i++){
                vec.push_back(i);
            }
            return vec;
        };
        T LeastCommon(){
            return map_counter.begin();
        };
        std::vector<T> LeastCommon(int n){
            std::vector<T> vec;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
                vec.push_back(i);
            }
            return vec;
        };
        std::map<T, double> Normalized(){
            double sum = 0;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
                sum += i->second;
            }
            std::map<T, double> ans;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
                ans[i->first] = i->second/sum;
            }
            return ans;
        };
        */
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
            return 0;
           // return -1;
        }
        void Increment(T key){
            auto ans = map_counter.find(key);
            if(ans != map_counter.end()){
                ans->second += 1;
            }else{
                map_counter.insert(std::pair<T,int>(key, 1));
            }
        }
        void Increment(T key, int n){
            auto ans = map_counter.find(key);
            if(ans != map_counter.end()){
                ans->second += n;
            }else{
                map_counter.insert(std::pair<T,int>(key, n));
            }
        }
        void Decrement(T key){
            auto ans = map_counter.find(key);
            if(ans != map_counter.end()){
                ans->second -= 1;
            }else{
                ;
            }
        }
        void Decrement(T key, int n){
            auto ans = map_counter.find(key);
            if(ans != map_counter.end()){
                if(n > ans->second){
                    ans->second = 0;
                }else{
                    ans->second -= n;
                }
                
            }else{
                ;
            }
        }
        void Remove(T key){
            auto ans = map_counter.find(key);
            if(ans == map_counter.end()){
                ;
            }else{
                map_counter.erase(ans);
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
            std::vector<int> ans;
            for(auto i = map_counter.begin(); i != map_counter.end(); i++){
            
                ans.push_back(i->second);
            }
            return ans;
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
  // int comma = b.map_counter.size() - 1;
  std::string str= "{";
    //std::cout << "{";
    for(auto i = b.map_counter.begin(); i != b.map_counter.end(); i++){
        std::stringstream ss;
        std::string temp_str;
        ss << i->first <<":"<< i->second << ",";
        ss >> temp_str;
        str += temp_str;
        //if(comma) std::cout <<",";
        //comma --;
        
    }
    str += "}\n";
    os << str;
    return os;
}

#endif 