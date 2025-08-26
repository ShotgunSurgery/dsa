#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // vector<int> result;
        // stack<int> st;
        // unordered_map<int, int> nge;
        // int nge_int;

        // for(int integer: nums){
        //     nge[integer] = -1;
        // }

        // for(int x: nums){
        //     if(x == nums[nums.size() - 1]){
        //         while(!st.empty()) st.pop();
        //         st.push(x);
        //         for(int x: nums){
        //             while(!st.empty() && st.top() <= x){
        //                 if(st.top() != nums[nums.size() - 1]) continue;
        //                 else nge[st.top()] = x;
        //             }
        //         }
        //     }
        //     while(!st.empty() && st.top() <= x){
        //         nge[st.top()] = x;
        //         st.pop();
        //     }
        //     st.push(x);
        // }

        // for(int i = 0; i < nums.size(); i++){
        //     result.push_back(nge[nums[i]]);
        // }
        int n = nums.size();
        vector<int> result(n, -1); 
        stack<int> st;             

        for (int i = 0; i < 2 * n; i++)
        { 
            int curr = nums[i % n];

            while (!st.empty() && nums[st.top()] < curr)
            {
                result[st.top()] = curr;
                st.pop();
            }

            if (i < n)
            {
                st.push(i); 
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> result = s.nextGreaterElements(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}