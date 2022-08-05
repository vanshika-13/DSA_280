/*Given an m x n binary matrix mat, return the number of submatrices that have all ones.

 

Example 1:


Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation: 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
Example 2:


Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation: 
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.*/

#include <bits/stdc++.h>
using namespace std;
int numSubmat(vector<vector<int>> &mat)
{

    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                dp[i][j] = mat[i][j];
            }
            else
            {
                if (mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
            }
        }
    }
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            int min_val = dp[i][j];

            for (int k = i; k >= 0; k--)
            {
                min_val = min(min_val, dp[k][j]);

                if (min_val == 0)
                {
                    break;
                }

                res += min_val;
            }
        }
    }

    return res;
}
int main()
{
    return 0;
}