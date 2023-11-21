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
    cout<<"Enter data of node: "<<endl;
    cin>>val;
    if(val == -1)
    {
        return NULL;
    }
    root = new Node(val);
    cout<<"Enter left node of "<<val<<" : "<<endl;
    root->left = insertData(root->left);
    cout<<"Enter right node of "<<val<<" : "<<endl;
    root->right = insertData(root->right);
    return root;
}
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
    // us the height of right subtree for a particular node and finally the height at that node will be 1+max(left,right)
    // and this will continue for all tree nodes to get the global max height.
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