// code for bubble sort in array 


#include <bits/stdc++.h>
using namespace std;


int main()
{
    cout << "Enter number of elements:\n";
    int n;
    cin >> n;
    int arr[n];
    cout << "\nEnter elements in array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >>arr[i];
    }                 
    // bubbleSort(arr,n);
    int temp = 0;
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    cout << "The sorted array is :\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}