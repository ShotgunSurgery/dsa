#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

int main(){

    // following two don't store duplicate elements 

    unordered_set<int> set_name;
    set_name.insert(50);
    set_name.insert(20);

    // this stores elements in ascending order 
    set<int> ordered_set;
    ordered_set.insert(5);
    ordered_set.insert(2);

    // multiset allows duplicate elements 
    multiset<int> multiset_name;
    multiset_name.insert(4);
    multiset_name.insert(4);

    cout<<"Ordered set: ";
    for(int integer : ordered_set){
        cout<<integer<<" ";
    }

    cout<<endl;
}