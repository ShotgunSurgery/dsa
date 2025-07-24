#include <iostream>

// we write this following line in every cpp program because - if the user give a function a name that is already 
// the name of an inbuilt function then the compiler won't know which is which so we write std: pre_defined_function_name
// and something else for the suer defined one 
using namespace std;

int hasher(string key){
    int hash_value = 0;
    for(char c : key){
        hash_value += c;
    }
    return hash_value;
    // return hash_value % size_of_array_you_want_to_fit_it_into; -> this is modulo arithmatic 
}
int main(){
    string test = "apple";
    cout<<hasher(test);
}

// collisoin handling
// key-value concepts