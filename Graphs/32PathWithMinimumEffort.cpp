// We'll be given a 2D matrix and we need to find the minimum effort required to reach the destination (n,m) from
// the source(0,0) , what is the effort for a path? Maximum of all differences in adjacent cell values along a path

#include<stdio.h>
using namespace std;
int main()
{
    int n,m;
    int arr[n][m];

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
            cin>>arr[i][j];
    }

    // why this problem requires a priority queue and a normal queue won't be optimal ? because herein while 
    // calculating the difference b/w adjacent cells, the difference can vary
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;

    // pushing the source
    pq.push({0,{0,0}});

    
    vector<vector<int>> dist(n,vector<int> (m,1e9));
    dist[0][0] = 0;

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(!q.empty())
    {
        int diff = q.top().first;
        int row = q.top().second.first;
        int col = q.top().second.second;
        q.pop();

        if(row == n-1 && col == m-1)
            return diff;

        for(int i = 0;i < 4;i++)
        {
            int nextRow = row + delRow[i];
            int nextCol = col + delCol[i];
            if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m)
            {
                int newEffort = max(abs(arr[row][col]-arr[nextRow][nextCol]),diff);
                if(newEffort < dist[nextRow][nextCol])
                {
                    dist[nextRow][nextCol] = newEffort;
                    pq.push({newEffort,{nextRow,nextCol}});
                }

            }
        }
    }

}