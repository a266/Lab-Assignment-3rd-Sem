#include<iostream>
#define MAX 10

using namespace std;
class Stack{
 public:
 int a[MAX];
 int i=-1;
 bool isempty(){
  bool t;
  if(i==-1)
   t=1;
  else
   t=0;
  return t;
 }
 bool isfull(){
  if(i==MAX-1)
   return 1;
  else
   return 0;
 }

 
 
 void in(int n){
  if(isfull()==1)
   cout<<"CAN'T ENTER MORE DATA "<<endl;
  else{
   
   
   
   i++;
   a[i]=n; 
   }
 
 }
 void in(){
  if(isfull()==1)
   cout<<"CAN'T ENTER MORE DATA "<<endl;
  else{
   cout<<"ENTER VALUE ";
   int n;
   cin>>n;
   
   i++;
   a[i]=n; 
      
   }
 
 } 
 void pop(){
  if(isempty()==1)
   cout<<"NOTHING TO POP"<<endl;
  else
   i--;
 }
 void show(){
  int j=0;
  
  for(j=0;j<=i;j++)
   cout<<a[j]<<" ";
  cout<<endl;
 }
 int peek(){
  cout<<"PEEK IS "<<a[i]<<endl;
 }


};
Stack rev(int ar[],int n){
 Stack s;
 int j=0;
 for(j=n-1;j>=0;j--)
  s.in(ar[j]);
 
 return s;
}
int main(void){
 Stack ar,s;
 
 int n;
 cout<<"Enter length of array(LESS THAN OR 10) ";
 cin>>n;
 int i;
 for(i=0;i<n;i++)
  ar.in();
 
 s=rev(ar.a,n);
 cout<<endl<<"REVERSE ARRAY....  "<<endl;
 s.show();
}
