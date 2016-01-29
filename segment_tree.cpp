#include<bits/stdc++.h>
using namespace std;


int n,tree[200001],ar[100001];


void create(int node,int start=0,int last=n-1)
{
    if(start==last)
    {
        tree[node]=ar[start];return;
    }
    if(start<last)
    {
        int m=(start+last)>>1;
        create(2*node,start,m);
        create(2*node+1,m+1,last);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node,int start,int last,int s=0,int e=n-1)
{
    if(s>last||e<start)return INFINITY;
    if(s>=start&&e<=last)return tree[node];

    int m=(s+e)>>1;
    return min(query(2*node,start,last,s,m),query(2*node+1,start,last,m+1,e));
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    create(1);
    int q;cin>>q;
    while(q--)
    {
        int s,e;cin>>s>>e;
        cout<<query(1,s,e)<<endl;
    }
}
