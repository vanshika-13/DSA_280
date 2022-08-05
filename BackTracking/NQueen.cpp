/*The N Queen is the problem of placing N chess queens on an
N×N chessboard so that no two queens attack each other. For example, following is a solution for 4 Queen problem.
The expected output is a binary matrix which has 1s for the blocks where queens are placed. For example,
the following is the output matrix for above 4 queen solution.
              { 0,  1,  0,  0}
              { 0,  0,  0,  1}
              { 1,  0,  0,  0}
              { 0,  0,  1,  0}*/

/* C++ program to solve N Queen Problem using
backtracking */
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

using namespace std;
bool isSafe1(int row, int col, vector<string> board, int n)
{
    // check upper element
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe1(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}
int main()
{
    int n = 4; // we are taking 4*4 grid and 4 queens
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    return 0;
}