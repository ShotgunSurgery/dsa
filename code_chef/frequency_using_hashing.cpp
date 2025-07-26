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
    for (int integer : recorder)
    {
        cout << integer;
    }
}

int main()
{
    vector<int> input_array = {1, 2, 3, 4, 5};
    function(input_array);
    return 0;
}