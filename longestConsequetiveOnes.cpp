#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(auto &i : arr)
    {
        cin>>i;
    }

    int zeroCount=0,i=0,ans=0;
    for(int j = 0 ; j<n ; j++)
    {
        if(arr[j]==0)
        {
            zeroCount++;
        }

        while(zeroCount>k)
        {
            if(arr[i]==0)
            {
                zeroCount--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
    
    cout<<ans<<endl;
    return 0;
}
