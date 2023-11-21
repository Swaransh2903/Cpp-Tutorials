// When we are talking about a directed graph, we can't say that we got a cycle by just reaching an adjacent node 
// that has already been visited and that is not the parent. Let's understand this thing via an example:

//  1 -> 2 -> 3 -> 4
//            |    |
//           \/   \/
//            7 -> 5 -> 6

// if we take the loop (3,4,5,7) , it is not a cycle actually because there is no way we can reach any of the nodes back via
// starting from them. But let's say we run a DFS on this entire graph, what happens is that we move from 1 to 2 to 
// 3 to 4 to 5 to 6 and then when no adjacents of 6 are left we backtrack to 5(no adjacents again) to 4(no adjacents again)
// to finally 3 , wherein we find an adjacent(7) which has yet not been visited , so we follow the path via 7 now.
// Now for 7 -> 5 will be a neighbour node that has already been visited and since the parent node from where 7 came
// was 3, we'll assume that this 5 was visited by some other node and thus it acts as a meeting point of 2 nodes and
// & hence we assume it to be cycle. However what we fail to realize is that, this was true when our graphs were
// bidirectional. Here due to the unidirectional nature of the graph, it is possible to reach the same node from
// 2 different nodes(2 different paths) & still there can be a scenario where there isn't a cycle.

// How to solve then? What if we can track the path we are following to reach the visited node? In the previous
// example we took a different path to reach 5 , which made us realize the non existence of a cycle , but what if 
// we had something like this :   8
//                              /   /\
//                             \/    \
//                              9 -> 10

// then we would've moved from 8 to 9 to 10 and then again to 8 but this time without backtracking i.e without changing
// path i.e the existence of a cycle

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> vis[],vector<int> pathVis[],vector<int> adj[],int node)
{
    // inside the dfs we'll mark both visited and path visited implying that we have visited that node as well as 
    // visited it via the current path being followed in successive recursive calls
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
        // examining the path visited flag for the adjacent node because what happens it as soon as we run out of
        // adjacents and move out of the loop , we again replace the pathVis flag with 0 meaning that now whenever
        // we again get to this node, it will be via a different path.
        else if(pathVis[it])
            return true;
    }
    // when we would've reached here it would mean that we ran out of adjacents for the current node and so we
    // again replace the path visited flag for this node with 0, meaning that this node is again available for 
    // traversal via a different path.
    pathVis[node] = 0;
    // this return statement will indicate that  we were able to fully traversed the current path and we didn't find
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
        // if at any point in any of the components, we find a cycle then that will imply for the whole graph and
        // we directly return a true.
        if(!vis[i])
        {
            if(dfs(vis,pathVis,adj,i))
                return true;
        }
    }

    // if during the entire graph traversal we didn't return a true, then it would mean that there was no existence
    // of a cycle and thus we can directly return a false.
    return false;
}