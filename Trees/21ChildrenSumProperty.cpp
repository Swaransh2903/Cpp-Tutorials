//         2                                    45
//       /  \                                  /  \
//      35  10                  --->          35  10
//     / \  / \                              / \  / \
//    2  3  5  2                            30 5 8   2

// Basically in this question, we'll be given a tree and we need to convert it into one which follows the children
// sum property. Basically for a node , the sum of it's children node data should be equal to the node's data.
// Also we are only allowed to make increments of +1 any number of time and we cannot decrease the value of any node.

// Now basically , you cannot do like this ki you take the leaf nodes value and sum it up to form their parents
// value and do the same for every node that preceeds those parents. Because there could be a scenario wherein on
// adding up the left and right child's value for a particular node , the node value becomes very small compared
// to it's previous value(and we are allowed to only increment the value) because probably the node had a very
// large value initially and it's children had very small values.

// Example:           50                           39
//                   /  \                         /  \
//                  7    2          --->          8   31
//                 /\   /\                       /\   / \
//                3  5  1 30                    3  5  1  30

// following the previous logic wherein we get to the leaf nodes , add up their values to form their parent's val
// and then successively do it for all the left and right value to get the final root value will fail here because
// we would have then decremented the value of root from 50 to 39 which isn't allowed.

// What we would do instead is that we'll compare the root's value with it's children before going to the left and
// right respectively and if the combined sum of children value is less than root's value then we update the 
// children value with root's value else we update the root's value with the combined sum of left and right child/

// Why does this work? => because when we were moving from a node to it's adjacent we are basically  updating the
// smaller value with the larger one , so basiclally everytime we return  back from recursion it would mean that
// we would be returning either a larger value or an equivalent value to current root value so we would not to have
// to decrement it's value at any stage.

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
void childrenSumProperty(Node* root)
{
    if(root == NULL)
        return;

    int childSum = 0;

    if(root->left)
        childSum += root->left->data;
    if(root->right)
        childSum += root->right->data;
    
    // if suppose on adding the left and right child value we found that they were greater than the current root's
    // value then we'll be updating the root's value by the summation because our logic is based on updating the
    // smaller value with the larger one , so if in future after backtracking the value of root->left and root->right
    // has got updated , we would already knew it happened because there current value was lesser than what we got
    // via summation after backtracking and so the summation of the new nodes would also produce a larger value for
    // the root to get updated with(so only scope for increment for every node). 
    if(child >= root->data)
        root->data = child;
    else{

        if(root->left)
            root->left->data = root->data;
        if(root->right)
            root->right->data = root->data;
    }

    childrenSumProperty(root->left);
    childrenSumProperty(root->right);

    int total = 0;
    
    // this is the part for backtracking wherein we update the result
    if(root->left)
        total += root->left;
    if(root->right)
        total += root->right;
    
    if(root->left || root->right) 
        root->data = total;
    
}
int main()
{
    Node* root; 

    root = insertData(root);

    childrenSumProperty(root);

}