// For every node the entire left subtree should have nodes with values lesser than the current node value and the
// entire right subtree should have nodes with values greater than the current node value.In addition to this all
// nodes will be unique


//  Ex:                     8
//                         / \
//                        3   10
//                       / \  / \
//                      1  6  N  14
//                        / \
//                        4  7

// Why a BST? -> Generally in a Binary Search Tree the height is kept as O(log n) where n = number of nodes in tree
// because it helps to efficiently search in the tree so in a very rare case the bst would end up being a degenrate
// tree whose traversal is computationally expensive

#include<bits/stdc++.h>
using namespace std;
class Node
{
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
    cout<<"Enter node's value: ";
    cin>>val;

    if(val == -1)
        return NULL;
    root = new Node(val);

    cout<<"Moving leftwards from node "<<val<<endl;
    root->left = insertData(root->left);
    cout<<"Moving rightwards from node "<<val<<endl;
    root->right = insertData(root->right);

    return root;
}
Node* searchInBst(Node* root,int target)
{
    // utilizing the property of BST, what we are doing here is that if the current node's value is greater than
    // than the target that we desire, we know that the target can only be a part of the left subtree of the current
    // node and hence we move left and continue our search and similarly if the current node's value is smaller
    // than the target that we desire then we know that the target can only be a part of the right subtree of the 
    // current node and hence we move right and continue our search . At the end if along any path we don't find the
    // node we return NULL else we return the node expected which will in turn be returned by all the previous calls.

    // Time Complexity : O(log N) ->  because at a time we are deciding based on the current node's value that we 
    // need to move to left or right , so at every stage we are eliminating the search for half of the tree.
    if(root == NULL)
        return NULL;
    
    if(root->data == target)
        return root;

    Node* leftCheck = NULL;
    Node* rightCheck = NULL;

    if(target < root->data)
        leftCheck = searchInBst(root->left,target);
    else if(target > root->data)
        rightCheck = searchInBst(root->right,target);

    if(leftCheck)
        return leftCheck;
    else
        return rightCheck;
    
}
int main()
{
    Node* root;

    root = insertData(root);

    int target;
    cout<<"Enter node to be searched: ";
    cin>>target; 

    Node* targetNode = searchInBst(root,target);

}