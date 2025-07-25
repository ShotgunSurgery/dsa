#include <iostream>

using namespace std;

int main(){
        int test_case;
        cin>>test_case;
        int** ptr = (int**)malloc(test_case * sizeof(int));
        for(int i = 0; i < test_case; i++){
            int size;
            cin>>size;
            ptr[i] = (int*)malloc(size * sizeof(int));
        }
            

}