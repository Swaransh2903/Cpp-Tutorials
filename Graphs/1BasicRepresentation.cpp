#include<bits/stdc++.h>
using namespace std;
int main()
{
    // n = no. of vertices
    // m = no. of edges
    int n,m;
    cin>>n>>m;

    // storing?? -> Two ways
    // 1) Adjacency List
    // 2) Adjacency Matrix

    // Adjacency Matrix: If there is 1 based indexing , declare a 2D n+1*n+1 (no. of vertices * no. of vertices) matrix and 
    // mark that position as 1 , wherein there is an edge b/w the respective indices.
    //               Space - O(n+1*n+1)

    int adj[n+1][n+1];
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        // undirected
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Adjacency List: We create a array of vector (i.e every element or index of vector will contain an empty list)
    // at first. At every index we will be storing the adjacent nodes of that index.
    //               Space - O(2*m) -> why? because every edge is formed by connecting 2 nodes and since in adjacency
    // list we are storing only the mapped nodes , so twice the number of edges(because currently we are dealing
    // with undirected graph so edges are bidirectional)
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        // undirected
        adj[u].push_back(v);
        adj[v].push_back(u);

        // In case of a directed graph , it'll be mentioned whether there's an edge from u to v or v to u , accordingly
        // we'll push
        // -> Suppose there is an edge from v to u:
        adj[v].push_back(u);  // Space O(m)


        // Suppose there were weights assigned to each edge b/w 2 vertices -> then at every index instead of pushing just the index
        // mapped to the corresponding index , we'll also push the edge weight in a pair format
        vector<pair<int,int>> adj[n+1];
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    

}