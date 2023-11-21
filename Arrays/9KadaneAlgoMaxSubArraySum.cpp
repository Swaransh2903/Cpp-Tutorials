// Note that the subarray can contain both +ve and -ve elements.

// Brute: Try out all subarrays and then find the maximum sum out of all the sums generated

// TC: O(n^3) or O(n^2) -> based on how you are finding the subarrays.


// Optimal: Kadane's Algo

// TC : O(N), SC: O(1) 

// In Kadane's Algo, we'll be maintaining a maximum variable to store the max sum and whenever we encounter a -ve 
// element and on adding it to the current sum the overall sum becomes negative then we'll instead initialize it again
// with 0 and recompute the sum with remaining elements because adding -ve elements will only decrease the overall
// sum however if on adding the negative element the overall sum still remains +ve then we'll not set the sum as 0
// because there can be a possibility that the elements that come after this are very large +ve values and since they
// will be placed contiguously they'll increase the overall sum thus updating the maximum.

// Ex: [4,-7] -> herein maximum will have initially 0 which gets updated by 4 but we won't consider the sum 4+(-7)
// = -3 because on adding '-7' the overall sum becomes negative , and since we already have a +ve value before it,
// that single element can itself act as a subarray with max sum.


// [4,-1,6] -> however here even though on adding (-1) to 4, we get a sum < maximum(before getting to -1 it would
// contain value = 4) but still we'll add -1 to sum because there is an existence of a large +ve value after this
// which we would've missed(6) if we would've not considered the contiguous values due to decrease in sum. Now when
// we add 6 to 4+(-1) -> overall sum becomes 9 and hence maximum gets updated.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{-2,-3,4,-1,-2,1,5,-3};
    // vector<int> vect{-2,-3,-4};

    int maxSum = INT_MIN; 
    int sum = 0;

    for(int i = 0;i < vect.size();i++)
    {
        sum += vect[i];

        if(sum > maxSum)
            maxSum = sum;

        if(sum < 0)
            sum = 0;
    }
    cout<<maxSum;

}

// Second Variation : herein we need to get the subarray(any of the subarray in case of multiple) that contains
// maximum sum.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{-2,-3,4,-1,-2,1,5,-3};
    // vector<int> vect{-2,-3,-4};

    int maxSum = INT_MIN; 
    int sum = 0;
    int ansStart = -1,ansEnd =-1,start = -1;

    for(int i = 0;i < vect.size();i++)
    {
        // whenever the sum becomes 0 that means we are creating a fresh subarray
        if(sum == 0)
            start = i;

        sum += vect[i];

        // eventually whenever the maxSum is getting updated that means we have got a subarray that contains a sum
        // greater than previous max . Till now we were formulating sum and this became the point wherein the sum
        // overshooted the previous max -> so ansEnd(end pointer of subarray with contains current maxSum) becomes
        // equal to i(the current point we are standing on) and ansStart(start pointer of subarray with contains current maxSum)
        // becomes equal to start that was the point where we started with sum = 0.
        if(sum > maxSum)
        {
            ansStart = start;ansEnd = i;
            maxSum = sum;
        }

        if(sum < 0)
            sum = 0;
    }
    cout<<maxSum;

}