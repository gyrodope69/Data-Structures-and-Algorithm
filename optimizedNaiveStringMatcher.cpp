#include<bits/stdc++.h>
using namespace std;

void optString( string s , string p)
{
  int n = s.length(); // original string
  int m = p.length(); // pattern string
  int i = 0; 
  while(i<=n-m)
  {
    int j;
    for(j = 0; j < m; j++)
    {
        if(s[i+j]!=p[j])
        {
            break;
        }
    }
    if(j==m)
    {
        cout<<"Patter found at index "<<i<<endl;
        i=i+m;
    }
    else if(j==0)
    {
        i=i+1;
    }
    else
    {
        i=i+j;
    }
  }

}
int main()
{
    string s ,  p;
    cin>>s;
    cin>>p;
    optString(s, p);
    return 0;
}