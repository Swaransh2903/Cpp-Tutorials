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
void iterativePreorder(Node* root,stack<Node*> &st)
{
    // Why do we push right first and then left in case of iterative even though preorder follows: root left right?
    // So firstly we'll always print the root node we are standing on first because that should be the first in 
    // sequence . Now since , stack follows a last in first out order whatever gets inserted should be printed first,
    // so at every node we'll have to ensure that we insert the right guy first and then the left one so that left
    // remains on top and gets popped out and further gets printed.
    while(!st.empty())
    {
        Node* node = st.top();
        st.pop();
        cout<<node->data<<" ";

        if(node->right != NULL)
            st.push(node->right);
        if(node->left != NULL)
            st.push(node->left);
    }
}
void iterativeInorder(Node* root)
{
    stack<Node*> st2;
    Node* node = root;
    while(true)
    {
        if(node != NULL)
        {
            st2.push(node);
            node = node->left;
        }
        else
        {
            if(st2.empty()) 
                break;
            node = st2.top();
            st2.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    }
}
void iterativePostOrderUsingTwoStacks(Node* root)
{
    stack<Node*> st3;
    stack<Node*> st4;
    Node* node = root;
    st3.push(node);
    while(!st3.empty())
    {
        node = st3.top();
        st3.pop();
        st4.push(node);

        if(node->left != NULL)
            st3.push(node->left);
        if(node->right != NULL)
            st3.push(node->right);
    }
    while(!st4.empty())
    {
        // cout<<"hi";
        cout<<st4.top()->data<<" ";
        st4.pop();
    }
}
void iterativePostOderUsingOneStack(Node* root)
{
    Node* node = root;
    stack<Node*> st;

    while(node != NULL || !st.empty())
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left; 
        }
        else
        {
            Node* temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }

            }
            else
                node = temp;

        }
    }
    
}
int main()
{
    Node* root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(7);
    stack<Node*> st;
    st.push(root);
    iterativePreorder(root,st);
    cout<<endl;
    iterativeInorder(root);
    cout<<endl;
    iterativePostOrderUsingTwoStacks(root);
    cout<<endl;
    iterativePostOderUsingOneStack(root);
}