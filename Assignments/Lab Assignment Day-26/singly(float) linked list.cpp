#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	
	float data;
	node *next;
};
class linked_list{
	public:
	node *head;
	
	
	linked_list(){
		head=NULL;
		
		}
	bool underflow(){
		if(head==NULL)
			return true;
		return false;
	}	
	void insert_at_beg(float n){

		if(head==NULL){
			insert_at_end(n);
		}
			
		else{
				
			node *p;
			p=new node();
			p->data=n;
			p->next=head;
			head=p;
		}
	}
void insert_at_end(float n){
	
		if(head==NULL){
			head=new node();
			head->data=n;
		}
			
		else{
			node *t,*o;
			t=new node();
			o=new node();
			o->data=n;
			o->next=NULL;
			t=head;
			
			while(t->next!=NULL ){
				t=t->next;				
			}			
			t->next=o;		
		}	
	}
	void del_head(){
		node *t=head;
		head=head->next;
		free(t);
	}	
	float pop_front(){
		if(underflow())
			return -1456;
		float t=head->data;
		del_head();
		return t;
	}
	void insert_sorted(float n){
	//show();

	if(head==NULL){
		//cout<<"hh";
	insert_at_end(n);
	
		
	}

	else if(head->next==NULL){
	
	
		if((head->data)>n){
			
			insert_at_beg(n);
			
		
		}
		else
			insert_at_end(n);
		return;
	}
	else if(n<head->data){
		insert_at_beg(n);
	}
	else{
	
		node *p,*t,*q;
		q=new node();
		p= new node();
		q->data=n;
		q->next=NULL;
		t=head->next;
		p=head;
		while(t->data<n && t->next!=NULL){
			p=t;
			t=t->next;
		}
		if(t->next==NULL){
			if(t->data<n)
				insert_at_end(n);
			else{
				q->next=t;
				p->next=q;
			}
		}
			
		else{
			
			q->next=t;
			p->next=q;
		}
		return;
	}}	
	};	
