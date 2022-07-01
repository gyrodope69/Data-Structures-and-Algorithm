#include<bits/stdc++.h>
using namespace std;

int precedence(char c)

{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='/' || c=='*')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else 
    {
        return -1;
    }

}

string infixToPostfix(string s)
{
    stack<char> st;
    reverse(s.begin(),s.end());
    string res="";
    for(int i=0 ; i<s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            res+=s[i];
        }
        else if(s[i]==')')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
         {
            while(!st.empty() && st.top()!=')')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedence(st.top())>=s[i])
            {
                res+=st.top();
                st.pop();
            }
           st.push(s[i]);
        }
        
    }
    while(!st.empty())
    {
        res+= st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
/*
Algorithms:
1. Reverse the string 
2. Traverse from left to right 
3. if '(' push to stack
4. if ')' pop untul we fount '('
5. if operator
    pop from stack and print untilman operator with less precedence is found
6. again reverse the result string
*/
// */-abc-/akl
int main()
{
    string s="(a-b/c)*(a/k-l)";
    // getline(cin, s);
    string ans = infixToPostfix(s);
    cout<<ans<<endl;    
    return 0;
}