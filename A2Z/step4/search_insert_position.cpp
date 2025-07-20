#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int searchInsert(vector<int> & nums, int target){
        int low = 0, high = nums.size() - 1, ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(low == high && low == mid){
                ans = mid;
                low = mid + 1;
            }

            else if(nums[mid] == target){
                return mid;
            }

            else if(target > nums[mid] ){
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }
        
        if(nums[ans] == target){
            return ans;
        }
        else if(nums[ans] < target){
            return (ans + 1);
        }
        else{
        return (ans);}

    }
};
int main(){
    Solution s;
    vector<int> nums = { 1,3,5,6};
    int target = 7;
    cout<<s.searchInsert(nums, target);

}