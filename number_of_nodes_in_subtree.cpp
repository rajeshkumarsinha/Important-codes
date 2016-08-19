// C++ program to find minimum initial points to reach destination
#include<bits/stdc++.h>
#define R 3
#define C 3
using namespace std;


vector<int>g[1009];

int dp[1009];

int solve(int u){
    if(dp[u]!=-1)return dp[u];
    int ans=1;
    for(int j=0;j<g[u].size();j++){
        ans+=solve(g[u][j]);
    }
    return dp[u]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }


    for(int i=1;i<=n;i++){
        if(dp[i]==-1)solve(i);
    }
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    return 0;
}
