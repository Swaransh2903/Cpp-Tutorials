// This is similar to Djikstra wherein the objective is to find the shortest path from the source to every other
// node. This can work for both weighted as well as unweighted graph.Though this is slower compared to Djikstra,
// it can handle edges with negative weights. It cannot work in case of -ve weight cycles however it can be useful
// in determining whether a negative weight cycle exists or not.

// Approach: It states that for the graph having N vertices, all the edges should be relaxed N-1 times to compute 
// the single source shortest path.

// Why Relaxing Edges N-1 times, gives us Single Source Shortest Path?

// In the worst-case scenario, a shortest path between two vertices can have at most N-1 edges, where N is the 
// number of vertices. This is because a simple path in a graph with N vertices can have at most N-1 edges, as 
// it’s impossible to form a closed loop without revisiting a vertex.

//  If a graph contains a negative-weight cycle reachable from the source vertex, the algorithm can detect it after N-1 iterations,
//  since the negative cycle disrupts the shortest path lengths(in the Nth iteration).

// Why Does the Reduction of Distance in the N’th Relaxation Indicates the Existence of a Negative Cycle?

// As previously discussed, achieving the single source shortest paths to all other nodes takes N-1 relaxations.
//  If the N’th relaxation further reduces the shortest distance for any node, it implies that a certain edge with
//  negative weight has been traversed once more. It is important to note that during the N-1 relaxations, we 
// presumed that each vertex is traversed only once. However, the reduction of distance during the N’th relaxation
//  indicates revisiting a vertex.


// Time Complexity: O(V*E)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // all the other nodes are assumed to be at maxx distance from source whereas source will be at 0 distance
        // from itself
		vector<int> dist(V, 1e8);
		dist[S] = 0;

        // since we need to relax all the edges v-1(number of vertex - 1) times , we run a loop for v-1 times and
        // perform relaxation in every iteration
		for (int i = 0; i < V - 1; i++) {

            // we go across every edge in the adjaceny list and try to perform the relaxation if possible
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
                // before relaxing adjoining nodes from the current node , we need to first be sure that that node
                // has been visited or relaxed itself so we keep a check wherein we relax the edge only if dist[u] != 1e8
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}

        // By this time we would've relaxed all edges i.e we would've got the shortest path from source to every node,
        // however if negative wt cycle existed in the graph , then on relaxing the edge for the nth time it's distance
        // would further get reduced (negative weight getting traversed more than one time) so we do a final check:

		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}


		return dist;
	}
};


int main() {

	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellman_ford(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}