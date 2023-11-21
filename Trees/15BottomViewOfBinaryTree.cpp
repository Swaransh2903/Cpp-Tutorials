// this is just an extension of finding the top view of binary tree,i.e the central logic remains the same just that
// there since we were looking from the top , we were processing the first node from every vertical and here since
// we are looking from the bottom we would be processing the last node from every vertical because every node above
// the last one in the same vertical will hide above it.

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
void getBottomView(Node* root,vector<int> &ans)
{
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    mp[0] = root->data;

    while(!q.empty())
    {
        Node* node = q.front().first;
        int vertical = q.front().second;
        q.pop();

        if(node->left)
        {
            q.push({node->left,vertical-1});
            mp[vertical-1] = node->left->data;
        }
        if(node->right)
        {
            q.push({node->right,vertical+1});
            mp[vertical+1] = node->right->data;
        }

    }

    for(auto it:mp)
        ans.push_back(it.second);

}
int main()
{
    Node* root;
    vector<int> ans;

    root = insertData(root);
    getBottomView(root,ans);

    return ans;
}