#include<iostream>
using namespace std;
#define size 10

class Node{
	public:
		int data;
		Node* next;
};

Node* newnode(int key){
	Node* ptr=new Node;
	ptr->data=key;
	ptr->next=NULL;
	return ptr;
} 

Node* table[size]={NULL};

int hash(int key){
	return (key%size);
}

void insert(int key){
	int index=key%size;
	if(table[index]==NULL){
		table[index]=newnode(key);
		return;
	}
	Node* temp=table[index];
	Node* prev;
	while(temp!=NULL){
		prev=temp;
		temp=temp->next;
	}
	prev->next=newnode(key);
	
	return;
}

Node* search(int key){
	int index=hash(key);
	Node *temp=table[index];
	while(temp!=NULL){
		if(temp->data==key){
			cout<<"Key Found: "<<key<<endl;
			return temp;
		}
		temp=temp->next;
	}
	cout<<"Key doesn't exist!!!!"<<endl;
	return NULL;
}

void remove(int key){
	int index=hash(key);
	Node *temp=table[index];
	Node *prev;
	while(temp != NULL && temp->data != key){
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"Key is not exist"<<endl;
		return;
	}
	if(temp==table[index]){
		table[index]=temp->next;
		delete(temp);
		return;
	}
	prev->next=temp->next;
	return;
}

void display()
{
    for(int i=0;i<size;i++)
    {
      	cout<<"Table index "<<i<<": ";
        Node* temp=table[i];
        while(temp!=NULL)
        {
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<endl;
    }

}

int main(){
	Node *temp;
	int x;
	do
    {
        cout<<"1.insert element"<<endl;
		cout<<"2.search element"<<endl;
		cout<<"3.delete elelement"<<endl;
		cout<<"4.display"<<endl;
		cout<<"0.Exit"<<endl;
        int n;
        cin>>n;
        switch(n)
        {
           	case 1:
           		system("CLS");
               	cout<<"Enter the item";
                cin>>x;
                insert(x);
                break;
            case 2:
            	system("CLS");
              	cout<<"Enter the element which you want to search: ";
              	cin>>x;
              	temp=search(x);
              	if(temp)
                    cout<<"Item is present"<<endl;
                else
                    cout<<"Item is not present"<<endl;
              	break;
            case 3:
            	system("CLS");
            	cout<<"Enter the element which you want to delete: ";
                cin>>x;
				remove(x);
                break;
            case 4:
            	system("CLS");
            	display();
                break;
            case 0:
                cout<<"Good Bye!!!!!!!";
				break;
            default:cout<<"Wrong Selection!!! please try again!!!"<<endl;
        }
    }
	while(x!=0);
}
