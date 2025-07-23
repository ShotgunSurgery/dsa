// #include <bits/stdc++.h> -> non standard header file that includes all the std cpp libs
#include <iostream>
#include <vector>
using namespace std;

long long findMinSumSubarray(int n, int k, vector<int>& arr) {
    int l = 0;
    long long sum = 0;
    for(int i = 0; i < k; i++){
        sum = sum + arr[i];
    }
    long long ans = sum;
    while((l + k) < arr.size()){       
        sum = sum - arr[l];
        
        sum = sum + arr[l + k];
        
        ans = (sum > ans) ? sum : ans;
         l+=1;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findMinSumSubarray(n, k, arr) << endl;
    return 0;
}