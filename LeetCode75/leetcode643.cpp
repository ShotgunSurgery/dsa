#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int l = 0, avg = 0, sum = 0, new_avg;
        while ((l + 4) < nums.size())
        {
            for (l; l < (l + 4); l++)
            {
                sum = sum + nums[l];
            }
            new_avg = sum / 4;
            avg = (new_avg > avg) ? new_avg : avg;
            l += 1;
        }
        return avg;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int target = 4;
    cout << s.findMaxAverage(nums, target);
}