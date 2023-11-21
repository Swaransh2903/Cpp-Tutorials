// In the array there will be equal number of +ve and -ve elements given in any particular order.Maintaining the order
// of how +ve and -ve elements occur in the array (like if 3 occurs before 2 in original then 3 should occur 
// before 2 in resultant also), you have to arrange elements in alternate fashion i.e If there are 6 elements then
// resultant array should be like +ve,-ve,+ve,-ve,+ve,-ve.


// Optimal:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{3,1,-2,-5,2,-4};
    int ans[vect.size()];

    int positivePointer = 0;
    int negativePointer = 1;

    for(int i = 0;i < vect.size();i++)
    {
        if(vect[i] > 0)
        {
            ans[positivePointer] = vect[i];
            positivePointer += 2;
        }
        
        else
        {
            ans[negativePointer] = vect[i];
            negativePointer += 2;
        }
    }

    return ans;
}