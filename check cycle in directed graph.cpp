


bool cycle(int i,bool mark[],bool path[],vector<int>graph[100009])
{
    for(int j=0;j<graph[i].size();j++)
    {
        if(path[graph[i][j]])return true;

        path[graph[i][j]]=true;

        if(cycle(graph[i][j],mark,path,graph))return true;

        path[graph[i][j]]=false;
    }
    mark[i]=true;
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        bool mark[100009];memset(mark,false,sizeof(mark));
        bool path[100009];memset(path,false,sizeof(path));

        vector<int>graph[100009];
        for(int i=0;i<prerequisites.size();i++)graph[prerequisites[i].first].push_back(prerequisites[i].second);
        for(int i=0;i<numCourses;i++)
        {
            if(mark[i])continue;
            if(cycle(i,mark,path,graph))return false;
        }
        return true;
    }

};
