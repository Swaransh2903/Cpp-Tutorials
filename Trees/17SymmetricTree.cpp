// A binary tree is said to be symmetric if it forms a mirror image around the centre. One side of the tree
// can be imposed over the other side.

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
    cout<<"Enter node's data: ";
    cin>>val;

    if(val == -1)
        return NULL;
    root = new Node(val);

    cout<<"Moving leftwards from node "<<val<<" : "<<endl;
    root->left = insertData(root->left);
    cout<<"Moving rightwards from node "<<val<<" : "<<endl;
    root->right = insertData(root->right);

    return root;
}
bool isSymmetric(struct Node* root1, struct Node* root2)
{
    // If both trees are empty, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;
 
    // For two trees to be mirror images, the following
    // three conditions must be true
    // 1.) Their root node's key must be same
    // 2.) left subtree of left tree and right subtree of
    // right tree have to be mirror images
    // 3.) right subtree of left tree and left subtree of
    // right tree have to be mirror images
    if (root1 && root2 && root1->key == root2->key)
        return isSymmetric(root1->left, root2->right)
               && isSymmetric(root1->right, root2->left);
 
    // if none of above conditions is true then root1
    // and root2 are not mirror images
    return false;
}
int main()
{
    Node* root;

    root = insertData(root);
    isSymmetric(root->left,root->right);

}