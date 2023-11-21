//  Find the shortest path from source(node: 0) to all other nodes.


// Approach: Get the topo sort of the graph either via DFS or BFS. Initially take a distance array of
// size equal to the number of nodes in the graph and wherein all values are currently marked with infinity. As 
// and when we start traversing from the very first node in the stack (obtained as a result of topo sort using
// dfs), we keep on updating the distances with the minimum distance required to reach that node from the source
// node.Finally we'll get our required ans in the form of the updated distance array.

// Why does this approach work? -> First let us see that when we are applying toposort using dfs , what is actually
// happening behind the scene. See toposort is based on the very fact that the guys with indegree(0) {those which we can
// say act as the origin of the graph and have no nodes pointing to them} are placed on the top of the stack and 
// then based on the increasing order of the indegree, the nodes are placed eventually. So by following this methodology
// we already know that whenever we'll be popping out an element from stack it would be a node that would've been
// reached by the previous nodes that we would've popped out and since at each stage we are updating the distances,
// so it would mean that since : toposort ensures that when moving from point A - B, A has the smallest path value from source, 
// so when moving from B-C path will be smallest till C from source. So we are accessing elements on the basis of
// their reachability and hence cutting off a lot of redundancies.

#include<bits/stdc++.h>
using namespace std;
void topoSort(int node,vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &st)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        // now the adjacent of the current node will be stored in the form of a pair wherein the first element will
        // correspond to the adjacent Node that we require and the second element will be the edge weight which will
        // be used later on
        int adjNode = it.first;
        if(!vis[adjNode])
            topoSort(adjNode,adj,vis,st);
    }
    // as soon as we run out of adjacents for a particular node, we know it's time to backtrack so we push that
    // node in the stack
    st.push(node);
}
int main()
{
    // edges and vertices
    int e,n;

    vector<pair<int,int>> adj[n]
    for(int i = 0;i < e;i++)
    {
        // this time corresponding to each node we'll be storing the adjacent node as well as the corresponding edge
        // weight, so if there are multiple neighbours for a given node , we store a vector of pairs corresponding to
        // that node index. 
        int u,v,edgeWt;
        ajd[u].push_back({v,edgeWt});
    }

    // Finding the topoSort:
    // TC : Plain DFS(O(N+E))
    stack<int> st;
    vector<int> vis(n,0);

    // running the loop for multiple components
    for(int i = 0; i < n;i++)
    {
        if(!vis[i])
            topoSort(i,adj,vis,st);
    }

    // creating the distance array:
    vector<int> dist(n);
    for(int i = 0;i < n;i++)
        dist[i] = INT_MAX;
    
    // if we assume 0 to be the source , the distance to reach it should be 0 itself.
    dist[0] = 0;

    // now while stack dosen't get empty we can continue our traversal and keep on updating the distances:

    // TC - O(N) {for stack} + O(E) {for the internal adjacent traversal}
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        for(auto it:adj[node])
        {
            int adjNode = it.first;
            // edgeWeight
            int distance = it.second;
            // we see if the distance that we are taking to reach the adjacent
            //  from the source node is less than the current distance in the
            // distance array and accordingly updating
            dist[adjNode] = min(dist[node]+distance,dist[adjNode]);
        }
    }
    return dist;
}