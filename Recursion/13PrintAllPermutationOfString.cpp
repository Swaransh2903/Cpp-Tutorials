// // Brute Force - this method involves generating all permutations of a string using map and a container for the 
// // obtained permutation.

// #include<bits/stdc++.h>
// using namespace std;
// void f(int arr[], int n, vector<int> &permute,map<int,int> &mp)
// {

//     // this is a temporary vector wherein we are storing the resultant permutations and printing them
//     if(permute.size() == n)
//     {
//         for(int i=0;i<n;i++)
//             cout<<permute[i]<<" ";
//         cout<<endl;
//         return;
//     }
//     for(int i=0;i<n;i++)
//     {
//         // basically what we know is that the permutation can be any combination of elements(size == size of array)
//         // and order dosen't matter. So if we have a 3 size array, we can either start from 0/1/2.So before doing
//         // the recursion part we'll have to run a for loop and see which index element we haven't included in our
//         // permute list using the map.
//         if(!mp[arr[i]])
//         {
//             // if we find that element has not been included, we push it in the list and the map value.
//             permute.push_back(arr[i]);
//             mp[arr[i]] = 1;
//             // then we call the function recursively to check for the remaining elements.
//             f(arr,n,permute,mp);
//             // when we are returning from a function , then it would mean that we got a desired permutation and thus
//             // the return statement inside the if statement got executed. This would mean that currently we have made
//             // the required permutation using the current 'i' and so now we'll map it to 0 and pop that element.
//             mp[arr[i]] = 0;
//             permute.pop_back();
//         }
//         // If suppose our array was : 1,2,3 -> then according to our code, first permutation that we would've got would've
//         // been 1,2,3 so when we would've popped out 3 first after the first return. But what happens after this is that since
//         // i=2 (arr[2]=3) was the last element, the loop would've got over and automatically it would've gone back
//         // to the calling function. Note: At that time i = 1 would've been executed but now since we got back to it's
//         // calling function we remove i=1 element so that i=2 element gets inserted first this time.
//     }
// }
// int main()
// {
//     int n = 3;
//     int arr[] = {1,2,3};
//     vector<int> permute;
//     // permute.push_back(arr[0]);
//     map<int,int> mp;
//     // mp[arr[0]] = 1;
//     f(arr,n,permute,mp);
// }

// Optimized Technique(without map):

// The optimized methods including swapping every index element with every other index element after it and then
// doing recursively for each of these combinations. So let's say we have 1,2,3 -> we can swap 1 with 1 , 1 with 2
// ,1 with 3 and then move forward.

#include<bits/stdc++.h>
using namespace std;
void f(int ind,vector<int> &arr,int n)
{
    // this is a temporary vector wherein we are storing the resultant permutations and printing them
    if(ind == arr.size())
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i = ind; i < n; i++)
    {
        swap(arr[ind],arr[i]);
        f(ind+1,arr,n);
        swap(arr[ind],arr[i]);
    }

}
int main()
{
    int n = 3;
    vector<int> arr {1,2,3};
    // vector<int> permute;
    // permute.push_back(arr[0]);
    // map<int,int> mp;
    // mp[arr[0]] = 1;
    int k = 0;
    f(k,arr,n);
}