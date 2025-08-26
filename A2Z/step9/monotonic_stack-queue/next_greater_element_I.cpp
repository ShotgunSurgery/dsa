#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nge;
        stack<int> st;
        vector<int> result;
        int int_nge;

        for (int integer : nums2)
        {
            nge[integer] = -1;
        }

        for (int x : nums2)
        {
            while (!st.empty() && st.top() < x)
            {
                nge[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            result.push_back(nge[nums1[i]]);
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = s.nextGreaterElement(nums1, nums2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}