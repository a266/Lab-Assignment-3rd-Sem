#include<iostream>
using namespace std;

int count=0;

void display(int array[], int size) {
   	for(int i = 0; i<size; i++)
      	cout << array[i] << " ";
   	cout << endl;
}

int binarySearch(int arr[],int low,int high,int x){
	if(high<=low){
		count++;
		if(x>arr[low])
			return (low+1);
		else
			return low;
	}
	int mid=((low+high)/2);
	if(x==arr[mid]){
		return mid+1;
		count++;
	}
	if(x>arr[mid])
	{
		return binarySearch(arr,mid+1,high,x);
		count++;	
	}
	return binarySearch(arr,low,mid-1,x);
}

int insertionSort(int array[], int size) {
   	int key, j;
   	int swap=0;
   	int pos;
   	for(int i = 1; i<size; i++) {
      	key = array[i];
      	cout<<"Pass : "<<i<<endl;
      	j = i-1;
      	
      	
      	pos=binarySearch(array,0,j,key);
      	
      	while(j >= pos) {
      		swap++;
        	array[j+1] = array[j];
        	j=j-1;
      	}
      	array[j+1] = key;
      	for(int k=0;k<size;k++)
		{
			cout<<array[k]<<" ";
		}
		cout<<endl;
   	}
   	cout<<"Total number of swapping: "<<swap<<endl;
}


int main() {
   	int n;
   	cout << "Enter the number of elements: ";
   	cin >> n;
   	int arr[n];
   	cout << "Enter elements:" << endl;
   	for(int i = 0; i<n; i++) {
      	cin >> arr[i];
   	}
   	cout << "Array before Sorting: ";
   	display(arr, n);
   	insertionSort(arr, n);
   	cout << "Array after Sorting: ";
   	display(arr, n);
   	cout<<"Total number of comparision: "<<count<<endl;
}
