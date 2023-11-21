// The idea is that in BFS we start from a node and then we traverse to all it's neighbours and then to successive
// neighbours and so on. So basically as and when we push nodes into the queue and look for a node's neighbour 
// there could be a possibility that we are looking for a neighbour node that has already been visited but at the
// same time it can be the neighbour node from where the current node came from i.e parent node. But let's say that
// we encounter a node that has already been visited and at the same time it is not the parent of the current node
// we are referring to , then that means this node was visited by some other node and if a common node gets visited
// by 2 or more nodes simultaneously(and at the same time not being parent), then that means it's a cycle.


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0;i < m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    vector<int> vis[n+1];
    vis[src] = 1;
    queue<pair<int,int>> q;
    int parent = -1;
    int flag = 0;
    // the parent for the source element will be -1
    q.push({src,parent});
    while(!q.empty())
    {
        int top = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it:adj[top])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push({it,top});
            }
            // if in case our element was visited , then to be sure that there was no cycle in the graph, the adjacent
            //  element should be the parent of the graph (because we are following the path via the parent to reach 
            // the node) else there is a cycle.
            else if(it != parent)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
}