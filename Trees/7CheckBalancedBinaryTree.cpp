// A balanced tree is one wherein the absolute difference b/w the left subtree and right subtree height for every
// node is less than or equal to 1.

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
int findHeight(Node* root)
{
    // if we are following a recursive approach, then we generally go for a bottom up approach wherein we accumulate
    // the sub answers in order to get the main answer. So herein the sub answer would be the height of the subtrees
    // on either side of any node. The final answer for that subcall would mean the max height we could have 
    // considering those subtrees and finally the final answer for our question would be the final answer 
    // considering all such subcalls made. So basically the base case would be the root pointing to NULL which means
    // that we are currently standing at height : 0. As and when we move upwards there is an increment of height by 1
    // So basically if I want to get the max height , I need to get the max height at every stage and then sum it up.
    // So the left call will give us the height of left subtree for a particular node and the right call will give
    // us the height of right subtree for a particular node and finally the height at that node will be 1+max(left,right).
    if(root == NULL)
        return 0;
    int leftSubtreeHeight = findHeight(root->left);
    int rightSubtreeHeight = findHeight(root->right);
    return 1 + max(leftSubtreeHeight,rightSubtreeHeight);
}
int main()
{
    Node* root;
    root = insertData(root);
    int height = findHeight(root);
    cout<<" The height of the tree: "<<height;

}
bool checkBalancedTree(Node* root)
{
    // this is the O(n^2) method to approach this question. The most obvious way is to get the left subtree and right
    // subtree height for every node and then if at any stage we see that the difference exceeds 1 then we directly
    // return false and since one instance of false for the entire tree would mean that the tree isn't balanced
    // we'll combine the left and right recursion call for checking whether the subtrees are balanced or not via 
    // &&. Time complexity in the worst case will be O(N^2) because for a skewed tree like 5-4-3-2-1-NULL(all positioned
    // to either left or right) we'll be traversing to 4 nodes for 5 , 3 nodes for 4 ..... thus O(N^2)
    if(root == NULL)
        return true;
    int leftSubtreeHeight = findHeight(root->left);
    int rightSubtreeHeight = findHeight(root->right);
    if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1)
        return false;
    bool leftSubtreeBalancedCheck = checkBalancedTree(root->left);
    bool rightSubtreeBalancedCheck = checkBalancedTree(root->right);
    return leftSubtreeBalancedCheck && rightSubtreeBalancedCheck;
}
int checkBalancedTreeInLessTime(Node* root)
{
    // this is the O(N) method to approach this question. Generally we get the height of the tree in O(N) and herein
    // we have modified the func to get the height of the tree somewhat to check simultaneously whether the tree is
    // balanced or not. So we need to think in this way , that whenever we had to get the height of the tree we used
    // to make calls for subtrees wherein we calculated the heights of subtree by the formula:1 + max(leftSubtreeHeight,rightSubtreeHeight)
    // for every subtree. Now, basically whenever we are calculating the left and right subtree height for any node
    // we can check whether it is balanced node or not , so we can add our condition for checking the height difference
    // and if it exceeds 1 , we can modify the condition of return statement wherein we return -1 instead of 1 + max 
    // So, eventually even if from any 1 node we get -1 from let's say the left recursive call 
    // then for the right recursive call if we get -1 again then we directly return a -1 else let's say we get 
    // something positive from the right side then also the diff b/w the left subtree and right subtree would exceed
    // -1 , so we'll be directly returning -1 at every stage.
    if(root == NULL)
        return 0;
    int leftSubtreeHeight = checkBalancedTreeInShorterSpan(root->left);
    int rightSubtreeHeight = checkBalancedTreeInShorterSpan(root->right);
    if(leftSubtreeHeight == -1 && rightSubtreeHeight == -1)
        return -1;
    if(abs(leftSubtreeHeight-rightSubtreeHeight) > 1)
        return -1;
    return 1 + max(leftSubtreeHeight,rightSubtreeHeight);
}
Node* insertData(Node* root)
{
    int val;
    cout<<"Enter data else enter -1: "<<endl;
    cin>>val;
    if(val == -1)
        return NULL;
    root = new Node(val);
    cout<<"Enter left node of "<<val<<" : "<<endl;
    root->left = insertData(root->left);
    cout<<"Enter right node of "<<val<<" : "<<endl;
    root->right = insertData(root->right);
    return root;
}
int main()
{
    Node* root;
    root = insertData(root);
    checkBalancedTree(root);

}