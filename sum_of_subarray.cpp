#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cout<<"Entet the number of elements: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the array: ";
    for(int i = 0; i < n ; i++) {
        cin>>arr[i];
    }
   
    cout<<"Sum of all subarrays: \n";
    for(int i = 0; i < n; i++) {
        int sum=0;
        for(int j=i ; j<n ; j++) {
           sum+=arr[j];
           cout<<sum<<endl;
        }
    }
}