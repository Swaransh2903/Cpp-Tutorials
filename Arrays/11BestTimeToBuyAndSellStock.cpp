// You are given stock prices of a particular stock on various days : [7,1,5,3,6,4] and you need to find out the 
// maximum profit you can make buy deciding the buying date as well as the selling date(the selling date will
// always be greater than the buying date).

// Brute : We assume each day as buying date(by iterating i = 0 to n) and then see which successive elements gives the max difference (which
// can be assumed to be the selling date).We calculate the max out of all the differences and that will be our 
// max profit.


// Optimal : If we observe a pattern, then what we know is that since the selling date will always be greater than
// buying date and since we need to choose the buying date for any selling date such that it ensures max profit,
// what we actually need to do is to get the min(which can act as buying date) to the left of every element while
// iterating(which can act as selling date).

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{7,1,5,3,6,4};

    int maxProfit = 0,mini = vect[0];

    for(int i = 1;i < vect.size();i++)
    {
        int cost = vect[i] - mini;
        maxProfit = max(maxProfit,cost);
        mini = min(mini,vect[i]);
    }
}