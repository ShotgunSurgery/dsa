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
            // cout << "mid: " << mid << endl;
            if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                while((nums[mid] == nums[lo] || nums[mid] == nums[hi]) && mid < nums.size() - 1){
                    // cout << "mid: " << mid << endl;
                    mid+=1;
                }
            }

            // cout << "test" << mid;    

            //brute force approach 1 testing 
            if(nums[lo] == nums[mid] && nums[mid] == nums[hi] && (nums.size() - 1) == mid){
                // cout << "check";
                mid = (0 + (nums.size() - 1)/2);
                while((nums[mid] == nums[lo] || nums[mid] == nums[hi]) && mid >= 0){
                    
                    mid-=1;
                }
            }
            // cout << mid << endl;
            // cout << "check";
            // cout << "lo: " << lo << " " << " hi: " << hi << " " << " mid: " << mid << endl;
            if (nums[mid] == target)
                return 1;

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
                    // cout << "nums[mid]: " << nums[mid] << " " << " target: " << target << " " << " nums[hi]: " << nums[hi] << endl;
                    hi = mid - 1;
                }
            }
            // cout << "lo: " << lo << " " << " hi: " << hi << " " << " mid: " << mid << endl;
        }
        return 0; 
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 0, 1, 1, 1};
    int target = 0;
    cout << s.search(nums, target);
}   