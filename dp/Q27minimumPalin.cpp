/*Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".*/

#include <bits/stdc++.h>
using namespace std;
int minInsertions(string s)
{
    int n = s.length();
    string y;
    for (int i = n - 1; i >= 0; i--)
    {
        y.push_back(s[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return n - dp[n][n];
}
int main()
{
    return 0;
}