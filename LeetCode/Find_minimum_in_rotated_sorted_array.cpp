#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = (nums.size() - 1), lowest = nums[lo];
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            // cout << "lo: " << lo << " " << " hi: " << hi << " " << " mid: " << mid << endl;
            
            if(nums[lo] < nums[mid]){
                // cout << "lo: " << nums[lo] << " " << " hi: " << nums[hi] << " " << " mid: " << nums[mid] << " lowest: " << lowest << endl;
                                //  return -1;
                if(nums[lo] <= lowest){
                    lowest = nums[lo];
                    lo = mid + 1;
                                // cout << "lo: " << lo << " " << " hi: " << hi << " " << " mid: " << mid << endl;
                                //  return -1;  
                };
            }
            else{
                  if(nums[mid] <= lowest){
                    lowest = nums[mid];
                    hi = mid - 1;
                  };
            }
        }
        return lowest;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 4, 5, 0, 1, 2};
    cout << s.findMin(nums);    
}