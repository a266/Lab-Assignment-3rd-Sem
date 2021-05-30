#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node *next;
}*head=NULL;

void addEnd(){
	cout<<"Eneter value: ";
	int n;
	cin>>n;
	struct node p=(struct node)malloc(sizeof(struct node*));
	p->data=n;
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
		retturn;
	}
	else
	{
		struct node *temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
	}
}

void addBeg(){
	
}
