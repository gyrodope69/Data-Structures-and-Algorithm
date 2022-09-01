#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }
    int rows = x;
    int cols = y;

    while (rows >= 0 && cols >= 0)
    {
        if (arr[rows][cols] == 1)
        {
            return false;
        }
        rows--;
        cols--;
    }

    rows = x;
    cols = y;

    while (rows >= 0 && cols < n)
    {
        if (arr[rows][cols] == 1)
        {
            return false;
        }

        rows--;
        cols++;
    }
    return true;
}

bool nQueen(int **arr, int x, int n)
{
    if (x >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
                  return true;
        }
        arr[x][col] = 0; // backtacking
    }
    return false;
}

int main()
{
    int n=4;
    // cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr = new int *[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, n, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"Boo"<<endl;
    }
    return 0;
}