#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution{
    public:
     vector<vector<int>> findDiffrence(vector<int>& nums1, vector<int>& nums2){
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        set<int> set_diffrence1;
        set<int> set_diffrence2;

        // inserter function tells where to store the elements so the first parameter is that and the second one is where to begin storing 
        set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set_diffrence1, set_diffrence1.begin()));
        set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), inserter(set_diffrence2, set_diffrence2.begin()));

        vector<vector<int>> result;
        result.push_back(vector<int>(set_diffrence1.begin(), set_diffrence1.end()));
        result.push_back(vector<int>(set_diffrence2.begin(), set_diffrence2.end()));

        return result;
     }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};
    vector<vector<int>> result = s.findDiffrence(nums1, nums2);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}