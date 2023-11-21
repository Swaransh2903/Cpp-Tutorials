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
    cout<<"Enter node's data: ";
    cin>>val;

    if(val == -1)
        return NULL;
    root = new Node(val);

    cout<<"Moving leftwards from node "<<val<<endl;
    root->left = insertData(root->left);
    cout<<"Moving rightwards from node "<<val<<endl;
    root->right = insertData(root->right);

    return root;
}
Node* getNodePointerForTarget(Node* root,int target)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == target)
        return root;

    Node* leftResult = getNodePointerForTarget(root->left,target);
    Node* rightResult = getNodePointerForTarget(root->right,target);

    if(leftResult)
        return leftResult;
    else
        return rightResult;
}
void markParents(Node* root,unordered_map<Node*,Node*>& parent)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        if(node->left)
        {
            q.push(node->left);
            parent[node->left] = node;
        }
        if(node->right)
        {
            q.push(node->right);
            parent[node->right] = node;
        }
    }
}
void getAllNodesAtDistanceK(Node* root,int target,int k,vector<int>& ans)
{
    Node* targetNode = getNodePointerForTarget(root,target);

    unordered_map<Node*,Node*> parent;

    markParents(root,parent);

    unordered_map<Node*,int> visitedNodes;
    queue<Node*> q;
    int currLvl = 0;

    q.push(targetNode);
    visitedNodes[targetNode] = 1;

    while(!q.empty())
    {
        if(currLvl++ == k)
            break;

        int size = q.size();
        
        for(int i = 0;i < size;i++)
        {
            Node* node = q.front();
            q.pop();

            if(node->left && !visitedNodes[node->left])
            {
                q.push(node->left);
                visitedNodes[node->left] = 1;
            }
            if(node->right && !visitedNodes[node->right])
            {
                q.push(node->right);
                visitedNodes[node->right] = 1;
            }
            if(parent[node] && !visitedNodes[parent[node]])
            {
                q.push(parent[node]);
                visitedNodes[parent[node]] = 1;
            }
        }
    }

    while(!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }




}
int main()
{
    Node* root;

    root = insertData(root);
    
    int target,k;
    cout<<"Enter target node and distance: ";
    cin>>target>>k;

    if(k == 0)
        return getNodePointerForTarget(target);

    vector<int> ans;
    getAllNodesAtDistanceK(root,target,k,ans);

}