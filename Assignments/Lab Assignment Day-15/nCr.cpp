#include<iostream>
using namespace std;

int ncr(int n , int r){
	if(n<=r) return 1;
	if(n==0 || r==0) return 1;
	
	return ncr(n-1 , r-1)+ncr(n-1 , r);
}

int main(){
	int n , r;
	cout<<"Enter n and r: ";
	cin>>n>>r;
	cout<<ncr(n , r)<<endl;
}
