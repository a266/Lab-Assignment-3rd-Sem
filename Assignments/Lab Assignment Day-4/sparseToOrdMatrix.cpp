#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the rows of the sparse matrix: ";
	cin>>n;
	int s[n][3],i,j;
	cout<<"Enter the elements of sparse matrix:";
	for(i=0;i<n;i++)
	for(j=0;j<3;j++)
	cin>>s[i][j];
	int r=s[0][0];
	int c=s[0][1];
	int a[r][c];
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			a[i][j]=0;
	for(i=1;i<=s[0][2];i++)
	{
		int m1=s[i][0];
		int n1=s[i][1];
		a[m1][n1]=s[i][2];
	}
	cout<<"Ordinary Matrix:\n";
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
