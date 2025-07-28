#include <iostream>
using namespace std;

void sort(int *arr, int n)
{
    // always use < instead of <= cause <= requires three cycles for the processor to compute whereas < only requires one
    for (int i = 0; i < n; i++)
    {
        int biggest = 0;
        for(int j = n-1; j >= 1; j--){
            if(arr[biggest] > arr[biggest + 1]){
            swap(arr[biggest], arr[biggest + 1]);
            biggest = biggest + 1;
        }
        else{
            biggest = biggest + 1;
        }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;
    return 0;
}