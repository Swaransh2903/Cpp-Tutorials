// You'll be given a key and you need to find out the lowest value that is greater than the given key and at the 
// same time also part of the BST.

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
    int minimum = INT_MAX;

    // so to find the ceil of the BST , the idea is that when we stand at a particular node: there can be 3 scenarios:
    // one wherein the current node's data is equal to the key , second wherein the current node's data is greater
    // than the key and third wherein the current node's data is lesser than the key. Now if we assume the 1st case 
    // to be a legitimate one(i.e if we assume that root's value being equal to the key as the smallest value
    // greater than the key), then we know that it is going to be our final ans because on the left subtree for this node,
    // all the node's value will be lesser than the root->data and since root->data == key , they'll in turn be 
    // lesser than the key also. Also, there is no point checking rightwards in this case because we've already got
    // root->data == key , so on the right all values will be greater than key and hence will not form the minimum
    // greater.If we talk of the third scenario wherein the current node's value is less than the key,then we need to
    // continue our search righwards because the left subtree will contain smaller values and if we consider the
    // second scenario wherein the current node's value is greater than the key, then this can be a possible ans
    // so we store it but not necessarily the minimum so we move leftwards(because there are chances that on the
    // left subtree we find a node that has value smaller than the current node's value but still greater than key)
    while(root)
    {
        // assuming that key = root->data is also being considered as a valid case
        if(root->data == key)
        {
            minimum = root->data;
            break;
        }

        if(root->data > key)
        {
            minimum = min(root->data,minimum);
            root = root->left;
        }

        else 
            root = root->right;
    }
    return minimum;
}
int main()
{
    Node* root;
    
    root = insertData(root);

    int key;
    cout<<"Enter key value: ";
    cin>>key;

    Node* ceilNode = findCeilInBst(root,key);
}