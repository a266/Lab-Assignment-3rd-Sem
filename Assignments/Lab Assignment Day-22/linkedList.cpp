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

class LinkedList:public Node{
	Node *head;
	public:
		LinkedList(){
			head=NULL;
		}
		
	void insertBeg();
	void insertEnd();
	void display();
	int countNodes();
	int NodesAtEven();
	int NodesAtOdd();
	int swapNodes();
	void deleteEnd();
	void deleteBeg();
	void deleteItem();
	void reverse();
};

void LinkedList :: insertBeg(){
	cout<<"This is the process to insert the element from the begening"<<endl;
	int item;
	cout<<"\nEnter an Element: ";
	cin>>item;
	Node *curr=new Node();
	curr->data=item;
	curr->next=head;
	head=curr;
	return;
}

void LinkedList :: insertEnd(){
	cout<<"This is the process to insert the element from the End"<<endl;
	int item;
	cout<<"\nEnter an Element: ";
	cin>>item;
	Node *curr=new Node();
	curr->data=item;
	curr->next=NULL;
	if(head==NULL)
	{
		head=curr;
		return;
	}
	else
	{
		Node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=curr;
	}
}

void LinkedList :: display(){
	Node *temp=head;
	if(temp==NULL)
		cout<<"\nThe List is Empty!!!!!!"<<endl;
	cout<<"The List is:-\n"<<endl;
	while(temp!=NULL){
		cout<<temp->data;
		cout<<"-->";
		temp=temp->next;
	}
	cout<<"NULL";
	cout<<endl<<endl;
}

int LinkedList::countNodes(){
	Node *temp;
		temp=head;
		int i=0;
		while(temp!=NULL){
				temp=temp->next;	
				i++;
		}
	return i;		
}

int LinkedList::NodesAtEven(){
	cout<<"Even nodes are ..."<<endl<<endl;
		Node *temp;
		temp=head;
		int i=0;
		while(temp!=NULL){
			if(i%2==0)
				cout<<temp->data<<"-->";
			temp=temp->next;	
			i++;
		}
	cout<<endl;
	
}
int LinkedList::NodesAtOdd(){
	
		cout<<"Odd Nodes are :- "<<endl<<endl;
		Node *temp;
		temp=head;
		int i=0;
		while(temp!=NULL){
			if(i%2!=0)
				cout<<temp->data<<"-->";
			temp=temp->next;	
			i++;
	}
}
int LinkedList::swapNodes()
{
	Node *temp;
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		int temp1;
		temp1=head->data;
		head->data=temp->data;
		temp->data=temp1;
	cout<<"After Swapping the First and Last Node we get:- "<<endl;
	display();
}

void LinkedList::deleteBeg()
{
	cout<<"Delete at begening is done!!!"<<endl<<endl;
	if(head==NULL){
		cout<<"List is Empty!!!"<<endl;
		return;
	}
	Node *temp=head;
	head=head->next;
	free(temp);
}

void LinkedList::deleteEnd()
{
	cout<<"Delete at end is done!!!"<<endl<<endl;
	if(head==NULL){
		cout<<"List is Empty!!!"<<endl;
		return;
	}
	Node *temp=head,*prev;
	if(head->next==NULL){
		head=NULL;
		free(temp);
		return;
	}
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
}

void LinkedList::deleteItem()
{
	int item;
	cout<<"This is the process to delete the item which you enter!!!"<<endl;
	cout<<"Enter an element: ";
	cin>>item;
	if(head==NULL){
		cout<<"List is Empty!!!"<<endl;
		return;
	}
	Node *temp=head,*prev;
	if(temp->data==item ){
		head=head->next;
		delete(temp);
	}
	while(temp!=NULL && temp->data!=item){
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"Element Will Not Found"<<endl;
		return;
	}
	prev->next=temp->next;
	free(temp);
}
void LinkedList::reverse()
{
	Node *p,*q,*r=NULL;
	p=head;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=r;
		r=q;
	}
	head=q;
	cout<<"The Reverse Process is done!!!!!"<<endl;
	display();
}


int main()
{
	LinkedList l;
	int c;
	do{
		cout<<"\n******Enter Your Choice******\n";
		cout<<"1:Create Linked List at Begening"<<endl;
		cout<<"2:Create Linked List at End"<<endl;
		cout<<"3:Display the Linked List"<<endl;
		cout<<"4:Count Nodes"<<endl;
		cout<<"5:Odd Nodes"<<endl;
		cout<<"6:Even Nodes"<<endl;
		cout<<"7:Swap"<<endl;
		cout<<"8:Delete Element at begening"<<endl;
		cout<<"9:Delete Element at end"<<endl;
		cout<<"10:Delete item"<<endl;
		cout<<"11:Reverse"<<endl;
		cout<<"0:EXIT out!!!!"<<endl;		
		cin>>c;
		switch(c){
			case 1:
				system("CLS");
				l.insertBeg();
				break;
			case 2:
				l.insertEnd();
				break;
			case 3:
				system("CLS");
				l.display();
				break;
			case 4:
				cout<<"NO.of nodes are: "<<l.countNodes()<<endl;
				break;
			case 5:
				system("CLS");
				l.NodesAtOdd();
				break;
			case 6:
				system("CLS");
				l.NodesAtEven();
				break;
			case 7:
				system("CLS");
				l.swapNodes();
				break;
			case 8:
				system("CLS");
				l.deleteBeg();
				break;
			case 9:
				system("CLS");
				l.deleteEnd();
				break;
			case 10:
				system("CLS");
				l.deleteItem();
				break;
			case 11:
				system("CLS");
				l.reverse();
				break;
			case 0:
				cout<<"Good Bye!!!!!!!";
				break;
		}
	}
	while(c!=0);
	return 0;
}
