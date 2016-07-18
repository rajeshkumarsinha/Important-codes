#include<bits/stdc++.h>
using namespace std;

#define l long long
#define ii pair<int,string>
#define mod 1000000007

l g[1001];
l f[1001];
l h[1001];
l power(l x,l y){
    l ans=1;
    while(y){
        if(y&1)ans=ans*x;ans%=mod;
        x=x*x;x=x%mod;y>>=1;
    }
    return ans;
}
int main(){
    f[0]=1;f[1]=1;
    f[2]=2;f[3]=4;

    for(int i=4;i<=1000;i++){
        f[i]=(f[i-1]+f[i-2]+f[i-3]+f[i-4])%mod;
    }
    int t;cin>>t;
    while(t--){
        l n,m;cin>>n>>m;
        for(int i=1;i<=m;i++)g[i]=power(f[i],n);
        h[1]=1;
        for(int i=2;i<=m;i++){
            h[i]=g[i];
            for(int j=1;j<i;j++){
                h[i]=h[i]-(h[j]*g[i-j])%mod;
                h[i]+=(l)4*mod;
                h[i]%=mod;

            }
        }
        cout<<h[m]<<endl;
    }
}
