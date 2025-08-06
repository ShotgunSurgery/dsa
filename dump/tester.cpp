#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int upper_bound(vector<int> &array, int N, int X) {
        int lower = 0, upper = N - 1, index = -1;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if (array[mid] == X) {
                index = mid;
                lower = mid + 1; // keep going right
            } else if (array[mid] < X) {
                lower = mid + 1;
            } else {
                upper = mid - 1; // correct here
            }
        }
        return index;
    }

    int lower_bound(vector<int> &array, int N, int X) {
        int lower = 0, upper = N - 1, index = -1;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if (array[mid] == X) {
                index = mid;
                upper = mid - 1; // keep going left
            } else if (array[mid] < X) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return index;
    }

    int counter(vector<int> &array, int N, int X) {
        int upper = upper_bound(array, N, X);
        int lower = lower_bound(array, N, X);
        if (upper == -1 || lower == -1) return 0;
        return (upper - lower + 1);
    }
};

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> array;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        array.push_back(x);
    }

    Solution s;
    cout << s.counter(array, N, X);
    return 0;
}
