#include<bits/stdc++.h>
using namespace std;

#define l long long


struct node{
    int data;
    node* lc;
    node* rc;
};

node* getNode(int data){
    node* temp=new node;
    temp->data=data;
    temp->lc=NULL;
    temp->rc=NULL;
    return temp;
}

node* Insert(node* root,int data){
    if(root==NULL)return getNode(data);
    else if(root->data>data)root->lc=Insert(root->lc,data);
    else root->rc=Insert(root->rc,data);
    return root;
}

void inOrder(node* root){
    if(root){
        inOrder(root->lc);
        cout<<root->data<<" ";
        inOrder(root->rc);
    }
}

node* minNode(node* root){
    while(root->lc)root=root->lc;return root;
}

node* Delete(node* root,int data){
    if(root==NULL)return root;
    else if(root->data>data)root->lc=Delete(root->lc,data);
    else if(root->data<data)root->rc=Delete(root->rc,data);
    else{
        if(root->lc==NULL){
            node* rc=root->rc;
            free(root);return rc;
        }
        else if(root->rc==NULL){
            node* lc=root->lc;
            free(root);return lc;
        }
        else{
            node* minnode=minNode(root->rc);
            root->data=minnode->data;
            root->rc=Delete(root->rc,minnode->data);
        }
    }
    return root;
}
int main(){
    node* root=NULL;
    while(true){
        int type,data;
        cin>>type>>data;
        //1 for insertion
        if(type){
            root=Insert(root,data);
        }
        else{
            root=Delete(root,data);
        }
        inOrder(root);cout<<endl;
    }
}
