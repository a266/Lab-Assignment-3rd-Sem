#include<iostream>
using namespace std;


int sum(int arr[],int n)
{ 
	if(n==0)
		{
			return 0;
		}
  	return arr[0]+sum(arr+1,n-1);
}

int main()
{
   	int n;
   	cout<<"Enter number of element you want to input:";
   	cin>>n;
   	int arr[n];
   	cout<<"Enter elements you want to input:"<<endl;
   	for(int i=0;i<n;i++)
   	{
	   cin>>arr[i];
	}
   	cout<<sum(arr,n);
  	return 0;
}

