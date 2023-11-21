// Left Rotate Array by one place : [1,2,3,4,5] -> [2,3,4,5,1]

// Brute:

// The brute would've been taking another array, storing the first element at last and first n-1 positions being
// occupied by elements of index 1 to n-1.

// Optimal(works in O(1) space):

#include<iostream>
using namespace std;
int main()
{
    int arr[5] = {1,2,3,4,5};
    int firstElement = arr[0];

    for(int i = 0;i < 4;i++)
    {
        arr[i] = arr[i+1];
    }

    arr[4] = firstElement;

    for(int i = 0;i < 5;i++)
        cout<<arr[i]<<",";
}

// What is the space being used in the algorithm : O(N) -> array space , however the extra space will be O(1)


// Left Rotate An Array by K places:


// For k > size of array , we'll be doing k%n and this will serve as the number of rotations we need to perform

// Brute:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr{1,2,3,4,5,6};

    int k;
    cin>>k;
    int n = arr.size();

    if(k > n)
        k = k % n; 

    if(k == 0 || k == n)
        return arr;

    queue<int> temp;

    for(int i = 0;i < k;i++)
        temp.push(arr[i]);

    int startPointer = 0;

    for(int i = 0; i < n-k;i++)
    {
        arr[startPointer] =arr[n-k+i];
        startPointer++;
    }

    for(int i = startPointer;i < n;i++)
    {
        arr[startPointer] = temp.front();
        temp.pop();
    }
    return arr;
}


// Optimal: 

#include<stdio.h>
using namespace std;
int main()
{
    vector<int> vect{1,2,3,4,5,6};
    reverse(vect,vect+k);
    reverse(vect+k,vect+vect.size());
    reverse(vect,vect.size());
}