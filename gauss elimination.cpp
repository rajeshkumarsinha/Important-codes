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
vector<double>vec[1009];

double ans[1009];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;cin>>n;
	cout<<setprecision(32)<<fixed;
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n+1;j++)
	    {
	        double x;cin>>x;vec[i].pb(x);
	    }
	}

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(vec[i][i]==0)swap(vec[i],vec[j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(vec[i][i]==0)
            {
                cout<<"Unsolvable"<<endl;return 0;
            }
            double coef=vec[j][i]/vec[i][i];
            for(int k=0;k<n+1;k++)
            {
                vec[j][k]=vec[j][k]-(vec[i][k]*coef);
            }
        }
    }
/*
    for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n+1;j++)
	    {
	        cout<<vec[i][j]<<" ";
	    }cout<<endl;
	}
*/
    for(int i=n-1;i>=0;i--)
    {
        ans[i]=vec[i][n];
        for(int j=n-1;j>i;j--)ans[i]=ans[i]-ans[j]*vec[i][j];
        ans[i]/=vec[i][i];
    }
    for(int i=0;i<n;i++)
	{
	    printf("%.2f\n",ans[i]);
	    //cout<<ans[i]<<endl;
	}
}
