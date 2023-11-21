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

    cout<<"Moving leftwards from node "<<val<<endl;
    root->left = insertData(root->left);
    cout<<"Moving righttwards from node "<<val<<endl;
    root->right = insertData(root->right);

    return root;
}
int maxPathSum(Node* root,int& maxi)
{
    if(root == NULL)
        return 0;

    // Similar to finding the diameter of binary tree, start forming the sums by starting from the bottom and 
    // accumulate the max sum at every stage to get the overall max path sum . So let's say you went from node 2 to
    // node 3 , the next 2 lines will get the max sum on the left side as well as right side of node 3 and then
    // at that particular node the max sum will be the node's val + the max sum on the left as well as max sum on
    // the right.We have included this check with 0 to return max value because we want to avoid the possibility
    // of returning negative sum in case all nodes on the left or right subtree of a particular node were negative.
    int leftSum = max(0,maxPathSum(root->left,maxi));
    int rightSum = max(0,maxPathSum(root->right,maxi));

    maxi = max(maxi,root->val+leftSum+rightSum);

    // When you have decided the max sum on 3 , this node 3 might have been either on the left or right of node 3
    // and the value that should be returned to node 2 should be a summation of node 3 val as well as the max out
    // of the leftsubtree or rightsubtree sum of node 3 because from 2 via 3 we would've only gone to one path 
    // either the left subtree one or the right subtree one.
    return root->val + max(leftSum,rightSum);
}
int main()
{
    Node* root;

    root = insertData(root);
    
    int maxi = INT_MIN;
    int maxSum = maxPathSum(root,maxi);

}