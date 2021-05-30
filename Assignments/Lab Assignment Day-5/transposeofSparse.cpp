#include<iostream>
#include<stdlib.h>
using namespace std;
void readMatrix(int s[10][3]){
  cout<<"Enter the elements of Sparse matrix\n";
  for(int i=0;i==0 || i<=s[0][2];i++){
   for(int j=0;j<3;j++)
    cin>>s[i][j];
  }
}
void print(int s[10][3]){
  cout<<"Sparse matrix\n";
  for(int i=0;i<=s[0][2];i++){
   for(int j=0;j<3;j++)
    cout<<s[i][j]<<" ";
   cout<<"\n";
  }
}

void add(int a[10][3],int b[10][3],int c[10][3]){
   if(a[0][0]!=b[0][0] || a[0][1]!=b[0][1])
     cout<<"Addition is not possible\n";
   else{
     c[0][0]=a[0][0];
     c[0][1]=a[0][1];
     int k=1,i=1,j=1;
     while(i<=a[0][2] && j<=b[0][2]){
        if(a[i][0] < b[j][0]){
           c[k][0]=a[i][0];
           c[k][1]=a[i][1];
       c[k][2]=a[i][2];
          k++;i++;
        }
        else if(a[i][0] > b[j][0]){
           c[k][0]=b[j][0];
           c[k][1]=b[j][1];
       c[k][2]=b[j][2];
       k++;j++;
        }
        else if(a[i][1] < b[j][1]){
           c[k][0]=a[i][0];
           c[k][1]=a[i][1];
       c[k][2]=a[i][2];
       k++;i++;
        }
        else if(a[i][1] > b[j][1]){
           c[k][0]=b[j][0];
           c[k][1]=b[j][1];
       c[k][2]=b[j][2];
       k++;j++;
        }
        else{
          c[k][0]=a[i][0];
      c[k][1]=a[i][1];
      c[k][2]=a[i][2]+b[i][2];
      k++;i++;j++;
        }
     }
     while(i<=a[0][2]){
       c[k][0]=a[i][0];
       c[k][1]=a[i][1];
       c[k][2]=a[i][2];
       k++;i++;
     }
     while(j<=b[0][2]){
       c[k][0]=b[j][0];
       c[k][1]=b[j][1];
       c[k][2]=b[j][2];
       k++;j++;
     }
     c[0][2]=k-1;
   }
   print(a);
   print(b);
   print(c);
}
void transpose(int s[10][3],int t[10][3]){
   t[0][0]=s[0][1];
   t[0][1]=s[0][0];
   t[0][2]=s[0][2];
   int k=1;
   for(int i=0;i<s[0][1];i++){
     for(int j=1;j<=s[0][2];j++){
       if(i==s[j][1]){
         t[k][0]=i;
     t[k][1]=s[j][0];
     t[k][2]=s[j][2];
     k++;
       }
     }
   }
   print(s);
   cout<<"Transpose Matrix\n";
   print(t);
}
int main(){
  system("clear");
  int c[10][3],a[10][3],b[10][3];
  readMatrix(a);
  readMatrix(b);
  add(a,b,c);
  transpose(a,b);
}
