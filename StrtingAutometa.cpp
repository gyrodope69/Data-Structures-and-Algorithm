#include<bits/stdc++.h>
using namespace std;

int transitionFunction(int q , char T , int n , int m, string P)
{
//   int n = T.size();
//   int m = P.size();

  set<char> s;
  for(auto x: P)
  {
    s.insert(x);
  }
  for(int q=0 ; q<=m ; q++)
  {
    int k;
     for(auto x : s)
     {
       k = min(k+1 , q+2);
       while()

     }  
  }


}
void mathcher(string T , string P)
{
    int n = T.length();
    int m = P.length();
    int q=0;
    for(int i = 1 ; i < n ; i++)
    {
        q = transitionFunction(q, T[i],n,m,P);
        if(q==m)
         cout<<"Pattern Found at "<<i-m;
    }
}

int main()
{
 string T , P;
 cout<<"Enter the text string : ";
 cin>>T;
 cout<<"\n Enter the pattern : ";
 cin>>P;

}