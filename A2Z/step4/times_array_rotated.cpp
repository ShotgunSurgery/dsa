#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = 0, hi = (nums.size() - 1), lowest = lo;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[lo] <= nums[mid])
            {
                if (nums[lo] <= nums[lowest])
                {
                    lowest = lo;
                    lo = mid + 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= nums[lowest])
                {
                    lowest = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
        }
        return lowest;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    int final = nums.size() - s.findMin(nums);
    cout << final;
}