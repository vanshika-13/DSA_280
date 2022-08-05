/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step*/

#include <bits/stdc++.h>
using namespace std;
// normal reccursive approach->
int solve(int n, vector<int> &dp)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return solve(n - 1, dp) + solve(n - 2, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}
// dp approach->
int solve(int n, vector<int> &dp)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}
// iterative approach->
int climbStairs(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    int one_before = 1;
    int two_before = 1;
    int all_ways = 0;
    for (int i = 2; i <= n; i++)
    {
        all_ways = one_before + two_before;
        two_before = one_before;
        one_before = all_ways;
    }
    return all_ways;
}
int main()
{
    climbStairs(6);
    return 0;
}