#include<iostream>
using namespace std;

int fact(int n){
	if(n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);
}

int main()
{
	int p;
	cout<<"Enter the number: ";
	cin>>p;
	cout<<"Factorial of the number is: "<<endl;
	cout<<fact(p);
	return 0;
}
