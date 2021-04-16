#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	int row,column;
    cout<<"Enter row and column for 1st matrix: ";
	cin>>row>>column;
	int a[row][column],b[row][column],c[row][column];
	cout<<"\nEnter matrix elements:\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
    	{
			cin>>a[i][j];
    	}
	}
	cout<<"\n";
	cout<<"Enter row and column for 2nd matrix: ";
	cin>>row>>column;
	cout<<"\nEnter matrix elements:\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
    	{
			cin>>b[i][j];
    	}
	}
	
	cout<<"\nSum of the two matrix is:\n";	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			cout<<c[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}
