#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 100

int data[MAX][3];
int len;
void insert(int r, int c, int val) 
{ 
 
    data[len][0] = r; 
    data[len][1] = c; 
    data[len][2] = val; 
    len++; 
}

void print() 
{ 
    cout << "\nDimension of Sparse Matrix: "
         << len << " x " << 3; 
    cout << "\nSparse Matrix: \nRow Column Value\n"; 
  
    for (int i = 0; i < len; i++) { 
  
        cout << data[i][0] << " "
             << data[i][1] << " "
             << data[i][2] << "\n"; 
    } 
}  

 int main()
 {
 	int a[10][10],b[10][10],row,col,i,j;
 	cout<<"Enter row and coloumn of the matrix:\n";
 	cin>>row>>col;
 	cout<<"Enter matrix:\n";
 	for(i=0;i<row;i++)
 	{
 		for(j=0;j<col;j++)
 		{
 			cin>>a[i][j];	
		}
	}
	for(i=0;i<row;i++)
 	{
 		for(j=0;j<col;j++)
 		{
 			if(a[i][j]>0)
				insert(i,j,a[i][j]);	
		}
	}
	print();
	return 0;
 }
