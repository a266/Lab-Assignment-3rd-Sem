#include<iostream>
using namespace std;
#include "linkedListNew.cpp"

/**
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
		~linkedlist()
		{
			node *temp=head;
			while(head!=NULL)
			{
            	head=head->next;
            	delete temp;
            	temp=head;
			}
		}
	double deletebeg();
	int top();
	void insertatsorted(double);
    bool isempty();
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
    
    while(temp!=NULL && item>temp->data)
    //while(temp!=NULL && temp->data)
	{
        prev=temp;
        temp=temp->next;
    }
    //cout<<"Insert"<<endl;
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


double linkedlist::deletebeg()
{
    if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		return INT_MIN;
	}
    double x=head->data;
	node *temp=head->next;
	delete head;
	head=temp;
	return x;
}
**/
void bucket_sort(double a[] , int n){
	
	linkedlist l[10];
	for(int i=0 ; i<n ; ++i)
	{
        int digit=a[i]*10;
        l[digit].insertatsorted(a[i]);
	}
	int j=0;
	for(int i=0 ; i<10 ; ++i)
	{
        while(!l[i].isempty())
			a[j++]=l[i].deletebeg();
	}
}

int main(){
	int n , i;
	cout<<"Enter number of elements: ";
	cin>>n;
	double a[n];
	cout<<"Enter elements: "<<endl;
	for(i=0 ; i<n ; ++i)
		cin>>a[i];

	cout<<"Before sorting"<<endl;
	
	for(i=0 ; i<n ; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
	
	bucket_sort(a , n);
	
	cout<<"After sorting"<<endl;
	for(i=0 ; i<n ; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
