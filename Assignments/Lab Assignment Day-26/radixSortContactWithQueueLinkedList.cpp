#include<iostream>
using namespace std;

struct node{
      int data;
      struct node *next;
};
class queue{
      node *front , *rear;
public:
      queue(){
            front=NULL;
            rear=NULL;
      }
      ~queue(){
            node *temp=new node;
            while(front!=NULL){
                  temp=front;
                  front=front->next;
                  delete temp;
            }
      }
      void enqueue(int);
      int dequeue();

      void display();
      bool isempty();
};
void queue::enqueue(int item){
      node *curr=new(nothrow) node;
      curr->data=item;
      if(rear==NULL){
            curr->next=rear;
            rear=curr;
            front=curr;
            return;
      }
      curr->next=NULL;
      rear->next=curr;
      rear=curr;
}
int queue::dequeue(){

      int x;

      if(rear==NULL){
            cout<<"queue is empty"<<endl;
            return INT_MIN;
      }
      node *temp=new(nothrow) node;

      if(temp==NULL){
            cout<<"Failed"<<endl;
            return INT_MIN;
      }

      temp=front;

      x=temp->data;
      front=front->next;
      if(front==NULL) rear=NULL;
      delete temp;
      return x;
}

bool queue::isempty(){
      return rear==NULL;
}
void queue::display(){

      if(rear==NULL){
            cout<<"queue is empty"<<endl;
            return;
      }
      node* temp=front;
      while(temp!=rear){

            cout<<temp->data<<" ";
            temp=temp->next;
      }
      cout<<temp->data<<endl;
}





int getMax(int a[] , int n){
	int m=INT_MIN;
	for(int i=0 ; i<n ; ++i)
		m=max(m , a[i]);
	return m;
}

void radix_sort(int a[] , int n)
{
	int m=getMax(a , n);
	int pow10=1;
	int t=1;
	queue q[10];
	for(int pow10=1 ; m/pow10>0 ; pow10*=10)
	{
        for(int i=0 ; i<n ; ++i)
		{
            int digit=(a[i]/pow10)%10;
            q[digit].enqueue(a[i]);
        }
		int j=0;
		for(int i=0 ; i<10 ; ++i)
		{
        	while(!q[i].isempty())
				a[j++]=q[i].dequeue();
		}
	}

}
int main(){
	int n , i;
	cout<<"Enter number of elements: ";
	cin>>n;
	cout<<"Enter elements: "<<endl;
	int a[n];
	for(i=0 ; i<n ; ++i)
		cin>>a[i];
		
	cout<<"Before sorting"<<endl;
	for(i=0 ; i<n ; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
	
	radix_sort(a , n);
	
	cout<<"After sorting"<<endl;
	for(i=0 ; i<n ; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

