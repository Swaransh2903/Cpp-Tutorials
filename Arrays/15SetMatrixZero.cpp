//  Assume you are given this matrix: [1,1,1,1]
//                                    [1,0,0,1]
//                                    [1,1,0,1]
//                                    [1,1,1,1]

// Now for this matrix you need to return a resultant matrix such that wherein you encounter a '0' you need to set
// the entire row and column for that '0' to '0'. The catch is that you have to do this thing only for the '0'
// that were already present in the array and not for the converted ones. Like in this example if we consider 
// position (1,1) : we have a 0 and we end up converting entire 1st row and 1st col into 0 but that dosen't mean
// we'll convert the entire 0th row and 1st col into 0 also because (0,1) has been converted into 0 (because it 
// intially had 1).

// Brute: To assure that we only convert the original 0s rows and cols into 0 what we can do is whenever we encounter
// a '0' we iterate over that row and column and convert all 1s into '-1' and not '0'(so that we can distinguish
// b/w the original 0s and the one's converted). Later on we can do another pass and convert all '-1' to '0' to form
// the resultant matrix.

// TC: O(n*m)*O(n+m) + O(n*m)

#include<bits/stdc++.h>
using namespace std;
void markRow(vector<vector<int>> &vect,int row)
{
    for(int j = 0;j < vect[0].size();j++)
    {
        if(vect[row][j] == 1)
            vect[row][j] = -1;
    }
}
void markCol(vector<vector<int>> &vect,int col)
{
    for(int i = 0;i < vect.size();i++)
    {
        if(vect[i][col] == 1)
            vect[i][col] = -1;
    }
}
int main()
{
    vector<vector<int>> vect{{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};

    for(int i = 0;i < vect.size();i++)
    {
        for(int j  = 0;j < vect[0].size();j++)
        {
            if(vect[i][j] == 0)
            {
                markRow(vect,i);
                markCol(vect,j);
            }

        }
    }

    for(int i = 0;i < vect.size();i++)
    {
        for(int j  = 0;j < vect[0].size();j++)
        {
            if(vect[i][j] == -1)
                vect[i][j] = 0;
        }
    }

    for(int i = 0;i < vect.size();i++)
    {
        for(int j  = 0;j < vect[0].size();j++)
        {
            cout<<vect[i][j]<<",";
        }
        cout<<endl;
    }
}

// Better : We know that to mark an entire row and column to 0 , we just require the existence of one 1 '0' in that
// particular row or column and then the entire row or column can be marked as 0. So what we can do is that we can
// maintain separate arrays for rows and columns (initialzed with 0 values) and wherever we find vect[i][j] == 0,
// we'll mark that row and column as visited i.e here we can place all 0s .We can then do a second pass through
// the array and mark any element with '1' value to '0', if the column or row for that particular element has been 
// visited.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> vect{{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
    vector<int> rows(vect.size(),0);
    vector<int> cols(vect[0].size(),0);

    for(int i = 0;i < vect.size();i++)
    {
        for(int j  = 0;j < vect[0].size();j++)
        {
            if(vect[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for(int i = 0;i < vect.size();i++)
    {
        for(int j  = 0;j < vect[0].size();j++)
        {
            if(rows[i] == 1 || cols[j] == 1)
                vect[i][j] = 0;
        }
    }

    for(int i = 0;i < vect.size();i++)
    {
        for(int j  = 0;j < vect[0].size();j++)
        {
            cout<<vect[i][j]<<",";
        }
        cout<<endl;
    }
     
}

// Optimal : Eliminating the extra space: not understood