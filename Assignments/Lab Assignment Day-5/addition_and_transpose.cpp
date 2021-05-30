#include<iostream>
using namespace std;
#include<stdlib.h>

#define MAX 20

void printsparse(int b[MAX][3]);
void readsparse(int b[MAX][3]);

void addsparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3]);

void transpose(int b1[][3],int b2[][3])
{
	int i,j,k,n;

	b2[0][0]=b1[0][1];
	b2[0][1]=b1[0][0];
	b2[0][2]=b1[0][2];
	
	k=1;

	n=b1[0][2];
	
	for(i=0;i<b1[0][1];i++)
    {
		for(j=1;j<=n;j++)
        {
			if(i==b1[j][1])
			{
				b2[k][0]=i;
				b2[k][1]=b1[j][0];
				b2[k][2]=b1[j][2];
				k++;
			}
        }
    }        
}

int main()
{
   
    int b1[MAX][3],b2[MAX][3],b3[MAX][3];
    
    readsparse(b1);
    
    readsparse(b2);
    
    addsparse(b1,b2,b3);
    
    printsparse(b3);
}
void readsparse(int b[MAX][3])
{
   
    int i,t,m,n;
    
    cout<<"Enter no. of rows and columns:";
    
    cin>>m>>n;
    cout<<"No. of non-zero triples:"<<endl;
    
    cin>>t;
    
    b[0][0]=m;    
    b[0][1]=n;    
    b[0][2]=t;
    
    for(i=1;i<=t;i++)
    {        
        cout<<"Enter the triples(row,column,value):"<<endl;            
        cin>>b[i][0]>>b[i][1]>>b[i][2];
    }
}

void addsparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3])
{
   
    int t1,t2,i,j,k;
    
    if(b1[0][0]!=b2[0][0]||b1[0][1]!=b2[0][1])
    {
        
        exit(0);
    }
    
    t1=b1[0][2];
    
    t2=b2[0][2];
    
    i=j=k=0;
    
    b3[0][0]=b1[0][0];
    
    b3[0][1]=b1[0][1];
    
    while(i <= t1 && j <= t2)
    {
        
        if(b1[i][0] < b2[j][0])      

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
void printsparse(int b[MAX][3])
{
   
    int t;
    
    t=b[0][2];
    
    cout<<"\n row \t column \t value";
    
    for(int i=1;i<=t;i++)
    {
        cout<<endl<<b[i][0]<<"     "<<b[i][1]<<"     "<<b[i][2];
    }
}
