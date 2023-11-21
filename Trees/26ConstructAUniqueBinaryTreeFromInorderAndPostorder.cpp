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
Node* createUniqueTree(Node* root,int inorderStart,int inorderEnd,vector<int>& inorder,int postorderStart,int postorderEnd,
vector<int>& postorder,unordered_map<int,int>& inorderNodePos)
{
    if(inorderStart > inorderEnd || postorderStart > postorderEnd)
        return NULL;
    
    root = new Node(postorder[postorderEnd]);

    int inorderPartitionPos = inorderNodePos[postorder[postorderEnd]];
    int numsLeft = inorderPartitionPos - inorderStart;

    root->left = createUniqueTree(root->left,inorderStart,inorderPartitionPos-1,inorder,postorderStart,postorderStart+numsLeft-1,postorder,inorderNodePos);
    root->right = createUniqueTree(root->right,inorderPartitionPos+1,inorderEnd,inorder,postorderStart+numsLeft,postorderEnd-1,postorder,inorderNodePos);

    return root;
}
void preorderTraversal(Node* root)
{
    if(root == NULL)
    {
        cout<<"NULL"<<" ";
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main()
{
    Node* root;
    vector<int> inorder {40,20,50,10,60,30};
    vector<int> postorder {40,50,20,60,30,10};
    unordered_map<int,int> inorderNodePos;

    for(int i = 0;i < inorder.size();i++)
        inorderNodePos[i] = i;
    
    root = createUniqueTree(root,0,inorder.size()-1,inorder,0,postorder.size()-1,postorder,inorderNodePos);

    preorderTraversal(root);

}