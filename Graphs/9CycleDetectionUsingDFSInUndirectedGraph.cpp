#include<bits/stdc++.h>
using namespace std;
bool detectCycle(vector<int> adj[],vector<int> vis[],int node,int parent)
{
    // we mark the current node as visited.
    vis[node] = 1;
    for(auto it:adj[node])
    {
        // if an adjacent node is not visited , we call dfs for it , but at the same time we keep it in an if condition
        // so that if in future successive calls we get a cycle, we can directly return a true.
        if(!vis[it])
        {
            if(detectCycle(adj,vis,it,node))
                return true;
        }
        // else if the adjacent wasn't visited and it was not parent that means that node has been visited by some other node 
        // and so that means there is a cycle
        else if(it != parent)
            return true;
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i = 0;i < m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    vector<int> vis[n];

    // to handle disconnected components 
    for(int i = 0;i < n;i++)
    {
        // everytime when we start from a node that isn't visited we'll be visiting all the connected nodes i.e.
        // we'll be traversing through an entire component. So next time when we come across a node that isn't visited
        // , it means that it is a node from another component and so the parent of each of these starting nodes
        // will be -1.
        if(!vis[i])
            // in case a node was not visited we would be checking for a cycle in that component and in case we
            // detect a cycle , it isn't needed to check for other disconnected components so we directly
            //  return a true on finding a cycle
            if(detectCycle(adj,vis,i,-1))
                return true;
    }
    return false;

}