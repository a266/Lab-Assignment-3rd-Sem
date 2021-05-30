#include<iostream>
using namespace std;


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<" ";  
} 

void bubble(int x[],int n)
{
	int hold,j,i,pass=0,comp_count=0,k;
	
	for(i=0;i<n;i++)
	{
		int flag=0;
		int subpass=0;
		for(j=0;j<n-i-1;j++)
		{
			cout<<"pass "<<i+1<<": "<<endl;
			if(x[j]>x[j+1])
			{
				swap(x[j],x[j+1]);
				flag=1;
			}
			comp_count++;
			cout << "	sub pass " << ++subpass <<" :  ";
			printArray(x,n);
			cout<<endl;
		}
		if (flag != 1) 
        break; 
	}
	cout<<"---------------------------------------------------------------";
	cout<<endl;
	cout<<"The number of comparision is: "<<comp_count<<endl;
	cout << "Sorted array :";
	printArray(x,n);
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
    bubble(arr, n);  
    return 0; 
}
