/*Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.

Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.
Thumbnail
Example 2:

Input:
R=2
C=2
M=[[-1,-2],[-3,-4]]
Output:
-1
Explanation:
Taking only the first cell is the 
optimal choice.*/

#include <bits/stdc++.h>
using namespace std;
int kaden(vector<int> ans, int n)
{
    int ma = INT_MIN;
    int untill = 0;
    for (int i = 0; i < n; i++)
    {
        untill += ans[i];
        if (untill > ma)
        {
            ma = untill;
        }
        if (untill < 0)
        {
            untill = 0;
        }
    }
    return ma;
}
int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    // code here
    int ma = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        vector<int> ans(C, 0);
        for (int j = i; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                ans[k] = ans[k] + M[j][k];
            }
            ma = max(ma, kaden(ans, C));
        }
    }
    return ma;
}
int main()
{
    return 0;
}