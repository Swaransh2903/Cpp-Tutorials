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
    cout<<"Moving rightwards from node "<<val<<endl;
    root->right = insertData(root->right);

    return root;
}
Node* getNodePointerFromTarget(Node* root,int target)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == target)
        return root;

    Node* leftCheck = getNodePointerFromTarget(root->left,target);
    Node* rightCheck = getNodePointerFromTarget(root->right,target);

    if(leftCheck)
        return leftCheck;
    else
        return rightCheck;
}
void markParents(Node* root,unordered_map<Node*,Node*> &parent)
{
    queue<int> q;
    q.push(root);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        if(node->left)
        {
            parent[node->left] = node;
            q.push(node->left);
        }
        if(node->right)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
}
int minTimeForBTBurning(Node* root,int target)
{
    Node* targetNode = getNodePointerFromTarget(root,target);

    unordered_map<Node*,Node*> parent;
    markParents(root,parent);

    unordered_map<Node*,int> visitedNodes;
    queue<int> q;
    int currLvl = 0;

    q.push(targetNode);
    visitedNodes[targetNode] = 1;

    while(!q.empty())
    {
        int size = q.size();
        int flag = 0;

        for(int i = 0;i < size;i++)
        {
            Node* node = q.front();
            q.pop();

            if(node->left && !visitedNodes[node->left])
            {
                flag = 1;                
                visitedNodes[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !visitedNodes[node->right])
            {
                flag = 1;                
                visitedNodes[node->right] = 1;
                q.push(node->right);
            }
            if(parent[node] && !visitedNodes[parent[node]])
            {
                flag = 1;                    
                visitedNodes[parent[node]] = 1;
                q.push(parent[node]);
            }
        }

        if(flag == 1)
            currLvl++;
    }

    return currLvl;
}
int main()
{
    Node* root;
    root = insertData(root);

    int target;
    cout<<"Enter target node: ";
    cin>>target;

    cout<<"The minimum time required to burn the binary tree starting from node "<<target<<" is: "<<minTimeForBTBurning(root,target);

}