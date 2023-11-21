// Since we need to get how the tree would look from right side/left side , we'll be getting the rightmost node at
// every level(basically last node at every level) to get the right view and similarly the leftmost node at every
// level(basically first node at every level) to get the left view.

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
void getLeftView(Node* root,vector<int> &ans)
{
    map<int,int> nodes;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();
        // contrary to the right view, we are only inserting a node on any level if on that level we haven't inserted 
        // one previously thus ensuring that we only insert the first node(extreme left) for every level.
        if(!nodes[level])
            nodes[level] = node->data;

        if(node->left)
            q.push({node->left,level+1});
        if(node->right)
            q.push({node->right,level+1});
    }

    for(auto it:nodes)
        ans.push_back(it.second);
}
void getRightView(Node* root,vector<int> &ans)
{
    map<int,int> nodes;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();
        nodes[level] = node->data;

        if(node->left)
            q.push({node->left,level+1});
        if(node->right)
            q.push({node->right,level+1});
    }

    for(auto it:nodes)
        ans.push_back(it.second);
}
int main()
{
    Node* root;
    vector<int> ans;

    root = insertData(root);
    if(root)
    {
        getRightView(root,ans);
        getLeftView(root,ans);
    }

    return ans;
}