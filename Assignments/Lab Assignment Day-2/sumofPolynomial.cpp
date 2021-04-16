#include<iostream>
#include<stdlib.h>
using namespace std;
void show(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}
void in(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
}
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
void final(int a[],int b[],int c[],int k ){
	int i;
	for(i=0;i<k;i++)
		c[i]=a[i]+b[i];
}
void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
       cout << poly[i];
       if (i != 0)
        cout << "x^" << i ;
       if (i != n-1)
       cout << " + ";
    }
}
int main(void){
	int a[7],b[7];
	int m,n,k;
	cout<<"Enter highest power of the first polynominal ";
	cin>>m;
	cout<<"Enter highest power of the second polynominal ";
	cin>>n;
	k=max(m,n);
	int c[k];
	cout<<"Enter first poly\n"<<endl;
	in(a,m);
	printPoly(a,m);
	cout<<"\nEnter second poly\n"<<endl;
	in(b,n);
	printPoly(b,n);
	final(a,b,c,k);
	cout<<endl<<endl<<"resulted poly"<<endl;
	printPoly(c,k);
}
