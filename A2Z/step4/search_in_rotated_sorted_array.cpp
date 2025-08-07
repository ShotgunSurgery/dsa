#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public: 
    int search(vector<int> & nums, int target){
        int low = 0, high = sizeof(nums) - 1;
        while(low < high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[low]){
                if(nums[mid] >= target && nums[low] <= target){
                    high = mid;
                    continue;
                }
            }
            if(nums[mid] <  nums[high]){
                
            };
        }
         
    }

};

int main(){
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    int target = 3;
    cout << s.search(nums, target);
}

