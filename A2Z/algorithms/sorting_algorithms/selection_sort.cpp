#include <iostream>
#include <vector>
using namespace std;

vector<int> selection_sort(vector<int> arr, int n){
    int smallest = 0;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > 0; j--){
            if(arr[smallest] > arr[smallest + 1]) smallest = smallest + 1;
        }
        swap(arr[smallest], arr[i]);
    }
    return arr;
}
int main(){
        vector<int> arr = {1,2,6,4,3,7,5};
        int n = 7;
        // the .data() function returns a pointer to the first element in the vector
        // int* ptr = selection_sort(arr.data(), n);
        vector<int> ptr = selection_sort(arr, n);
        for(int each : ptr) cout<<each<< " ";
}