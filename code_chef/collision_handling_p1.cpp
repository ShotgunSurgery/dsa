#include <iostream>
#include <vector>
using namespace std;

const int M = 999983;
// the following means 10^9;
const int MX = 1e9;

int Hash[M] = {0};

// Hash Function
int f(int x)
{
    return x % M;
}

int main()
{
    int n, count = 0;
    cin >> n;
    vector<int> store_arr(M, 0);
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t, index;
        cin >> t;
        a.push_back(t);
        index = f(a[i]);
        if (store_arr[index])
        {
            store_arr[index] += 1;
        }
        else
        {
            while(store_arr[index]){
                index += 1;
            }
            store_arr[index] += 1;            
        }
    }
    for(int i = 0; i < n; i++){
        int square = a[i] * a[i], idx = f(square);
        if(store_arr[idx] == square){
            count += 1;
        }
        else{
            for(int j = 0; j < n; j++){
                if(store_arr[j] == square) count += 1;
            }
        }
        
    }
    // for(int i = 0; i < store_arr.size(); i++){
    //     printf("%d ", store_arr[i]);
    // }
    return 0;
}
