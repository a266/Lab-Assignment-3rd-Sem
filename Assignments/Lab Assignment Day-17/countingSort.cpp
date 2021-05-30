#include<iostream>
#include<algorithm>
using namespace std;
int pass=0;
int c=0;

void display(int array[], int size) {
   	for(int i = 1; i<=size; i++)
      	cout << array[i] << " ";
   	cout << endl;
}

int getMax(int array[], int size) {
   	int max = array[1];
   	for(int i = 2; i<=size; i++) {
      	if(array[i] > max)
        max = array[i];
   	}
   return max;
}

int countSort(int array[], int size) {
   	int output[size+1],t=1;
   	int max = getMax(array, size);
   	int count[max+1];
   	for(int i = 0; i<=max; i++){
      	count[i] = 0;
      	pass++;
      	}
   	for(int i = 1; i <=size; i++){
   		count[array[i]]++;
   		pass++;
	    }
	cout<<"Count array "<<endl;
	display(count,max+1);
   	for(int i = 1; i<=max; i++){
   		count[i] += count[i-1];
   		pass++;
	   	}
	cout<<"Count array "<<endl;
	display(count,max+1);
   	for(int i = size; i>=1; i--) {
      	output[count[array[i]]] = array[i];
      	count[array[i]] -= 1;
		pass++; 
   	}
   	cout<<"output  array "<<endl;
	display(output,size);
   	for(int i = 1; i<=size; i++) {
      	array[i] = output[i];
   	}
   	return pass;
}
int main() {
   	int n;
   	cout << "Enter the number of elements: ";
   	cin >> n;
   	int arr[n+1];
   	cout << "Enter elements:" << endl;
   	for(int i = 1; i<=n; i++) {
      	cin >> arr[i];
   	}
   	cout << "Array before Sorting: ";
   	display(arr, n);
   	c=countSort(arr, n);
   	cout << "Array after Sorting: \n";
   	display(arr, n);
   	cout<<"Pass no: "<<c;
   	return 0;
}
