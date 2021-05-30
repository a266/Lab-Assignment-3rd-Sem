#include<iostream>
#define MAX 1000
using namespace std;

int search(int arr[],int left,int right,int x)
{
	if(left<=right)
	{
		int mid1;
		int mid2;
		mid1=left+((right-left)/3);
		mid2=right-((right-1)/3);
		if(arr[mid1]==x)
			return mid1;
		else if(arr[mid2]==x)
			return mid2;
		else if(x<arr[mid1])
			return search(arr,left,mid1-1,x);
		else if(x>arr[mid2])
			return search(arr,mid2+1,right,x);
		else
			return search(arr,mid1+1,mid2-1,x);
	}
	else
		return -1;
}


int main()
{
	int arr[MAX],l=0,r,x,n;
	cout<<"Enter number of element which you want to enter in the array: ";
	cin>>n;
	cout<<"Enter sorted array: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];	
	}
	cout<<"Enter a number you want to search: ";
	cin>>x;
	r=n-1;
	cout<<"The number is preasent in "<<search(arr,l,r,x)<<endl;
	return 0;
}
