#include<iostream>
using namespace std;
int c=0;
int pass=0;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[],int n)
{
	if (n == 1)
    	return;
    	
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
            c++;
            
    bubbleSort(arr, n-1);
}

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout<<arr[i]<<"  ";
}

int main()
{
    int n;
    cout<<"Enter the limit of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the array element:\n";
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	bubbleSort(arr,n);
    cout<<"Sorted array : "<<endl;
    printArray(arr, n);
	cout<<"\nNo. of comparisions: "<<c;  
    return 0; 
}
