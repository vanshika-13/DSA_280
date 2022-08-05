/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.*/

#include <bits/stdc++.h>
using namespace std;
// recursion == > pick non pick

int solve(int i, vector<int> nums)
{
    if (i >= nums.size())
        return 0;
    int pick = nums[i] + solve(i + 2, nums);
    int nonPick = solve(i + 1, nums);
    return max(pick, nonPick);
}
int rob(vector<int> nums)
{
    return solve(0, nums);
}

// applying dp on recursion

int solve(int i, vector<int> nums, vector<int> dp)
{
    if (i >= nums.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int pick = nums[i] + solve(i + 2, nums, dp);
    int nonPick = solve(i + 1, nums, dp);
    return dp[i] = max(pick, nonPick);
}
int rob(vector<int> &nums)
{
    vector<int> dp(nums.size());
    for (int i = 0; i < nums.size(); i++)
        dp[i] = -1;
    return solve(0, nums, dp);
}
// memoization dp == > iterative dp

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 2);
    dp[n] = 0;
    dp[n + 1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = nums[i] + dp[i + 2];
        dp[i] = max(dp[i], dp[i + 1]);
    }
    return dp[0];
}
// SPACE FREE --> OMITTING(dp array) ie.solving using variables

int rob(vector<int> &nums)
{
    int n = nums.size();
    int ip1 = 0;
    int ip2 = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int curi = nums[i] + ip2;
        curi = max(curi, ip1);
        ip2 = ip1;
        ip1 = curi;
    }
    return ip1;
}
int main()
{
    return 0;
}