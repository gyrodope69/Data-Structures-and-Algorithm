#include <bits/stdc++.h>
using namespace std;

// function to give the precedence
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }

    if (ch == '*' && ch == '/')
    {
        return 2;
    }

    if (ch == '+' && ch == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

// fucntion to convert infix to postfix
string infixToPostfix(string s)
{
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > s[i])
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    string ans = infixToPostfix(s);
    cout << ans << endl;
    return 0;
}