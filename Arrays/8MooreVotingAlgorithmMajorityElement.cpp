// In this question, we need to find out the element that appears more than n/2 times in an array considering the 
// size of the array to be n

// Brute:
// TC: O(N^2)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{2,1,1,0,1,1};

    for(int i = 0;i < v.size();i++)
    {
        int cnt = 0;
        for(int j = 0; j < v.size();j++)
        {
            if(arr[i] == arr[j])
                cnt++;
        }
        if(cnt > v.size()/2)
            return arr[i];
    }
    return -1;
}


// Another brute that is better than the current brute : sort the array and then take the count of each element in 
// a single pass and where the count exceeds n/2 return else return -1 outside loop . TC: O(nlogn)

// Better: Use hashing, TC : O(N) or O(NlogN) {based on the type of map and number of collisions}, SC: O(N)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{2,1,1,0,1,1};
    unordered_map<int,int> elemFreq;

    for(int i = 0;i < v.size();i++)
    {
        elemFreq[v[i]]++;
    }

    for(auto it:elemFreq)
    {
        if(it.second > v.size()/2)
            return it.first;
    }
    return -1;
}

// Optimal:

// Moore's Voting Algo:

// In this algo we assume initially the current element that we are on as the majority element and we take its count
// to be 1 initially(i.e one occurence of the majority). The idea is to increment the counter whenever we encounter
// the same element else we decrement the counter. If the counter becomes 0, then we again start with a fresh element
// (assuming it to be a majority) and new counter.

// Intuition : The idea is to find an element that occurs more than n/2 times in an array , so if we are incrementing
// the votes(counter) over the occurence of the same element and decrementing the votes on occurence of any other 
// element :  we are actually trying to see the winning probability of the current element that we assumed as majority i.e
// if cnt becomes 0 , it will signify that in that particular section of array, the element that we assumed as 
// majority had equal number of occurence w.r.t to other elements in section and hence it cannot be assumed as the
// majority. Now , since the majority element will occur more than n/2 that means that the no. of occurence of the
// other elements combinedly will be less than n/2 and hence the cnt will have some +ve value remaining at the end,
// if there exists a majority.

// However , what the algo does is that it tells that if a majority element exists , then it would definitely be the
// element that we had at last: for which there was a +ve cnt value remaining. For this scenario : [5,2,5,2,1,1,1]
// the cnt will be 3 but the value '1' is not the majority(occurs less than n/2 times)
// because we are considering the cnt value only in a particular sub section of the array and there could be a possibility that the subsection occurs at the end with
// one single value only but for the rest of the array that element was not present.So, if the question states that
// there can or cannot exist a majority, then we'll have to do a second pass for checking if the current element 
// that we got is actually the majority or not.

#include<bit#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{2,1,1,0,1,1};

    int cntOfAssumedMajority = 0;
    int assumedMajority;
    for(int i = 0;i < v.size();i++)
    {
        if(cntOfAssumedMajority == 0)
        {
            cntOfAssumedMajority = 1;
            assumedMajority = v[i];
        }
        else if(v[i] == assumedMajority)
            cntOfAssumedMajority++;
        else
            cntOfAssumedMajority--;
    }

    int cnt = 0;
    for(int i = 0;i < v.size();i++)
    {
        if(v[i] == assumedMajority)
            cnt++;
    }
    if(cnt > v.size()/2)
        return assumedMajority;
    return -1;
}
