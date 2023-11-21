// We'll be given a n*m matrix and you need to find out the shortest path reach a destination from a given source.
// The matrix will only comprise of 0s and 1s and you need to traverse through one's only.Note: we need to return
// the minimum distance to reach the destination.

// We don't need a priority queue here because in the question to move from one cell to it's adjacent we require
// unit distance so basically there will be no such thing as minimal distance because at every iteration we'll be 
// only increasing a constant number '1'. 


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

    // this time since we are dealing with a 2D matrix instead of storing linear indexes we'll have rows and columns
    // to store and therefore we take a pair wherein pari.first -> is the distance and pair.second is another pair
    // that is the row and column of that particular cell
    queue<pair<int,pair<int,int>>> q;

    int srcRow,srcCol;
    cin>>srcRow>>srcCol;

    int destRow,destCol;
    cin>>destRow>>destCol;

    // now the distance array this time would be a 2D matrix with n rows and m columns populated with 1e9 values
    vector<vector<int>> dist(n,vector<int>(m,1e9));

    // from the source to the source distance is 0
    dist[srcRow][srcCol] = 0;

    q.push({0,{srcRow,srcCol}});

    // from a particular we can travel in four directions so defining the direction array changes:
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(!q.empty())
    {
        int distance = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        // traversing in all 4 neighbours of that particular cell:
        for(int i = 0;i < 4;i++)
        {
            int nextRow = row + delRow[i];
            int nextCol = col + delCol[i];

            if(nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < m && arr[nextRow][nextCol] == 1 && (distance+ 1) < dist[nextRow][nextRow])
            {
                // why do we directly return here if we reach the destination? because since we are applying bfs
                // for a node first all its adjacent will be pushed into the queue and then we'll look for there
                // adjacents and since the edge weights are constant(1), basically reaching the destination would
                // mean that we would've reached it via the shortest path because there is a constant increment in
                // distance via every path
                if(nextRow == destRow && nextCol == destCol)
                    return distance + 1;
                dist[nextRow][nextCol] = distance + 1;
                q.push({distance[nextRow][nextCol],{nextRow,nextCol}});
            }
        }
    }
}