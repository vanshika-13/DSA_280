/*Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).*/

#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.size() == 0)
        return 0;
    int tot = 0, cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] != 0)
                tot++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }
    int xarr[4] = {0, 0, 1, -1};
    int yarr[4] = {1, -1, 0, 0};
    int n = grid.size();
    int m = grid[0].size();
    int day = 0;
    while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + xarr[i], ny = y + yarr[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                    continue;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if (!q.empty())
            day++;
    }

    return (cnt == tot) ? day : -1;
}
int main()
{
    return 0;
}