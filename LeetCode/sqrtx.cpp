#include <iostream>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = x, temp;
        while(left <= right){
            int mid = left + (right - left)/2;
            long long sqr = 1LL * mid * mid;
            if(sqr == x) return mid;
            else if(sqr > x) right = mid - 1;
            else{
                left = mid + 1;
                temp = mid;
                // cout << "left: " << left << " mid: " << mid << " right" << right << endl;
            }
        }
        return temp;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.mySqrt(n);
}