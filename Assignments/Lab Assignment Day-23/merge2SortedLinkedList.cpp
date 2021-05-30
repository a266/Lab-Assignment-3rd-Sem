#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

void print(Node* node)
{
	cout<<"The result is: "<<endl;
	while(node != NULL){
		cout<<node->data<<"-->";
		node=node->next;
	}
	cout<<"NULL"<<endl;
}


void push(struct Node** head,int item){
	Node *curr=new Node();
	curr->data=item;
	Node* temp=*head,*prev;
	while(temp!=NULL && temp->data<item){
		prev=temp;
		temp=temp->next;
	}
	if(temp==*head){
		curr->next=*head;
		*head=curr;
		return;
	}
	prev->next=curr;
	curr->next=temp;
}

Node* sortedMerge(Node* head1,Node* head2)
{
	if(head1==NULL)
	return head2;
	if(head2==NULL)
	return head1;
	
	Node* result=NULL;
		
	if(head1->data<=head2->data)
	{
		result=head1;
		result->next=sortedMerge(head1->next,head2);
	}
	else
	{
		result=head2;
		result->next=sortedMerge(head1,head2->next);
	}
	return result;
}

int main()
{
    int m , n;
    cout<<"Enter size of two linkedlist"<<endl;
    cin>>m>>n;
    Node* head1=NULL;
    Node* head2=NULL;
    int k;
    cout<<"Enter item for list1"<<endl;
    for(int i=0 ; i<m ; ++i){
        cin>>k;
        push(&head1, k);
    }
    cout<<"Enter item for list2"<<endl;
    for(int i=0 ; i<n ; ++i){
        cin>>k;
        push(&head1, k);
    }	
	Node* result=sortedMerge(head1,head2);
	print(result);
}
