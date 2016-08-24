#include<bits/stdc++.h>
using namespace std;


int solve(int Egg,int Floor){
    if(Floor==0)return 0;
    if(Egg==0)return 1000000;
    if(Egg==1)return Floor-1;

    int ans=1000000;
    for(int i=1;i<=Floor;i++){
        int val=1+max(solve(Egg-1,i-1),solve(Egg,Floor-i));
        ans=min(ans,val);
    }
    return ans;
}
int main(){
    cout<<solve(2,100);
}
