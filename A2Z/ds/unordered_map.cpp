#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    // declaration and initialization 
    unordered_map<string, int> map;
    map["key1 "] = 1;
    map["key2 "] = 2;
    map["key3 "] = 3;


    // for (auto i = map.begin(); i != map.end(); i++)
    // {
    //     cout << i->first << " " << i->second << endl;
    // }

    // finding elements 
    // auto element = map.find("key1 ");
    // cout << element->first << element->second;

    //accessing elements and inserting 
    map["key1 "] = 3;
    cout << map["key1 "];
} 