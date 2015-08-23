#include <iostream>

using namespace std;

#define nodeptr struct node*

struct node{
    int data;
    node* next;
};

void print(nodeptr head)
{
    if(head)
    {
        cout<<head->data<<" ";
        print(head->next);
    }
}

void push(nodeptr *head,int data)
{
    nodeptr temp=new node;
    temp->data=data;
    temp->next=*head;
    *head=temp;
}

nodeptr mergelist(nodeptr a,nodeptr b)
{
    nodeptr mergedlist=NULL;
    if(a==NULL)return b;
    else if(b==NULL)return a;

    if(a->data<=b->data)
    {
        mergedlist=a;
        mergedlist->next=mergelist(a->next,b);
    }
    else
    {
        mergedlist=b;
        mergedlist->next=mergelist(a,b->next);
    }
    return mergedlist;
}

void partition(nodeptr head,nodeptr *front,nodeptr * back)
{
    nodeptr fast;
    nodeptr slow;

    if(head==NULL||head->next==NULL)
    {
        *front=head;
        *back=NULL;
    }
    else
    {
        slow=head;
        fast=head->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        *back=slow->next;
        slow->next=NULL;
        *front=head;
        print(*front);cout<<endl;
        print(*back);cout<<endl;
    }
}

void mergesort(nodeptr *source)
{
    nodeptr head=*source;
    nodeptr a=NULL;
    nodeptr b=NULL;

    if(head==NULL||head->next==NULL)return ;
    partition(head,&a,&b);

    mergesort(&a);
    mergesort(&b);

    *source=mergelist(a,b);
}

int main()
{
    nodeptr head=NULL;
    push(&head,23);
    push(&head,3);
    push(&head,13);
    push(&head,73);print(head);
    cout<<endl;
    mergesort(&head);
    print(head);
    return 0;
}
