
#include <bits/stdc++.h>
using namespace std;

#define l long long
#define mod 1000000007
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

/*
	replace endl with

*/
int graph[4][4] = { {0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0}
                  };
int dp[1<<15][15];
int n,src;
void init()
{
    for(int i=0;i<n;i++)
        dp[1<<i][i]=graph[src][i];
}

int tsp(int status,int x)
{
    if(dp[status][x]!=-1)
        return dp[status][x];

    int mask=1<<x;
    dp[status][x]=1e9;
    for(int i=0;i<n;i++)
    {
        if(i!=x&&(status&(1<<i)))
            dp[status][x]=min(dp[status][x]
                              ,tsp(status-mask,i)+graph[i][x]);
    }
    return dp[status][x];
}

int main()
{
	std::ios::sync_with_stdio(false);
	n=4,src=2;
    for(int i=0;i<pow(2,n);i++)
    {
        for(int j=0;j<n;j++)dp[i][j]=-1;
    }

	init();
	printf( "%d\n", tsp( ( 1 << n ) - 1, src ) );
	return 0;
}
