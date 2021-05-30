#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class Queue:public Node{
	Node *front,*rear;
	public:
		Queue(){
			front=NULL;
			rear=NULL;
		}
		
	bool isEmpty();
	void enqueue();
	int dequeue();
	void display();
	void showFront();
	~Queue();
};


bool Queue::isEmpty()
{
	if(front==NULL && rear==NULL)
		return true;
	else
		return false;
}

void Queue :: enqueue(){
	cout<<"This is the process to insert the element"<<endl;
	int item;
	cout<<"\nEnter an Element: ";
	cin>>item;
	Node *curr=new Node();
	curr->data=item;
	curr->next=NULL;
	if(front==NULL)
	{
		front=curr;
		rear=curr;
	}
	else
	{
		rear->next=curr;
		rear=curr;
	}
	return;
}

int Queue :: dequeue(){
	cout<<"This is the process to pop the element from the End"<<endl;
	if(isEmpty()){
		cout<<"Queue is Empty!!!!!"<<endl;
	}
	else if(front==rear)
	{
		free(front);
		front=rear=NULL;
	}
	else
	{
		Node *temp=front;
		front=front->next;
		int x=temp->data;
		delete(temp);
		return x;
	}
}

void Queue :: display(){
	if(front==NULL){
		cout<<"Queue is Empty"<<endl;
		return;
	}
	Node *temp=front;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void Queue ::showFront(){
	if(isEmpty())
		cout<<"Queue is Empty!!!!!!"<<endl;
	else
		cout<<"Element at top is: "<<front->data<<endl<<endl;	
}

Queue::~Queue(){
	Node *temp=front;
	while(front!=NULL){
		front=front->next;
		delete (temp);
		temp=front;
	}
}

int main()
{
	Queue l;
	int c;
	do{
		cout<<"\n******Enter Your Choice Stack******\n";
		cout<<"1:Enqueue Element"<<endl;
		cout<<"2:Dequeue Element"<<endl;
		cout<<"3:Display the Queue"<<endl;
		cout<<"4:Peak Element"<<endl;
		cout<<"0:EXIT out!!!!"<<endl;		
		cin>>c;
		switch(c){
			case 1:
				system("CLS");
				l.enqueue();
				break;
			case 2:
				system("CLS");
				l.dequeue();
				break;
			case 3:
				system("CLS");
				l.display();
				break;
			case 4:
				system("CLS");
				l.showFront();
				break;
			case 0:
				cout<<"Good Bye!!!!!!!";
				break;
		}
	}
	while(c!=0);
	return 0;
}
