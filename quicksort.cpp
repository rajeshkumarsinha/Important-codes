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
int partition(int ar[],int start,int end)
{
    int pivot=start,i=start,j=end;
    while(i<j)
    {
        while(i<end&&ar[i]<=ar[pivot])i++;
        while(ar[j]>ar[pivot])j--;
        if(i<j)swap(ar[i],ar[j]);
    }
    swap(ar[j],ar[pivot]);
    return j;
}

void quicksort(int ar[],int start,int end)
{
    if(start<end)
    {
        int p=partition(ar,start,end);
        quicksort(ar,start,p-1);
        quicksort(ar,p+1,end);
    }
}

int main()
{
//    string str;
//    getline(cin,str);
//    istringstream sso(str);
//    string x;
//    while(sso>>x)cout<<x<<endl;
    int n;cin>>n;int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];
    quicksort(ar,0,n-1);for(int i=0;i<n;i++)cout<<ar[i]<<" ";
}
