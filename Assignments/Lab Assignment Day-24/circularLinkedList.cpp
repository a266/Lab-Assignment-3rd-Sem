#include<iostream>
#include<conio.h>
#include <bits/stdc++.h>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class CircularLinkedList:public Node{
	Node *last;
	public:
		CircularLinkedList(){
			last=NULL;
		}
		
	void insertBeg();
	void insertEnd();
	void display();
	void deleteBeg();
	void deleteEnd();
	~CircularLinkedList();
};



void CircularLinkedList :: insertBeg(){
	cout<<"This is the process to insert the element from the begening"<<endl;
	int item;
	cout<<"\nEnter an Element: ";
	cin>>item;
	Node *curr=new Node();
	curr->data=item;
	if(last==NULL){
		curr->next=curr;
		last=curr;
	}
	curr->next=last->next;
	last->next=curr;
	return;
}

void CircularLinkedList :: insertEnd(){
	cout<<"This is the process to insert the element from the End"<<endl;
	int item;
	cout<<"\nEnter an Element: ";
	cin>>item;
	Node *curr=new Node();
	curr->data=item;
	curr->next=NULL;
	if(last==NULL)
	{
		curr->next=curr;
		last=curr;
	}
	curr->next=last->next;
	last->next=curr;
	last=curr;
	return;
}

void CircularLinkedList :: display(){
	
	if(last==NULL)
	{
		cout<<"\nThe Circular LinkedList is Empty!!!!!!"<<endl;
		return;
	}
	Node *temp=last->next;	
	while(temp!=last){
		cout<<temp->data<<"-->";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<endl<<endl;
}


void CircularLinkedList::deleteBeg(){
	cout<<"In This process the first element is deleted"<<endl;
	if(last==NULL){
		cout<<"The list is Empty!!!!!"<<endl;
		return;
	}
	else if(last==last->next)
	{
		Node *temp=last;
		delete temp;
		last=NULL;
		return;
	}
	
	else if(last==last->next)
	{
		delete last;
		last=NULL;
		return;
	}
	
	else
	{
		Node *temp=last->next;
		last->next=temp->next;
		free(temp);
		display();
		return;
	}
}

void CircularLinkedList::deleteEnd(){
	cout<<"In This process the last element is deleted"<<endl;
	if(last==NULL){
		cout<<"The list is Empty!!!!!"<<endl;
		return;
	}
	
	else if(last==last->next)
	{
		delete last;
		last=NULL;
		return;
	}
	
	else
	{
		Node *temp=last->next;
		while(temp->next!=last){
			temp=temp->next;
		}
		temp->next=last->next;
		delete last;
		last=temp;
		display();
		return;
	}	
}


CircularLinkedList :: ~CircularLinkedList(){
	Node *temp=last;
	while(last!=NULL){
		last=last->next;
		delete (temp);
		temp=last;
	}
}

int main()
{
	CircularLinkedList l;
	int c;
	do{
		cout<<"\n******Enter Your Choice For Circular Linked List******\n";
		cout<<"1:Create Linked List at Begening"<<endl;
		cout<<"2:Create Linked List at End"<<endl;
		cout<<"3:Display the Linked List"<<endl;
		cout<<"4:Delete the element at Begening"<<endl;
		cout<<"5:Delete the element at end"<<endl;
		cout<<"0:EXIT out!!!!"<<endl;	
		cin>>c;
		switch(c){
			case 1:
				system("CLS");
				l.insertBeg();
				break;
			case 2:
				system("CLS");
				l.insertEnd();
				break;
			case 3:
				system("CLS");
				l.display();
				break;
			case 4:
				system("CLS");
				l.deleteBeg();
				break;
			case 5:
				system("CLS");
				l.deleteEnd();
				break;
			case 0:
				cout<<"Good Bye!!!!!!!";
				break;
		}
	}
	while(c!=0);
	return 0;
}
