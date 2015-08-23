#include<bits/stdc++.h>
using namespace std;


#define ll long long

ll mulmod(ll a,ll b,ll mod)
{
    ll x=0,y=a%mod;
    while(b)
    {

        if(b%2==1)x=(x+y)%mod;

        y=y*2;
        y%=mod;
        b=b/2;
    }
    return x%mod;
}

ll power(ll a,ll b,ll m)
{
    if(b==0)return 1;
    ll num=power(a,b/2,m);

    if(b%2==0)return mulmod(num,num,m)%m;
    if(b%2==1)return mulmod(a,(mulmod(num,num,m)%m),m)%m;
}

bool Miller(ll p,int iteration)

{
    if(p<2)return false;
    if(p==2)return true;
    if(p%2==0)return false;

    ll s=p-1;
    while(s%2==0)
    {
        s/=2;
    }
    for(int i=0;i<iteration;i++)
    {
        ll temp=s,randomnumber=rand()%(p-1)+1;
        ll value=power(randomnumber,temp,p);;

        while(value!=1&&value!=p-1&&temp!=p-1)
        {
            temp=temp*2;
            value=power(randomnumber,temp,p);

        }

        if(value!=p-1&&temp%2==0)return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        if(Miller(x,200))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
