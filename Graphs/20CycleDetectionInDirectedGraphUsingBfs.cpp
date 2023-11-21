// Since we know that a toposort will only be generated in the case of directed acyclic graph , if we apply the 
// inverse of it and check if the we don't get the required the toposort , that means that the graph contained a cycle

#include<stdio.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    // this will be the vector storing the indegrees of each node
    vector<int> indegree(0,n);
    for(int i = 0;i < n;i++)
    {
        int u,v;
        cin>>u>>v;
        // assuming that the graph will be always directed from u to v.
        adj[u].push_back(v);

        // because there is an incoming edge to v , we increase it's indegree.
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 0;i < indegree.size();i++)
    {
        // all the nodes with indegree: 0 , should occupy the first few positions in the ordering because since 
        // these have an indegree 0, they will have no predecessor(because there is no incoming edge to them).
        if(indegree[i] == 0)
            q.push(i);
    }

    int nodeCnt = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        nodeCnt++;
        // now that we have the nodes with indegree 0 being pushed into the queue , we traverse for the adjacent 
        // nodes of this node and reduce their indegrees because there is an edge pointing to them from the current
        // node
        for(auto it : adj[node])
        {
            indegree[it] --;
            // if at any stage the indegree of a node becomes 0 , that means we have taken into consideration all the 
            // nodes that were pointing to it (they have already been accumulated into the queue and the topoSort vector)
            // and so we can safely push it in the queue so that it can further be pushed into the topoSort vector 
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    // if the final cnt is equal to the number of elements in the graph, then in a way we can say that all the nodes
    // were able to become a part of our topo sort and so the graph didn't contain a cycle. 
    if(nodeCnt == n)
        return true;
    return false;
}


// Why this inversion theorem works in case of BFS but not in case of detecting cycle via dfs? because herein we
// are providing a constraint that an element gets pushed in the queue only when it's indegree becomes 0 ,but in
// case of a cycle there will eventually come a point wherein we would be checking from wherein we can not reduce
// the indegrees of any of the adjacents to zero because there would be another node (the one responsible for
// forming the cycle) that will be pointing towards the adjacent hence increasing the indegree. Hence eventually
// the queue will get empty before pushing all elements so we can check outside whether we were able to traverse
// completely or not. However in case of DFS, our implementation is stack based without any constraints, so eventually
// irrespective of the fact that there exists a cycle , all elements will get pushed into the stack and so we won't 
// be able to do an equality test.
