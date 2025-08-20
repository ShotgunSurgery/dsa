#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int predecesence(char ch)
    {
        if (ch == '+' || ch == '-')
            return 1;
        else if (ch == '*' || ch == '/')
            return 2;
        else
            return 3;
    }

    string infixToPostfix(string str)
    {

        stack<char> s;
        string output = "";

        for (char ch : str)
        {
            if (isalpha(ch) || isdigit(ch))
            {
                output += ch;
            }
            else if (ch == '(')
            {
                s.push(ch);
            }
            else if (ch == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    output += s.top();
                    s.pop();
                }
                if (!s.empty() && s.top() == '(')
                {
                    s.pop(); // discard '('
                }
            }
            else
            { // operator +, -, *, /
                while (!s.empty() && s.top() != '(' && predecesence(ch) <= predecesence(s.top()))
                {
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

    string infixToPrefix(const string &str)
{
    string rev = "";

    for (char ch : str)
    {
        if (ch == '(')
            rev = ')' + rev;
        else if (ch == ')')
            rev = '(' + rev;
        else
            rev = ch + rev;
    }

    string postfix = infixToPostfix(rev);

    string prefix = "";
    for (char ch : postfix)
        prefix = ch + prefix;

    return prefix;
}

};

int main()
{
    Solution s;

    string str = "(a+b)*c";
    cout << s.infixToPrefix(str);
}   