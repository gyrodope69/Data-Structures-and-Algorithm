#include<bits/stdc++.h>

using namespace std;

bool checkRedundancy(string s)
{
    stack<char> st;
    for(int i=0 ; i<s.length() ; i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
        {
            st.push(s[i]);
        }

        else if(s[i]=='(')
        {
            st.push(s[i]);
        }

        else if(s[i]==')')
        {
            if(st.top()=='(')
            {
                return true;
            }

            while(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
            {
                st.pop();
            }
            st.pop();
        }
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<checkRedundancy(s);
    
    return 0;
}