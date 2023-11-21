// Currently we are solving this problem keeping in mind undirected graph with variable edge Weights

// Djikstra will not work in case of negative weight cycle because since the weights are negative, when we try to
// add distances , it is overall reducing the value and everytime we'll be pushing those values in the queue which
// results in an infinite loop.

// Why Priority Queue over normal queue? because in priority queue , we'll be storing values based on sorted 
// order of distances , so that means there are more chances that when I am at a particular node , I have reached it
// via a shorter distance path whereas if I would've used queue instead then there will be no particular order of 
// accessing the values in the queue and a longer distance node might get processed first which will in turn push the
// longer distances nodes which are it's adjacent and haven't been visited. So later on if we reach via a shorter
// path we'll be againing be updating the distances and pushing into the queue. However, if we would've used priority
// queue instead , then the shorter distance node would've got processed first and we would prevent the unnecessary
// pushing of future longer distance nodes in the queue.
#include<stdio.h>
using namespace std;
int main()
{
    int e,n;
    cin>>e>>n;
    
    // this time the adjacent of the node will contain a pair : pair.first : is the adjacent node whereas pair.second:
    // is the distance required to reach that adjacent node from the current node(edgeWt)
    vector<pair<int,int>> adj[n];
    for(int i =  0;i < e;i++)
    {
        int u,v,edgeWt;
        cin>>u>>v>>edgeWt;
        adj[u].push_back({v,edgeWt});
        adj[v].push_back({u,edgeWt});
    }
    //Create a priority queue for storing the nodes as a pair {dist,node} where dist is the distance from source to the node. 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // now we need to have a distance array initialized with the maximum distance from source for every other node
    vector<int> dist(n);
    for(int i = 0;i < n;i++)
        dist[i] = INT_MAX;
    
    // we get the source node now from wherein we need to look for adjacent node distances
    int src; 
    cin>>src;
    // source to source distance will be 0
    dist[src] = 0;

    pq.push({0,src});
    while(!pq.empty())
    {
        int distOfSrcFromCurrNode = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node])
        {
            int distOfNextNodeFromCurrentNode = it.second;
            if((distOfSrcFromCurrNode+distOfNextNodeFromCurrentNode) < dist[it.first])
            {
                dist[it.first] = distOfSrcFromCurrNode+distOfNextNodeFromCurrentNode;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    return dist;
}