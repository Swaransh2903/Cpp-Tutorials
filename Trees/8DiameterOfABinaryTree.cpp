// Diameter : length of longest path that exists b/w any 2 nodes in the tree and it isn't necessary that the path
// should pass via the root of the tree.

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node* insertData(Node* root)
{
    int val;
    cout<<"Enter node value : "<<endl;
    cin>>val;

    if(val == -1)
        return NULL;
    
    root = new Node(val);
    cout<<"Moving leftwards from node: "<<val<<endl;
    root->left = insertData(root->left);
    cout<<"Moving rightwards from node: "<<val<<endl;
    root->right = insertData(root->right);

    return root;
}
int findHeight(Node* root)
{
    if(root == NULL)
        return 0;
    int leftSubtreeHeight = findHeight(root->left);
    int rightSubtreeHeight = findHeight(root->right);
    return 1+max(leftSubtreeHeight,rightSubtreeHeight); 
}
int findDiameterInLessTime(Node* root,int &maxim)
{
    // The O(n) approach to solve this problem.Now we already know that when we calculate the height of the tree
    // we follow a bottom up approach wherein we start calculating the height right from the bottom and then accumulate
    // the ans of the subcalls to get the final answer.Now for doing this why do we need to calculate separate height
    // for every node and then calculate longest path length individually. When we are calculating the height of node
    // via bottom up approach , we can simultaneously update the longest path length there itself and then in a 
    // single traversal , we can get the diameter. So let's say we are standing a node(node 1) that has been called via 
    // another node(let's say node 2), so for node 1 the longest path will be the sum of leftsubtree height as well
    // as right subtree height so we update the maxim but then since our approach involved calculating the height
    // at every stage what we need to return to node 2 from node 1 should be the height of the subtree(which will
    // actually be the height of node 1 i.e : 1 + max(leftSubtreeHeight,rightSubtreeHeight))
    if(root == NULL)
        return 0;
    int leftSubtreeHeight = findDiameterInLessTime(root->left);
    int rightSubtreeHeight = findDiameterInLessTime(root->right);
    maxim = max(maxim,leftSubtreeHeight+rightSubtreeHeight);
    return 1 + max(leftSubtreeHeight,rightSubtreeHeight);
}
void findDiameter(Node* root,int& maxim)
{
    // The O(n^2) approach to solve this problem .Since we need to find the longest path passing through every node and then find
    // the maximum out of all the lengths , we can make a recursive call to find the left as well as right subtree
    // height at every node (since we are calculating the height at every stage we are bound to get the longest
    // path leftwards as well as rightwards for that node) and then sum both the heights to get the longest path
    // passing through that node. We can repeat this for all the 'n' nodes and probably maintain a max variable
    // which will update the longest path if it gets a bigger value.So for 'n' nodes we are finding the height 
    // individually , thus taking an order of n^2.
    if(root == NULL)
        return;
    int leftSubtreeHeight = findHeight(root->left);
    int rightSubtreeHeight = findHeight(root->right);
    maxim = max(maxim,leftSubtreeHeight+rightSubtreeHeight);
    findDiameter(root->left,maxim);
    findDiameter(root->right,maxim);

}
int main()
{
    Node* root;
    root = insertData(root);
    int max = INT_MIN;
    cout<<"The diameter of the tree is: "<<findDiameter(root,max);
}