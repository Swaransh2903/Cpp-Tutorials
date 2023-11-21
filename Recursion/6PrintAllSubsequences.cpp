#include<bits/stdc++.h>
using namespace std;
void f(int ind, int arr[], vector<int> &v, int n)
{
    // now since we need to get all the subsequences printed we need to traverse the
    // entire array and formulate a subsequence which will be decided
    // on the basis of whether we pick an element at a particular index or not. 
    // Whenever our index value exceeds the size of array that means we've traversed
    // the entirety of the array and whatever sequence we were trying to form has
    // already become a part of the vector. So we can simply print and return.
    if(ind >= n)
    {
        if(v.size() == 0)
            cout<<"";
        else{
            for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    // Now when we are formulating the subsequence we know that a subsequence needs
    // to maintain an order(and therefore we move from 0th index to the last) but at
    // the same time it need not be continuous(which means we can skip values at particular
    // indexes and also take it). So every time when we are standing at a particular
    // index, we've 2 options either pick that element or not pick it, and so we'll
    // have 2 recursive cases , one for including that element and moving forward 
    // and another wherein we exclude that element and move forward. So let's say we
    // first consider the scenario wherein we pick the element and move forward when
    // we are done with the traversal and the list has been printed we'll be have to remove
    // that element from the list because eventually we'll be going to an index before
    // it and then it will disrupt the ordering if a later index element is already
    // added.
    v.push_back(arr[ind]);
    f(ind+1,arr,v,n);
    v.pop_back();
    f(ind+1,arr,v,n); 
}
int main()
{
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> v;
    f(0,arr,v,n);

}