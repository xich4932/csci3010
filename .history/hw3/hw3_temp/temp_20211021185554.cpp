#include<iostream>
using namespace std;

enum party{one, two, three ,none};

void main(){
    for(enum party start = party::one; start < party::none; start = (party)(start+1)){
        cout << start << endl;
        cout << (start + 1) << endl;
    }
}
