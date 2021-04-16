#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter row of sparse matrix: ";
	cin>>n;
	cout<<"Enter elements:\n";
	int s[n][3],i,j;
	for(i=0;i<n;i++)
	for(j=0;j<3;j++){
	cin>>s[i][j];
	}
	for(i=0;i<n;i++)
	for(j=0;j<3;j++)
	{
		s[i][j]=s[j][i];
	}
	cout<<"Transpose Matrix is:\n";
	for(i=0;i<3;i++){
	for(j=0;j<n;j++)
	{
	
	cout<< s[i][j];
	}
	cout("\n");
	}
	return 0;
}
