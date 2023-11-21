// You have to insert a node in BST at a particular position such that all the properties of BST still remain intact
// after insertion.


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
void insertNodeInBst(Node* root,int key)
{
    Node* parent = root;
    while(root)
    {
        parent = root;
        if(root->data > key)
        {
            root = root->left;
        }
        else
            root = root->right;
    }
    if(parent->data > key)
        parent->left = new Node(key);
    else
        parent->right = new Node(key);
}
int main()
{
    Node* root;

    root =  insertData(root);

    int key;
    cout<<"Enter value to be inserted: ";
    cin>>key;

    if(root == NULL)
    {
        Node* node = new Node(key);
        return node;
    }
    insertNodeInBst(root,key);


}