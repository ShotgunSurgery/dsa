#include <stdio>
#include <iostream>

class Solution{
	public:
		int lowerBound(vector<int> nums, int x){
			int low = 0, high = nums.size(),ans = 0;
			while(low < high){
				mid = low + (high - low)/2;
				if(nums[mid] >= x){
					ans = mid;
					high = mid;
				}
				else{
					low = mid + 1;
				}
			}
		return ans;
		}
}

int main(){
	vector<int>  = 
}
