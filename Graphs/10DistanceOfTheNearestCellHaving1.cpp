// We need to return a matrix wherein at each index we'll have the distance of the nearest 1 from that index element
// in the original matrix. Distance is calculated by : Row number difference + Column number difference.
// Note that matrix will only contain 0s and 1s.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];

    // the 2D vector that we'll return as answer
    vector<vector<int>> ans(n,vector<int>(m,0));

    // visited matrix
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(arr[i][j] == 1)
            {
                // what we are trying to do is that we'll be considering all the 1s as starting positions (hence 0
                // distance) and then will be traversing via bfs sequentially in the four directions. If we get 0s
                // we'll already know whether we got them in the 1st bfs traversal(hence neighbour node of 1 i.e
                // distance = 1) or 2nd/3rd.... traversal(not immediate neighbour node of 1, i.e distance = 2/3...)
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
            else
                vis[i][j] = 0;
        }
    }

    // four direction traversal
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(!q.empty())
    {
        int currRow = q.front().first.first;
        int currCol = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        // for any index the nearest 1s location would be the number of steps we moved to reach there{for 1
        // it would be 0 only and for 0 it would depend on how many steps we took to reach that 0 from the
        // 1 we had inserted in the queue}
        ans[row][col] = steps;

        for(int i = 0;i < 4;i++)
        {
            int nextRow = currRow + delRow[i];
            int nextCol = currCol + delCol[i];

            // now we will be checking whether we are at a valid index and at the same time looking for only 0s because
            // all 1s have already been visited
            if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && vis[i][j] == 0)
            {
                // if we eventually find : 0 , at a valid index, then that 0 was at distance of 1 + the current number of
                // steps (because we are applying BFS)
                q.push({{nextRow,nextCol},steps+1});
                vis[nextRow][nextCol] = 1;
            }

        }
    }
}