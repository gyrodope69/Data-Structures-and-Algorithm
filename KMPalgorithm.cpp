#include<bits/stdc++.h>
using namespace std;

int* prefixFunction(string p,int *pi)
{
    int m = p.size();
    // int pi[m];
    pi[0]=-1;
    pi[1]=0;
    int k=0;
    for(int i = 2 ; i<=m ; i++)
    {
        while( k>0 && p[k+1]!=p[i]){
            k=pi[k];
        }
        if(p[k+1]==p[i]){
         k++;
        }
        pi[i]=k;
    }
    return pi;
}

void KMPstringMatcher(string txt, string p )
{
    int n = txt.size();
    int m = p.size();
    int pi[m];
    int *arr = prefixFunction(p,pi);
    int q = 0 ;
    for(int i=1 ; i<n ; i++)
    {
        while(q>0 && p[q+1]!=txt[i])
        {
            q=arr[q];
        }
        if(p[q+1]==txt[i])
        {
            q=q+1;
        }
        if(q==m)
        {
            cout<<"Pattern occurs at shift"<<i-m;
            q=arr[q];
        }
    }
}

int main()
{
    string txt;
    cout<<"Enter the txt : ";
    cin>>txt;
    cout<<"\n";
    string p;
    cout<<"Enter pattern: ";
    cin>>p;
    int l = p.size();
    // int pi[l];
    // int *arr = prefixFunction('#'+p,pi);
    // for(int i=1 ; i<=l; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    KMPstringMatcher(txt,'#'+ p);
    return 0;
}