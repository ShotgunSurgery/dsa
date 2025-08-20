#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:

    stack<int> s;
    stack<int> dummy;
    int i = 0, min;

    MinStack() {
        
    }
    
    void push(int val) {
        if(i == 0){
            min = val;
            i++;
        }
        if(val <= min){
            min = val;
            dummy.push(val);
        }
        
        if(s.empty()) i--;
        s.push(val);    
    }
    
    void pop() {
        if(s.top() == dummy.top()) dummy.pop();
        s.pop();
        if(s.empty()) i--;
    }
    
    int top() {
        return s.top();
        if(s.empty()) i--;
    }
    
    int getMin() {
        return dummy.top();
        if(s.empty()) i--;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    MinStack m;
    
}