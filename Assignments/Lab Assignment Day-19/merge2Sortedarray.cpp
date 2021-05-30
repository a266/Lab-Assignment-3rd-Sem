#include <iostream>

using namespace std;

void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int result[])
	{
   		int i, j, k;
   		i = 0;
   		j = 0;
   		k = 0;
   		while(i < n1 && j < n2)
    		{
      			if (arr1[i] < arr2[j]) 
				{
         			result[k] = arr1[i];
         			++k;
         			++i;
      			} 
				else
				{
         			result[k] = arr2[j];
         			++k;
         			++j;
      			}
   			}
   		
   		while(i < n1)
   	
	   		{
      			result[k] = arr1[i];
      			++k;
      			++i;
   			}
   		
   		while (j < n2)
	   		{
      			result[k] = arr2[j];
      			++k;
      			++j;
   			}
	}


void dispalyArray(int arr[], int n)
	{
   		for (int i = 0; i < n; ++i) 
		{
      		cout << arr[i] << " ";
   		}
   		cout << endl;
	}


int main()
{
	int m,n;
	cout<<"Eneter total number of element you want to enter in first array: ";
	cin>>m;
	int arr1[m],arr2[n];
	cout<<"Enter elements for array1 :"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>arr1[i];
	}
	cout<<"Eneter total number of element you want to enter in second array: ";
	cin>>n;
	cout<<"Enter elements for array2 :"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr2[i];
	}
	int result[m+n];
	
   	cout << "First sorted array:" << endl;
   	dispalyArray(arr1,m);
   	cout << "Second sorted array:" << endl;
   	dispalyArray(arr2,n);
   	mergeSortedArrays(arr1,m,arr2,n,result);
   	cout << "Final sorted array:" << endl;
   	dispalyArray(result,m+n);
   	return 0;
}
