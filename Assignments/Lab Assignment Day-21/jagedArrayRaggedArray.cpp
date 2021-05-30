#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int r,c,t=1;
	cout<<"Enter row : "<<endl;
	cin>>r;
	int *s=(int*)malloc(r*(sizeof(int)));
	int **a=(int**)malloc(r*sizeof(int*));
	for(int i=0;i<r;i++){
		cout<<"Enter the size of the r"<<t++<<":"<<endl;
		cin>>c;
		s[t-2]=c;
		a[i]=(int*)malloc(c*sizeof(int));
	}
	cout<<"Enter the element for the jagged array: "<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<s[i];j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"The element of the jagged array are: "<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<s[i];j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	free(a);
	free(s);
}
