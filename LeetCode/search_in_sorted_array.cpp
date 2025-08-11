#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1 ;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            cout << "lo: " << lo << " " << " hi: " << hi << " " << " mid: " << mid << endl;
            if (nums[mid] == target)
                return mid;

            if (nums[lo] <= nums[mid])
            {
                if (nums[lo] <= target && target < nums[mid])
                {
                    // cout << "nums[lo]: " << nums[lo] << " " << " target: " << target << " " << " nums[mid]: " << nums[mid] << endl;
                    // cout << "check" << endl;
                    hi = mid -1;
                }
                else{
                    lo = mid + 1;
                }
            }
            else {
                if(nums[mid] < target && target <= nums[hi]){
                    lo = mid + 1;
                }
                else {
                    cout << "nums[mid]: " << nums[mid] << " " << " target: " << target << " " << " nums[hi]: " << nums[hi] << endl;
                    hi = mid - 1;
                }
            }
            // cout << "lo: " << lo << " " << " hi: " << hi << " " << " mid: " << mid << endl;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 1};
    int target = 1;
    cout << s.search(nums, target);
}