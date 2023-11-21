// What is a permutation ? If suppose array is : [1,2,3] -> then all the postive rearrangements of this array as no.
// 123,321,213,132,231,312 are permutations of this number denoted by the array

// Now when we say we need to get the next permutation , what it actually means is that suppose we have received
// any of the particular rearrangement (let's say we got [3,1,2] = 312) for the above example -> we have to get
// the next permutation that will appear lexicographically

// lexicographical(sorted) order for above ex: 123,132,213,231,312,321 -> so after 312 : 321 should come and that
// should be the next permutation.

// For the last one -> the first one will be the ans.

// Brute: Generate all permutations and store them somewhere. See what permutation is given and search for it and 
// return the next one.


// Optimal: 

// Approach : Since the things are arranged sorted order, if we take into consideration a particular permutation:
// let's say : 231 , till some value from the right the the elements will be increasing and then there would be a dip
// at somepoint , like for '231' 3>1 but 2<3 , so we increased from 1 to 3 but then we dipped as soon as we reached
// at '2'(if this doesn't happen till the very last, that means we have the very last permutation
// (because it is lexicographically greatest and hence all numbers will follow a descending pattern) and we can just
// reverse it to get the final ans because then the digits follow an ascending pattern throughout i.e first permutation). 
// Now we know that if we have not taken into account the last permutation lexicographically with a particular
// starting value(like for 1 if we don't take 132 and for 2 if we don't take 231), then the next permutation will
// atleast share 1 element as common prefix with the given permutation . For example , if we would've taken 
// 213 -> the next would've been 231 and both share prefix '2'. So since things are in sorted order, that sorting 
// will apply to each individual digit in a particular permutation also and so every permutation will be sharing the
// longest common prefix with it's previous permutation and that prefix matching will only break when at a particular
// digit in a permutation a smaller element got replaced by a larger element . Like in case of 213 at the first 
// index 1(smaller) got replaced by 3(larger) to form the next permutation and that is 231 . So to find that swapping
// postion we'll have to find the point where arr[i] < arr[i+1]. Once we get that, we know that this will act as 
// the first point of prefix mismatch and this will be instrumental in determining the next permutation . Like for:
// 213 , we'll get the dipping point as '1' and we need to replace it with a larger value from the right because
// the permutations occuring after this will be lexicographically greater than this. For the next permutation we'll
// have to find the min value that is greater than current dipping point because there can be multiple values  which
// are greater but we need to get the immediate next. For the remaining array(the one after the dipping point) we
// know that arr[i] would've been > arr[i+1] i.e. followed a descending pattern and thus reversing this part will 
// form an ascending pattern i.e the minimal subarray with the remaining elements.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{2,1,3};
    // vector<int> vect{3,2,1};
    int dippingPoint = -1;
    int n = vect.size();

    for(int i = n-2;i >= 0;i--)
    {
        if(vect[i] < vect[i+1])
        {
            dippingPoint = i;
            break;
        }
    }

    // last permutation
    if(dippingPoint == -1)
    {
        reverse(vect.begin(),vect.end());
    }

    else
    {

        // now since we know that if the dippingPoint was found somewhere in b/w, all the elements to the right of
        // it are arranged in descending order and since we need to get the smallest element that is greater than
        // the dippingPoint value, we can run a loop from the end till the point dippingPoint+1, and the first
        // occurence of a value greater than dippingPoint value will be the ans for this,because all the values left
        // of it though greater will not be the smallest value that is greater since they are arranged in descending
        // order.
        int pos = dippingPoint+1;

        for(int i = n-1;i >= dippingPoint+1;i--)
        {
            if(vect[i] > vect[dippingPoint])
            {
                pos = i;
                break;
            }
        }
        // int posOfSmallestValGreaterThanDippingPoint = dippingPoint+1;
        // int smallestValGreaterThanDippingPoint = vect[dippingPoint+1];
        // for(int i = dippingPoint+1;i <= n-1;i++)
        // {
        //     if(vect[i] > vect[dippingPoint] && vect[i] < smallestValGreaterThanDippingPoint)
        //     {
        //         smallestValGreaterThanDippingPoint = vect[i];
        //         pos = i;
        //     }
        // }
        // swap dipping point value with the smallest value greater than the dipping point value
        swap(vect[dippingPoint],vect[pos]);


        // once we have replaced the dipping point with the required value, we know that all elements right of this
        // point are in descending order and by reversing it we generate an ascending order which would be 
        // lexicographically smallest yet greater than current permutation (ensured by dippingPoint swap) thus
        // forming the next permutation.

        reverse(vect.begin() + dippingPoint + 1,vect.end());
    }

    for(auto it:vect)
            cout<<it<<",";
}