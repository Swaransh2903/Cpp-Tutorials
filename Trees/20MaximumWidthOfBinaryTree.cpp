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
        data =  val;
        left = right = NULL;
    }
};
Node* insertData(Node* root)
{
    int val;
    cout<<"Enter node's value: ";
    cin>>val;
    root = new Node(val);

    cout<<"Moving leftwards from node "<<val<<" : "<<endl;
    root->left = insertData(root->left);
    cout<<"Moving rightwards from node "<<val<<" : "<<endl;
    root->right = insertData(root->right);

    return root;
}
int maximumWidth(Node* root)
{
    queue<Node*> q;
    q.push(root->data);
    int maximum = 0;

    while(!q.empty())
    {
        int size = q.size();
        maximum = max(maximum,size);

        for(int i = 0;i < size;i++)
        {
            Node* node = q.front();
            q.pop();

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    return maximum;
}
int main()
{
    Node* root;

    root = insertData(root);
    cout<<"The maximum width of binary tree is: "<<maximumWidth(root);

}