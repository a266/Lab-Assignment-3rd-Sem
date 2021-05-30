#include<iostream>
#include<stdlib.h>
#define max 5
using namespace std;
class queue{
	public:
	int a[max];
	int front=-1;
	int rear=-1;
	void enqueue(){
		int n;
		cout<<"Enter the value ";
		cin>>n;
		if(rear==max-1)
			cout<<"QUEUE IS FULL "<<endl;
		else if(front==-1 && rear==-1){
			front++;
			rear++;
			a[rear]=n;
		}
		else{
		
			rear++;
			a[rear]=n;
		}		
		
		}
		
	void show(){
		if(rear == -1||front == rear)
			cout<<"QUEUE IS EMPTY"<<endl;
			
		else{
			int i;
			for(i=front;i<=rear;i++)
				cout<<a[i]<<" ";
			
		}
		cout<<endl;
	}
	void dequeue(){
		if(front==-1|| front ==rear)
			cout<<"QUEUE IS UNDERFLOW "<<endl;
		else
			front++;
	}
};
int main(void){
	queue a;
	int c;
	do{
		cout<<"1 to enqueue "<<endl;
		cout<<"2 to dequeue "<<endl;
		cout<<"3 to show "<<endl;
		cout<<"0 to close "<<endl;
		cout<<"ENTER CHOICE ";
		cin>>c;
		switch(c){
			case 1:
				a.enqueue();
				break;
			case 2:
				a.dequeue();
				break;
			case 3:
				a.show();
				break;
			case 0:
				cout<<"Quit Out";
		}
	}
	while(c!=0);
	return 1;
}
