#include<stdio.h>
#include<iostream>
using namespace std;
 int main()
 {
 	int a[10][10],b[10][10],i,j,row,col;
	cout<<"Enter row and column: ";
	cin>>row>>col;
	cout<<"Enter matrix elements:\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\n";
	
	cout<<"Matrix transpose:\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			b[i][j]=a[j][i];
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
 }
