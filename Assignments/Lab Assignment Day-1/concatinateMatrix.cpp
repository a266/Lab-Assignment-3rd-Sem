#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a[10][10],b[10][10],c[10][10],row,col,i,j;
	cout<<"Enter row and coloumn for 1st matrix:\n";
	cin>>row>>col;
	cout<<"Enter elements of first matrix:\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\n";
	
	cout<<"Enter row and coloumn for 2nd matrix:\n";
	cin>>row>>col;
	cout<<"Enter elements of second matrix:\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<"\n";
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			c[i][j]=a[i][j];
			c[i][j+col]=b[i][j];
		}
	}
	
	for (i = 0; i < row; i++)
	{ 
        for (j=0;j<2*col;j++) 
            cout<<c[i][j]<<" "; 
        cout << endl; 
	}
	return 0;
}
