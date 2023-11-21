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

    cout<<"Moving leftwards from node "<<val<<" : "<<endl;
    root->left = insertData(root->left);
    cout<<"Moving rightwards from node "<<val<<" : "<<endl;
    root->right = insertData(root->right);
    
    return root;
}
void verticalOrderTraversal(Node* root,vector<vector<int>> &ans)
{
    map<int,map<int,multiset<int>>> nodes;

    // node,vertical,level
    queue<pair<Node*,pair<int,int>> q;
    q.push({root,{0,0}});

    while(!q.empty())
    {
        Node* node = q.front().first;
        int vertical = q.front().second.first;
        int level = q.front().second.second;
        q.pop();

        nodes[vertical][level].insert(node->data);

        if(node->left)
            q.push({node->left,{vertical-1,level+1}});
        if(node->right)
            q.push({node->right,{vertical+1,level+1}});
    }

    for(auto verticals:nodes)
    {
        vector<int> temp;

        for(auto levelNodes : verticals.second)
        {
            temp.insert(temp.end(),verticals.second.begin(),verticals.second.end());
        }
        
        ans.push_back(temp);
    }
}
int main()
{
    Node* root;
    vector<vector<int>> ans;

    root = insertData(root);
    verticalOrderTraversal(root,ans);

    return ans;
}