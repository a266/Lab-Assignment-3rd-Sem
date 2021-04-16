#include <iostream>
using namespace std;
int main()
{
    int A[10][10];
    int B[10][10];
    int row, col, isEqual,i,j;
    cout<<"Enter row and coloumn of two matrix: ";
    cin>>row>>col;
    cout<<"Enter elements in matrix A:\n";
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"Enter elements in matrix B:\n";
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cin>>B[i][j];
        }
    }
    isEqual = 1;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        { 
            if(A[i][j] != B[i][j])
            {
                isEqual = 0;
                break;
            }
        }
    }

    if(isEqual == 1)
    {
        cout<<"\nMatrix A is equal to Matrix B";
    }
    else
    {
        cout<<"\nMatrix A is not equal to Matrix B";
    }
 
    return 0;
}
