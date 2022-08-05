/**/

#include <bits/stdc++.h>
using namespace std;
/*
iterative
int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int count = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<m;i++)
        {
            dp[0][i] =0;
        }
        for(int i=0;i<n;i++)
        {
            dp[i][0] =0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] =dp[i-1][j-1] +1;
                    count = max(count,dp[i][j]);
                }
            }
        }
        return count;
    }
*/
class Solution
{
public:
    vector<int> nums1;
    vector<int> nums2;

    int memo[1001][1001] = {0};
    int maxLength = 0;

    int dp(int i, int j)
    {
        if (i == nums1.size() || j == nums2.size())
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];

        memo[i][j] = (nums1[i] == nums2[j]) ? 1 + dp(i + 1, j + 1) : 0;
        maxLength = max(maxLength, memo[i][j]);

        return memo[i][j];
    }

    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for (int x = 0; x < 1000; x++)
        {
            for (int y = 0; y < 1000; y++)
                memo[x][y] = -1;
        }

        for (int x = 0; x < nums1.size(); x++)
        {
            for (int y = 0; y < nums2.size(); y++)
            {
                if (memo[x][y] == -1)
                    dp(x, y);
            }
        }

        return maxLength;
    }
};
int main()
{
    return 0;
}