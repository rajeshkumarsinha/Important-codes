#include<bits/stdc++.h>
using namespace std;

int bit[100009];
int n;
int ar[100009];

void update(int i,int val){
	while(i<=n){
		bit[i]+=val;
		i=i+(i&-i);
	}
}
int Sum(int i){
	int s=0;
	while(i){
		s+=bit[i];
		i=i-(i&-i);
	}
	return s;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		update(i,ar[i]);
	}
	int q;cin>>q;
	while(q--){
		int t;cin>>t;
		if(t){
			int i, val;cin>>i>>val;
			update(i,-ar[i]);
			update(i,val);
			ar[i]=val;
		}
		else{
			int L,R;cin>>L>>R;
			cout<<Sum(R)-Sum(L-1)<<endl;
		}
	}
}
