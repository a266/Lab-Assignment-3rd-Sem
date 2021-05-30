#include<iostream>
using namespace std;
struct node
{
      int data;
      node* next;
};

node* table[10];
node* newnode(int key)
{
      node* ptr=new node;
      ptr->data=key;
      ptr->next=NULL;
      return ptr;
}

void insert(int key)
{
      int indx=key%10;
      if(table[indx]==NULL)
      {
            table[indx]=newnode(key);
            return ;
      }
      node* temp=table[indx];
      node* prev;
      while(temp!=NULL)
      {
            prev=temp;
            temp=temp->next;
      }
      prev->next=newnode(key);
      return;

}
node* search(int key)
{
      int indx=key%10;
      node* temp=table[indx];
      while(temp!=NULL)
      {
            if(temp->data==key) return temp;
            temp=temp->next;
      }
      return NULL;

}
void del(int key)
{
      int indx=key%10;
      node* temp=table[indx];
      node* prev;
      while(temp!=NULL and temp->data!=key)
      {
            prev=temp;
            temp=temp->next;
      }
      if(temp==NULL)
      {
            cout<<"Item not found"<<endl;
            return;
      }
      if(temp==table[indx])
      {
            table[indx]=temp->next;
            delete temp;
            return;
      }
      prev->next=temp->next;
      delete temp;
}
void destructor()
{
      int i=0;
      while(i<10)
      {
            node*cur=table[i++];
            while(cur!=NULL)
            {
                  node* temp=cur;
                  cur=cur->next;
                  delete temp;

            }
      }
}
void display()
{
      int i=0;
      while(i<10)
      {
            node*cur=table[i++];
            while(cur!=NULL)
            {
                  node* temp=cur;
                  cur=cur->next;
                  cout<<temp->data<<"->";

            }

            cout<<endl;
            if(table[i]==NULL) break;
      }

}
int main()
{
      int x , n;
      node* temp;
      while(1)
      {
            cout<<"1.Insert\n2.search\n3.delete\n4.exit\n5.display"<<endl;
            cin>>x;
            switch(x)
            {
            case 1:
            	  system("CLS");
                  cout<<"Enter your item"<<endl;
                  cin>>n;
                  insert(n);
                  break;
            case 2:
            	  system("CLS");
                  cout<<"Enter the item"<<endl;
                  cin>>n;
                  temp=search(n);
                  if(temp)
                        cout<<"Item is present"<<endl;
                  else
                        cout<<"Item is not present"<<endl;
                  break;

            case 3:
            	  system("CLS");
                  cout<<"Enter the item"<<endl;
                  cin>>n;
                  del(n);
                  break;
            case 4:
            	  system("CLS");
                  destructor();
                  return 0;
            case 5:
            	  system("CLS");
                  display();
                  break;


            }
      }

}
