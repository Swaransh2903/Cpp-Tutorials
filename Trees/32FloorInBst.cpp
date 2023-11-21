// you need to find the greatest value in a binary tree which is smaller than or equal to the given key.


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
Node* findCeilInBst(Node* root,int key)
{
    int maximum = INT_MIN;
    while(root)
    {
        // assuming that key = root->data is also being considered as a valid case
        if(root->data == key)
        {
            maximum = root->data;
            break;
        }

        if(root->data > key)
            root = root->left;

        else 
        {
            maximum = max(root->data,maximum);
            root = root->right;
        }
    }
    return maximum;
}
int main()
{
    Node* root;
    
    root = insertData(root);

    int key;
    cout<<"Enter key value: ";
    cin>>key;

    Node* floorNode = findFloorInBst(root,key);
}
