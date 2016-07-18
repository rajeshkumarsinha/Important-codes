#include<bits/stdc++.h>
using namespace std;

int bit[1039][1039];
int n;
int ar[1039][1039];

void update(int i,int j,int val){
	while(i<=n){
		int y=j;
		while(y<=n){
			bit[i][y]+=val;
			y=y+(y&-y);
		}
		i=i+(i&-i);
	}
}
int Sum(int i,int j){
	int s=0;
	while(i){
		int y=j;
		while(y){
			s+=bit[i][y];
			y=y-(y&-y);
		}
		i=i-(i&-i);
	}
	return s;
}

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main(){
	int t=readInt();
	while(t--){
		n=readInt();
		memset(ar,0,sizeof(ar));
		memset(bit,0,sizeof(bit));
		while(true){
			char s[5];scanf("%s",s);
			if(s[1]=='E'){
				int i, j, val;
				i=readInt();j=readInt();val=readInt();
				i++;j++;
				update(i,j,-ar[i][j]);
				update(i,j,val);
				ar[i][j]=val;
			}
			else if(s[1]=='U'){
				int L1,R1,L2,R2;
				L1=readInt();R1=readInt();L2=readInt();R2=readInt();
				L1++;R1++;L2++;R2++;
				int s1=Sum(L2,R2)+Sum(L1-1,R1-1)-Sum(L2,R1-1)-Sum(L1-1,R2);
				printf("%d\n",s1);		
			}
			else{
				break;
			}
		}
	}
}
