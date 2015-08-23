#include <bits/stdc++.h>
using namespace std;

#define sum(a,b) a+b
#define l long long
#define mod 1000000007
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second


l tree[300009],ar[100009],lazy[300009];
//update from s->e

l query(l node,l start,l end,l s,l e)
{
    if(start>e||end<s)return 0;

    if(lazy[node])
    {
        if(start==end)
        {
            tree[node]+=lazy[node];
        }
        else
        {
            tree[node]+=lazy[node]*(end-start+1);
            lazy[2*node]+=lazy[node];lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(start>=s&&end<=e)return tree[node];
    int m=(start+end)/2;
    return sum(query(2*node,start,m,s,e),query(2*node+1,1+m,end,s,e));
}

void update(l node,l start,l end,l s,l e,l val)
{
    if(start>e||end<s)return;
    if(lazy[node])
    {
        if(start==end)
        {
            tree[node]+=lazy[node];
        }
        else
        {
            tree[node]+=lazy[node]*(end-start+1);
            lazy[2*node]+=lazy[node];lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(start>=s&&end<=e)
    {
        if(start==end)
        {
            tree[node]+=val;
        }
        else
        {
            tree[node]+=val*(end-start+1);
            lazy[2*node]+=val;lazy[2*node+1]+=val;
        }
        return;
    }

    int m=(start+end)/2;
    update(2*node,start,m,s,e,val);update(2*node+1,1+m,end,s,e,val);
    tree[node]=query(2*node,start,m,start,m)+query(2*node+1,m+1,end,m+1,end);
}


int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		memset(ar,0,sizeof(ar));
		memset(lazy,0,sizeof(lazy));
		int n,m;cin>>n>>m;
		while(m--)
		{
		    int type;cin>>type;
		    if(type==0)
		    {
		        int p,q,v;cin>>p>>q>>v;
		        update(1,1,n,p,q,v);
		    }
		    else
		    {
		        int p,q;cin>>p>>q;
		        cout<<query(1,1,n,p,q)<<endl;
		    }
		}
	}
}
