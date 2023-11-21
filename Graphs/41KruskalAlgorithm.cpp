// Kruskal Algorithm is another method to find the minimum spanning tree (n nodes,n-1 edges wherein every node
// can be reached from every other node), but this is an application of disjoint set.


// Now what disjoint set will do is that at every instance it will tell us that whether two nodes that we are 
// considering presently are part of the same component or not, so let's say if in a graph there was an edge b/w
// 1 and 4 , 4 and 2 ,1 and 2 . So as we do in disjoint set,we'll be considering all these nodes as separate components
// initially and as and when we get an edge b/w nodes (while we traverse through the edges array) we'll be
// connect them (part of single component i.e same ultimate parent), so let's say first we connect 1 and 4 then 
// 4 and 2 , then when we encounter the edge b/w 1 and 2 it will get discarded because 1 and 2 have already been
// connected via 4 

// Now disjoint set dosen't keep into account the minimum edgeWt while connecting the edges , so it will end up
// forming a spanning tree which might not be the minimum. To get the minimum spanning tree, we would've to first
// store the edges in the graph in sorted order of edgeWt, so that everytime we process an edge for forming a 
// connection, we do so on an edge with min edgeWt

