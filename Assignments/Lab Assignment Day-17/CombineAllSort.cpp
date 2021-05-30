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

void inputArray(int arr[],int size){
	
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
}

void bubbleSort(int x[],int n)
{
	int hold,j,i,pass=0,comp_count=0,k,t=0;
	int subpass=0;
	for(i=0;i<n;i++)
	{
		t++;
		int flag=0;
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
	cout<<"-----------------------------------------------------------";
	cout<<endl;
	cout<<"Total number of pass is: "<<t<<endl;
	cout<<"Total number of comparision is: "<<comp_count<<endl;
	cout<<"Array Status: Fully Sorted"<<endl;
	cout << "Sorted array :";
	printArray(x,n);
	cout<<endl;
	if(n==comp_count || comp_count<n){
		cout<<"Time Complexity=O(n).\nSpace Complexity=O(1)"<<endl;
	}
	else{
		cout<<"Time Complexity=O(n^2).\nSpace Complexity=O(1)"<<endl;
	}
	cout<<"\n----------------------------------------------------";
}

void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx,count_comp=0,t2=0;
    for (i = 0; i < n-1; i++)  
    {
			t2++;
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
        int temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
        for(int k=0;k<n;k++)
		{
			cout<<arr[k]<<" ";
		}
		cout<<endl;  
    }
    cout<<"_________________________________________________"<<endl;
	cout<<"Total number of pass is: "<<t2<<endl;
	cout<<"Total number of comparision: "<<count_comp<<endl;
	cout<<"Array Status: Fully Sorted"<<endl;
    cout<<"Sorted Array:"<<endl;
    printArray(arr,n);
	cout<<endl;
	if(n==count_comp || count_comp<n){
		cout<<"Time Complexity=O(n^2).\nSpace Complexity=O(1)"<<endl;
	}
	else{
		cout<<"Time Complexity=O(n^2).\nSpace Complexity=O(1)"<<endl;
	}
	cout<<"\n----------------------------------------------------";
}



void insertionSort(int array[], int size) {
   	int i,key, j,count=0,t1=0;
   	for( i = 1; i<size; i++) {
   		t1++;
      	key = array[i];
      	cout<<"Pass : "<<i<<endl;
      	j = i;
      	while(j > 0 && (++count && array[j-1]>key)) {
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
   	cout<<"__________________________________________________"<<endl;
   	cout<<"Total number of pass is: "<<t1<<endl;
   	cout<<"Total number of comparision: "<<count<<endl;
   	cout<<"Array Status: Fully Sorted"<<endl;
   	cout << "Sorted array :";
	printArray(array,size);
	cout<<endl;
	if(size==count || count<size){
		cout<<"Time Complexity=O(n).\nSpace Complexity=O(1)"<<endl;
	}
	else{
		cout<<"Time Complexity=O(n^2).\nSpace Complexity=O(1)"<<endl;
	}
	cout<<"\n----------------------------------------------------";
}


void commandForSelectionSort(int a[],int b[],int c[],int n)
{
	cout<<"\nIn Case of Selection Sort:"<<endl;
	cout<<"\nFor Best Case:"<<endl;
    cout<<"\nBefore Sort :";
	printArray(a,n);
	cout<<endl;
    selectionSort(a,n);
    cout<<"\nFor Average Case:"<<endl;
	cout<<"\nBefore Sort :";
	printArray(b,n);
	cout<<endl;
    selectionSort(b,n);
    cout<<"\nFor Worst Case:"<<endl;
    cout<<"\nBefore Sort :";
	printArray(c,n);
	cout<<endl;
    selectionSort(c,n);
}


void commandForBubbleSort(int a[],int b[],int c[],int n)
{
	cout<<"\nIn Case of Bubble Sort:"<<endl<<endl;
    cout<<"\nFor Best Case:"<<endl;
    cout<<"\nBefore Sort :";
	printArray(a,n);
	cout<<endl;
    bubbleSort(a,n);
	cout<<"\nFor Average Case:"<<endl;
	cout<<"\nBefore Sort :";
	printArray(b,n);
	cout<<endl; 
    bubbleSort(b,n);
    cout<<"\nFor Worst Case:"<<endl;
    cout<<"\nBefore Sort :";
	printArray(c,n);
	cout<<endl;
    bubbleSort(c,n);
}


void commandForInsertionSort(int a[],int b[],int c[],int n)
{
	cout<<"\nIn Case of Insertion Sort:"<<endl;
    cout<<"\nFor Best Case:"<<endl;
    cout<<"\nBefore Sort :";
	printArray(a,n);
	cout<<endl;
    insertionSort(a,n);
    cout<<"\nFor Average Case:"<<endl;
	cout<<"\nBefore Sort :";
	printArray(b,n);
	cout<<endl;
    insertionSort(b,n);
    cout<<"\nFor Worst Case:"<<endl;
    cout<<"\nBefore Sort :";
	printArray(c,n);
	cout<<endl;
    insertionSort(c,n);
//    return 0;
}

int main(void){
	
	int n;
    cout<<"Enter the limit of the array:";
    cin>>n;
    int a[n],b[n],c[n];
    cout<<"Enter element For Best Case: "<<endl;
    inputArray(a,n);
    cout<<"Enter element For Average Case: "<<endl;
    inputArray(b,n);
    cout<<"Enter element For Worst Case: "<<endl;
    inputArray(c,n);
	
	
	int w;
	do{
		cout<<endl;
		cout<<"Press 1 for Bubble Sort: "<<endl;
		cout<<"Press 2 for Insertion Sort: "<<endl;
		cout<<"Press 3 for Selection Sort: "<<endl;
		cout<<"Press 0 to close "<<endl;
		cout<<"ENTER CHOICE ";
		cin>>w;
		switch(w){
			case 1:
				commandForBubbleSort(a,b,c,n);
				break;
			case 2:
				commandForSelectionSort(a,b,c,n);
				break;
			case 3:
				commandForInsertionSort(a,b,c,n);
				break;
			case 0:
				cout<<"Exit!!!!!!";
		}
	}
	while(w!=0);
	return 0;
}
