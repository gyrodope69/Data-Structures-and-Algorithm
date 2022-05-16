#include <bits/stdc++.h>

using namespace std;

/***NORMAL IMPLEMENTATION****/


// int  binSearch(int n, int arr[], int key)
// {
//   int start=0;
//   int end=n;
//   while(start<=end)
//   {
//       int mid=(start+end)/2;
//       if(arr[mid]==key)
//       {
//           return mid;
//       }
//       else if(arr[mid]>key)
//       {
//          end=mid-1;
//       }
//       else if(arr[mid]<key)
//       {
//           start=mid+1;
//       }
//   }
//   return -1;
// }

/*****IMPLEMENTING BINARY SEARCH USING RECURSION*****/
int binSearch(int s, int e, int key, int arr[])
{
    int mid = (s + e) / 2;
    if (arr[mid] == key)
        return mid;

    else if (arr[mid] > key)
    {
        return binSearch(s, mid - 1, key, arr);
    }
    else if (arr[mid] < key)
    {
        return binSearch(mid + 1, e, key, arr);
    }

    else
        return -1;
}


// Time Complexity of binary search is:  O(logn)

int main()
{
    int n;
    cout << "Enter the size of array:\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // sort(arr,arr+n);
    int key, s = 0, e = n;
    cout << "Enter the element that you want to search:\n";
    cin >> key;
    cout << binSearch(s, e, key, arr) << endl;

    return 0;
}

