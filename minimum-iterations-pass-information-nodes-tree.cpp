#include<bits/stdc++.h>
using namespace std;

/*
17
0 1
0 2
0 3
0 4
0 5
0 6

1 7
1 8
1 9

4 10
4 11

6 12

7 13
7 14
10 15
11 16

*/
vector<int>g[1009];
int dp[1009];

int solve(int u){
	if(dp[u]!=-1)return dp[u];
	
	dp[u]=g[u].size();
	
	vector<int>child;
	for(int j=0;j<g[u].size();j++){
		child.push_back(solve(g[u][j]));
	}
	sort(child.rbegin(),child.rend());
	
	for(int j=0;j<child.size();j++){
		dp[u]=max(dp[u],j+1+child[j]);
	}
	return dp[u];
}
int main(){
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	memset(dp,-1,sizeof(dp));	
	solve(0);
	for(int i=0;i<n;i++)cout<<dp[i]<<" ";
}
