//  we have to replace all those 0s with X which are surrounded by X on all four directions

#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>> &vis,char arr[][m], int delRow[],int delCol[])
{
    vis[row][col] = 1;

    // check for top, bottom,left and right
    for(int i = 0; i < 4;i++)
    {
        int nextRow = row + delRow[i];
        int nextCol = col + delCol[i];
        if(nextRow >= 0 && nextRow < vis.size() && nextCol >= 0 && nextCol < vis[0].size() && !vis[nextRow][nextCol] 
        && arr[nextRow][nextCol] == '0')
            dfs(nextRow,nextCol,vis,arr,delRow,delCol);
    }
    

}
int main()
{
    int n,m;
    cin>>n>>m;
    char arr[n][m];

    vector<vector<int>> vis(n,vector<int> (m,0));
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};
    // Intuition : We know that in order to convert a group of 0s to X they should be surrounded by X on all the 4
    // sides, that gives us kind of idea that any 0 that is at any boundary of the matrix and all 0s connected to
    // it cannot be converted to X , because there will be atleast one side not surrounded by X. So, if via dfs we
    // can mark all the boundary 0s as well as 0s connected to the boundary 0s as visited, we'll be rest assured
    // that all the remaining 0s can be converted to X.

    // 1st Boundary & 2nd Boundary: traverse first and last row:

    for(int j = 0;j < m;j++)
    {
        // first row
        if(!vis[0][j] && arr[0][j] == '0')
            dfs(0,j,vis,arr,delRow,delCol);

        // last row
        if(!vis[n-1][j] && arr[n-1][j] == '0')
            dfs(n-1,j,vis,arr,delRow,delCol);
    } 

    // 3rd Boundary & 4th Boundary: traverse first and last column:

    for(int i = 0;i < n;i++)
    {
        // first column
        if(!vis[i][0] && arr[i][0] == '0')
            dfs(i,0,vis,arr,delRow,delCol);

        // last column
        if(!vis[i][m-1] && arr[i][m-1] == '0')
            dfs(i,m-1,vis,arr,delRow,delCol);
    } 

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            // if any 0 was not visited , that means it wasn't touched by anyone in the boundary and thus it is 
            // safe to convert it into an X.
            if(!vis[i][j] && arr[i][j] == '0')
                arr[i][j] == 'X';
        }
    }

    // Time Complexity : O(N) + O(N) {for row boundary traversal} + O(M) + O(M) {for column traversal} + assume 
    // that we have all the elements as 0 in worst case , so in a single traversal a boundary 0 element will mark
    // all cells as 0 (N*M) and since we are moving in all 4 directions ( 4*N*M)
}