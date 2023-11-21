//  We'll be given a starting row and starting column which will contain some initial colour. We'll be given a new
// colour that needs to be assigned that row and column as well as all the rows+columns that are connected to it and
// have the same colour(the previous colour of starting node) and this thing extends further.

#include<bits/stdc++.h>
using namespace std;
void dfs(int currRow,int currCol,int colour[][],int prevColour,int newColour,int n,int m)
{
    // representing the direction array changes in the form: {up,right,down,left}
    int delRow = {-1,0,1,0};
    int delCol = {0,1,0,-1};
    for(int i = 0;i < 4;i++)
    {
        int neighbourRow = currRow+delRow[i];
        int neighbourCol = currCol+delCol[i];
        if(neighbourRow>=0 && neighbourRow<n && neighbourCol>=0 && neighbourCol<m && colour[neighbourRow][neighbourCol] == prevColour)
        {
            colour[neighbourRow][neighbourCol] = newColour;
            dfs(neighbourRow,neighbourCol,colour,prevColour,newColour,n,m);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int colour[n][m];
    for(int row = 0 ; row < n ; row++)
    {
        for(int col = 0 ; col < m ; col++)
            cin>>colour[row][col];
    }

    // Let's input the start row and column
    int startRow, startCol;
    cin>>startRow>>startCol;
    
    // Let's input the new colour
    int newColour;
    cin>>newColour;

    // We first check whether the colour of the start row and col matches the new Colour or not
    if(colour[startRow][startCol] != newColour)
    {
        // we store the previous colour of start node first, so that we can check using this colour on it's neighbours
        int prevColour = colour[startRow][startCol];
        colour[startRow][startCol] = newColour;
        dfs(startRow,startCol,colour,prevColour,newColour,n,m)
    }

    // Time Complexity: In the worst case all the nodes in the graph might have the same initial colour so we have
    // O(n*m) nodes, so O(n*m) dfs traversals + for every node we'll be checking it's 4 neigbours , so an 
    // additional O(4*(n*m)) -> O(n*m) + O(4*n*m) -> near about : O(n*m)

    // Space Complexity: If we define a new 2D matrix to store the new colours : O(N*M) + the recursive stack space 
    // to store all the nodes O(N*M)

}