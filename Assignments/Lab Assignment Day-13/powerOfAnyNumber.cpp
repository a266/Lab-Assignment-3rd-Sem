#include<iostream>
using namespace std;

int power(int num,int a)
{
	if(a != 0)
		return (num * power(num,a-1));
	return 1;
}

int main()
{
	int a,num,result;
	cout<<"Enter number: ";
	cin>>num;
	cout<<"Enter the power: ";
	cin>>a;
	result = power(a,num);
	cout<<"The reasult is: "<<result<<endl;
	return 0;
}

