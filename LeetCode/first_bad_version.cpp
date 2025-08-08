#include <iostream>

using namespace std;

// Simulated "API"
int bad = 4;  // ← You can change this to test other cases

bool isBadVersion(int version) {
    return version >= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n - 1, temp; 
        while(left <= right){
            int mid = left + (left - right)/2;
            if(!isBadVersion(mid)) left = mid + 1;
            else if(isBadVersion(mid)) {
                temp = mid;
                right - mid - 1;
            }
        }
        return temp;
    }
};

int main() {
    Solution s;
    int n = 5;
    cout << s.firstBadVersion(n) << endl;
}
