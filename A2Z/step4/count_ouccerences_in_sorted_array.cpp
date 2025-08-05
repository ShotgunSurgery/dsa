#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    int upper_bound(vector<int> & array, int N, int X){
        int lower = 0, upper = N -1, index = 0;
        while(lower < upper){
            int mid = (lower + upper)/2;
            if(mid == X){
                index = mid;
                lower = mid + 1;
            }

            else{
                upper = mid;
            }
        }
        return index;
    }

    int lower_bound(vector<int> & array, int N, int X){

    }

    int counter(vector<int> & array, int N, int X){
     int upper = upper_bound(array, N, X);
     int lower = lower_bound(array, N, X);
    }
};
int mian(){
    int N, X;
    cin >> N >> X;
    vector<int> array;
    Solution s;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        array.push_back(x);
        cout << s.counter(array, N, X);
    }
    cout << s.upper_bound(array, N, X);
    return 0;

}