#include <bits/stdc++.h>
using namespace std;

#define l long long
#define mod 1000000007
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

vector<int>graph[10009];
bool visited[10009];
int low[10009],disc[10009],parent[10009];

void aputil(int u)
{
    static int time=0;
    visited[u]=true;
    int children=0;
    low[u]=disc[u]=++time;

    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visited[v])
        {
            children++;//increase the number of children
            parent[v]=u;//set the parent
            aputil(v);//call the function recursively

            low[u]=min(low[u],low[v]);//change the low for u

            if(parent[u]==-1&&children>1)cout<<u<<endl;//check for root
            else if(parent[u]!=-1&&low[v]>=disc[u])cout<<u<<endl;//check for non root nodes
        }
        else if(v!=parent[u])low[u]=min(low[u],disc[v]);
        /*
        if there is back edge then change the low of u by the discovery time of v
        */
    }
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
	    int a,b;cin>>a>>b;
	    graph[a].pb(b);graph[b].pb(a);
	}
    for(int i=0;i<n;i++)parent[i]=-1;
    for(int i=0;i<n;i++)if(!visited[i])aputil(i);
}
