// Eventual Safe States: a safe node is a node for which all the paths starting from that ultimately lead to a terminal
// node. A terminal node is a node which has no outgoing edges(i.e outdegree is 0).

// How to solve? -> Let's say we have a cycle , then all the nodes that are part of a cycle will eventually end on 
// corresponding nodes only and since their outdegree will not be 0, these nodes will definitely not be a safe
// node as well as those nodes which lead to a cycle(i.e indirectly connected to a cycle) will also not be a safe
// node, because there will be atleast one path starting from these nodes which will not result in a terminal node(which will end up at the starting point of a cycle
// or somewhere in b/w). So, we'll be tweaking the previous code a bit , in order to get the list of eventual safe nodes in ascending order.

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> vis[],vector<int> pathVis[],vector<int> adj[],int node)
{
    // inside the dfs we'll mark both visited and path visited implying that we have visited that node as well as 
    // visited it via the current path which will be followed in successive recursive calls.
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it:adj[node])
    {
        // if any node hasn't been visited yet , then we call the dfs on it again
        if(!vis[it])
        {
            // if in any successive call we detect a cycle we can return true instead of looking for other cycles.
            if(dfs(vis,pathVis,adj,it))
                return true;
        }
        // if the node was visited, in order to prove the existence of a cycle , we have to know whether the node
        // that we reached again has been reached via the same path or not and that will be determined by 
        // examining the path visited flag for the adjacent node because what happens is as soon as we run out of
        // adjacents and move out of the loop , we again replace the pathVis flag with 0 meaning that now whenever
        // we again get to this node, it will be via a different path.
        else if(pathVis[it])
            return true;
    }
    // when we would've reached here it would mean that we ran out of adjacents for the current node and so we
    // again replace the path visited flag for this node with 0, meaning that this node is again available for 
    // traversal via a different path.
    pathVis[node] = 0;
    // this return statement will indicate that following the current path was fully traversed and we didn't find
    // any cycle in the current path , so we need to backtrack and check for cycles elsewhere.
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i = 0;i < n;i++)
    {
        int u,v;
        cin>>u>>v;
        // assuming that the graph will be always directed from u to v.
        adj[u].push_back(v);
    }

    // this time we'll be having 2 arrays, one that will see whether the nodes have been visited and one which will
    // see whether the nodes have been visited using the same path(thus proving the existence of a cycle).
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);
    
    // we run this loop for disconnected components
    for(int i = 0;i < n;i++)
    {
        // since herein we need to find list of all safe nodes, therefore we'll have to get all the cycles in the 
        // graph so that we can filter out all the unsafe nodes.
        if(!vis[i])
        {
            dfs(vis,pathVis,adj,i);
        }
    }

    vector<int> ans;

    // what are we doing finally?  -> so let's say you start from a node and you marked pathVis for all the elements
    // with 1 . Now if we finally detect a cycle , then in the function we are directly returning true without
    // unmarking the pathVis for all these nodes which eventually led to the cycle. For all the nodes that were 
    // leading to an terminal node (for all paths) , they would've never been caught in a cycle and so we would've
    // eventually moved out of the loop and unmarked the pathVis for these nodes. So at the end if the pathVis for
    // any node is '0', we can definitely say that it is a safe node. 
    for(int i = 0;i < n;i++)
    {
        if(pathVis[i] == 0)
            ans.push_back(i);
    }

    return ans;
}