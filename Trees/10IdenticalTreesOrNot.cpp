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
bool findIdentical(Node* root1,Node* root2)
{
    if(!root1 && !root2)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->val != root2->val)
        return false;
    return findIdentical(root1->left,root2->left) && findIdentical(root1->right,root2->right);
}
Node* insertData(Node* root)
{
    int val;
    cout<<"Enter data else enter -1: "<<endl;
    cin>>val;
    if(val == -1)
        return NULL;
    root = new Node(val);
    cout<<"Enter left node of "<<val<<" : "<<endl;
    root->left = insertData(root->left);
    cout<<"Enter right node of "<<val<<" : "<<endl;
    root->right = insertData(root->right);
    return root;
}
int main()
{
    Node* root1,root2;
    root1 = insertData(root1);
    root2 = insertData(root2);
    findIdentical(root1,root2);

}