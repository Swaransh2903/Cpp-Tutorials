// [1,0,2,3,2,0,0,4,5,1] -> [1,2,3,2,4,5,1,0,0,0]

// brute:

#include<iostream>
using namespace std;
int main()
{
    vector<int> arr{1,0,2,3,2,0,0,4,5,1};
    vector<int> temp;

    // TC- O(N)
    for(int i = 0;i < temp.size();i++)
    {
        if(arr[i] != 0)
        {
            temp.push_back(arr[i])
        }
    }

    // TC : O(temp.size())
    for(int j = 0;j < temp.size();j++)
        arr[j] = temp[j];

    // Tc: O(n-temp.size()) 
    for(int j = temp.size();j < arr.size();j++)
        arr[j] = 0;
    
    // Space(worst case) - O(N){if every element was non zero we would be pushing it in the temp}
}

// better:

// Two iterations but O(1) space

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr{1,0,2,3,2,0,0,4,5,1};

    int startPointer = 0;
    int cntOfZero = 0;
    int n = arr.size();

    for(int i = 0;i < arr.size();i++)
    {
        if(arr[i] != 0)
        {
            arr[startPointer] = arr[i];
            startPointer++;
        }
        else
            cntOfZero++;
    }

    for(int j = n - cntOfZero;j < n;j++)
        arr[j] =  0;

    for(int i = 0;i < n;i++)
        cout<<arr[i]<<",";
}

// optimal:

// TC- O(N) {1 iteration} and O(1) space

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr{1,0,2,3,2,0,0,4,5,1};
    int zeroPos = -1;
    int n = arr.size();

    for(int i = 0;i < n;i++)
    {
        if(arr[i] == 0)
        {
            zeroPos = i;
            break;
        }
    }

    if(zeroPos == -1)
        return arr;

    for(int j = zeroPos + 1;j < n;j++)
    {
        if(arr[j] != 0)
        {
            swap(arr[j],arr[zeroPos]);
            zeroPos++;
        }
    }
    return arr;
}