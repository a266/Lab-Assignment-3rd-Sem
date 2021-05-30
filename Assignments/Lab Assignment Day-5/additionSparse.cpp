#include<stdio.h>
#include<iostream>

#define MAX 20

using namespace std;

void printSparse(int b[MAX][3]);
void readSparse(int b[MAX][3]);
void addSparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3]);
void printTranspose(int s[MAX][3],int t[MAX][3]);

int main()
{
   
	int a[MAX][3],b[MAX][3],c[MAX][3],t[MAX][3];
	readSparse(a);
	readSparse(b);
	addSparse(a,b,c);
	printTranspose(c,t); 
//	printSparse(t);
	return 0;
}
void readSparse(int b[MAX][3])
{
	int i,t,n,r,c,j;
	cout<<"Enter no. of rows: ";
	cin>>n;
	cout<<"Enter sparse elements:";
	cout<<"\nrow\tcolumn\tvalue\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
		cin>>b[i][j];
		}
	}
    
	r=b[0][0];
	c=b[0][1];
	b[r][c];
	
}


void printSparse(int b[MAX][3]) 
{ 
    int i,t;
	t=b[0][2];
	cout<<"\nrow\tcolumn\tvalue";
	for(i=0;i<t;i++)
	{   
		cout<<"\n"<<b[i][0]<<"\t"<<b[i][1]<<"\t"<<b[i][2];
    } 
}

void printTranspose(int s[MAX][3],int t[MAX][3])
{
	t[0][0]=s[0][1];
	t[0][1]=s[0][0];
	t[0][2]=s[0][2];
	int k=1;
	for(int i=0;i<s[0][1];i++)
	{
		for(int j=0;j<s[0][2];j++)
		{
			if(i==s[j][1])
			{
				t[k][0]=s[j][1];
				t[k][1]=s[j][0];
				t[k][2]=s[j][2];
				k++;
			}
		}
	}
//	printSparse(s);
//	cout<<"\nTranspose matrix is:\n";
//	printSparse(t);
}


void addSparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3])
{
	int t1,t2,i,j,k;  
	if(b1[0][0]!=b2[0][0]||b1[0][1]!=b2[0][1])
    {
		cout<<"You have entered invalid matrix!!Size must be equal";
		exit(0);
    }
	t1=b1[0][2];
	t2=b2[0][2];
	i=j=k=0;
	b3[0][0]=b1[0][0];
	b3[0][1]=b1[0][1];
	
	while(i<=t1&&j<=t2)
    {   
		if(b1[i][0]<b2[j][0])
       
	{       
		b3[k][0]=b1[i][0];      
		b3[k][1]=b1[i][1];
		b3[k][2]=b1[i][2];       
		k++;       
		i++;   
	}   
	else if(b2[j][0]<b1[i][0])
	{
		b3[k][0]=b2[j][0];       
		b3[k][1]=b2[j][1];
		b3[k][2]=b2[j][2];
    	k++;
		j++;
	}   
	else if(b1[i][1]<b2[j][1])
	{
		b3[k][0]=b1[i][0];          
		b3[k][1]=b1[i][1];
		b3[k][2]=b1[i][2];
		k++;
		i++;
    }       
	else if(b2[j][1]<b1[i][1])     
	{
		b3[k][0]=b2[j][0];
		b3[k][1]=b2[j][1];
		b3[k][2]=b2[j][2];   
		k++;   
		j++;
	}
	else   
	{
           
		b3[k][0]=b1[i][0];   
		b3[k][1]=b1[i][1];   
		b3[k][2]=b1[i][2]+b2[j][2];
		k++;
		i++;   
		j++;   
	}
    }
   
while(i<=t1)        
    {       
		b3[k][0]=b1[i][0];      
		b3[k][1]=b1[i][1];
		b3[k][2]=b1[i][2];
		i++;
		k++;
    }
   
while(j<=t2)
    {
		b3[k][0]=b2[j][0];  
		b3[k][1]=b1[j][1];
		b3[k][2]=b1[j][2];
		j++;
		k++;
    }
   
	b3[0][2]=k-1;
}

