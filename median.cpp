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

int findkth(int a[],int m,int b[],int n ,int k)
{
    if(m>n)return findkth(b,n,a,m,k);
    if(m==0)return b[k-1];

    if(k==1)return min(a[0],b[0]);

    int i=min(k/2,m),j=k-i;

    if(a[i-1]>b[j-1])return findkth(a,i,b+j,n-j,k-j);
    else return findkth(a+i,m-i,b,j,k-i);

}
int main()
{
	std::ios::sync_with_stdio(false);
	int a[]={2,3,4,5,9},b[]={-1,0,1,7};
	while(true)
	{
        int k;cin>>k;
        cout<<findkth(a,5,b,4,k)<<endl;
	}
}
