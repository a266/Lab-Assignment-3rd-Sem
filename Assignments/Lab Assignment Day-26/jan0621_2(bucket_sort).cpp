#include<iostream>
using namespace std;
#include "linkedlist.cpp"



void bucket_sort(double a[] , int n){
	linkedlist l[10];
	for(int i=0 ; i<n ; ++i){
            int digit=a[i]*10;
            l[digit].insertatsorted(a[i]);
	}
	int j=0;
	for(int i=0 ; i<10 ; ++i){
           while(!l[i].isempty()) a[j++]=l[i].deletebeg();
	}


}
int main(){
	int n , i;
	cin>>n;
	double a[n];
	for(i=0 ; i<n ; ++i)
		cin>>a[i];

	cout<<"Before sorting"<<endl;
	for(i=0 ; i<n ; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
	bucket_sort(a , n);
	cout<<"After sorting"<<endl;
	for(i=0 ; i<n ; ++i)
		cout<<a[i]<<" ";
	cout<<endl;


}

