#include<bits/stdc++.h>
using namespace std;

bool recurssionSort(int arr[],int n)
{
    
 if(n==1)
 {
     return true;
 }
  bool rest = recurssionSort(arr+1,n-1);
  return(arr[0]<arr[1] && rest);
}

int main()
{
    int arr[]={1,2,3,4};
    cout<<recurssionSort(arr,4);
    return 0;
}