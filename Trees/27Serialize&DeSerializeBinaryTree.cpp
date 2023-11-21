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
void serialize(Node* root,string &str)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        if(node == NULL)
            str += "#"
        else    
        str += to_string(node->data);

        if(node)
        {
            q.push(node->left);
            q.push(node->right);
        }

        // Why not inserting the node in case of null ptr and just appending # won't work? because you've to ensure 
        // that you maintain the same order while serializing as well deserializing(for convenience) and if you
        // don't push the null values then the level order will get disrupted because at a time on a given level(let's say a)
        // the left node gets processed first so if this node turns out to be a leaf node then for it's left and
        // right we would've got NULL values and before checking for the right node on level a we would've have 
        // added characters corresponding to the subtree of the current left node we are standing on thus disrupting
        // the level order.


        // if(node->left)
        //     q.push(node->left);
        // else if(!node->left)
        //     str += "#,";
        
        // if(node->right)
        //     q.push(node->right);
        // else if(!node->right)
        //     str += "#,"
    }
}
Node* deserialize(string str)
{
    queue<Node*> q;

    if(str.size() == 0) 
        return NULL;

    Node* root = new Node(stoi(str[0]));
    q.push(root);
    int i = 1;

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        if(i < str.size())
        {
            if(str[i] == "#")
                node->left = NULL;
            else
            {
                Node*  leftNode = new Node(stoi(str[i]));
                node->left = leftNode;
            }
            i++;
        }
        if(i < str.size())
        {
            if(str[i] == "#")
                node->right = NULL;
            else
            {
                Node*  rightNode = new Node(stoi(str[i]));
                node->right = rightNode;
            }
            i++;
        }
    }
    return root;
}
int main()
{
    Node* root;
    
    root = insertData(root);

    string str = "";
    if(root)
        serialize(root,str);

    Node* deserializedRoot = deserialize(str);
}