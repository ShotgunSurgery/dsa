#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += nums[i];

    double avg = (double)sum / k;

    for (int i = k; i < nums.size(); i++)
    {
        sum += nums[i] - nums[i - k];
        double new_avg = (double)sum / k;
        avg = max(avg, new_avg);
    }

    return avg;
}

};

int main()
{
    Solution s;
    vector<int> nums = {-1};
    int target = 1;
    
    cout << s.findMaxAverage(nums, target);
}