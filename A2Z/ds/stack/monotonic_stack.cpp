// The goal here is not to preseve all input but to filter down to a monotonic stack structure 

// Increasing monotonic stack -> elements are placed in increasing order
// Decreasing monotonic stack -> elements are placed in decreasing order 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> monotonicallyIncreasing(vector<int> &nums){
    stack<int> st;
    vector<int> result;
    int i, n = nums.size();
    for(i = 0; i < n;i++){
        while(!st.empty() && st.top() > nums[i]){
            st.pop();
        }
        st.push(nums[i]);
    }

    while(!st.empty()){
        result.insert(result.begin(), st.top());
        st.pop();
    }
    return result;
}

int main(){
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<int> result = monotonicallyIncreasing(nums);
    cout << "Monotonic Stack: ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}