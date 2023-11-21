// 
// Assume Array:   [1,2,3,4]                                [13,9,5,1]
//                 [5,6,7,8]            convert             [14,10,6,2]
//                 [9,10,11,12]        ---------->          [15,11,7,3]
//                 [13,14,15,16]        (rotated)           [16,12,8,4]

// Let's observe a pattern : (0,0) [1] goes to (0,3)
//                           (0,1) [2] goes to (1,3)
//                           (0,2) [3] goes to (2,3)
//                           (0,3) [4] goes to (3,3)

// For row 2:                (1,0) [5] goes to (0,2)
//                           (1,1) [6] goes to (1,2)
//                           (1,2) [7] goes to (2,2)
//                           (1,3) [8] goes to (3,2)


// So we see the column in first case becomes equal to row of resultant and when the row value of element is it's
// column value in resultant is (n-1) - i {assuming n to be size}.

// Time Complexity: O(n^2) , Space: O(n^2)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> vect{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> ans(vect.size(),vector<int> (vect[0].size()));
    int n = vect.size();

    for(int i = 0;i < vect.size();i++)
    {
        for(int j  = 0;j < vect[0].size();j++)
        {
            ans[j][n-1-i] = vect[i][j];
        }
    }

    for(int i = 0;i < ans.size();i++)
    {
        for(int j  = 0;j < ans[0].size();j++)
        {
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }
}

// Optimal: 

// Now when we are working on a 2D matrix , we'll have to traverse through the entire matrix atleast once 
// and so we cannot get rid of the time complexity. What we can do is we can save up the extra space.

// If we look closely into the resultant array, it's just that every row(ith) gets replaced by every column(ith)
// in the reverse order. So if we find the transpose of the matrix it will replace all rows with columns. After that
// if we reverse individual rows our job will be done.

// How to find transpose?

//                 [1,2,3,4]                                [1,5,9,13]
//                 [5,6,7,8]            convert             [2,6,10,14]
//                 [9,10,11,12]        ---------->          [3,7,11,15]
//                 [13,14,15,16]        (transpose)         [4,8,12,16]

// If we try to see a pattern the diagonal elements remain the same and the ith row and jth column element in the
// original gets placed at jth row and ith column in resultant : 2 is at (1,2) in original and 2 is at (2,1) in 
// resultant, so we can just travel for one half (right of diagonal) and swap it with left portion

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> vect{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    // getting transpose
    for(int i = 0;i < vect.size() - 1;i++)
    {
        for(int j =  i+1;j < vect[0].size();j++)
        {
            swap(vect[i][j],vect[j][i]);
        }
    }
    
    // reversing the rows:
    for(int i = 0;i < vect.size();i++)
        reverse(vect[i].begin(),vect[i].end());
    

    for(int i = 0;i < vect.size();i++)
    {
        for(int j  = 0;j < vect[0].size();j++)
        {
            cout<<vect[i][j]<<",";
        }
        cout<<endl;
    }

}