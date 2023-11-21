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
Node* constructTree(Node* root,vector<int> &inorder,vector<int> &preorder,int inorderStart,int inorderEnd,
int preorderStart,int preorderEnd,unordered_map<int,int>& inorderKeyPos)
{
    if(inorderStart > inorderEnd || preorderStart > preorderEnd)
        return NULL;

    root = new Node(preorder[preorderStart]);

    int inorderPartitionPos = inorderKeyPos[root->val];
    int numsLeft = inorderPartitionPos - inorderStart;

    root->left = constructTree(root->left,inorder,preorder,inorderStart,inorderPartitionPos-1,preorderStart+1,preorderStart+numsLeft);
    root->right = constructTree(root->right,inorder,preorder,inorderPartitionPos+1,inorderEnd,preorderStart+numsLeft+1,preorderEnd);

    return root;

}
int main()
{
    Node* root;
    vector<int> inorder;
    vector<int> preorder;
    unordered_map<int,int> inorderKeyPos;

    for(int i = 0;i < inorder.size();i++)
        inorderKeyPos[inorder[i]] = i;

    constructTree(root,inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);
}