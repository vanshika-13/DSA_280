/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 */

#include <bits/stdc++.h>
using namespace std;
/*
C++ code | Recursion (will give TLE)

class Solution {
public:
    int recursion(vector<vector<int>> &grid,int n,int m) {
        if(n==0 && m==0) return grid[n][m];
        if(n<0 || m<0) return 1e8;

        int left=grid[n][m]+recursion(grid,n,m-1); //left and up because i started from the bottom cell.
        int up=grid[n][m]+recursion(grid,n-1,m);
        return min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return recursion(grid,n-1,m-1);

    }
};
C++ code | Memoization (top down)

class Solution {
public:
    int recursion(vector<vector<int>> &grid,int n,int m,vector<vector<int>> &dp) {
        if(n==0 && m==0) return dp[n][m]=grid[n][m];
        if(n<0 || m<0) return 1e8; // whenever we go out of bounds, that implies we cannot include this path in our answer
        //hence we return a huge number since we have to find the minimum answer.
        if(dp[n][m]!=-1) return dp[n][m];
        int left=grid[n][m]+recursion(grid,n,m-1,dp);
        int up=grid[n][m]+recursion(grid,n-1,m,dp);
        return dp[n][m]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return recursion(grid,n-1,m-1,dp);

    }
};
C++ code | Tabulation (bottom up)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        int sum=0;
        for(int i=0;i<m;i++) {
            sum+=grid[0][i];
            dp[0][i]=sum;
        }
        sum=0;
        for(int i=0;i<n;i++) {
            sum+=grid[i][0];
            dp[i][0]=sum;
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                dp[i][j]=min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];

    }
};
*/
// C++ code | Tabulation(space optimised)

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    prev[0] = grid[0][0];
    for (int i = 0; i < n; i++)
    {

        vector<int> curr(m, 0);
        curr[0] = prev[0];
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int left = 1e8;
            int up = 1e8;
            if (i - 1 >= 0)
                up = grid[i][j] + prev[j];
            if (j - 1 >= 0)
                left = grid[i][j] + curr[j - 1];
            curr[j] = min(left, up);
        }
        prev = curr;
    }
    return prev[m - 1];
}
int main()
{
    return 0;
}