#include<bits/stdc++.h>
using namespace std;  

 int uglyNum(int n)
 {
    if(n==1)
    {
        return 1;
    }
    vector<int> dp; // vector of ans
    int count = 1;  
    dp.push_back(1);  
    int p2=0 , p3=0, p5=0;
    int ans = 1;
    while(count<n)
    {
        priority_queue<int,vector<int>,greater<int>> heap; 
        heap.push(2*dp[p2]);
        heap.push(3*dp[p3]);
        heap.push(5*dp[p5]);
        
        ans = heap.top();
        dp.push_back(ans);
        count++;
        if(ans%2==0)
            p2++;
        if(ans%3==0)
            p3++;
        if(ans%5==0)
            p5++;
    }
    return ans;

 }

int main()
{
    int n;
    cin>>n;
    cout<<uglyNum(n)<<endl;
    return 0;
}