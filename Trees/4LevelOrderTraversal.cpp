#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;Node* right;
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
    cout<<"Moving leftwards ";
    root->left = insertData(root->left);
    cout<<"Moving rightwards ";
    root->right = insertData(root->right);
    return root;
    
}
void levelOrder(Node* root,queue<Node*> &q)
{
    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL) 
            q.push(node->right);

    }
}
int main()
{
    Node* root;
    root = insertData(root);
    queue<Node*> q;
    q.push(root);
    levelOrder(root,q);

}