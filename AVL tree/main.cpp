#include <iostream>
using namespace std;

struct node{
    int val;
    int c;
    node* lc;
    node* rc;
    int height;
};

node* getnode(int val,int c)
{
    node* temp=new node;
    temp->c=c;
    temp->val=val;
    temp->lc=NULL;
    temp->rc=NULL;
    temp->height=1;
    return temp;
}

int height(node* root)
{
    if(root==NULL)return 0;
    return root->height;
}

node* rcrotate(node* y)
{
    node* x=y->lc;
    node* t2=x->rc;
    x->rc=y;
    y->lc=t2;

    y->height=max(height(y->lc),height(y->rc))+1;
    x->height=max(height(x->lc),height(x->rc))+1;

    return x;
}

node* lcrotate(node* x)
{
    node* y=x->rc;
    node* t2=y->lc;
    y->lc=x;
    x->rc=t2;

    x->height=max(height(x->lc),height(x->rc))+1;
    y->height=max(height(y->lc),height(y->rc))+1;

    return y;
}

int getbalance(node* root)
{
    if(root==NULL)return 0;
    return height(root->lc)-height(root->rc);
}

node* insert(node* root,int val,int c)
{
    if(root==NULL)
    {
        return getnode(val,c);
    }

    if(root->val>val)
    {
        root->lc=insert(root->lc,val,c);
    }
    else if(root->val<val)
    {
        root->rc=insert(root->rc,val,c);
    }
    else
    {
        root->c+=c;
    }

    root->height=max(height(root->lc),height(root->rc))+1;
    int balance=getbalance(root);

    if(balance>1&&val<root->lc->val)
    {
        return rcrotate(root);
    }





    if(balance<-1&&val>root->rc->val)
    {
        return lcrotate(root);
    }

    if(balance>1&&val>root->lc->val)
    {
        root->lc=lcrotate(root->lc);
        return rcrotate(root);
    }

    if(balance<-1&&val<root->rc->val)
    {
        root->rc=rcrotate(root->rc);
        return lcrotate(root);
    }

    return root;
}

void preorder(node* root)
{
    if(root==NULL)return;
    cout<<root->val<<" ";
    preorder(root->lc);

    preorder(root->rc);
}

int main()
{
    node* root=NULL;
    root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  preorder(root);
    return 0;
}
