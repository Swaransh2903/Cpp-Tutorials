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
void insertData(Node* root)
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
// Node* findNodeInBst(Node* root,int key)
// {
//     if(root == NULL)
//         return NULL;

//     if(root->data == key)
//         return root;
    
//     Node* leftCheck = NULL;
//     Node* rightCheck = NULL;

//     if(root->data > key)
//         leftCheck = findNodeInBst(root->left,key);
//     else
//         rightCheck = findNodeInBst(root->right,key);

//     if(leftCheck)
//         return leftCheck;
//     else
//         return rightCheck;
// }
Node* findAndDeleteNodeInBst(Node* root,int key)
{
    Node* startNode = root;
    Node* parent = root;

    if(root == NULL)
        return NULL;

    if(root->data == key)
    {
        if(root->left)
        {
            Node* tempNode = root;
            root = root->left;

            while(root->right)
                root = root->right;
            
            root->right = tempNode->right;
        }
        else 
            return root->right;
    }

    while(root)
    {
        if(root->data == key)
        {
            if(root->left)
            {
                parent->left = root->left;
                if(root->right)
                {
                    Node* tempNode = root;
                    root = root->left;

                    while(root->right)
                        root = root->right;
                    
                    root->right = tempNode->right;
                }
            }
            else
                parent->right = root->right;
            
            break;

        }
        if(root->data > key)
        {
            parent = root;
            root = root->left;
        }
        else
        {
            parent = root;
            root = root->right;
        }
    }

}
// void deleteNode(Node* root,Node* nodePointer,int key)
// {

// }
int main()
{
    Node* root;

    root = insertData(root);

    int key;
    cout<<"Enter node to be deleted: ";
    cin>>key;

    Node* nodePointer = findNodeInBst(root,key);

    if(!nodePointer)
        cout<<"Not able to find "<<key<<" in tree"<<endl;
    else
        deleteNode(root,nodePointer,key);

}