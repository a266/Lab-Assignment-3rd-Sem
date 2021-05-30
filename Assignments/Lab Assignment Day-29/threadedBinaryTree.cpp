#include<iostream>
using namespace std;
struct node
{
    bool lthread;
    node* lchild;
    node* rchild;
    int data;
    bool rthread;
};
node* inordersucc(node* x)
{
    if(x->rthread==true)
      	return x->rchild;
    x=x->rchild;
    while(x->lthread!=true)
	 	x=x->lchild;
    return x;
}
void inordertraversal(node* root)
{
    if(root==NULL) return;
      	node* temp=root;
    while(temp->lchild!=NULL) temp=temp->lchild;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=inordersucc(temp);
    }
}
node* newnode(int key)
{
    node* ptr=new node;
    ptr->data=key;
    ptr->lthread=true;
    ptr->rthread=true;
}
node* insert(node* root , int key)
{
    if(root==NULL)
    {
        root=newnode(key);
        root->lchild=NULL;
        root->rchild=NULL;
        return root;
    }
    node* temp=root;
    node* parent=NULL;
    while(temp!=NULL)
    {
        if(key==temp->data)
        {
            cout<<"duplicate"<<endl;
            	return root;
        }
        parent=temp;
        if(key<temp->data)
        {
            if(temp->lthread==false)
                temp=temp->lchild;
            else break;
        }
        else
        {
            if(temp->rthread==false)
                temp=temp->rchild;
            else break;
        }
    }
    node* curr=newnode(key);

    if(key<parent->data)
    {
        curr->lchild=parent->lchild;
        curr->rchild=parent;
        parent->lchild=curr;
        parent->lthread=false;
    }
    else
    {
        curr->lchild=parent;
        curr->rchild=parent->rchild;
        parent->rchild=curr;
        parent->rthread=false;
    }
}



int main()
{
    node* root=NULL;
    int x;
    do
    {

        cout<<"1.insert element\n2.inorder treaversal\n0.exit"<<endl;
        int n;
        cin>>n;
        switch(n)
        	{
            case 1:
            		system("CLS");
                  	cout<<"Enter the item"<<endl;
                  	cin>>x;
                  	root=insert(root , x);
                  	break;
            case 2:
            		system("CLS");
                  	if(root==NULL)
                  	{
                        cout<<"tree is empty"<<endl;
                        break;
                  	}
                  	inordertraversal(root);
                  	cout<<endl;
                  	break;
            
            case 4:
                  	cout<<"Good Bye!!!!!!!";
					break;
            default:cout<<"Wrong Selection!!! please try again!!!"<<endl;
			}
    }while(x!=0);
    return 0;
}
