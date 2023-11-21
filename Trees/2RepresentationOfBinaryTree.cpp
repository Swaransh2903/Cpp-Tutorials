// Trees are represented in the form of structure/class wherein the structure will be composed of data (current node's
// value) as well as the pointer to the left node and right node.

#include<bits/stdc++.h>
using namespace std;
class Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);

}