// Printing all:

// #include<bits/stdc++.h>
// using namespace std;
// void f(int ind,int sum,int target,int arr[],int n,vector<int> &v)
// {
//     if(ind == n)
//     {
//         if(sum == target)
//         { 
//             for(int i=0;i<v.size();i++)
//                 cout<<v[i]<<" ";
//             cout<<endl;
//         }
//         return;
//     }
//     if((arr[ind]) <= target)
//     { 
//         //cout<<ind<<" "<<sum<<endl;
//         v.push_back(arr[ind]);
//         sum += arr[ind];
//         f(ind+1,sum,target,arr,n,v);
//         sum = sum - arr[ind];
//         v.pop_back();
//     }
//     f(ind+1,sum,target,arr,n,v);
    

// }
// int main()
// {
//     int sum = 0;
//     int target = 2;
//     int arr[] = {1,2,1};
//     int n = 3;
//     vector<int> v;
//     f(0,sum,target,arr,n,v);
// }

// Printing count:

#include<bits/stdc++.h>
using namespace std;
int f(int ind,int arr[],int sum,int target,int n)
{
    if(ind == n)
    {
        return (sum == target)?1:0;
    }
    int take = 0;
    if(arr[ind] <= target)
    {
        sum += arr[ind];
        take = f(ind+1,arr,sum,target,n);
        sum -=  arr[ind];
    }
    int notTake = f(ind+1,arr,sum,target,n);
    return take+notTake;

}
int main()
{
    int cnt = 0;
    int sum = 0;
    int ind = 0;
    int n = 5;
    int target = 5;
    int arr[] = {1,2,1,3,1};
    cout<<f(ind,arr,sum,target,n);
}