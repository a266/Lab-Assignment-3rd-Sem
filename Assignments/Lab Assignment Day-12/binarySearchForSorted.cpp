#include<iostream>
using namespace std;

int binarySearch(int arr[],int l,int r,int x)
{

	while(l<=r){
		int mid=(l+r)/2;
		if(x==arr[mid])
			return mid;
		else if(x>arr[mid])
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
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
	int p=binarySearch(arr,l,r,x);
	cout<<p<<endl;
}
