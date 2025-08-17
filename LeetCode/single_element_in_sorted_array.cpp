#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(mid % 2 == 0 && mid > 0){
                if(nums[mid] == nums[mid - 1]) hi = mid - 1;
                else return nums[mid];
            }
            else{
                if(nums[mid] == nums[mid + 1]){
                    if(mid > 0) hi = mid - 1;
                }
                else if(mid < nums.size()) lo = mid + 1;
            }
        }
        return nums[hi];
    }
};

int main(){
    Solution s;
    vector<int> nums = {};
    cout << s.singleNonDuplicate(nums);
}