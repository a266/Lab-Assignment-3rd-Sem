#include <bits/stdc++.h> 
using namespace std; 
 

int printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}
  
void selection(int arr[], int n)  
{  
    int i, j, min_idx,count_comp=0,key;
    for (i = 0; i < n-1; i++)  
    {
        min_idx = i;
        
		cout<<"Pass : "<<i+1<<endl;  
        for (j = i+1; j < n; j++)
		{ 
			count_comp++;
        	if (arr[j] < arr[min_idx])
			{  
            	min_idx = j;
        	}
    	}
    	key=arr[min_idx];
    	while(min_idx>1){
    		arr[min_idx]=arr[min_idx-1];
    		min_idx=min_idx-1;
		}
		arr[i]=key;
//    	
//        int temp=arr[i];
//        arr[i]=arr[min_idx];
//        arr[min_idx]=temp;
        for(int k=0;k<n;k++)
		{
			cout<<arr[k]<<" ";
		}
		cout<<endl;  
    }
	cout<<"the number of comparision: "<<count_comp<<endl;
	
    cout<<"Sorted Array:"<<endl;
    
    printArray(arr,n);
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
    selection(arr, n);  
    return 0; 
} 
