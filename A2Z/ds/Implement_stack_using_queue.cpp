#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> q;
    void push(int x)
    {
        int i;
        q.push(x);
        for (i = 0;i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        q.pop();
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.emplace();
    }
};

int main()
{
}