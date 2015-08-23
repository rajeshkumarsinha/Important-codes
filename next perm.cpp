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
int main()
{
	std::ios::sync_with_stdio(false);
	string s;cin>>s;
	for(int c=0;c<10;c++)
	{
	    int pos=-1;
	    for(int i=0;i<s.length()-1;i++)
	    {
	        if(s[i]<s[i+1])pos=i;
	    }

	    int maxpos=pos+1;
	    for(int j=pos+1;j<s.length();j++)
	    {
	        if(s[j]>s[pos])maxpos=j;
	    }
	    swap(s[pos],s[maxpos]);

	    int start=pos+1,end=s.length()-1;
	    while(start<end)
	    {
	        swap(s[start],s[end]);start++;end--;
	    }
	    cout<<s<<endl;
	}
}
