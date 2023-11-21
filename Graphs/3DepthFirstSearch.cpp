#include<bits/stc++.h>
using namespace std;
void dfs(int n, vector<int> adj[], vector<int> &vis,int start)
{
    // Basically here in we are traversing depth wise wherein if we start from a node we traverse a path until we
    // reach the end node from where there are no more outward edges, then we return and move along alternate paths.
    
    //  O(N) time for making a recursive call once for each node
    vis[start] = 1;
    cout<<start;
    // Space Complexity: O(2n) - Recursion Stack Space + visited array
    // O(Degree) time for traversing through all neighbours of a particular node and since total degree = 2 no.
    // of edges (i.e 2*m) -> total time taken here : O(2*m)
    for(auto neighbour:adj[start])
    {
        if(!vis[neighbour])
        {
            dfs(n,adj,vis,neighbour);
        }
    }
    // Time Complexity: O(n) + O(2*m)
    return;

}
int main()
{
    // n - vertices, m - edges
    int n,m;
    cin>>n>>m;

    // considering 1 based indexing so (n+1) size adj list
    vector<int> adj[n+1];

    // visited array- so that at every index , we consider only those adjacent indices which haven't been visited yet
    vector<int> vis(n+1,0);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        // assuming undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // inputting starting index for traversal
    int startingIndex;
    cin>>startingIndex;
    dfs(n,adj,vis,startingIndex);
}