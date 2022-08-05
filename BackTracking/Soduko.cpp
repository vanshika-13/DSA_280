/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
*/

#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>> &board, int n, int i, int k, char c)
{
    for (int m = 0; m < 9; m++)
    {
        if (board[i][m] == c || board[m][k] == c)
        {
            return false;
        }
    }
    int sx = (i / 3) * 3;
    int sy = (k / 3) * 3;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[x + sx][y + sy] == c)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board, int n, int i, int k)
{
    if (i == n)
    {
        return true;
    }
    if (k == n)
    {
        k = 0;
        return solve(board, n, i + 1, k);
    }
    if (board[i][k] != '.')
    {
        return solve(board, n, i, k + 1);
    }
    for (int j = 1; j <= 9; j++)
    {
        if (isSafe(board, n, i, k, '0' + j))
        {
            board[i][k] = '0' + j;
            if (solve(board, n, i, k + 1))
                return true;
            board[i][k] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    solve(board, n, 0, 0);
}
int main()
{
    return 0;
}