#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void function(const vector<int> &input_array)
{
    int max_elementt = *max_element(input_array.begin(), input_array.end());
    vector<int> recorder(max_elementt + 1, 0);

    for (int integer : input_array)
    {
        recorder[integer] += 1;
    }
    for (int integer : input_array)
    {
        cout<<recorder[integer]<<" ";
    }
}

int main()
{
    vector<vector<int>> main_array;

    int T;
    cin >> T;

    // In a while loop any non-zero number is treated as true and zero is treated as false so
    // also T first returns a value and then decrements so this is a shorthand in cpp to run loop T times
    while (T--)
    {
        int N;
        cin >> N;

        vector<int> arr(N);

        for(int i = 0; i < N; i++){
            cin>>arr[i];
        }

        main_array.push_back(arr);
    }

    for(vector<int> v : main_array){
        function(v);
        cout<<endl;
    }
    return 0;
}