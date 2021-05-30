#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

const float pi=3.14;

float vol(float l)
{
	return l*l*l;
}

float vol(float r,float h)
{
	return (pi*r*r*h);
}

float vol(float l,float b,float h)
{
	return (l*b*h);
}
int main()
{
	float l,r,h,b,t;
	cout<<"Enter the length of cube:\n";
	cin>>l;
	t=vol(l);
	cout<<"\nVoloume of cube is: "<<t;
	cout<<"\n\nEnter the radius and height of cylinder:\n";
	cin>>r>>h;
	t=vol(r,h);
	cout<<"\nVolume of cylinder: "<<t;
	cout<<"\n\nEnter the Length,Breadth and Height of the rectangular box:\n";
	cin>>l>>b>>h;
	t=vol(l,b,h);
	cout<<"\nVolume of rectangular box: "<<t;
	return 0;
}
