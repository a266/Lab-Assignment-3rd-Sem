#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll> 
#define pb push_back
#define For(i,n) for(ll i=0;i<n;i++)
#define MOD 1000000007
#define MAX 100005
#define pll pair <ll,ll>
#define fi first
#define se second
#define endl '\n'
using namespace std;
int cnt=0;
int partition(int a1[],int l,int r){
    int pivot = a1[l];
    int i = l-1,j=r+1;
    while(true){
    	do{
    		i++;
    	}while(a1[i]<pivot && ++cnt);
    	do{
    		j--;
    	}while(a1[j]>pivot && ++cnt);
    	if(j>i){
    		cout<<"Swapping "<<a1[i]<<" and "<<a1[j]<<endl;
    	    swap(a1[i],a1[j]);
    	}
    	else{
    	    return j;
    	}
    }
    // cout<<i<<" "<<j<<endl;
    
}
void qSort(int v[],int l,int r){
    if(l<r){
    	int p = partition(v,l,r);
    	qSort(v,l,p-1);
    	qSort(v,p+1,r);
    	cout<<"Array after pass: "<<endl;
    	for(int i=l;i<=r;i++){
    	    cout<<v[i]<<" ";
    	}
    	cout<<endl;
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int tc=1;
	cin>>tc;
	For(ti,tc){
		cnt=0;
		int n;
		cin>>n;
		int a1[n];
		For(i,n)cin>>a1[i];
		cout<<"Array before Sorting:\n";
		For(i,n)cout<<a1[i]<<" ";
		cout<<endl<<endl;
		qSort(a1,0,n-1);
		cout<<endl;
		cout<<"Array after Sorting:\n";
		For(i,n){
			cout<<a1[i]<<" ";
		}
		cout<<endl;
		cout<<"Number of passes: "<<cnt<<endl;
		cout<<endl;
	}	
}