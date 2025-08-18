#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:

    queue<int> q;        
    int topp = -1; 

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);        
        topp+=1;
    }
    
    int pop() {
        queue<int> dummy;
        for(int i = 0;i < q.size() - 1; i++){
            int temp = q.front();
            q.pop();
            dummy.push(temp);
        }        
        int var = q.front();
        q.pop();
        for(int i = 0; i < q.size() - 1; i++){
            int temp = dummy.front();
            dummy.pop();
            q.push(temp);
        }
        topp-=1;
        return var;
    }
    
    // int top() {
    //     queue<int> dummy;
    //     int temp;
    //     int size = q.size();
    //     for(int i = 1;i <= size; i++){
    //         // cout << "i check: " << i << q.size() << endl;
    //         temp = q.front();
    //         // int temp -> variable shadowing -> at the end the one declared in the larger scope will be returned 
    //         // cout << temp << endl;
    //         q.pop();
    //         // dummy.push(temp);
    //     }        
    //     return temp;        
    // }

    int top() {
    queue<int> dummy;
    int temp;

    while (!q.empty()) {
        temp = q.front();  // last one stored in temp
        dummy.push(temp);
        q.pop();
    }

    // restore original queue
    q = dummy;

    return temp;  // this is the last pushed element
}

    
    bool empty() {
        // cout << "check empty: " << topp << endl;
        if(topp == -1) return true;
        else return false;
    }
};

int main(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->top();
    // cout << obj->pop();
    // cout << "empty: " << obj->empty();
}