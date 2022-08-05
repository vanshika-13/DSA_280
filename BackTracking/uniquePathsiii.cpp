/*You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:


Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.*/

#include <bits/stdc++.h>
using namespace std;
int empty = 1;
int solve(vector<vector<int>> &grid, int n, int m, int i, int j, int count)
{
    if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == -1)
    {
        return 0;
    }
    if (grid[i][j] == 2)
    {
        if (count == empty)
        {
            return 1;
        }
        return 0;
    }
    grid[i][j] = -1;
    int l = solve(grid, n, m, i, j - 1, count + 1);
    int r = solve(grid, n, m, i, j + 1, count + 1);
    int u = solve(grid, n, m, i - 1, j, count + 1);
    int d = solve(grid, n, m, i + 1, j, count + 1);
    grid[i][j] = 0;

    return l + r + u + d;
}
int uniquePathsIII(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                sx = i, sy = j;
            }
            else if (grid[i][j] == 0)
            {
                empty++;
            }
        }
    }
    return solve(grid, n, m, sx, sy, 0);
}
int main()
{
    return 0;
}