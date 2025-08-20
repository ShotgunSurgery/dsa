#include <iostream>
#include <stack>

using namespace std;

class Dummy{
    public:
    // traversing the stack
    void print(stack<int> st){
        while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    };
};

int main(){
    Dummy dy;
    stack<int> st;
    st.push(69);
    st.push(70);

    // copying the stack from st to st2
    stack<int> st2(st);
    cout << "This is stack2: " << endl;
    dy.print(st2);
    return 0;
}   