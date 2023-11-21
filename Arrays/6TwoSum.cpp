// Let's take first variety wherein we need to tell whether there exist 2 elements in the array whose sum is equal
// to given target.

// Brute: O(N^2) {near about: not exactly} ->when we are standing at an element we form a pair of the current
// element with all it's successive elements and see if any of them sums up to given target
#include<iostream>
using namespace std;
int main()
{
    int arr[5] = {1,3,4,5,2};
    int k = 3;

    for(int i = 0;i < 5;i++)
    {
        for(int j = i+1;j < 5;j++)
        {   
            if((arr[i] + arr[j]) == k)
                return true;
        }
    }
    return false;
}

// Better : O(nlogn){ordered_map} or O(n) {assuming very less collision in case of unordered_map}.In this approach
// we store all the values of the array in a hashmap. If in case we are iterating and we are on a particular element and
// the remainder(required sum - that array index value where we are currently standing) is present in the map:
// that means two elements exist in the array(the current as well as the remainder that was found in the map) that
// sum up to the target.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {1,3,4,5,2};
    int k = 3;
    map<int,int> mp;

    for(int i = 0;i < 5;i++)
    {
        int rem =  k - arr[i];
        if(mp.find(rem) != mp.end())
            return true;
        mp[rem] = i;
    }
    return false;
}

// Optimal O(NlogN): TC , O(1): SC: This approach is only optimal when we for the variety 1 problem, wherein we need to just find out
// whether 2 elements add up to give the target or not . If the question would've been that we need to return 
// all possible pair of element indices that sum up to the target, then this approach wouldn't have been optimal
// because this approach is based on sorting and in case of getting the indices, we would've to store the indices
// somewhere first before sorting which would consume the O(N) space which we would've saved otherwise for the 
// 1st variety question.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ans{1,3,4,5,2};
    int k = 3;

    sort(ans.begin(),ans.end());

    int left =  0 , right = ans.size()-1;

    while(left <= right)
    {
        if(arr[left] + arr[right] == k)
            return true;
        else if(arr[left] + arr[right] > k)
            right--;
        else
            left++;
    }
    return false;
}