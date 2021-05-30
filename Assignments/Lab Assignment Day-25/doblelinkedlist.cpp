#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node *prev;
};

class DoubleyLinkedList:public Node{
	Node *head,*tail;
	public:
		DoubleyLinkedList(){
			head=NULL;
			tail=NULL;
		}
	Node* getnode();
	void insertBeg();
	void insertEnd();
	void insertAfter();
	void insertBefore();
	void insertAtAnyPos();
	void delBeg();
	void delEnd();
	void delAfter();
	void delBefore();
	void delAtAnyPos();
	void display();
	~DoubleyLinkedList();
};

Node* DoubleyLinkedList::getnode()
{
	Node *newnode;
	newnode=new Node;
	cout<<"Enter data :";
	cin>>newnode->data;
	newnode->next=NULL;
	newnode->prev=NULL;
	return(newnode);
}

void DoubleyLinkedList::insertBeg(){
	Node *temp;
	temp=getnode();
	if(head==NULL){
		head=tail=temp;
	}
	else{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	cout<<head->data<<"is inserted.\n";
	display();
}

void DoubleyLinkedList::insertEnd(){
	Node *temp;
	temp=getnode();
	if(head==NULL){
		head=tail=temp;
	}
	else{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
	cout<<tail->data<<"is inserted.\n";
	display();
}

void DoubleyLinkedList::insertAfter(){
	Node *curr=new Node();
	Node *temp=head;
	int item;
	cout<<"Enter the value:";
	cin>>item;
	curr->data=item;
	if(temp==NULL){
		cout<<"The list is empty!!!\n please make the list first and the try again!!!!"<<endl;
		return;
	}
	else{
		curr->prev=temp;
		curr->next=temp->next;
		temp->next->prev=curr;
		temp->next=curr;
		return;
	}
	
}

void DoubleyLinkedList::insertBefore(){
	
}

void DoubleyLinkedList::insertAtAnyPos(){
	
}

void DoubleyLinkedList::delBeg(){
	if(head==NULL){
		cout<<"The list is empty!!!"<<endl;
	}
	else{
		cout<<head->data<<" is deleted.\n";
		if(head==tail){
			head=tail=NULL;
		}
		else{
			Node* temp;
			temp=head;
			head=head->next;
			head->prev=NULL;
			free(temp);
		}
		display();
	}
}

void DoubleyLinkedList::delEnd(){
	if(head==NULL){
		cout<<"the list is empty!!!!"<<endl;
	}
	else{
		cout<<tail->data<<" is deleted.\n";
		if(head==tail){
			head=tail=NULL;
		}
		else{
			Node* temp;
			temp=tail;
			tail=tail->prev;
			free(temp);
			tail->next=NULL;
		}
		display();
	}
}

void DoubleyLinkedList::delAfter(){
	
}

void DoubleyLinkedList::delBefore(){
	
}

void DoubleyLinkedList::delAtAnyPos(){
	
}

void DoubleyLinkedList::display(){
	if(head==NULL){
		cout<<"The List is Empty!!!!\n";
	}
	else{
		Node *temp=head;
		cout<<"The element in the list are: ";
		while(temp!=NULL){
			cout<<temp->data<<"<-->";
			temp=temp->next;
		}
	}
	cout<<"NULL"<<endl;
}

DoubleyLinkedList :: ~DoubleyLinkedList(){
	Node *temp=head;
	while(head!=NULL){
		head=head->next;
		delete (temp);
		temp=head;
	}
}

int main()
{
	DoubleyLinkedList d;
	int c;
	do{
		cout<<"\n******Enter Your Choice******\n";
		cout<<"1:Insert Element at The Begening of the Doubly Linked List "<<endl;
		cout<<"2:Insert Element at The End of the Doubly Linked List"<<endl;
		cout<<"3:Display the Linked List"<<endl;
		cout<<"4:Delete Element at begening"<<endl;
		cout<<"5:Delete Element at end"<<endl;
		cout<<"6:bguyfvcgh"<<endl;
		cout<<"0:EXIT out!!!!"<<endl;		
		cin>>c;
		switch(c){
			case 1:
				system("CLS");
				d.insertBeg();
				break;
			case 2:
				system("CLS");
				d.insertEnd();
				break;
			case 3:
				system("CLS");
				d.display();
				break;
			case 4:
				system("CLS");
				d.delBeg();
				break;
			case 5:
				system("CLS");
				d.delEnd();
				break;
			case 6:
				system("CLS");
				d.insertAfter();
				break;
			case 0:
				cout<<"Good Bye!!!!!!!";
				break;
			default:cout<<"Wrong Selection!!! please try again!!!"<<endl;
		}
	}
	while(c!=0);
	return 0;
}
