#include<iostream>
#include<stdlib.h>
#define MAX 10

using namespace std;

class Stack{
 	public:
 		int a[MAX];
 		int i = -1;
 		
bool isempty(){
	int t;
  	if(i== -1)
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

void in()
{
  	if(isfull()==1)
   		cout<<"STACK IS FULL!! CAN'T ENTER MORE DATA "<<endl;
  	else{
   		cout<<"ENTER VALUE: ";
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
  
  	for(j=i;j>=0;j--)
   	cout<<a[j]<<" ";
  	cout<<endl;
}

int peek(){
  	cout<<"PEEK IS "<<a[i]<<endl;
}

};
int main(void){
 	Stack ar;
 	int m=1;
 	while(m!=0){
  		cout<<endl<<"ENTER CHOICE "<<endl<<"1 TO INPUT "<<endl<<"2 TO SHOW"<<endl<<"3 TO CHECK IF IT IS FULL "<<endl<<"4 POP OUT!!!"<<endl<<"0 TO CLOSE THE PROGRAM"<<endl;
  		cin>>m;
  		cout<<endl<<endl;
  		system("CLS");
  	switch(m){
   	case 1:
    	ar.in();
    	system("CLS");
    	break;
   	case 2:
    	cout<<endl<<"THE STACK"<<endl;
    	ar.show();
    	break;
   	case 3:
    	ar.isfull();
    	break;
    case 4:
    	ar.pop();
    	break;
   	case 0:
    	ar.show();
    	cout<<"CLOSING THE PROGRAM....";
    	break;        
}
  
}
}
