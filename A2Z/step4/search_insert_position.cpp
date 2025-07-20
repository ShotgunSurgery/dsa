#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int searchInsert(vector<int> & nums, int target){

        if( nums.empty() || nums.size() == 0) return 0;
 
        int low = 0, high = nums.size() - 1, n = nums.size();

        while(low < high){

            int mid = low + (high - low)/2;
            
            if(target == nums[mid]){
                mid;
            }

            else if(nums[mid] > target){
                high = mid;
            }

            else if(target > nums[mid] ){
                low = mid + 1;
            }
        }
        
       return nums[low] < target ? low + 1: low;

    }
};
int main(){
    Solution s;
    vector<int> nums = { 1,3,5,6};
    int target = 7;
    cout<<s.searchInsert(nums, target);

}