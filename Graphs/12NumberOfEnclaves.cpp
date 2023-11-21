// This question is same as the previous one just rephrased. We have to count the number of lands wherein we can 
// not escape from the boundary . Land cells contain 1 whereas water cells contain 0 . If you can reach the boundary
// from any direction using only land cells (1s) then you can escape. So basically, all those cells that are land
// and are connected to the boundary 1s can escape. But this time we will be trying this question via BFS.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char arr[n][m];

    vector<vector<int>> vis(n,vector<int> (m,0));
    queue<pair<int,int>> q;

      // 1st Boundary & 2nd Boundary: traverse first and last row:

    for(int j = 0;j < m;j++)
    {
        // first row
        if(!vis[0][j] && arr[0][j] == '1')
        {
            vis[0][j] = 1;
            q.push({0,j});
        }

        // last row
        if(!vis[n-1][j] && arr[n-1][j] == '1')
        {
            vis[n-1][j] = 1;
            q.push({n-1,j});
        }
    } 

    // 3rd Boundary & 4th Boundary: traverse first and last column:

    for(int i = 0;i < n;i++)
    {
        // first column
        if(!vis[i][0] && arr[i][0] == '1')
        {
            vis[i][0] = 1;
            q.push({i,0});
        }

        // last column
        if(!vis[i][m-1] && arr[i][m-1] == '1')
        {
            vis[i][m-1] = 1;
            q.push({i,m-1});
        }
    } 

    // the four directions
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(!q.empty())
    {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();

        for(int i = 0;i < 4;i++)
        {
            int nextRow = currRow + delRow[i];
            int nextCol = currCol + delCol[i];

            if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && !vis[nextRow][nextCol] && arr[nextRow][nextCol] == '1')
            {
                q.push({nextRow,nextCol});
                vis[nextRow][nextCol] = 1;
            }
        }
    }
    
    // after we have marked all the connected nodes containing 1s , we will count the number of nodes that contain 1
    // and are not visited to get the final ans
    int cntNotEscapableLands = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(arr[i][j] == '1' && !vis[i][j])
                cntNotEscapableLands++;
        }
    }

    cout<<cntNotEscapableLands;
}