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
bool rootToNodePath(Node* root,int target,vector<int> &ans)
{
    if(root == NULL)
        return false;
    
    if(root->data == target)
        return true;

    ans.push_back(root->data);
    
    if(rootToNodePath(root->left,target,ans) || rootToNodePath(root->right,target,ans))
        return true;

    ans.pop_back();

    return false;

}
int main()
{
    Node* root;
    vector<int> ans;
    int target;

    root = insertData(root);

    cout<<"Enter target node: ";
    cin>>target;

    rootToNodePath(root,target,ans);
}