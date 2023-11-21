// Now generally to find the total number of nodes in any tree(complete/full or the ones we've discussed) we could
// have used any traversal technique and then as and when a node gets processed we would've a counter variable
// that gets incremented by one so when all nodes get processed the counter variable will be equal to the total
// number of nodes in the tree.

// But this approach will have a time complexity of O(N) and we are expected to devise a solution which runs in lesser
// time than this. Now since this question pertains to complete binary tree , we'll have to observe &
// utilize some property of complete tree that might be helpful in getting the number of nodes in lesser than O(N)
// complexity.

// When we talk of complete binary trees, in these trees all the levels are completely filled expect the last level
// wherein the nodes are filled as left as possible. So, we know that the max possible height of a complete tree
// containing n nodes will be somewhere close to O(log n). So what if we utilize this height property of binary
// tree to get the number of nodes? Like we start from the root , compute its height and then go to its children
// and do the same. Now at any particular sub level, the tree structure would end up becoming a full binary tree
// (try to observe via taking a complete bt ex)and since in a full binary tree all levels are completely filled,
// we can definitely say that if the height for that subtree comes out to be 'n' then the number of nodes in that
// subtree will be 2^n-1.In that way we can calculate the height for the other half too and then sum all of it 
// to get the final ans

// O(log*log)n = O(log^2)n -> calculating height of single node will be log n and at max you'll be computing
// height for log n nodes only

//                                        1
//                                      /   \
//                                     2     3
//                                    / \    / \
//                                   4  5   6   7
//                                  /
//                                  8

// This is the worst case scenario wherein you'll be traversing the entire left subtree of root because for each  
// node(on left of root) the diff b/w left & right >=1 at every stage(not talking of 5) so we cannot directly
// apply the formula since some nodes are missing on 