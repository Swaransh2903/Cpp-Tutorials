// As already discussed while approaching Topo Sort using DFS , we know that the nodes that should appear in  the 
// ordering first will have the highest outdegree or should have an indegree 0 (there will be atleast one node with
// indegree 0 if we are taking a directed acyclic graph)

#include<stdio.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    // this will be the vector storing the indegrees of each node
    vector<int> indegree(0,n);
    for(int i = 0;i < n;i++)
    {
        int u,v;
        cin>>u>>v;
        // assuming that the graph will be always directed from u to v.
        adj[u].push_back(v);

        // because there is an incoming edge to v , we increase it's indegree.
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 0;i < indegree.size();i++)
    {
        // all the nodes with indegree: 0 , should occupy the first few positions in the ordering because since 
        // these have an indegree 0, they will have no predecessor(because there is no incoming edge to them).
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> topoSort;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        // now that we have the nodes with indegree 0 being pushed into the queue , we traverse for the adjacent 
        // nodes of this node and reduce their indegrees because there is an edge pointing to them from the current
        // node i.e we have dealt with one indegree and so reduce the current indegree count by one and so on
        for(auto it : adj[node])
        {
            indegree[it] --;
            // if at any stage the indegree of a node becomes 0 , that means we have taken into consideration all the 
            // nodes that were pointing to it (they have already been accumulated into the queue and the topoSort vector)
            // and so we can safely push it in the queue so that it can further be pushed into the topoSort vector 
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return topoSort;
}