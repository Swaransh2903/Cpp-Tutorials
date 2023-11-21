// Spanning tree: a tree which has 'n' nodes and 'n-1' edges and all nodes are reachable from each other


// Now a graph which will have 'n' nodes and let's say more than 'n-1' edges can be converted into a spanning tree
// by dropping some edges while keeping the number of nodes intact . Now there can be multiple ways to do so by 
// deciding which edge we intend to drop. Since the edges do have edgeWt, we will be say the total sum is the sum
// of all the edge weights of the edges that are part of the spanning tree. When we say 'Minimum Spanning Tree',
// we need to drop edges in such a way that the total cost(sum of all edge weights) is minimum.

// There can be more than one minimum spanning tree per graph also.

// Prim's Algorithm helps us to find a mst(either the total cost incurred or the edges involved in the formation
// of mst).

#include<stdio.h>
using namespace std;
int main()
{
    int n,
    // number of nodes
    cin>>n>>e;

    // let's say we need to determine only the minimum spanning tree cost:

    // this will contain all the edges wherein the internal vector is composed of 3 elements: index[0] & index[1]
    // are the nodes which are connected by an edge and index[2] : is the corresponding edgewt
    vector<vector<int>> adj(n);

    // Now since the minimum spanning tree requires the min edgeWt, we can visualize that we'll be requiring a 
    // priority queue that processes the elements in sorted order(ascending) of weights. Since all nodes are to be
    // included , we can start from any node of our choice. 
    
    // Approach and reason why it is valid: To a particular node multiple other nodes can be connected and since
    // we know that we need to have all nodes in the mst which are connected to each other in someway, we are rest
    // assured that whatever node we are starting from , we need to consider one outward edge from it atleast and 
    // since we are pushing based on sorted order of edgeWt, we know that the edge with the minimum edgeWt out of 
    // all the adjacents will get processed first.So this is somewhat greedy approach wherein we know that one edge
    // will be connected to every node(in the final mst) that we are moving to, so from there just get the minimum
    // edge wt edge at every stage which will be assured by the priority queue

    priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int>>> pq;  

    // why do we need a visited array? -> because we need to traverse every node only once (i.e once we have decided
    // that which path from the node we have to take into consideration that node will be considered as visited)
    vector<int> vis(n,0);

    // assuming we start from 0
    pq.push({0,0});

    int sum = 0;

    while(!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // if a node is visited, it would mean that we've visited it via connecting the shortest edgeWt and there is
        // no need to visit it again 
        if(vis[node] == 1)
            continue;

        vis[node] = 1;
        sum += wt;

        for(auto it:adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];

            // Suppose we are standing on a particular node. We know that we atleast need to consider one edge from
            // this node to the other node in order to form a mst because mst comprises of all nodes that were there 
            // in the original graph and all these nodes need to be a part of a single component.So if a particular 
            // adjacent isn't visited , we push it in the queue but not mark it as visited here because: let's take an
            // example wherein 0 has adjacents '1' at a distance '2' and '2' at a distance '1' and then we have '1' again
            // at a distance '1' from '2'. Now if we were starting from 0: in order to form the mst we atleast
            // require the one edge out of the 2 edges(1 or 2) protuding from 0. Since we push the edges in a priority
            // queue, always the least edgeWt edge will be considered from a particular node(so '2' will be considered)
            // as it at a distance 1 from '0' compared to '1' which is at a distance '2'). So marking this as visited
            // after the termination of the loop for the current node will indicate that we were able to reach 2 via 0
            // and since this is the minimum , we don't need to look for 2 from any other node now.But it is not
            // necessary that we visit 1 also from 0 itself because in this example itself we see that when we visit
            // 1 via 2 we reach it at a distance '1' which is less compared to '2'(from 0).So if we would've marked
            // all the adjacents as visited , then it would imply that we are visiting all nodes from 0 itself which
            // is not correct because any of the adjacent nodes can be reached via any other adjacent using a shorter
            // edge weight.
            if(!vis[adjNode])
                pq.push({edgeWt,adjNode});
        }

        // TC : At max the priority queue will have all the edges (O(E)) and getting the min distance guy at the top
        // which at worst case for a dense graph will be O(log(E)). Pushing in priority queue will take another O(log E)
        // and traversing for adjacents will take O(E)
        // thus, O(E*log E) + O(E*log E) = O(ElogE)

    }

}