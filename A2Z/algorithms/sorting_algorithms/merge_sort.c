#include <stdio.h>

merge_sort(int array[5], int left, int right){
    int mid = left + (right - left)/2;
    
}
int main(){
    int array[5] = {29, 10, 14, 37, 13};
    int n = sizeof(array) / sizeof(array[0]);
    merge_sort(array, 0, n - 1);
}