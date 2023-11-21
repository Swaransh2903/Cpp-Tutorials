// Topological Sorting is only possible in DAG. What is Topological Sort? if u->v (there exists an edge from u to v
// ) then in the final order of nodes u should appear before v. Why only directed graph? because if in case of 
// undirected graph we say that there is an edge b/w u and v , then that would mean that there is an edge from u to v
// (so u should appear before v) but at the same time there is an edge from v to u (so v should appear before u)
// which isn't possible . Why acyclic? Imagine there is a cycle 1->2->3->1 , then it would mean that 3 should appear
// after 1 but at the same time before 1 also which isn't possible.

// How to Solve?

#include<stdio.h>
using namespace std;
void dfs(vector<int> &vis,vector<int> adj[],int node,stack<int> &st)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
            dfs(vis,adj,it,st);
    }
    // we'll push that element only when the dfs for that element gets over.
    st.push(node);
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

    vector<int> vis(n,0);
    // the nodes with max outdegree should appear first in the sorting because they are the ones who are setting up
    // the path for most number of nodes i.e predecessor. So let's say if we follow an approach wherein we push
    // the elements as we do so in DFS and only push an element in a stack only when the
    // DFS for that element got over , then it would mean that we are pushing an element in a stack when
    // we have completed traversal for all paths that were protruding out of that node and so all the
    // nodes that follow this node will appear later in the stack 
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(vis,adj,i,st);
    }
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}