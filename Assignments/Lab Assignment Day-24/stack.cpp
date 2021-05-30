#include<iostream>
#include<conio.h>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class Stack:public Node{
	Node *top;
	public:
		Stack(){
			top=NULL;
		}
		
	bool isEmpty();
	void push();
	int pop();
	void display();
	void showTop();
	~Stack();
};


bool Stack::isEmpty()
{
	if(top==NULL)
		return true;
	else
		return false;
}

void Stack :: push(){
	cout<<"This is the process to insert the element"<<endl;
	int item;
	cout<<"\nEnter an Element: ";
	cin>>item;
	Node *curr=new Node();
	if(curr==NULL)
	{
		cout<<"failed"<<endl;
		return;
	}
	curr->data=item;
	curr->next=top;
	top=curr;
	return;
}

int Stack :: pop(){
	cout<<"This is the process to pop the element from the End"<<endl;
	if(isEmpty()){
		cout<<"Stack is Empty!!!!!"<<endl;
	}
	else
	{
		Node *temp=top;
		top=top->next;
		int x=temp->data;
		delete(temp);
		return x;
	}
}

void Stack :: display(){
	if(top==NULL){
		cout<<"Stack is Empty"<<endl;
		return;
	}
	Node *temp=top;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

void Stack::showTop(){
	if(isEmpty())
		cout<<"Stack is Empty!!!!!!"<<endl;
	else
		cout<<"Element at top is: "<<top->data<<endl<<endl;	
}

Stack::~Stack(){
	Node *temp=top;
	while(top!=NULL){
		top=top->next;
		delete temp;
		temp=top;
	}
}

int main()
{
	Stack l;
	int c;
	do{
		cout<<"\n******Enter Your Choice Stack******\n";
		cout<<"1:Push Element"<<endl;
		cout<<"2:Pop Element"<<endl;
		cout<<"3:Display the Stack"<<endl;
		cout<<"4:Peak Element"<<endl;
		cout<<"0:EXIT out!!!!"<<endl;		
		cin>>c;
		switch(c){
			case 1:
				system("CLS");
				l.push();
				break;
			case 2:
				system("CLS");
				l.pop();
				break;
			case 3:
				system("CLS");
				l.display();
				break;
			case 4:
				system("CLS");
				l.showTop();
				break;
			case 0:
				cout<<"Good Bye!!!!!!!";
				break;
		}
	}
	while(c!=0);
	return 0;
}
