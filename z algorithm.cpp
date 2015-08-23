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

int z[100009];
int main()
{
	std::ios::sync_with_stdio(false);
	string s;cin>>s;z[0]=s.length();


	int L=0,R=0;
	for(int i=1;i<s.length();i++)
	{
	    if(i>R)
	    {
	        L=R=i;
	        while(R<s.length()&&s[R-L]==s[R])R++;
	        z[i]=R-L;R--;
	    }
	    else
	    {
	        int k=i-L;
	        if(z[k]<R-i+1)z[i]=z[k];
	        else
	        {
	            L=i;
	            while(R<s.length()&&s[R-L]==s[R])R++;
	            z[i]=R-L;R--;
	        }
	    }
	}

	for(int i=0;i<s.length();i++)cout<<z[i]<<" ";
}
