#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int r,c;
	cout<<"Enter row and coloumn of the matrix: ";
	cin>>r>>c;
	int **a=(int**)malloc(r*sizeof(int*));
	for(int i=0;i<r;i++)
	{
		a[i]=(int*)malloc(c*sizeof(int));
	}
	cout<<"Enter Matrix Element: "<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	int **b=(int**)malloc(r*sizeof(int*));
	
	for(int i=0;i<r;i++)
		b[i]=(int*)malloc(c*sizeof(int));
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			b[i][j]=a[j][i];
			
	cout<<"The give matrix is: "<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"The Transpose of the matrix is: "<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
