#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    stack<int> s;

    MyQueue()
    {
    }

    void push(int x)
    {

        int i;
        stack<int> s2;

        while (!s.empty())
        {
            s2.push(s.top());
            s.pop();
        }

        s.push(x);

        while (!s2.empty())
        {
            s.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int var = s.top();
        s.pop();
        return var;
    }

    int peek()
    {
        return s.top();
    }

    bool empty()
    {
        return s.empty();
    }
};

int main()
{
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */