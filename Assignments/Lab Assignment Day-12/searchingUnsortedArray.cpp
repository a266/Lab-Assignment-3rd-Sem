#include<iostream>
using namespace std;

int search(int arr[],int l,int r,int x)
{

	if(l>r)return -1;
	if(arr[l]==x)return l;
	if(arr[r]==x)return r;
	return search(arr,l+1,r-1,x);
}

int main()
{
	int n;
	int arr[n],x;
	cout<<"Eneter array size: ";
	cin>>n;
	int l=0,r=0;
	cout<<"Eneter the element which you want to find: ";
	cin>>x;
	cout<<"Enter array element: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	r=n;
	int p=search(arr,l,r,x);
	cout<<p<<endl;
}
