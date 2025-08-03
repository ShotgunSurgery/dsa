#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public: 
    int subArraySum(int nums[], int size_nums, int target){
        int count = 0, sum = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for(int i = 0; i < size_nums; i++){
            sum += nums[i];
            if(map.find(sum - target) != map.end()){
                count += map[sum - target];
            }
        }
        return count;
    };
};
