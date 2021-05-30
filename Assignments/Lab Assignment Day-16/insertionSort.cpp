#include<iostream>
using namespace std;


void display(int array[], int size) {
   	for(int i = 0; i<size; i++)
      	cout << array[i] << " ";
   	cout << endl;
}


void insertionSort(int array[], int size) {
   	int key, j,count=0;
   	for(int i = 1; i<size; i++) {
      	key = array[i];
      	cout<<"Pass : "<<i<<endl;
      	j = i;
      	while(j > 0 && (++count && array[j-1]>key)) {
//      		count++;
        	array[j] = array[j-1];
        	j--;
      	}
      	array[j] = key;
      	for(int k=0;k<size;k++)
		{
			cout<<array[k]<<" ";
		}
		cout<<endl;
   	}
   	cout<<"the number of comparision: "<<count<<endl;
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
}
