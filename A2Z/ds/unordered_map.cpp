#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    unordered_map<string, int> map;
    map["key1 "] = 1;
    map["key2 "] = 2;
    map["key3 "] = 3;
    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }
}