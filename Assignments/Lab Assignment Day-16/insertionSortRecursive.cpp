#include<iostream>
using namespace std;

int c=0;
int pass=0;


void insertionSort(int arr[],int n)
{
	if(n<=1)
	return;
	insertionSort(arr,n-1);
	cout<<"Pass :  "<<++pass<<endl;
	for(int k=0;k<n;k++)
	{
		cout<<arr[k]<<" ";
		cout<<endl;
	}
	int key=arr[n-1];
	int j=n-2;
	while(j>=0 && (c++ && arr[j]>key))
	{
		arr[j+1]=arr[j];
		j--;
	}
	arr[j+1]=key;
}

void display(int array[], int size) {
   	for(int i = 0; i<size; i++)
      	cout << array[i] << " ";
   	cout << endl;
}

int main()
{
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
}
