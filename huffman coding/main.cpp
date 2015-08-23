#include <bits/stdc++.h>
using namespace std;


struct node{
    char ch;
    int frequency;
    node* left;
    node* right;
};

int sz=0;
node* minheap[1009];

int parent(int i)
{
    return i/2;
}

void insert(node* tobeinserted)
{
    minheap[++sz]=tobeinserted;
    int i=sz;
    while(parent(i)>0)
    {
        if(minheap[i]->frequency<minheap[parent(i)]->frequency)
        {
            swap(minheap[i],minheap[parent(i)]);
        }
        i=parent(i);
    }
}


void minheapify(int i)
{
    int min=i;
    if(2*i>=1&&2*i<=sz&&minheap[min]->frequency>minheap[2*i]->frequency)min=2*i;
    if(2*i+1>=1&&2*i+1<=sz&&minheap[min]->frequency>minheap[2*i+1]->frequency)min=1+2*i;
    if(min!=i)
    {
        swap(minheap[i],minheap[min]);
        minheapify(min);
    }
}

void deletemin()
{
    //cout<<minheap[1]->frequency<<endl;
    minheap[1]=minheap[sz];
    sz--;
    minheapify(1);
}

node* min()
{
    node* temp=minheap[1];
    deletemin();
    return temp;
}

void print(node* head,string str)
{
    if(head->ch!='\0')
    {
        cout<<head->ch<<" ";
        cout<<str<<endl;
        return;
    }
    else
    {
            print(head->left,str+'0');
            print(head->right,str+'1');
    }

}

int main()
{

    for(int i=0;i<6;i++)
    {
        node* temp=new node;
        //temp->frequency=rand()%10;
        cin>>temp->frequency;
        cout<<temp->frequency<<endl;
        temp->ch='a'+i;
        temp->left=NULL;
        temp->right=NULL;
        insert(temp);
    }
    cout<<endl;
    while(sz>1)
    {
        node* a=min();
        node* b=min();
        node* newnode= new node;
        newnode->frequency=a->frequency+b->frequency;
        newnode->left=a;
        newnode->right=b;
        insert(newnode);
        cout<<newnode->frequency<<endl;
    }
        node* head=minheap[1];
        cout<<head->frequency<<endl;
        print(head,"");
}
