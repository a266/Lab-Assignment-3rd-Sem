#include<stdio.h>
#include<iostream>
#define MAX 5
using namespace std;

class circularQueue{
	public:
		int a[MAX];
		int front=-1;
		int rear=-1;
		
		bool isempty()
		{
			if(front==-1 && rear==-1)
				return true;
			else
				return false;
		}
		void enqueue()
		{
			int n;
			cout<<"\nEnter the number you want to enter: "<<endl;
			cin>>n;
			if((rear+1)%MAX==front)
				cout<<"Queue is Full\n"<<endl;
			else
			{
				if(front==-1)
					front=0;
				rear=(rear+1)%MAX;
				a[rear]=n;
			}
		}
		
		void dequeue()
		{
			if(isempty())
				cout<<"Queue is empty"<<endl;
			else
			{
				if(front==rear)
					front=rear=-1;
				else
					front=(front+1)%MAX;
			}
		}
		void peek()
		{
			if(isempty())
				cout<<"Queue is Empty\n";
			else
				cout<<"Element of front is "<<a[front]<<endl;
		}
		
		void display()
		{
			if(isempty())
				cout<<"Queue is empty\n"<<endl;
			else
			{
				if(front <= rear)
				{
					for(int i=front;i<=rear;i++)
						cout<<a[i]<<" ";
				}
				else
				{
					int i=front;
					while(i<MAX)
					{
						cout<<a[i]<<" ";
						i++;
					}
					i=0;
					while(i<=rear)
					{
						cout<<a[i]<<" ";
						i++;
					}
				}
			}
		}
};


int main()
{
	int c,choice;
	circularQueue a;
	
	do{
		cout<<"\n1 for Enqueue"<<endl;
		cout<<"2 for Dequeue"<<endl;
		cout<<"3 for Peek"<<endl;
		cout<<"4 for Display"<<endl;
		cout<<"0 for exit"<<endl<<endl;
		cout<<"Enter the Choice:  ";
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
				a.peek();
				break;
			case 4:
				a.display();
				break;
			case 0:
				cout<<"Exit";
		}
	}while(c!=0);
	return 0;
}
