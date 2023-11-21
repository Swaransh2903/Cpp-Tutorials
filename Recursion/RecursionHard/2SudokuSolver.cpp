// Sudoku : 9*9 board which consists of 9 (3*3) boards. In each of these 9 (3*3) boards, we need to
// place numbers from (1 to 9) such that in every row and every column a number occurs only once 
// and each digit occurs only once across entire 3*3 subgrid.

#include<bits/stdc++.h>
using namespace std;

// Now let's create the fnc that will determine whether the value can be placed or not:
bool canBePlaced(char c,vector<vector<char>> &board,int row,int col)
{
    for(int i = 0;i < 9;i++)
    {
        // check if the current char exists in any of the previous/next columns
        if(board[i][col] == c)
            return false;
        
        // check if the current char exists in any of the previous/next rows
        if(board[row][i] == c)
            return false;

        // check if the current char exists in anywhere in the current 3*3 grid
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
            return false;
    }
    return true;
}
// we are creating bool fnc because we've to determine that for the current arrangement of numbers
// in the sudoku can we fill the sudoku board completely fulfilling all the criterias
bool solve(vector<vector<char>> &board)
{
    // the method we are adopting is that we linearly traverse across the entire board(just like the
    // way we traverse a 2D matrix) and at any index we determine whether we will be able to fill that
    // value(0-9) (considering the rules)
    for(int i = 0;i < board.size();i++)
    {
        for(int j = 0;j < board[0].size();j++)
        {
            // if we find an index that is vacant , we need to fill it with any value b/w 1-9 that
            // satisfies all the 3 condns , so we check for vacant positions & then run a for loop.
            if(board[i][j] == '.')
            {
                for(char k = '1';c < '9';c++)
                {
                    // Now that we have to determine whether a particular element can be placed at an
                    // index or not we define a separate fnc for checking that (it will check for all
                    // 3 condns before placing)
                    if(canBePlaced(k,board,i,j))
                    {
                        // if it can be placed , we fill it and then call the function again to find the
                        // next vacant position
                        board[i][j] = k;
                        
                        // herein we are making a call to the function to check for the next vacant
                        // position after filling a valid digit at the current index. Why are we 
                        // adding this '== true' thing? Because we have to not find all possible correct
                        // sudoku but we need to check just that any valid sudoku exist or not. So, when
                        // we would've filled every index the return statement outside of all for's will
                        // return true and the function that called it would in turn return true and so this
                        // cycle continues
                        if(solve(board) == true)
                            return true;
                        // if at a particular index any of the digits didn't satisfy all the 3
                        // condns , that means that this way of filling is not correct and there is no
                        // point of moving forward. So we vacate the current index which we had just
                        // filled.
                        else
                            board[i][j] = '.';
                    }
                }
                // if in case any value from 1-9 cannot be placed at a given index , that means we
                // are solving sudoku wrongly so we return false to the calling fnc in order to 
                // indicate that we are filling wrongly and the currently filled index needs to 
                // vacated.
                return false;
            }
        }
    }
    // if we were able to come out of the loop , that means we had checked for all indexes and filled
    // the correct value in all vacant indexes -> overall forming a valid sudoku -> so we return a 
    // true.
    return true;

}
int main()
{
    // Let's assume a 9*9 sudoku
    int n = 9;

    // for now assume that this board contains the sudoku filled with values at some places and the
    // rest we need to fill
    vector<vector<char>> board;
    solve(board);

}


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n = 10;
//     // int farmerKaKhet = 1;
//     arr[0] = 1;
//     int arr[n];
//     int totalKhet = 1;
//     for(int i = 1;i < n;i++)
//     {
//         arr[i] = arr[i-1] ^ (i+1);
//         totalKhet += arr[i];
//     }
//     return totalKhet;
// }