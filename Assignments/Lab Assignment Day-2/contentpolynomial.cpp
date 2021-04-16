#include<iostream>
using namespace std;
int gcd(int a,int b){
	int g;
	if(b==0)
		return a;
	else
		return gcd(b,a%b);		
}
int content(int a[],int n){
	int g,i;
	g=a[0];
	for(i=1;i<n;i++){
		g=gcd(g,a[i]);
	
	}
	
	return g;
}

void in(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<"ENTER OF x^"<<i<<" ";
		cin>>a[i];
	}
		
}
int main(void){
	int a[5];
	int n;
	
	cin>>n;
	cout<<"ENTER THE COEFFICIENTS OF "<<endl;
	in(a,n);
	
	cout<<"Content of the poly "<<content(a,n);
}
