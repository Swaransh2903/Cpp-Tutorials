//  As the name suggests, we need to get all the nodes that form the boundary of the tree. So, if we break the
// problem into 3 parts : first is to get the nodes on the left side, second is to get the leaf nodes and third is
// to get the nodes on the right side. So for the left side nodes , the boundary would be formed by the getting
// the node's left for all the nodes left of root , however if no nodes are on the left of a particular node but
// right exists then we'll take the right and from there we'll again move leftwards. Now before processing the side
// right of root, we need to get the leaf nodes because there are no nodes beneath them and we need to get them 
// in left to right fashion, so we can use an inorder traversal for doing so(because in level order there can be
// a possibility that all the leaf nodes are not on the same level and so the right leaf nodes get processed first).
// Now, while processing the nodes right of root, we'll have to get the right child for every node and we'll only
// consider the left child when there is no right(reverse of what we did when we were processing children for the
// left side) and since we are printing the boundary traversal in anticlockwise direction, we have to reverse the 
// nodes on the right of root and then add them as part of our traversal.

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
    cout<<"Enter node data: ";
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
void leftOfRootTraversal(Node* root,vector<int> &ans)
{
    // the entire loop will run until we run out of both left and right nodes which are part of the left subtree of root
    // and in the loop till we get the left we move leftwards and add it in our ans and when the left becomes null
    // then we move rightwards
    while(root->left ||  root->right)
    {
        ans.push_back(root->data);
        if(root->left)
            root = root->left;
        else
            root = root->right;
    }
}
void findLeafNodes(Node* root,vector<int> &ans)
{
    // herein we are doing the inorder traversal but only adding the leaf nodes
    if(root == NULL)
        return;

    if(!root->left && !root->right)
        ans.push_back(root->data);

    findLeafNodes(root->left,ans);
    findLeafNodes(root->right,ans);
    
}
void rightOfRootTraversal(Node* root,vector<int> &ans)
{
    // the entire loop will run until we run out of both left and right nodes which are part of the right subtree of root
    // and in the loop till we get the right we move rightwards and add it in our ans and when the right becomes null
    // then we move leftwards . Also since the traversal has to have the nodes in anticlockwise direction but since
    // our right traversal will be clockwise, we insert the elements in a stack first instead of directly inserting
    // them in our ans and finally get the stack's top out one by one until the stack becomes empty and add the 
    // nodes in our ans , so that they get inserted in the reverse order.
    stack<int> st;

    while(root->left ||  root->right)
    {
        st.push(root->data);
        if(root->right)
            root = root->right;
        else
            root = root->left;
    }

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
void boundaryTraversal(Node* root,vector<int> &ans)
{
    // the root node will always be the 1st one when we are traversing the boundary
    ans.push_back(root->data);

    // Since we are moving leftwards first we check first if left exists and then call the function for root's left
    // traversal
    if(root->left)
        leftOfRootTraversal(root->left,ans);
    
    // when we are looking for leaf nodes , why are we doing the traversal only when either of root's left or right
    // exists ? -> because we are avoiding the possibility of adding the root node in our answer if it was a leaf
    // node because we've already added it. 
    if(root->left || root->right)
        findLeafNodes(root,ans);

    // Since we are moving rightwards last we check first if right exists and then call the function for root's right
    // traversal
    if(root->right)
        rightOfRootTraversal(root->right,ans);
    
}
int main()
{
    Node *root;
    root = insertData(root);

    vector<int> ans;
    boundaryTraversal(root,ans);

}