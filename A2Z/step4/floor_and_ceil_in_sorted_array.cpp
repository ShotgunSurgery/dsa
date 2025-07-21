#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
    {
        int floor = 0, ceil = a.size() - 1;
        while (floor <= ceil)
        {

            if (a.empty())
                return {0, 0};
            int mid = floor + (ceil - floor) / 2;
            // cout << floor << ceil << mid << endl;
            if (floor == ceil)
            {
                if((ceil - 1) < 0 || (ceil -1) > a.size() && mid == -1) return {a[ceil - 1], a[ceil]};
                else if(ceil < 0 || ceil > a.size() && mid == -1) return{a[ceil], a[ceil] + 1};
                return {a[ceil - 1], a[ceil]};
            }

            else if (a[mid] > x)
            {
                ceil = mid;
            }

            else if(a[mid] == x){
                return {x,x};
            }

            else
            {
                floor = mid + 1;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 4, 7, 8, 8, 10};
    cout << "Floor: " << s.getFloorAndCeil(nums, 6, 5).first << "Ceil: " << s.getFloorAndCeil(nums, 6, 5).second;
}