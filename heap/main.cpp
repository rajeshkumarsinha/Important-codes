#include <iostream>

using namespace std;

int ar[1090],size=0;
int parent(int i)
{
    return i/2;
}
void insert(int x)
{
    ar[++size]=x;
    int i=size;
    while(parent(i))
    {
        if(ar[parent(i)]>ar[i])
        {
            swap(ar[parent(i)],ar[i]);
        }
        i=parent(i);
    }
    cout<<ar[1]<<endl;
}
void minheapify(int i)
{
    int smallest=i;
    if(ar[2*i]<ar[smallest]&&2*i<=size)smallest=2*i;
    if(ar[2*i+1]<ar[smallest]&&2*i+1<=size)smallest=1+2*i;
    if(i!=smallest)
    {
        swap(ar[i],ar[smallest]);
        minheapify(smallest);
    }
}

void del()
{
    cout<<ar[1]<<endl;
    swap(ar[1],ar[size]);
    size--;
    minheapify(1);
}

int main()
{
    insert(8);
    insert(0);
    insert(80);
    insert(-7);
    del();del();del();del();
}
