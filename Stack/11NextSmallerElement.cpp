// For every element we have to find the first smaller element on the right of that element else return -1.

// Eg : [2,1,4,3]  -> For 2 : 1, For 1 : -1 , For 4 : 3 , For 3 : -1

// Brute Force: For every element we'll iterate over right and as soon as we get the first smaller element on the
// right we break the loop for current iteration and store the element somewhere. In worst case we'll be 
// traversing till the end of the list for every element and so the T.C will become O(n^2).

// Optimized: TC - O(n)

// #include<iostream>
#include<bits/stdc++.h>
// #include<stack>
// #include<vector>
using namespace std;
void nextSmaller(stack<int> &s, vector<int> &ans,vector<int> &arr)
{

    // In the optimized version, we'll be traversing the array from the right side, and let's say we are currently
    // at an element '6' , then for '6' we'll be popping accumulated elements in the stack until we find an element
    // which is smaller than 6 . Then we will be storing this element as the next smaller element for 6 and we'll be 
    // pushing 6 in the stack. Now since the stack traversal is from right to left, as we move leftwards from 6,
    // there can be 2 possibilities either the element on the left is greater than or equal to 6 else it is lesser
    // than it. If it is lesser than 6 , then to find the smaller element on the right side of 6 in the stack , we'll
    // comparatively doing traversal less times as we would've already popped out all elements greater than 6 in the
    // previous iteration which in turn would've been greater than the number smaller than 6 also. If it is greater
    // than 6 , then 6 will automatically become the next smaller element.
    for(int i = arr.size()-1;i>=0;i--)
    {
        int val = arr[i];
        // if we are traversing from right to left, for the first element from the right ,the stack would be empty
        // because there were no elements to compare and so we push -1.
        if(s.empty())
            ans.push_back(-1);

        // Now comes the part wherein we'll be searching for an element smaller than the current in the stack.
        else if(s.top()>=val)
        {
            // in this step we'll pop out all the greater elements, because they in turn will prove to be greater for 
            // some number on the left of the current element and hence they r of no use.
            while(!s.empty()&&s.top()>=val)
                s.pop();
            
            // if we end up reaching the end of stack, that means there were no smaller elements and hence we push
            // -1.
            if(s.empty())
                ans.push_back(-1);
            // else we push the smaller element.
            else
                ans.push_back(s.top());
        }

        // if the top of stack is smaller than current element then the top of the stack would be automatically 
        // considered the smaller element.
        else
        {
            ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return ;
}
int main()
{
    stack<int> s;
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);    
    arr.push_back(2);    


    vector<int> ans;
    nextSmaller(s,ans,arr);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<",";
}