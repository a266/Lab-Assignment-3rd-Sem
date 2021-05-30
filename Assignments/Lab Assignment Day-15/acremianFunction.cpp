#include<iostream>
using namespace std;

int ackermannFunction(int m,int n)
{
	if(m==0)
		return n=n+1;
	if(n==0)
		return ackermannFunction(m-1,1);
	else
		return ackermannFunction(m-1,ackermannFunction(m,n-1));
}

int main()
{
	int m,n;
	cout<<"Enter two numbers: ";
	cin>>m>>n;
	cout<<"The Reasult is:";
	cout<<ackermannFunction(m,n)<<endl;
	return 0;
}
