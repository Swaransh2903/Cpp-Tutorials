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
int findLCA(vector<int> &path1,vector<int> &path2)
{
    int minPath = min(path1.size(),path2.size());

    for(int i =  0;i < minPath;i++)
        if(path1[i] == path2[i])
            return path1[i];
    
    return -1;
}
int main()
{
    Node* root;
    vector<int> path1,path2;
    int node1,node2;

    root = insertData(root);

    cout<<"Enter target node: ";
    cin>>node1>>node2;

    rootToNodePath(root,node1,path1);
    rootToNodePath(root,node2,path2);

    int lca = findLCA(path1,path2);

    cout<<"The lowest common ancestor of "<<node1<<" and "<<node2<<" is: "<<lca;
}