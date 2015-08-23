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
bool valid(int a,int b)
{
    while(a)
    {
        if(a==b)return true;a/=10;
    }
    return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
        int x,y;cin>>x>>y;
        double logx=log10((double)x);
        for(double i=1;i<=1000000;i++)
        {
            int u=i*logx;
            double z=i*logx-u;
//            cout<<100000*pow(10,z)<<endl;
            double x=pow(10,min(4,u))*pow(10,z);
            int num=x;
            if(num!=x)num++;//cout<<num<<endl;
            if(valid(num,y))
            {
                cout<<"Case "<<j<<": "<<(int)i<<endl;break;
            }
        }
	}
}
