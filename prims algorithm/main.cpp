#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<int,int>
#define inf 1000000
vector<ii>v[1009];
int n,m;

void prim()
{
    int value[1009];
    for(int i=0;i<n;i++)value[i]=inf;
    value[0]=0;
    bool mark[1009];
    set<ii>temp;
    long long ans=0;
    temp.insert(ii(0,0));
    while(!temp.empty())
    {
        ii tempnode=*(temp.begin());
        temp.erase(temp.begin());
        int workingnode=tempnode.second;
        if(!mark[workingnode])
        {
            ans+=tempnode.first;
            cout<<tempnode.second<<" "<<tempnode.first<<endl;
            mark[workingnode]=true;
            for(int j=0;j<v[workingnode].size();j++)
            {
                if(!mark[v[workingnode][j].first])
                {
                    if(value[v[workingnode][j].first]>v[workingnode][j].second)
                    {
                        value[v[workingnode][j].first]=v[workingnode][j].second;
                        temp.insert(ii(value[v[workingnode][j].first],v[workingnode][j].first));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int start,end,wt;
        cin>>start>>end>>wt;
        v[start].push_back(ii(end,wt));
        v[end].push_back(ii(start,wt));
    }
    prim();
}
