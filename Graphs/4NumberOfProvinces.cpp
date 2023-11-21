// Suppose there is an undirected graph and we say 2 vertices belong to a single province if there exist a path from 
// one node to another -> then in order to find the number of provinces , we'll have to find the number of 
// disconnected components in the graph because for an undirected graph all the nodes of a single province will get
// traversed by single iteration through a starting node

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],vector<int> &vis,int node)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
            dfs(adj,vis,it);
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i = 0;i <  n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // the visited array can be used here in order to see how many provinces are there (let's say if we start from 
    // a node that is not visited then we can go to the entire structure that is connected to it and all of those
    // nodes can be marked visited. So next time when we encounter a node which isn't visited , we'll be sure that
    // it's a different province node.) 
    vector<int> vis(n,0);
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            // in this dfs call all the connected nodes to this node will be marked as visited
            dfs(adj,vis,i);
            // all the nodes that get visited in a single dfs traversal account to one province , so we increase
            // the province count by 1.
            cnt++;
        }
    }
    // Time Complexity : Overall dfs of the graph will take O(V+2E) and in worst case the number of connected 
    // components can be 0 -> so we will be traversing for n nodes separately - O(N) , thus total complexity :
    // O(N) + O(N+2E).
    cout<<cnt;

}