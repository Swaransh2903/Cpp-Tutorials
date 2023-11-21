// The task in this question is to fill N queens in a N*N size chessboard such that 3 conditions are met: 
// in every column there is exactly one queen, in every row there is exactly one queen , no 2 queens should 
// attack each other. We have to find all possible combinations of chessboard arrangement(placing 
// n queens) wherein these conditions are met.

#include<bits/stdc++.h>
using namespace std;

// Now we define the function to check whether it is safe to place a queen at a particular position or not.
// Now we already know that a queen attacks in eight directions on a chessboard.Naturally we would be moving
// the row and column pointer in such a way that we check for all eight directions.However, in our 
// approach since we are checking for a particular column and then incrementing the column , so at a particular
// point only the columns that are prior to the column we are checking for would've been filled and so we are
// left with only 3 directions to check for : upper diagonal , lower diagonal and left.
bool isSafe(int row,int col,vector<string> &combination,int n)
{
    int dupRow = row;
    int dupCol = col;
    
    // leftward check
    while(col >= 0)
    {
        if(combination[row][col] == 'Q')
            return false;
        col--;
    }

    col = dupCol;
    row = dupRow;

    // upper diagonal check
    while(row >=0 && col >= 0)
    {
        if(combination[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = dupCol;
    row = dupRow;

    // lower diagonal check
    while(row < n && col >= 0)
    {
        if(combination[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col,vector<string> &combination,vector<vector<string>> &ans,int n)
{
    // traversal approach: we'll be trying out all possibilities and see which one's give us the required ans.
    // We'll be running a loop (row wise) and inside the loop we'll be seeing that for the current row and 
    // column , can we place the queen? If suppose we are left with no place to place a queen , we simply return
    // because that would violate the rules otherwise. If our column index reaches 'n' , then if there would've
    // been a possible answer , then at that particular row and column in combination: 'Q' would've been 
    // updated.

    // Base Case : when col index becomes 'n' that means we've tested for all columns and we finally push that
    // combination.
    if(col == n)
    {
        ans.push_back(combination);
        return;
    }

    // row traversal to check every row against that column where we need to place the queen.
    for(int row = 0;row < n;row++)
    {
        // herein we check whether it is safe to place the queen at that particular row & column or not.
        if(isSafe(row,col,combination,n))
        {
            // if the postion was safe to insert the queen , we insert the queen at that particular position
            // and move forward to the next column because we can only place one queen per row and column.
            combination[row][col] = 'Q';
            solve(col+1,combination,ans,n);
            // there are 2 possibilities wherein we return from the calling fnc : one wherein we were able
            // to find a valid combination to place 'n' queens in an 'n' * 'n' chessboard and then we returned
            // to look for more such combinations or midway for a particular column we were not able to find any 
            // row where we could've placed a queen satisfying all condns and so we returned as there is no point
            // of checking for the remaining columns.In either of the scenarios, we need to get the queen out
            // that was placed at that particular row and column(before calling the fnc)
            // because that combination has already been tested.
            combination[row][col] = '.';
        }
    }
}

int main()
{
    // dimension of chessboard(in this case: 4*4)
    int n = 4;
    //  The ans will be contain all valid (n*n) solutions (queen arrangements)
    vector<vector<string>> ans;
    // combination will contain individual valid queen arrangement
    vector<string> combination(n);

    // setting default value as '.' for the entire chessboard
    string s(n,'.');
    for(int i = 0;i < n;i++)
    {
        combination[i] = s;
    }

    solve(0,combination,ans,n);

    // printing the combinations:
    for(auto combination:ans)
    {
        for(auto rowStr:combination)
        {
            for(int i = 0;i < rowStr.size();i++)
                cout<<rowStr[i]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
    }

}