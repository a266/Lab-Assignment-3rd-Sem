#include<iostream>
using namespace std;

struct node{
		double data;
		struct node *next;
	};
	
class linkedlist{
	node *head;
	public:
		linkedlist(){
			head=NULL;
		}
		~linkedlist(){

		node *temp=head;
		while(head!=NULL){
                  head=head->next;
                  delete temp;
                  temp=head;
		}
		}
		void insertatbeg(int);
		void insertatend(int);
		double deletebeg();
		void deleteend();
            void deleteitem(int);
		void display();
		void rev();
		int top();
		void insertatsorted(double);
            bool isempty();

		//void insertatanypos(int , int);
            //void countnode();
            //void swapnode();
            //void displayeven();
            //void displayodd();



};
bool linkedlist::isempty(){
      return head==NULL;
}
void linkedlist::insertatsorted(double item){
      node *temp=head , *prev;
      node *curr=new node;
      curr->data=item;
      if(head==NULL){
            curr->next=head;
            head=curr;
            return;
      }
      while(temp!=NULL and item>temp->data){
                  prev=temp;
                  temp=temp->next;

      }

      if(temp==NULL){


            curr->next=NULL;
            prev->next=curr;
            return;
      }
      if(temp==head){
            curr->next=head;
            head=curr;
            return;
      }
      curr->next=temp;
      prev->next=curr;

}
int linkedlist::top(){
      if(head==NULL){

            return INT_MIN;
      }
      return head->data;
}
/*void linkedlist::swapnode(){
      node *temp=head;
      while(temp->next!=NULL)
                  temp=temp->next;
      int t=temp->data;
      temp->data=head->data;
      head->data=t;
}*/
/*void linkedlist::countnode(){
      node *temp=head;
      int cnt=0;
      while(temp!=NULL){
            ++cnt;
            temp=temp->next;
      }
      cout<<"Total no. of nodes is "<<cnt<<endl;
}*/
/*void linkedlist::displayeven(){
      node *temp=head;
      int t=0;
      while(temp!=NULL){
            if(t%2==0)
                  cout<<temp->data<<" ";
            ++t;
            temp=temp->next;
      }
      cout<<endl;
}*/
/*void linkedlist::displayodd(){
      node *temp=head;
      int t=0;
      while(temp!=NULL){
            if(t%2!=0)
                  cout<<temp->data<<" ";
            ++t;
            temp=temp->next;
      }
      cout<<endl;
}*/
void linkedlist::insertatbeg(int item){
	node *temp=new node;
	temp->data=item;
	temp->next=head;
	head=temp;
}
void linkedlist::insertatend(int item){
	node *p=head;
	node *temp=new node;
	if(head==NULL){
		temp->data=item;
		temp->next=NULL;
		head=temp;
		return;
	}
	while(p->next!=NULL){
		p=p->next;
	}

	temp->data=item;
	temp->next=NULL;
	p->next=temp;
}
double linkedlist::deletebeg(){
      if(head==NULL){
		cout<<"List is empty"<<endl;
		return INT_MIN;
	}
      double x=head->data;
	node *temp=head->next;
	delete head;
	head=temp;
	return x;
}
void linkedlist::deleteend(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	if(head->next==NULL){

		delete head;
		head=NULL;
	}
	node *p=head;
	while(p->next->next!=NULL){
		p=p->next;
	}

	node *temp=p->next;
	delete temp;
	p->next=NULL;
}
void linkedlist::deleteitem(int item){
if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	if(head->data==item){

		node *temp=head;
		head=head->next;
		delete temp;
	}
	node *p=head;
	node *pre=NULL;
	while(p!=NULL and p->data!=item){
            pre=p;
		p=p->next;
	}
      if(p==NULL){
            cout<<"item is not present"<<endl;
            return;
      }
	pre->next=p->next;
	delete p;

}
void linkedlist::display(){
	node *temp=head;
	while(temp->next!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;

	}
	cout<<temp->data;
	cout<<endl;

}
void linkedlist::rev(){

      if(head!=NULL){
           node *prevnode=head;
           head=head->next;
           node *curnode=head;
           prevnode->next=NULL;

      while(head!=NULL){
            head=head->next;
            curnode->next=prevnode;
            prevnode=curnode;
            curnode=head;
      }
      head=prevnode;
      }
      else
            cout<<"List is empty"<<endl;
}
