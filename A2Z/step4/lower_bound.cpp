#include <iostream>
using namespace std;

class Solution{
public:
	int lowerBound(vector<int> &nums, int x){
		int lower = 0, higher = nums.size() - 1, mid = (lower + higher)/2;
		while(lower != higher){
			if(nums[x] == nums[mid]){}
			else if(nums[x] > nums[mid]){}
			else{}
			
		}
	}
}

int main(){
	vector<int> v = {1,2,2,3};
	int x = 2;
	cout<<"Index"<<lowerBound(v, x)<<"is the smallest index such that"<<v[lowerBound(v, x)] >= x;

}
