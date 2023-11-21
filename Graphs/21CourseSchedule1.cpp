// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks


// Application of finding a valid toposort for the given graph. If we are able to do so , that means we are able
// to schedule all tasks keeping the prerequisites in mind and hence we return that the tasks can be scheduled else
// not.

#include<stdio.h>
using namespace std;
int main()
{
    int m,n;
    // edges & vertices
    cin>>m>>n;
    vector<int> indegree(n,0);
    vector<int> adj[n];
    for(int i = 0;i < n;i++)
    {
        int u,v;
        cin>>u>>v;
        // Basically to do the first task we need to complete the second task first, so second task occurs before first
        // in topogical ordering , i.e there is an edge from v to u , i.e indegree of u increases.
        indegree[u]++;
        adj[v].push_back(u);
    }

    queue<int> q;
    for(int i = 0;i < n;i++)
    {
        // first we get the guys with indegree 0 in the queue , because these are the ones which have no prerequisites.
        if(indegree[i] == 0)
            q.push(i);
    }
    
    int nodeCnt = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        nodeCnt++;
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    if(nodeCnt == n)
        cout<<"We were able to complete all tasks";
    else
        cout<<"No";
}