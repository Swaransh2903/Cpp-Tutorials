#include<bits/stdc++.h>
using namespace std;
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

    int src;
    cin>>src;
    vector<int> colour(n,-1);
    queue<int> q;
    q.push(src);
    colour[src] = 0;

    int flag = 0;
    while(!q.empty()&&flag == 0)
    {
        int node = q.front();
        q.pop();

        for(auto it:adj[node])
        {
            if(colour[it] == -1)
            {
                colour[it] = !colour[node];
                q.push({it});
            }
            else if(colour[it] == colour[node])
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1)
        cout<<"Not Bipartite";
    else
        cout<<"Bipartite";
}