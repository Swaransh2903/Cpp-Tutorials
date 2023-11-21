// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following 
// meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index
//  [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit
//  time

#include<bits/stdc++.h>
using namespace std;
int main()
{
    // rows and columns of the orange grid
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
            cin>>arr[i][j];
    }

    // we initially take a cnt of fresh oranges , so that we can later check whether all the fresh oranges got rotten
    // or not after the traversal ends
    int cntFresh = 0;

    // we keep a visited array to mark all the oranges that got rotten via traversal to -> 2.
    vector<vector<int>> vis(n,vector<int>(m,0));

    // we take a queue of pair of pair , first pair represents the row and column & the outer pair has the second
    // entry as time , which will get incremented by one at every next iteration wherein we check the fresh neighbours.
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            // since all the rotten oranges rot the other nearby fresh oranges simultaneously, initially all the 
            // rotten oranges can act as the starting point.
            if(arr[i][j] == 2)
            {
                q.push({{i,j},0})
                vis[i][j] = 2;
            }
            // if they are fresh ones,increment the count of fresh
            else if(arr[i][j] == 1)
                cntFresh++;
        }
    }

    // formulating the array that will determine the traversal in the 4 directions
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    // this max time will be compared at every insertion where time gets incremented to get the final max time.
    int maxTime = 0;
    // this will keep a check of the fresh oranges that turned rotten over successive iterations
    int cntFreshTurnedToRotten = 0;

    while(!q.empty())
    {
        int currRow = q.front().first.first;
        int currCol = q.front().first.second;
        int time = q.front().second;
        q.pop();
        // travel in all 4 directions
        for(int i = 0;i < 4;i++)
        {
            int nextRow = currRow + delRow[i];
            int nextCol = currCol + delCol[i];
            // update the maxTime with the current time
            maxTime = max(maxTime,time);
            if((nextRow >= 0 && nextRow < n) && (nextCol >= 0 && nextCol < m))
            {
                // if a neighbour has not been explored (i.e vis[i][j] = 0) & it is a fresh orange (arr[i][j] == 1)
                if(vis[i][j] != 2 && arr[i][j] == 1)
                {
                    q.push({{i,j},time+1});
                    cntFreshTurnedToRotten++;
                }
            }            
        
        }
    }
    if(cntFresh == cntFreshTurnedToRotten)
        return maxTime;
    else
        return -1;
}
