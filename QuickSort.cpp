#include <bits/stdc++.h>

using namespace std;

void quick_sort(int arr[], int low, int high)   //function for quick sort 
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;  // taking first index of an array as pivot
        i = low;      // pointer i as start index
        j = high;     // pointer j as end index
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i <= high)
            {
                i++;  // increment i until pivot is less than any element
            }
            while (arr[j] > arr[pivot])
            {
                j--;  //decrement j until pivot is greater than any element
            }
            if (i < j)  // Swapping ith and jth element
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];  // swapping jth and pivot element
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quick_sort(arr, low, j - 1);  // running quick sort for left sub array of pivot
        quick_sort(arr, j + 1, high); // running quick sort for right sub array of pivot
    }
}
int main()
{
    int n, low, high;
    cout << "Enter the number of elements : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    low = 0;
    high = n - 1;

    quick_sort(arr, low, high);
    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}