#include<iostream>
using namespace std;

int lcm(int n1,int n2)
{
	int mult=0;
	mult=mult+n2;
	if((mult % n1 == 0) && (mult % n2 == 0))
	{
		return mult;
	}
	else
	{
		return lcm(n1,n2);
	}
}

int main()
{
	int n1,n2;
	cout<<"Enter two numbers: ";
	cin>>n1;
	cin>>n2;
	int x;
	x=lcm(n1,n2);
	cout<<"The lcm is: "<<x<<endl;
	return 0;	
}
