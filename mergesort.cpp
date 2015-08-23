#include<iostream>
using namespace std;

void combine(int ar[],int start,int mid,int end)
{
    int temp[5009];
    int i=start,j=mid+1,k=0;
    while(i<=mid&&j<=end)
    {
        if(ar[i]<ar[j])temp[k++]=ar[i++];
        else temp[k++]=ar[j++];
    }
    while(i<=mid)
    {
        temp[k++]=ar[i++];
    }
    while(j<=end)
    {
        temp[k++]=ar[j++];
    }
    for(int i=start;i<=end;i++)
    {
        ar[i]=temp[i-start];
    }
}

void mergesort(int ar[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(ar,start,mid);
        mergesort(ar,mid+1,end);

        combine(ar,start,mid,end);
    }
}

int main()
{
    while(true)
    {
        int ar[1000],n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>ar[i];
        mergesort(ar,0,n-1);
        for(int i=0;i<n;i++)cout<<ar[i]<<" ";
        cout<<endl;
    }

}
