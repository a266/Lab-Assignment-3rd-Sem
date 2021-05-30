#include<iostream>
#include<math.h>
using namespace std;


int main(){
	int t;cin>>t;
	while(t--){
		int a,b,n;
		cin>>a;
		cin>>b;
		cin>>n;
		for(int j=0;j<n;j++){
			a=a+pow(2,j)*b;
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}
