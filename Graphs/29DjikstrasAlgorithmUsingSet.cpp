// why are we  using set now instead of priority queue? Let's try to evaluate first what we did when we were using 
// priority queue -> we took a distance array wherein we assumed that initially all nodes are at max distance from
// source . Then as and when we traversed outwards from the src we kept on updating distance based on edge weights
// as and when we got smaller distances. Finally our distance array would contain the min distance from source to
// every other node. Now, we defined priority queue in such a way that the nodes are pushed in ascending order of
// distance(i.e the distance req to reach them from source). The set will also do the same thing but in has one added
// advantage wherein it omits duplicate keys. So let's say that if we reached a node via a distance 10 and initally
// the distance to reach it was 1e9(we update the distance). Now next time let's say we reach the same node via 
// distance 8 , what priority queue will do is it will keep this distance above the distance 10(maintaining sorted)
// order of distances but it will be still be computing for distance 10 later which will be pointless because if
// we reaching a node by some path at distance = 8 , it will always take lesser distance to reach its adjacent node
// then by traversing via a path which reaches the current node at distance = 10. However, the priority queue will
// still process this distance though the distances to the other nodes won't be changing. However with set, as soon
// as it recognizes the duplicate key(5) it will erase (10,5) from set thereby ensuring that we only traverse further
// via a path which takes less distance. However erasing in a set will take logarithmic complexity so basically it's
// a tradeoff which is dependent on how nodes will be connected in the graph and the change will be very minor.

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
    
    set<pair<int,int>> st;

    // now we need to have a distance array initialized with the maximum distance from source for every other node
    vector<int> dist(n);
    for(int i = 0;i < n;i++)
        dist[i] = INT_MAX;
    
    // we get the source node now from wherein we need to look for adjacent node distances
    int src; 
    cin>>src;
    // source to source distance will be 0
    dist[src] = 0;
    st.insert({0,src});

    while(!st.empty())
    {
        // get the iterator pointing to the start of set
        auto it1 = *(st.begin());
        int distOfSrcFromCurrNode = it1.first;
        int node = it1.second;
        st.erase(it1);  

        for(auto it:adj[node])
        {
            int distOfNextNodeFromCurrentNode = it.second;
            if((distOfSrcFromCurrNode+distOfNextNodeFromCurrentNode) < dist[it.first])
            {
                // if we reach the current node via a smaller distance , no need to keep the bigger distance
                if(dist[it.first] != INT_MAX)
                    st.erase({dist[it.first],it.first});
                dist[it.first] = distOfSrcFromCurrNode+distOfNextNodeFromCurrentNode;
                st.insert({dist[it.first],it.first});
            }
        }
    }
    return dist;
}