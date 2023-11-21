// This is an expansion of the number of islands problem with one catch that herein we have to get the list of those
// islands which are distinct i.e if there are 2 islands wherein ones are connected in exactly the same way, we 
// consider only one island. How to solve? If we can store the shape of the islands in some way in a set data 
// structure, then we can remove the duplicate shapes . Note : The identical islands can be formed at different 
// indices, however if they have same shape, during a traversal the difference b/w the indices of the
//  connected points will also be the same and we can utilize this property to get the shape and hence the distinct
// islands.

#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,int arr[][],vector<vector<int>> &vis,vector<pair<int,int>> &diff)
{
    vis[row][col] = 1;

    // since we'll be moving in all 8 directions , the row and column change will range from -1 to 1.
    for(int delRow = -1; delRow <= 1;delRow++)
    {
        for(int delCol = -1;delCol <= 1;delCol++)
        {
            int nextRow = row + delRow;
            int nextCol = col + delCol;
            if(nextRow >= 0 && nextRow < vis.size() && nextCol >= 0 && nextCol < vis[0].size() && !vis[nextRow][nextCol] 
            && arr[nextRow][nextCol] == 1)
            {
                // why this fails for some cases? Because assume :
                // 1 1 1       and   1 1 1
                // 1                     1  , this approach will consider both as the same shape because this takes
                // into account the relative diff b/w rows and columns w.r.t to the previous indices and herein there
                // is a column difference of 1 from the 3rd 1 in the 1st row for the second figure but that can be 
                // considered same for the first figure when we return via backtracking, but if we would've carried 
                // the starting position with us and calculated the relative diff with respect to that,then these 2
                // positions would've been treated differently. So we will always calculates differences in position
                // from the indices from where we started the dfs traversal.
                diff.push_back({nextRow-row},{nextCol-col});
                dfs(nextRow,nextCol,vis,diff);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];

    vector<vector<int>> vis(n,vector<int> (m,0));

    set<vector<pair<int,int>>> s;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(!vis[i][j] && arr[i][j] == 1)
            {
                vector<pair<int,int>> diff;
                diff.push_back({0,0});
                dfs(i,j,arr,vis,diff);
                s.insert(diff);
            }
        }
    }
    cout<<s.size();
}