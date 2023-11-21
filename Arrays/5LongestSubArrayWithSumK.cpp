// Note that the array will contain only positive elements.

// [1,2,3,1,1,1,1,4,2,3] , k = 3 -> 1,1,1


// Brute force : Generate all subarrays and find the longest one whose elements have summation equal to k.


#include<iostream>
using namespace std;
int main()
{
    int arr[10] = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    // cin>>k;
    int maximum = INT_MIN;

    // what is subarray? -> a part of array consisting of contiguous elements. So, eventually we can start from the
    // first element of the loop and for the first element all the elements succeeding it can form a subarray with
    // the first element. Similarly for the second element all the elements succeeding it can form a subarray with
    // the second element and therefore first element will not be a part of it.So, this outer loop of 'i' is being
    // used to increment this starting position everytime.
    for(int i = 0;i < 10;i++)
    {
        // Now when have got the starting position , we can go to all elements succeeding it contiguously to form
        // a subarray , so if the current element is paired up with the next element only or till the very last
        // also: both will form a valid subarray. So this j pointer acts as kind of the ending position for each
        // subarray that can be formed by fixing a starting position.
        for(int j = i;j < 10;j++)
        {
            int sum = 0;
            // Now we know by fixing i(start) & j(end) we get the individual subarrays , so this m loop is used 
            // to iterate over these individual subarrays
            for(int m = i;m <= j;m++)
            {
                sum += arr[m];
            }
            if(sum == k)
                maximum = max(maximum,j-i+1);
        }
    }

    cout<<maximum;
}

// Better: O(n^2):

#include<iostream>
using namespace std;
int main()
{
    int arr[10] = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    // cin>>k;
    int maximum = INT_MIN;

    for(int i = 0;i < 10;i++)
    {
        // if we just fix the starting position, we know that the ending position will increment by one at every
        // stage and will hold the sum of the previous subarray + current index element so we can just add
        // everything up as and when we iterate and compare the sum at every stage.
        int sum = 0;
        for(int j = i;j < 10;j++)
        {
            sum += arr[j];
            if(sum == k)
                maximum = max(maximum,j-i+1);
        }
    }

    cout<<maximum;
}

// Optimal - O(2N) {only correct for array containing positive elements}:

#include<iostream>
using namespace std;
int main()
{
    int arr[10] = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    int maximum = INT_MIN;
    int sum = arr[0];

    int right = 0,left = 0;
    int n = 10;

    // What are we doing here is we are setting an ending boundary and we know everytime we get a new element by
    // incrementing the ending position the overall sum will either increase(if +ve) or will remain the same(if 0).
    // Now imagine that we hit a point wherein the sum exceeds k. So the right pointer will actually be the position
    // wherein the sum exceeded the required and so we will have to start incrementing the start pointer(denoted
    // by left) to eventually land a place wherein the sum is within the required boundary.In the process of doing
    // it we would see at every stage if the sum becomes equal to k and if so we update the length of subarray
    // with the help of right and left position.
    while(right < n)
    {
        while(left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if(sum == k)
            maximum = max(maximum,right - left + 1);
        
        right++;
        if(right < n)
            sum += arr[right];
    }

    cout<<maximum;
}


// Optimal - O(nlogn){ordered-map} or O(n)/O(n^2)=> depends on number of collision{unordered_map}
// {This one's the optimal soln if array contained both +ve and -ve elements}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    int maximum = INT_MIN;
    map<int,int> prefixSum;

    for(int i = 0;i < 10;i++)
    {
        sum += arr[i];
        if(sum == k)
            maximum = max(maximum,i + 1);
        
        int rem = sum - k;
        
        if(prefixSum.find(rem) != prefixSum.end())
        {
            int len = i - prefixSum[rem];
            maximum = max(maximum,len);
        }

        if(prefixSum.find(rem) == prefixSum.end())
            prefixSum[rem] = i;
    }

}