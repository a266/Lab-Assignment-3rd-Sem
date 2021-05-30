#include<iostream>
using namespace std;
int c=0;

int printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[],int n,int i=0)
{
	if(n==i)
	if (n == i) {
        cout << "Number of comparison :" << c << endl;
        return;
    }
	int min_indx=i;
	for(int j=i+1;j<n;j++)
	{
		if(arr[j]<arr[min_indx])
		min_indx=j;
		c++;
	}
	if(min_indx!=i){
		swap(arr[i],arr[min_indx]);
	}
	cout<<"pass :"<<i+1<<" :"<<endl;
	for(int k=0;k<n;k++)
	cout<<arr[k]<<" ";
	cout<<endl;
	selectionSort(arr,n,i+1);
}

//void selectionSort(int arr[], int n,int i = 0) {
//    int minIndex;
//    if (n == i) {
//        cout << "Number of comparison :" << compare << endl;
//        return;
//    }
//    minIndex = i;
//    for (int j = i+1;j < n;j++){
//        if(arr[j] < arr[minIndex])
//            minIndex = j;
//        compare++;
//    }
//    if(minIndex != i) {
//        swap(arr[i], arr[minIndex]);
//    }
//    cout << "pass " << i+1 <<" :";
//    printArray(arr,n);
//    cout << endl;
//    selectionSort(arr, n,i+1);
//}

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
    selectionSort(arr,n,0);
	cout<<"Sorted Array :"<<endl;
	printArray(arr,n);
//	cout<<"The number of comparision is: "<<c<<endl;
    return 0;
}
