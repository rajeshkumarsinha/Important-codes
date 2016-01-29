#include<bits/stdc++.h>
using namespace std;

int bit[100009],n;
void update(int i)
{
    while(i<=n)
    {
        bit[i]++;i+=(i&(-i));
    }
}

int read(int i)
{
    int s=0;
    while(i)
    {
        s+=bit[i];i-=(i&(-i));
    }
    return s;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(bit,0,sizeof(bit));
        cin>>n;
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;//x=-x;
            temp1.push_back(x);
            temp2.push_back(x);
        }
        sort(temp2.begin(),temp2.end());
        for(int i=0;i<n;i++)
        {
            temp1[i]=lower_bound(temp2.begin(),temp2.end(),temp1[i])-temp2.begin();
            temp1[i]++;
        }
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=read(temp1[i]-1);
            update(temp1[i]);
        }
        cout<<ans<<endl;
    }
}
