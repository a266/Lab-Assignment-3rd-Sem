#include<iostream>
using namespace std;

bool prime(int x,int y)
{
	if(x==1 && y==1)
		return true;
	else if(x != 1 && y != 1 && x==y)
		return false;
	else if(x != 1 && y != 1 && x<y)
		return prime(x,y-x);
	else if(x != 1 && y != 1 && x>y)
		return prime(x-y,y);
}

int main()
{
	int x,y;
	cout<<"Enter two numbers: ";
	cin>>x>>y;
	if(prime(x,y))
		cout<<"prime";
	else
		cout<<"not-prime";
}
