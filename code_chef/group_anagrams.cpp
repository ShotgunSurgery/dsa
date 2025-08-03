#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs){

      vector<unordered_map<char, int>> maps;
      vector<vector<string>> final;

      for(int j = 0; j < strs.size(); j++){
        unordered_map<char, int> map;
        for(char ch : strs[j]){
            map[ch]++;
        }
        maps.push_back(map);
      }

      final[0].push_back(strs[0]);

      for(auto k = maps.begin(); k < maps.end(); k++){
        if(maps)
      }
    }
};

int main(){
    int no_strings;
    vector<string> vector_strings;
    for(int i = 0; i < no_strings; i++){
        char str[10];
        cin >> str;
        vector_strings.push_back(str);
    }
    Solution s;
    vector<vector<string>> output = s.groupAnagrams(vector_strings);
}