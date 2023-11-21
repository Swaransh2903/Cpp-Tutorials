// the question is same as finding the list of subseqeunces whose sum equal to k , with a slight modification 
// wherein we'll discard duplicate set of subsequences

#include<bits/stdc++.h>
using namespace std;
void f(int ind,vector<int> &arr,int n,int sum,int target,vector<int> &res,set<vector<int>> &unique)
{
    if(ind >= n)
    {
        if(sum == target)
            unique.insert(res);
        return;
    }
    if(arr[ind] <= target)
    {
        sum += arr[ind];
        res.push_back(arr[ind]);
        f(ind+1,arr,n,sum,target,res,unique);
        sum -= arr[ind];
        res.pop_back();
    }
    f(ind+1,arr,n,sum,target,res,unique);
}
int main()
{
    int n = 6;
    int target = 3;
    vector<int> arr{1,1,2,1,1,2};
    sort(arr.begin(),arr.end());
    set<vector<int>> unique;
    vector<int> res;
    f(0,arr,n,0,target,res,unique);
    for(auto vectors:unique)
    {
        for(auto elements:vectors)
            cout<<elements<<" ";
        cout<<endl;
    }
}