// When we are looking from the top, whatever nodes are visible will be included in the top view of the tree.
// Like when you are standing at a particular node and a node is just below it, technically we won't be able to see it
// it from top because that node will get hidden by the first node , so basically we kind of get an intuition that
// if we follow the approach used in vertical order traversal (trying to find out at what distance from the root
// the other nodes are distributed), we will be able to get our answer. Like in case of vertical order traversal,
// we used to look for nodes in same vertical , but herein we only get the first node in a particular vertical 
// because the other nodes will get hidden under this node in the same vertical.


// What I was initially thinking and where it fails -> to get to a vertical we either traverse to the left and right
// of the tree and to get to the the same vertical again we might have: like let's say from root we went to it's
// left(root->left) and then from there we went left again(root->left->left) and then from there we went right
// (root->left->left->right) , so root->left and root->left->left->right will be part of the same vertical and 
// basically we'll be able to see root->left in the top view because that's the first node in that vertical.
// So I thought that by travelling left left left...(for the left of root) and right right right....(for the right
// of root), we'll get the nodes which are part of the top view because they'll act as the first node for their 
// corresponding vertical , however if we consider this example:

// //                               1
//                              /      \
//                           2             3
//                              \        /     \
//                               4      5       6
//                             /
//                            7
//                         /
//                      8
//                    /
//                  9

// if the tree is this 
// my code would only output 
// 2136

// but the actual output would be 
// 982136



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

    cout<<"Moving leftwards from node "<<val<<" : "<<endl;
    root->left = insertData(root->left);
    cout<<"Moving rightwards from node "<<val<<" : "<<endl;
    root->right = insertData(root->right);

    return root;
}
void getTopView(Node* root,vector<int> &ans)
{
    // this map has been taken in order to mark a node we encounter first time in a vertical so that next time we
    // get a node in the same vertical , we don't take it. Why do we take a map and not an unordered one? because
    // we want to get the top view as seen from left to right , so basically the vertical with least value(which
    // will be the extreme left one) should be processed first. So the key is our vertical value and it will be
    // stored in our map in ascending order.
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    // since the root will always be the first node in case of 0th vertical we map it directly against 0.
    mp[0] = root->data;

    while(!q.empty())
    {
        Node* node = q.front().first;
        int vertical = q.front().second;
        q.pop();

        if(node->left)
        {
            q.push({node->left,vertical-1});
            if(!mp[vertical-1])
                mp[vertical-1] = node->left->data;
        }
        if(node->right)
        {
            q.push({node->right,vertical+1});
            if(!mp[vertical+1])
                mp[vertical+1] = node->right->data;
        }
    }

    for(auto it:mp)
        ans.push_back(it.second);

}
int main()
{
    Node* root;
    vector<int> ans;

    root = insertData(root);
    if(root)
        getTopView(root,ans);

    return ans;
}