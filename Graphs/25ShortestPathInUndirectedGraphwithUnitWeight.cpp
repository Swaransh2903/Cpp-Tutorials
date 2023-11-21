// Approach: Let's use a BFS approach to solve this problem. We'll  get the source node in the queue first pushed
// along with the distance: 0 (distance to reach the node from itself will be 0) and we'll be successively going
// to it's adjacent and reducing the corresponding distance needed to reach that node(if we are able to eventually)
// able to reach that node from the source via a path which covers shorter distance.

#include<stdio.h>
using namespace std;
int main()
{
    int e,n;
    cin>>e>>n;

    int adj[n];
    for(int i = 0;i < e;i++)
    {
        int u,v;
        cin>>u>>v;
        // No need to maintain an adjacency list that contains pair(node,distance/edgeWt) because in this the edgeWt
        // is already known.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // this is the source node from where we need to find the shortest distance to every other node.
    int src;
    cin>>src;
    queue<int> q;
    q.push(src);
    

    // we declare a distance array and currently we assume that all nodes are at maximum distance from source node
    vector<int> dist(,INT_MAX);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            // in case of adjacents nodes we only get them in the queue when the current distance to reach them 
            // is more than the distance we calculated via traversing from the source (because then they can 
            // potentially make a change in the distance required to reach the nodes that move outwardly from them)
            if(dist[node] + 1 < dist[it])
            {
                q.push(it);
                dist[it] = dist[node] + 1;
            }
        }
    }
}