#include <iostream>
using namespace std;

void changeByValue(int a){
    a++;
}

void changeByPointer(int* x){ // saying that this is a pointer to int datatype 
    *x = *x + 1;
}

void changeByReference(int& x){ // reference declaration    
    x = x + 1;
}

int main(){
    int a = 10;
    changeByValue(a); // passing the value of a 
    cout << a << endl;
    changeByPointer(&a); // passing the address of a
    cout << a << endl;
    changeByReference(a);
    cout << a << endl;
}