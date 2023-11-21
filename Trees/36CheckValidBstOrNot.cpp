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
    cout<<"Enter node's value: ";
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
bool checkValidBst(Node* root)
{
    if(root == NULL)
        return true;
    
    
    return checkValidBst(root->left) && checkValidBst(root->right);
}
int main()
{
    Node* root;

    root = insertData(root);

    if(checkValidBst(root))
        return true;
    else
        return false;

}