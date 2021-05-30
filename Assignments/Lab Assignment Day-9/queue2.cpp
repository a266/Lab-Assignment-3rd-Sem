#include<iostream>
#include<stdio.h>
#define MAX 5
using namespace std;


class Queue{
	public:
		int front= -1;
		int rear= -1;
		int a[MAX];
		void enqueue()
		{
		int n;
		cout<<"Enter the value ";
		cin>>n;
		if(rear==MAX -1)
			cout<<"Queue is full "<<endl;
		else{
			if(front == -1)
				front++;
			rear++;
			a[rear]=n;
		}		
		}
		
		
		void dequeue()
		{
			if(isempty())
				cout<<"Queue is empty\n"<<endl;
			else
				if(front == rear )
					front=rear=-1;
				else
					front++;
		}	
		
		
		void peek()
		{
			if(isempty())
				cout<<"Queue is Empty\n";
			else
				cout<<"Element of front is :"<<a[front]<<endl;
		}
		
		
		bool isempty()
		{
			if(front==-1 && rear==-1)
				return true;
			else
				return false;
		}
		
		
		void display()
		{
			if(isempty())
				cout<<"Queue is empty"<<endl;
			else
			{
				for(int i=front;i<=rear;i++)
					cout<<a[i]<<" ";
			}
		}
		
		
};


int main(void)
{
	Queue a;
	int c;
	do{
		cout<<"Enter the Choice: "<<endl;
		cout<<"Option 1: Enqueue the Element "<<endl;
		cout<<"Option 2: Dequeue the Element "<<endl;
		cout<<"Option 3: Show the queue "<<endl;
		cout<<"Option 4: Peek "<<endl;
		cout<<"Option 5: Press 0 to exit "<<endl<<endl;
		cin>>c;
		switch(c)
		{
			case 1:
				a.enqueue();
				break;
			case 2:
				a.dequeue();
				break;
			case 3:
				a.display();
				break;
			case 4:
				a.peek();
				break;
			case 0:
				cout<<"Exit...."<<endl;
				break;
		}
	}while(c!=0);
	return 0;
}
