#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		int upperBound(vector<int> &v,int target){
			int low = 0, high = v.size() - 1, ans = 0;
			while(low <= high){
				int mid = (low + high)/2;
				if(target == v[mid]){
					ans = mid;
					low = mid + 1;

				}

				else if(target > v[mid]){
					low = mid + 1;
				}

				else{
					high = mid - 1;
				}
			}

			return ans; 
		}
};

int main(){
	Solution s;
	vector<int> v = {1,2,2,3};
	int target = 2;
	cout<<"Index: "<<s.upperBound(v, target); 
}