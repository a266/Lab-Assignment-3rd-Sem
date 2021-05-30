#include<iostream>
using namespace std;

struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
};

int MAX(int a , int b)
{
    return a>=b? a : b;
}

node* newnode(int item)
{
    node* ptr=new node;
    ptr->data=item;
    ptr->rchild=NULL;
    ptr->lchild=NULL;
}

node* insert(node* root , int item)
{
    if(root==NULL) return newnode(item);
    else
    {
    	node* temp=root;
        node* par=NULL;
        while(temp!=NULL)
            {
                par=temp;
                if(item<temp->data) temp=temp->lchild;
                else temp=temp->rchild;
            }
        if(item<par->data) 
			par->lchild=newnode(item);
        else 
			par->rchild=newnode(item);
    }
    return root;
}

void printinorder(node* root)
{
    if(root==NULL) return;
    printinorder(root->lchild);
    cout<<root->data<<" ";
    printinorder(root->rchild);
}

void printpreorder(node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    printinorder(root->lchild);
    printinorder(root->rchild);
}

void printpostorder(node* root)
{
    if(root==NULL) return;
    printinorder(root->lchild);
    printinorder(root->rchild);
    cout<<root->data<<" ";
}

bool searchnodeiter(node* root , int key)
{
    while(root!=NULL)
    {
    	if(root->data==key) return true;
        else if(key<root->data) root=root->lchild;
        else root=root->rchild;
    }
    return false;
}

bool searchnoderecursively(node* root , int key)
{
    if(root==NULL) return false;
    if(root->data==key ) return true;
    else if(key<root->data)return searchnoderecursively(root->lchild , key);
    else return searchnoderecursively(root->rchild , key);
}

int totalnodes(node* root)
{
    if(root==NULL) return 0;
    return totalnodes(root->lchild)+totalnodes(root->rchild)+1;
}

int externalnodes(node* root)
{
    if(root==NULL) return 0;
    if(root->lchild==NULL and root->rchild==NULL) return 1;
    else return externalnodes(root->lchild)+externalnodes(root->rchild);
}
int internalnodes(node* root)
{
    if(root==NULL) return 0;
    if(root->lchild==NULL and root->rchild==NULL) return 0;
    else return internalnodes(root->lchild)+internalnodes(root->rchild)+1;
}
int height(node* root)
{
    if(root==NULL) return 0;
    int lh=height(root->lchild);
    int rh=height(root->rchild);
    return MAX(lh , rh)+1;
}
int smallestItem(node* root)
{
    if(root==NULL) return -1;
    while(root->lchild!=NULL) root=root->lchild;
    return root->data;
}
int largestItem(node* root)
{
    if(root==NULL) return -1;
    while(root->rchild!=NULL) root=root->rchild;
    return root->data;
}

void deletenode(node** root , int key)
{
	if(*root==NULL)return;
    node* x=*root;
    node* par=NULL;
    while(x!=NULL and x->data!=key)
    {
        par=x;
        if(key<x->data)
			x=x->lchild;
        else
			x=x->rchild;
    }
    if(x==NULL)
    {
        cout<<"Element not found"<<endl;
        return;
	}
    if(x->lchild==NULL or x->rchild==NULL)
    {
        node* ptr;
        if(x->lchild==NULL)
			ptr=x->rchild;
        else
			ptr=x->lchild;
        if(par==NULL)
        {
            cout<<ptr->data<<endl;
            cout<<ptr->rchild<<" "<<ptr->lchild<<endl;
            *root=ptr;
            delete x;
            return;
        }
        if(x==par->lchild) 
			par->lchild=ptr;
        else 
			par->rchild=ptr;
        delete x;
        return;
    }
    else
    {
        node* succ=x->rchild;
        node* parsucc=NULL;
        while(succ->lchild!=NULL)
        {
            parsucc=succ;
            succ=succ->lchild;
        }
        x->data=succ->data;
        if(parsucc==NULL)
            x->rchild=succ->rchild;
        else 
			parsucc->lchild=succ->rchild;
        delete succ;
        return;
	}
}

int getSum(node *root,int L,int H){
	if(root == NULL)return 0;
	if(root->data<L)
		return getSum(root->rchild,L,H);
	if(root->data>H)
		return getSum(root->lchild,L,H);
	if(root->data>=L && root->data<=H)
		return getSum(root->lchild,L,H)+(root->data)+getSum(root->rchild,L,H);
}

int main()
{
    node* root=NULL;
    int x;
    do
    {
        cout<<"1.insert element"<<endl;
		cout<<"2.preorder treaversal"<<endl;
		cout<<"3.inorder traversal"<<endl;
		cout<<"4.postorder traversal"<<endl;
		cout<<"5.smallest element"<<endl;
		cout<<"6.largest element"<<endl;
		cout<<"7.delete an element"<<endl;
		cout<<"8.count total no. of nodes"<<endl;
		cout<<"9.count total no. of external nodes"<<endl;
		cout<<"10.count total no. of internal nodes"<<endl;
		cout<<"11.height"<<endl;
		cout<<"12.searchnode"<<endl;
		cout<<"13.Get the sum using limit\n"<<endl;
		cout<<"14.Exit"<<endl;
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
              	printpreorder(root);
                cout<<endl;
                break;
            case 3:
            	system("CLS");
                printinorder(root);
                cout<<endl;
                break;
            case 4:
            	system("CLS");
              	printpostorder(root);
                cout<<endl;
                break;
            case 5:
            	system("CLS");
                cout<<"Smallest Element is: "<<smallestItem(root)<<endl;
                break;
            case 6:
            	system("CLS");
              	cout<<"Largest Element is: "<<largestItem(root)<<endl;
                break;
            case 7:
            	system("CLS");
                cout<<"Enter item"<<endl;
                cin>>x;
                deletenode(&root , x);
                break;
            case 8:
            	system("CLS");
                cout<<"Total Nodes in Binary Search Tree is: "<<totalnodes(root)<<endl;
                break;
            case 9:
            	system("CLS");
                cout<<"External nodes of Binary Search Tree is: "<<externalnodes(root)<<endl;
                break;
            case 10:
            	system("CLS");
                cout<<"Internal nodes of Binary Search Tree is: "<<internalnodes(root)<<endl;
                break;
            case 11:
            	system("CLS");
                cout<<"The Height of the Binary Search Tree is: "<<height(root)<<endl;
                break;
            case 12:
            	system("CLS");
                cout<<"Enter item to Search: "<<endl;
                cin>>x;
                if(searchnoderecursively(root , x))
					cout<<"Element is present"<<endl;
                else
					cout<<"Element is not present"<<endl;
                break;
            case 13:
            	system("CLS");
            	int l,h,sum;
                cout<<"Enter the lowerLimit: "<<endl;
                cin>>l;
                cout<<"Enter the UpperLimit: "<<endl;
                cin>>h;
                sum=getSum(root, l, h);
                cout<<"The sum is: "<<endl;
                cout<<sum<<endl<<endl;
                break;
            case 0:
                cout<<"Good Bye!!!!!!!";
				break;
            default:cout<<"Wrong Selection!!! please try again!!!"<<endl;
        }
    }
	while(x!=0);
	return 0;
}
