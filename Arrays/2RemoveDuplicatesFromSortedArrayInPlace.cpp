// brute (not being performed in O(1) space):

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6] = {1,1,2,2,3,3};

    // O(n) -> space if all were unique elements
    set<int> s;
    
    // O(NlogN)
    for(int i = 0;i < 6;i++)
        s.insert(arr[i]);

    int index = 0;

    // O(n)
    for(auto it:s)
    {
        arr[index] = it;
        index++;
    }
}

// optimal:

// We'll be using a 2 pointer approach here. Now let's say we keep our starting pointer at the first element itself,
// we know that the first element of an array will also be the first element of the array that contains only unique
// elements because things are sorted. However for the second element in array that we need to return, we need to move
// forward in the original array till we get an element that's not equivalent to the first element .

#include<iostream> 
using namespace std;
int main()
{
    int arr[6] = {1,1,2,2,3,3};
    
    int j = 0;
    int i = 1;

    while(i < 6)
    {
        if(arr[i] == arr[j])
            i++;
        else
            arr[j++] = arr[i];
    }
    return j;
}