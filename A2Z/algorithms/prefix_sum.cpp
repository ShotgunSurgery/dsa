#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int> &nums) {
        prefix.push_back(0);  // Initialize prefix[0] = 0

        for (int i = 0; i < nums.size(); i++) {
            prefix.push_back(prefix.back() + nums[i]);
            cout << "prefix[" << i + 1 << "] = " << prefix[i + 1] << endl;
        }
    }

    int sumRange(int left, int right) {
        cout << "prefix[" << right + 1 << "] = " << prefix[right + 1]
             << ", prefix[" << left << "] = " << prefix[left] << endl;

        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj(nums);

    cout << "sumRange(0, 2): " << obj.sumRange(0, 2) << endl;
    cout << "sumRange(0, 5): " << obj.sumRange(0, 5) << endl;
    cout << "sumRange(2, 5): " << obj.sumRange(2, 5) << endl;

    return 0;
}
