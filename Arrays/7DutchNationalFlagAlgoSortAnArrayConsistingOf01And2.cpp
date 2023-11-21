// // Brute:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{0,1,2,1,2,1,0};

    sort(vect.begin(),vect.end());

    for(auto it:vect)
        cout<<it<<" ";
}

// // Better:

// // Since the array comprises of only 3 elements, you can 3 counter variables for counting 0,1,2 and when you have 
// // got the count of each of these elements , you can start placing them one by one (i.e first put 0 till it's
// // count is over , then 1 and then 2).

// Time Complexity : O(2N)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{0,1,2,1,2,1,0};
    
    int cntZero = 0;
    int cntOne = 0;
    int cntTwo = 0;

    for(auto it:vect)
    {
        if(it == 0)
            cntZero++;
        
        if(it == 1)
            cntOne++;

        if(it == 2)
            cntTwo++;
    }

    int index = 0;

    while(cntZero--)
        vect[index++] = 0;

    while(cntOne--)
        vect[index++] = 1;

    while(cntTwo--)
        vect[index++] = 2;

    for(auto it:vect)
        cout<<it<<" ";
}

// Optimal :

// Dutch National Flag Algorithm: proposed by Edgar Djikstra , this algo is called so because of the tri colour in
// the national flag of Netherlands and Djikstra happens to be a Dutch and since herein we are sorting 3 elements
// some inspiration might have been taken from there.

// The central idea is to achieve the sorted order in a single pass wherein we push all low values to the extreme
// left and all high values to extreme right and we don't care about the middle values because they'll be eventually
// sorted only after we've taken care of their left and right.

// Best Explanation : https://www.youtube.com/watch?v=9pdkbqGwUhs&list=PLdjT3D6BlCLKn6EemjDyekJXM3tsdvRBD

// TC: O(n), SC: O(1)


#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{0,1,2,1,2,1,0};
    int low = 0, mid = 0, high = vect.size() - 1;

    while(mid <= high)
    {
        if(vect[mid] == 0)
        {
            swap(vect[low],vect[mid]);
            low++;
            mid++;
        }
        else if(vect[mid] == 1)
            mid++;
        else
        {
            swap(vect[mid],vect[high]);
            high--;
        }
    }

    for(auto it:vect)
        cout<<it<<" ";
}

