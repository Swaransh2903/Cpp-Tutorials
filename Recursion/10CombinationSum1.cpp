// This question is a variant of the question wherein we find all subsequences which sum to k , just that herein 
// we can take any element at a particular index multiple times.


#include<bits/stdc++.h>
using namespace std;
void f(int ind, int arr[], int n, int sum,int target,vector<int> &res)
{
    // So initially what we were doing? When we were not allowed to repeat the digits , we were left with 2 options -
    // either include the index element and then move to the next index or exclude it and then move to the next
    // index. Herein there will be just a slight modification wherein instead of moving forward we'll stay at the
    // same index after taking it once because multiple occurences of the same element can also contribute to make
    // the total sum equal to the target. The final target can either be composed of 2 or more elements with multiple
    // occurences of the element or solely of multiple occurences of a single element . In case it is not composed
    // of multiple occurences of a single element , then there will come a time wherein the current sum will exceed
    // the target value and then we'll return because we've realized that continuing on the same index further
    // will lead to an infinite loop.
    if(sum > target)
        return;
    if(ind >= n)
    {
        if(sum == target)
        {
            for(int i=0;i<res.size();i++)
                cout<<res[i]<<" ";
            cout<<endl;
        }
        return;
    }
    sum += arr[ind];
    res.push_back(arr[ind]);
    f(ind,arr,n,sum,target,res);
    sum -= arr[ind];
    res.pop_back();
    f(ind+1,arr,n,sum,target,res); 
}
int main()
{
    int target = 7;
    vector<int> res;
    int arr[] = {2,3,1,6,7};
    int n = 5;
    f(0,arr,n,0,target,res);
}