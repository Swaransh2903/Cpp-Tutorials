// basically we'll be given a source node and a destination node and we need to return the number of paths that will
// lead me to the destination from the source in shortest time(graph is undirected)

#include<stdio.h>
using namespace std;
int main()
{
    int e,n;
    cin>>e>>n;

    vector<int> adj[n];
    for(int i = 0;i < e;i++)
    {
        int u,v,timeToReach;
        cin>>u>>v>>timeToReach;
        adj[u].push_back({v,timeToReach});
        adj[v].push_back({u,timeToReach});
    }

    vector<int> dist(n,1e9);
    // what is this ways array for? Now when we are saying that we need to find the number of shortest paths to reach
    // a particular destination, it implies there are multiple ways to reach the destination node via the same 
    // distance. Similarly there can be a possibility that we reach an intermediate node via multiple paths having
    // same distance which in turn result in forming the shortest path to reach destination. So this ways array
    // actually denote the number of ways via which we can reach any node with the same distance which can be considered
    // in calculating the number of ways to reach the destination via the shortest distance/within the shortest time.
    // Example: if we have to go fromm 1->5->6 and we reach 5 at a distance 3 from source (1) via 3 paths and finally
    // from 5 to 6 using distance, then this ways array will ensure that we reached 6 from 1 via 5 with a distance 4
    // using 3 paths and not just one
    vector<int> ways (n,0);
    // assume this to be a min heap and not max
    priority_queue<pair<int,int>> pq;

    int src,dest; cin>>src>>dest;
    pq.push({0,src});

    while(!pq.empty())
    {
        int distOfCurrNodeFromSrc = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node])
        {
            int distOfNextNodeFromCurr = it.second;
            if((distOfCurrNodeFromSrc + distOfNextNodeFromCurr) < dist[it.first])
            {
                dist[it.first] = distOfCurrNodeFromSrc + distOfNextNodeFromCurr;
                pq.push({dist[it.first],it.first});
                // if we reach an adjacent at a lesser distance than the one stored in distance array, then it would
                // means the number of ways of reaching the adjacent via doing so will be equal to the number of ways
                // we reached the previous node because from there this is the first time we are updating te distance.
                ways[it.first] = ways[node];
            }
            // however if we again reach the adjacent node via the same distance , then the ways to reach that adjacent
            // will be the summation of the number of ways via which we have reached this node previously at the same
            // distance via some other adjacent + the number of ways we require to reach the adjacent node from which 
            // we are reaching this node now using the same distance
            else if((distOfCurrNodeFromSrc + distOfNextNodeFromCurr) == dist[it.first])
                ways[it.first] = ways[it.first] + ways[node];
        }
        return ways[dest];
    }
}