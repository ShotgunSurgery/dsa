#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 10;

struct Entry{
    string key;
    int value;
};

int hash_function(string key){
    int sum = 0;
    for (char c : key) sum += c;
    return sum % TABLE_SIZE;
}

int main(){
    Entry hashArray[TABLE_SIZE]; // declaring and array of the datatype Entry
    bool filled[TABLE_SIZE] = {false};

    string keys[] = {"James", "Jonathan", "Bob"};
    int kills[] = {12, 99, 69};

    for(int i = 0; i < 3; i++){
        int index = hash_function(keys[i]);

        hashArray[index].key = keys[i];
        hashArray[index].value = kills[i];
        filled[index] = true;

        cout<<"Inserted "<<keys[i]<<" "<<kills[i]<<" kills "<<" at position "<<index<<endl;
    }

    string query = "Jon";
    int lookupindex = hash_function(query);
    
    if(filled[lookupindex] && hashArray[lookupindex].key == query){
        cout<<"\nFound "<<query<<"'s kills -> "<<hashArray[lookupindex].value<<endl;
    }
    else{
        cout<< "\n" << query << " not found in hash array. \n";
    }

    return 0;    
}