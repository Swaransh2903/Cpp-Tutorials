// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 
// '0's (Water) and '1's(Land). Find the number of islands.

// Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands
//  horizontally or vertically or diagonally i.e., in all 8 directions.

#include<bits/stdc++.h>
using namespace std;
void bfs(int row,int col,int arr[][],vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    // this time since we are dealing with a 2D matrix, we'll be pushing both rows and columns in order to determine
    // a node, so we take a queue that contains a pair at each index.
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        // since we are moving in 8 directions , we know the change in row will be(-1 to +1) and same goes for
        // change in column
        for(int delRow = -1; delRow <=1; delRow++)
        {
            for(int delCol = -1; delCol <= 1; delCol++)
            {
                int neighbourRow = row + delRow;
                int neighbourCol = col + delCol;
                // if the adjacent lies within the matrix range and is an island which isn't visited
                if(neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && arr[neighbourRow][neighbourCol] == 1 && !vis[neighbourRow][neighbourCol])
                {
                    q.push({neighbourRow,neighbourCol});
                    vis[neighbourRow][neighbourCol] = 1;

                }
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    // this time we create a 2D visited array  
    vector<vector<int>> vis(n,vector<int> (m,0));
    int cnt = 0;
    for(int row = 0;row < n;row++)
    {
        for(int col=0;col<m;col++)
        {
            // starting point is an island that is not visited , so that we can follow bfs or dfs traversal to mark
            // all 1s that are connected to it.
            if(arr[row][col] == 1 && !vis[row][col])
            {
                cnt++;
                bfs(row,col,arr,vis);
            }
        }
    }
    // Space Complexity - O(n^2) {visited array} + O(n^2) {if all nodes are 1 in the matrix (worst case), then we'll
    // be storing the entire matrix in queue}
    // Time Complexity: O(n^2) {entire matrix traversal} + O(n^2 * 9) {in the worst case all nodes will be 1 and for each node we'll be checking nine neighbours}
}