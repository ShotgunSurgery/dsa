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
        int left = 1, right = n, temp = 0; 
        // cout << "left: " << left << " " << " right: " << right << " " << " mid: " << "-" << " " << " temp: " << temp << endl; 
        while(left <= right){
            int mid = left + (right - left)/2;
            // cout << "left: " << left << " " << " right: " << right << " " << " mid: " << mid << " " << " temp: " << temp << endl;
            if(!isBadVersion(mid)) left = mid + 1;
            else if(isBadVersion(mid)) {
                temp = mid;
                right = mid - 1;
            }
            // cout << "left: " << left << " " << " right: " << right << " " << " mid: " << mid << " " << " temp: " << temp << endl;
            // return -1;
        }
        return temp;
    }
};

int main() {
    Solution s;
    int n = 5;
    cout << s.firstBadVersion(n) << endl;
}
