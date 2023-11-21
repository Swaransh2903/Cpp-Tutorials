#include<bits/stc++.h>
using namespace std;
void bfs(int n,vector<int> adj[],vector<int> &vis,queue<int> &q)
{
    // this queue will run once for each node -> i.e O(n){because visited array will not allow insertion of the
    // same node twice}
    while(!q.empty())
    {
        int presentEle = q.front();
        cout<<presentEle<<" ";
        q.pop();
        // this will run for the degree of each node(i.e O(2m)) {number of edges moving outwards from that node}
        for(auto ele:adj[presentEle])
        {
            if(!vis[ele])
            {
                q.push(ele);
                vis[ele] = 1;
            }
        }

    }
    // Space Complexity - O(2N) - a queue and visited array
    // Time Complexity - O(n) + O(2m) i.e O(Number of vertices) + O(2 * Number of edges)
}
int main()
{
    // n - vertices, m - edges
    int n,m;

    // considering 1 based indexing so (n+1) size adj list
    vector<int> adj[n+1];

    // visited array- so that at every node , we consider only those adjacent indices which haven't been visited yet
    // when you are doing a graph traversal, if you don't keep a visited array, you could end up visiting the same
    // adjacent simultaneously which will lead to an endless traversal 
    vector<int> vis(n+1,0);

    // queue in order to push all the adjacents of a particular element
    // In Bfs we maintain a queue , wherein we start traversal from a particular node, get all it's adjacents in the
    // queue and then continue the traversal from the adjacents to their adjacents and we keep traversing in this
    // breadth wise fashion until we have travelled for all nodes.
    queue<int> q;
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
    q.push(startingIndex);
    // since starting index is already part of our queue , so we mark it as visited
    vis[startingIndex] = 1;
    bfs(n,adj,vis,q);
}