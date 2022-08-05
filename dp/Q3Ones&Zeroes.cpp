/**/

#include <bits/stdc++.h>
using namespace std;
// top-down
vector<vector<vector<int>>> dp;

int helper(vector<string> &str, int m, int n, int pos)
{
    if (pos == str.size())
        return 0;
    if (dp[pos][m][n] != -1)
        return dp[pos][m][n];
    int ones = count(str[pos].begin(), str[pos].end(), '1');
    int zeros = str[pos].size() - ones;
    if (ones <= n and zeros <= m)
        return dp[pos][m][n] = max(helper(str, m - zeros, n - ones, pos + 1) + 1, helper(str, m, n, pos + 1));
    return dp[pos][m][n] = helper(str, m, n, pos + 1);
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    dp.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return helper(strs, m, n, 0);
}

//bottom up

int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>> (m+1, vector<int>(n+1,0)));
        for(int i=1; i<=strs.size(); ++i){
            int zeros = count(strs[i-1].begin(), strs[i-1].end(),'0');
            int ones = strs[i-1].size()-zeros;
            for(int j=0; j<=m; ++j)
                for(int k=0; k<=n; ++k){
                    if(zeros<=j and ones<=k)
                        dp[i][j][k] = max(dp[i-1][j-zeros][k-ones]+1, dp[i-1][j][k]);
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
        }
        return dp[strs.size()][m][n];
    }
int main()
{
    return 0;
}