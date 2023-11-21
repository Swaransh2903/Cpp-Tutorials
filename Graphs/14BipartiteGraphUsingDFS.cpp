#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int src,vector<int> colours[],int colour)
{
    colours[src] = colour;
    for(auto it:adj[src])
    {
        // if the adjacent node has yet not been coloured, we assign it a colour which is complement of it's parent
        // ie. src and we call the dfs to fill future nodes with alternate colours
        if(colour[it] == -1)
        {
            colour[it] = !colour;
            // in later stages if we find the graph to not be bipartite(in some subcall we find an adjacent that
            // has been coloured with the same colour that has been assigned to the present node), we don't need to
            // check further so we have added an if statement to directly return false in such a scenario
            if(!dfs(adj,it,colours,colour[it]))
                return false;
        }
        // else if an adjacent is coloured with the same colour that means we visited this by some other
        // node and it was needed to assign this colour but from the other side it caused inconsistency
        // so we return a false.
        else if(colour[it] == colour)
            return false;
    }
    return true;
}
int main()
{
    // vertices & edges
    int n,m;
    vector<int> adj[n];

    for(int i = 0;i < n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // now instead of taking a visited array, we can take a colour array instead , with all values '-1' initially
    // and we'll be having two options for colouring - 0 & 1.
    vector<int> colours(n,-1);

    int src;
    cin>>src;

    // let's say we start colouring from colour - 0
    dfs(adj,src,colours,0);
}