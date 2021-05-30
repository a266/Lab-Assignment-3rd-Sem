#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	int a[100],m,n,x,i,j;
	cout<<"Enter the size of the array:\n";
	cin>>n;
	cout<<"Enter the elements:\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the sum:";
	cin>>m;
	cout<<"The pairs are: \n";
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]+a[j]==m)
				cout<<a[i]<<"\t"<<a[j];
		}
		cout<<"\n";
	}
	return 0;
}
