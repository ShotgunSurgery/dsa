// Reverse Polish Notation (RPN) -> postfix notation
#include <iostream>
#include <stack>
#include <ctype.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int predecesence(char ch)
    {
        if (ch == '+' || ch == '-')
            return 1;
        else if(ch == '*' || ch == '/')
            return 2;
        else return 3;
    }

    string infixToPostfix(string str)
    {

        stack<char> s;
        string output = "";

        for (char ch : str)
        {
           if (isalpha(ch) || isdigit(ch)) {
    output += ch;
}
else if (ch == '(') {
    s.push(ch);
}
else if (ch == ')') {
    while (!s.empty() && s.top() != '(') {
        output += s.top();
        s.pop();
    }
    if (!s.empty() && s.top() == '(') {
        s.pop(); // discard '('
    }
}
else { // operator +, -, *, /
    while (!s.empty() && s.top() != '(' && predecesence(ch) <= predecesence(s.top())) {
        output += s.top();
        s.pop();
    }
    s.push(ch);
}

        }

        while (!s.empty())
        {
            output = output + s.top();
            s.pop();
        }

        return output;
    }
};

int main()
{
    int n, i;
    cin >> n;
    vector<string> arr;
    Solution s;
    // string expression = "a+b*c";
    for (i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        arr.push_back(x);
    }

    for (i = 0; i < n; i++)
    {
        cout << s.infixToPostfix(arr[i]) << endl;
    }
}