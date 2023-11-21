// for an array, the values for which everything on the right is smaller than that particular value , will act as
// leaders of the array.

// Brute : for every element, traverse through the right of every element and see if all elements are lesser than
// the current element. If so-> push it in ans vector.

// Optimal: We know that for an element to be leader , all elements to the right of it have to be lesser than it. 
// In other words we can say that if that element(that we are checking for leadership) is greater than the 
// largest element on its right , then that element is a leader. So what we can do is that we start iterating 
// from the right and let's say we initalize  maximum as -1 initially and for every element we check if that 
// element is greater than the current maximum and at every point we update maximum with the max value encountered till now. 
// So while we are traversing backwards, by checking the current value with only the max value encountered till now 
// we can get whether the current element is leader or not and that will save us the extra iterations of traversing
// over the entire right thus getting all leader elements in a single pass.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{10,22,12,3,0,6};
    int currentMax = -1;
    vector<int> ans;

    for(int i = vect.size()-1;i >= 0;i--)
    {
        if(vect[i] > currentMax)
        {
            currentMax = vect[i];
            ans.push_back(vect[i]);
        }
    }

    reverse(ans.begin(),ans.end());

    for(auto it:ans)
        cout<<it<<",";
}