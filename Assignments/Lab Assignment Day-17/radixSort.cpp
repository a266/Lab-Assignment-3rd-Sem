#include<iostream>
using namespace std;
int pass=0;

void display(int array[], int size) {
   	for(int i = 0; i<size; i++)
      	cout << array[i] << " ";
   	cout << endl;
}

int getMax(int a[] , int n){
	int ma=-1 , i;
	for( i=0 ; i<n ; ++i){
		if(ma<a[i])
			ma=a[i];
	}
	return ma;
}
void counting_sort(int a[] , int n , int pow10){
	int  i , digit;
	int count[10] , output[n] ;
	for(i=0 ; i<10 ; ++i)
		count[i]=0;
	for(i=0 ; i<=n-1 ; ++i){
	 digit=(a[i]/pow10)%10;
		count[digit]++;
	}
		
	for(i=1 ; i<10 ; ++i)
		count[i]=count[i]+count[i-1];
	for(i=n-1 ; i>=0 ; --i){
		digit=(a[i]/pow10)%10;
		int index=count[digit]-1;
		output[index]=a[i];
		count[digit]--;
	}
	for(i=0 ; i<n ; ++i)
		a[i]=output[i];
}
void radix_sort(int a[] , int n){
	int ma=getMax(a , n);
	int pow10=1;
	int t=1;
	while(ma>0){
		counting_sort(a , n , pow10);
		pow10=pow10*10;
		ma/=10;
		cout<<"pass"<<t++<<":";
		for(int i=0 ; i<n ; ++i)
			cout<<a[i]<<" ";
			cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter the Range: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Before Sorting: "<<endl;
	display(arr,n);
	radix_sort(arr,n);
	cout<<"After Sorting: "<<endl;
	display(arr,n);
	return 0;
}

 

