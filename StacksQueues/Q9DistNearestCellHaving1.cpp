/*Given a binary grid of n*m. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1  i2| + |j1  j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {

                grid[i][j] = 0;
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            auto pr = q.front();
            q.pop();
            int x = pr.first;
            int y = pr.second;
            for (int i = 0; i < 4; i++)
            {

                if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && vis[x + dx[i]][y + dy[i]] != 1)
                {
                    // cout<<x+dx[i]<<"-"<<y+dy[i]<<endl;
                    grid[x + dx[i]][y + dy[i]] = 1 + grid[x][y];
                    vis[x + dx[i]][y + dy[i]] = 1;
                    q.push({x + dx[i], y + dy[i]});
                }
            }
        }
    }
    return grid;
}
int main()
{
    return 0;
}