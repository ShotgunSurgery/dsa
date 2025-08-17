#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[mid + 1]) {
            hi = mid;   // peak is on the left (including mid)
        } else {
            lo = mid + 1; // peak is on the right
        }
    }
    return lo;
};

int main(){
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums);
}