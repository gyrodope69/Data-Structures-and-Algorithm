#include<bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>> &matrix , int row , int col )
{
    vector<int> rows(row,-1);
    vector<int> cols(col,-1);
    // int i , j;
    for(int i=0 ; i<row; i++)
    {
        for(int j=0 ; j<col ; j++)
         {
            if(matrix[i][j]==0)
             {
                cols[j]=0;
                rows[i]=0;
             }
         }
    }

    for(int i = 0 ; i<row ; i++)
    {
        for(int j = 0 ; j<col ; j++)
        {
            if(cols[j]==0 || rows[i]==0)
            {
                matrix[i][j]=0;
            }
        }
    }
}
int main()
{
    int row , column;
    cout<<"Enter row and column: ";
    cin>>row>>column;
    vector<vector<int>> matrix;
    cout<<"Enter matrix:"<<endl;
    int x;
    for(int i = 0 ; i<row ; i++)
    {
        vector<int> temp;
        for(int j =0  ; j<column ; j++){
         cin>>x;
         temp.push_back(x);
        }
        matrix.push_back(temp);
        temp.clear();

    }
    setMatrixZero(matrix , row , column);
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < column ; j++) 
        { 
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }   
   return 0;
}