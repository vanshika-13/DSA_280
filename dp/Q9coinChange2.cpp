/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.



Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1*/

#include <bits/stdc++.h>
using namespace std;
// top->down
int solve(int i, vector<int> &coins, int amount, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return (amount % coins[0] == 0);
    }
    if (dp[i][amount] != -1)
    {
        return dp[i][amount];
    }
    // not take
    int notTake = solve(i - 1, coins, amount, dp);
    // take
    int take = 0;
    if (coins[i] <= amount)
    {
        take = solve(i, coins, amount - coins[i], dp);
    }

    return dp[i][amount] = notTake + take;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return solve(n - 1, coins, amount, dp);
}
/*bottom down-
 int change(int amount,vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        for(int i=0;i<=amount;i++)
        {
            dp[0][i] = (i%coins[0] == 0);

        }
        for(int i=1;i<n;i++)
        {
            for(int T = 0;T<= amount;T++)
            {
                int notTake = dp[i-1][T];
                //take
                int take =0;
                if(coins[i] <= T)
                {
                    take = dp[i][T-coins[i]];
                }
                dp[i][T] = notTake+take;
            }
        }
        return dp[n-1][amount];
    }
*/
int main()
{
    return 0;
}