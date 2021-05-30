#include<iostream> 
using namespace std; 
  
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) 
{ 
    int i = 0, j = 0, k = 0; 
    while (i<n1 && j <n2) 
    { 
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    } 
    while (i < n1) 
        arr3[k++] = arr1[i++];  
    while (j < n2) 
        arr3[k++] = arr2[j++]; 
} 

int main() 
{ 
    int arr1[100],arr2[100],n1,n2,i,j,k;
    cout<<"Enter the size of first array:\n";
    cin>>n1;
    cout<<"Enter first array element:\n";
    for(i=0;i<n1;i++)
    {
    	cin>>arr1[i];
	} 
    cout<<"Enter the size of second array:\n";
    cin>>n2;
    cout<<"Enter second array element:\n";
    for(i=0;i<n2;i++)
    {
    	cin>>arr2[i];
	}
    int arr3[n1+n2]; 
    mergeArrays(arr1, arr2, n1, n2, arr3);
    cout << "Array after merging" <<endl; 
    for (int i=0; i < n1+n2; i++) 
        cout << arr3[i] << " "; 
  
    return 0; 
} 

