#include<iostream>
using namespace std;

enum party{one, two, three ,none};

int main(){
    for(enum party start = one; start <= none; start = (party)(start+1)){
        cout << start << endl;
        cout << (start + 1) << endl;
    }
    return 0;
}
