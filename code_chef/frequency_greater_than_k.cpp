// lexiographic order -> order in which words in a dictionary are arranged 
// ordered map / sorted map / ordered dictionary 
// types of ordered map 
// insertion order -> sorted based on the order in which they were inserted
// sorted order -> based on the lexiographical or custom order
// this diffres from hash maps as elements are in order unlike hash maps (i.e. ordered maps). 
// frequency map / frequency counter / tally map / histogram -> used to store the count of ouccerence of elements i.e. keys: values :: element: count_of_that_element

#include <iostream>
#include <map>
using namespace std;

int main(){
    int N, K;
    string S;
    cin>>N;
    cin>>K;
    cin>>S;
    
    // map is cpp standard template library contianer, char is the data type of the key and int is the datatype of the 
    // value and mp is the name of the variable 
    map <char, int> mp;
    for(char & ch : S){
        mp[ch]++;
    }
    // auto tells the compiler to automatically deduce the datatype of the element it's iterating
    for (auto x: mp){
        if(x.second >= K) cout << x.first;
    }
    return 0;
}