#include<bits/stdc++.h>
using namespace std;
void nextSmaller(vector<int> &arr, vector<int> &next)
{
    int n = arr.size()-1;
    stack<int> s;
    for(int i = n ; i>=0 ; i--)
    {
        int val = arr[i];
        if(s.empty())
            next.push_back(-1);
        else if(s.top()!=-1 && arr[s.top()] >= val)
        {
            while(s.top()!=-1 && arr[s.top()] >= val)
                s.pop();
            if(s.empty())
                next.push_back(-1);
            else
                next.push_back(s.top());
        }
        else
            next.push_back(s.top());
        s.push(i);
    }
}
void prevSmaller(vector<int> &arr, vector<int> &prev)
{
    int n = arr.size()-1;
    stack<int> s;
    for(int i = 0 ; i<=n ; i++)
    {
        int val = arr[i];
        if(s.empty())
            prev.push_back(-1);
        else if(s.top()!=-1 && arr[s.top()] >= val)
        {
            while(s.top()!=-1 && arr[s.top()] >= val)
                s.pop();
            if(s.empty())
                prev.push_back(-1);
            else
                prev.push_back(s.top());
        }
        else
            prev.push_back(s.top());
        s.push(i);
    }
}
int main()
{
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    // vectors to store indices of next and previous smaller elements for every element.
    vector<int> next(arr.size());
    vector<int> prev(arr.size());
    // vector<int> heights;

    nextSmaller(heights,next);
    prevSmaller(heights,prev);

    int max_area = INT_MIN;

    for(int i=0 ;i<heights.size();i++)
    {
        int h = heights[i];
        int n = next[i];
        int p = prev[i];
        if(n==-1)
            n = heights.size();
        max_area = max(max_area,(n-p-1)*h);
    }
    cout<<max_area;
}
