// Insertion Sort using recurssion
#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int n)
{
    if (n == 1)
        return;

    int j = n - 1;
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    n = n - 1;
    insertion_sort(arr, n);
}

void print(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Entet the number of elements:\n";
    cin >> n;
    cout << "Enter the element in array:\n";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertion_sort(arr, n);
    cout << "Sorted array is :\n";
    print(arr, n);
    return 0;
}