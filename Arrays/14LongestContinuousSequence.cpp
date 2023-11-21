// If suppose the array is : [102,4,100,1,101,3,2,1,1] : then the longest continuous sequence will be {1,2,3,4} and
// it's length will be 4 i.e we need to return the length of the longest sequence present in the array such that
// the difference b/w the consecutive elements is one.

// Brute: Stand at a particular point and check in the rest of the array, whether the next element( i.e if you are
// at 101, check for 102.. 103) and so on is present or not . If present increase the length of sequence formed 
// else break from the loop and compare the temp length obtained with max length and update the max accordingly.

// TC : Near about O(N^3) , because you are iterating through every element (O(n)) and for each element you are looking
// for the next element in sequence (in the worst case if the array was [1,2,3,4] and you started from 1 you would've
// got 2,3,4 so 3 more iterations i.e O(n)) and you are searching for each of the next element in sequence which will
// be another O(N).

#include<bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int> &vect,int element)
{
    for(int i = 0;i < vect.size();i++)
    {
        if(vect[i] == element)
            return true;
    }
    return false;
}
int main()
{
    vector<int> vect{102,4,100,1,101,3,2,1,1};
    int maxLength = 1;

    for(int i = 0;i < vect.size();i++)
    {
        int currElement = vect[i];
        int currLength = 1;
        
        while(linearSearch(vect,currElement+1) == true)
        {
            currElement += 1;
            currLength++;
        }
        maxLength = max(maxLength,currLength);
    }
    cout<<maxLength;
}


// Better : Sort the array . Now since we need to get the consecutive longest sequence , if we sort things up , it
// will be easier to get the things done in a single pass. Like we first calculate the length till we get an element
// that's not consecutive and from there we start calculating a fresh length.One thing that we need to keep in mind
// is that there could be possibilities of duplicates and to handle that we can check whether the next occuring element
// is equal to lastElement then we'll not update the length but update the lastElement, so that when finally we reach
// a point wherein the element was one greater , then it gets compared with the last occurence of previous duplicate
// element.

// TC: o(NlogN) : sorting + O(n): single pass

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{102,4,100,1,101,3,2,1,1};
    int maxLength = 1;
    
    sort(vect.begin(),vect.end());

    int lastCheckedElement = vect[0];
    int currLength = 1;

    for(int i = 1;i < vect.size();i++)
    {
        if((vect[i] - lastCheckedElement) == 1)
        {
            lastCheckedElement = vect[i];
            currLength++;
        }
        else if(vect[i] == lastCheckedElement)
            lastCheckedElement = vect[i];
        else
        {
            maxLength = max(currLength,maxLength);
            currLength = 1;
            lastCheckedElement = vect[i];
        }
    }
    maxLength = max(currLength,maxLength);
    cout<<maxLength;
}

// Optimal: We can use a set to get rid of the duplicates(take unordered set for better T.C.) and we can use hashing
// to see whether an element exist in set or not . Like for example : if elements are inserted in the given order 
// only: [102,4,100,1,101,3,2,1,1], then when we are iterating for 102, we can check whether the previous element
// exists in the set or not i.e 101, how will this be helpful? If 101 exists in the set , we know 102 is not the 
// starting point of the sequence and it will better if we start forming the sequence from the starting point(i.e
// we start from an element for which previous isn't present). So that way we'll reduce the number of iterations
// by ignoring unnecessary steps. Like for the sequence '102' will be a part of, we can directly start from 100
// and the sequence 100 will form by successively adding '1' will automatically cover 102 thus getting all sequences
// in a single pass.

// TC: O(N) (in worst case the whole array would've been a consecutive increasing sequence and so there would've
// been a single pass through the array:O(N) and then eventually wherever we find the starting point, we'll increase
// the value of starting point N-1 times because we'll be able to find each of the successives: O(N))

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{102,4,100,1,101,3,2,1,1};
    int maxLength = 1;
    unordered_set<int> s;

    for(auto it:vect)
        s.insert(it);
    
    for(auto it:s)
    {
        if(s.find(it - 1) == s.end())
        {
            int currLength = 1;
            while(true)
            {
                if(s.find(it + 1) != s.end())
                {
                    it += 1;
                    currLength += 1;
                }
                else
                    break;
            }
            maxLength = max(maxLength,currLength);
        }
    }
    cout<<maxLength;
}

C:\Users\KIIT\Desktop\C prog LEARNING\.vscode\C++ Tuts