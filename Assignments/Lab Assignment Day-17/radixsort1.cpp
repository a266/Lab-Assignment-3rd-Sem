//#include <iostream> 
//using namespace std; 
//
//int getMax(int arr[],int n){
//	int max = arr[1];
//	for(int i=2;i<=n;i++)
//	{
//		if(arr[i]>=max)
//			max=arr[i];
//	}
//	return max;
//} 
//
//void countSort(int arr[], int n, int ex) 
//{ 
//    int output[n]; 
//    int i, count[10] = { 0 };  
//    for (i = 0; i < n; i++) 
//        count[(arr[i] / ex) % 10]++; 
//  
//    for (i = 1; i < 10; i++) 
//        count[i] += count[i - 1]; 
//
//    for (i = n - 1; i >= 0; i--) { 
//        output[count[(arr[i] / ex) % 10] - 1] = arr[i]; 
//        count[(arr[i] / ex) % 10]--; 
//    } 
//    for (i = 0; i < n; i++) 
//        arr[i] = output[i]; 
//} 
//
//void radixsort(int arr[], int n) 
//{  
//    int m = getMax(arr, n);  
//    for (int ex = 1; m / ex > 0; ex *= 10) 
//        countSort(arr, n, ex); 
//} 
// 
//void print(int arr[], int n) 
//{ 
//    for (int i = 0; i < n; i++) 
//        cout << arr[i] << " "; 
//} 
//
//int main() 
//{ 
//    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 }; 
//    int n = sizeof(arr) / sizeof(arr[0]); 
// 
//      radixsort(arr, n); 
//    print(arr, n); 
//    return 0; 
//}


#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void show(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<"-------------------------"<<endl;
}
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
int countsort(int a[],int n,int o){
	int i,k,j,pass=0;
	int b[n];
	int c[o+1];
	for(i=0;i<=o;i++){
		c[i]=0;
		pass+=1;
	}
	for(i=0;i<n;i++){
		pass++;
		c[a[i]]+=1;
	}
	cout<<"Count array "<<endl;
	show(c,o+1);
	for(i=1;i<=o;i++){
		c[i]+=c[i-1];
		pass+=1;
	}
	cout<<"Count array "<<endl;
	show(c,o+1);	
	for(j=n-1;j>=0;j--){
		i=c[a[j]]-1;
		b[i]=a[j];
		c[a[j]]-=1;
		pass++;
		}
	cout<<"output  array "<<endl;
	show(b,n);		
	for(i=0;i<n;i++){
	
		a[i]=b[i];
	}	

	return pass;
	}
int max(int a[],int n){
	int t=a[0];
	for(int i=1;i<n;i++)
		{
			if(t<a[i])
				t=a[i];
		}
		return t;
}
int main(void){
	int n;
	cout<<"Enter size ";
	cin>>n;
	int a[n];
	
	in(a,n);
	int y;
	y=countsort(a,n,max(a,n));
	show(a,n);
	cout<<"Pass no "<<y;
	return 0;
}
