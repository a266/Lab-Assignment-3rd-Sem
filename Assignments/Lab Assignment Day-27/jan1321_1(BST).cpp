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
node* mirrorimage(node* root)
{
      if(root==NULL) return root;
      mirrorimage(root->lchild);
      mirrorimage(root->rchild);


            node* temp=root->lchild;
            root->lchild=root->rchild;
            root->rchild=temp;



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
            if(item<par->data) par->lchild=newnode(item);
            else par->rchild=newnode(item);
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
bool searchnoderecur(node* root , int key)
{
            if(root==NULL) return false;
            if(root->data==key ) return true;
            else if(key<root->data)return searchnoderecur(root->lchild , key);
            else return searchnoderecur(root->rchild , key);


}
int totalnodes(node* root)
{
      if(root==NULL) return 0;
      return totalnodes(root->lchild)+totalnodes(root->rchild)+1;
}
int exnodes(node* root)
{
      if(root==NULL) return 0;
      if(root->lchild==NULL and root->rchild==NULL) return 1;
      else return exnodes(root->lchild)+exnodes(root->rchild);
}
int innodes(node* root)
{
      if(root==NULL) return 0;
      if(root->lchild==NULL and root->rchild==NULL) return 0;
      else return innodes(root->lchild)+innodes(root->rchild)+1;
}
int height(node* root)
{
      if(root==NULL) return 0;
      int lh=height(root->lchild);
      int rh=height(root->rchild);
      return MAX(lh , rh)+1;
}
int smallest(node* root)
{
      if(root==NULL) return -1;
      while(root->lchild!=NULL) root=root->lchild;
      return root->data;
}
int largest(node* root)
{
      if(root==NULL) return -1;
      while(root->rchild!=NULL) root=root->rchild;
      return root->data;
}
void delnode(node** root , int key)
{
      node* x=*root;
      node* par=NULL;
      while(x!=NULL and x->data!=key)
      {
            par=x;
            if(key<x->data) x=x->lchild;
            else x=x->rchild;
      }
      if(x==NULL)
      {
            cout<<"Not found"<<endl;
            return;
      }
      if(x->lchild==NULL or x->rchild==NULL)
      {
            node* ptr;
            if(x->lchild==NULL) ptr=x->rchild;
            else ptr=x->lchild;
            if(par==NULL)
            {

                  cout<<ptr->data<<endl;
                  cout<<ptr->rchild<<" "<<ptr->lchild<<endl;
                  *root=ptr;

                  delete x;
                  return;
            }
      else
            {
                  if(x==par->lchild) par->lchild=ptr;
                  else par->rchild=ptr;

                  delete x;
                  return;
            }

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
            if(parsucc!=NULL)
                  succ->lchild=succ->rchild;
            else x->rchild=succ->rchild;
            delete succ;
      }


}
int main()
{
      node* root=NULL;
      int x;
      while(1)
      {

            cout<<"1.insert element\n2.preorder treaversal\n3.inorder traversal\n4.postorder traversal\n5.smallest element\n6.largest element\n7.delete an element\n8.count total no. of nodes\n9.count total no. of external nodes\n10.count total no. of internal nodes\n11.height\n12.searchnode\n13.exit"<<endl;
            int n;
            cin>>n;
            switch(n)
            {
            case 1:
                  cout<<"Enter the item"<<endl;
                  cin>>x;
                  root=insert(root , x);
                  break;
            case 2:
                  printpreorder(root);
                  cout<<endl;
                  break;
            case 3:
                  printinorder(root);
                  cout<<endl;
                  break;
            case 4:
                  printpostorder(root);
                  cout<<endl;
                  break;
            case 5:
                  cout<<"smallest: "<<smallest(root)<<endl;
                  break;
            case 6:
                  cout<<"largest: "<<largest(root)<<endl;
                  break;
            case 7:
                  cout<<"Enter item"<<endl;
                  cin>>x;
                  delnode(&root , x);
                  //cout<<root->data<<endl;
                  break;
            case 8:
                  cout<<"total nodes: "<<totalnodes(root)<<endl;
                  break;
            case 9:
                  cout<<"external nodes: "<<exnodes(root)<<endl;
                  break;
            case 10:
                  cout<<"internal nodes: "<<innodes(root)<<endl;
                  break;
            case 11:
                  cout<<"height: "<<height(root)<<endl;
                  break;
            case 12:
                  cout<<"Enter item"<<endl;
                  cin>>x;
                  if(searchnoderecur(root , x)) cout<<"present"<<endl;
                  else cout<<"Not present"<<endl;
                  break;
            case 13:
                  root=mirrorimage(root);
                  break;
            case 14:
                  return 0;
            }
      }
}
