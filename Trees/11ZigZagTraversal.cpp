//  Example                            1
//                                    / \
//                                   2   3
//                                  / \   \
//                                 4   5   6

// Ans : 1 3 2 4 5 6 (first from left to right , then from right to left and then again from left to right)

// Approach: Now let's say we  had checked whether we were on an odd or even level and accordingly we would've
// inserted queue's left first or right first. Like let's say on level 0 we push 1 then when we move to level 1 
// since it's odd we push  3 first and then 2. But pushing nodes in the queue in zigzag fashion won't work because
// in that case even if we wish to start from 2's children (4 & 5) first for level 2 , we won't be able to because 
// 3 will act as the first guy in queue and hence it's children will be processed first. So what we can do instead
// is that we can take a flag variable wherein flag = 0 will indicate left to right and flag = 1 will indicate 
// right to left & we'll be switching it's value after every level has been processed. So we'll be push nodes in the
// normal fashion from left to right but the printing will be done based on flag value (so if flag value is 0 we
// print the nodes as it is else we reverse and then print).


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
    cout<<"Enter node data: ";
    cin>>val;

    if(val == -1)
        return NULL;
    root = new Node(val);

    cout<<"Moving leftwards from node: "<<val<<endl;
    root->left = insertData(root->left);
    cout<<"Moving rightwards from node: "<<val<<endl;
    root->right = insertData(root->right);

    return root;

}
void zigzagTraversal(Node* root,vector<vector<int>> &ans)
{
    if(root == NULL)
        return;

    // left to right traversal
    int flag = 0;
    vector<int> temp;
    queue<Node*> q;

    temp.push_back(root->data);
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> temp;

        for(int i = 0;i < size;i++)
        {
            Node* node = q.front();
            q.pop();
            temp.push_back(node->data);

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        if(flag == 0)
        {
            ans.push_back(temp);
            flag = 1;
        }
        else 
        {
            // what can we also do instead of reversing the vector that holds all nodes value at a particular level
            // is to check whether our flag is 0 or 1 inside the function wherein we are pushing the left and 
            // right nodes and let's say we are maintaining a vector array inside we can decide based on flag whether
            // we wish to push via starting index or ending index which will help us slightly in time complexity.
            reverse(temp.begin(),temp.end())
            ans.push_back(temp);
            flag = 0;
        }
    }
}
int main()
{
    Node *root;
    root = insertData(root);

    vector<vector<int>> ans;
    zigzagTraversal(root,ans);

}