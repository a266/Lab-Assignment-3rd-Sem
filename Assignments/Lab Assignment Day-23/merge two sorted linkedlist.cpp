#include<iostream>
using namespace std;

struct node{
		int data;
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
		void deletebeg();
		void deleteend();
            void deleteitem(int);
		void display();
		void rev();
		int top();

		//void insertatanypos(int , int);
            //void countnode();
            //void swapnode();
            //void displayeven();
            //void displayodd();



};
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
void linkedlist::deletebeg(){
      if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}

	node *temp=head->next;
	delete head;
	head=temp;
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
int main(){
      linkedlist l1 , l2;
      int m , n;
      cout<<"Enter size of two linkedlist"<<endl;
      cin>>m>>n;
      int k;
      cout<<"Enter item for list1"<<endl;
      for(int i=0 ; i<m ; ++i){
            cin>>k;
            l1.insertatend(k);
      }
      cout<<"Enter item for list2"<<endl;
      for(int i=0 ; i<n ; ++i){
            cin>>k;
            l2.insertatend(k);
      }
      linkedlist l3;
      while(l1.top()!=INT_MIN and l2.top()!=INT_MIN){
                  if(l1.top()<=l2.top()){
                        l3.insertatend(l1.top());
                        l1.deletebeg();
                  }
                  else{
                       l3.insertatend(l2.top());
                        l2.deletebeg();
                  }

      }
      while(l1.top()!=INT_MIN){
            l3.insertatend(l1.top());
            l1.deletebeg();
      }
      while(l2.top()!=INT_MIN){
            l3.insertatend(l2.top());
            l2.deletebeg();
      }
      l3.display();

}
