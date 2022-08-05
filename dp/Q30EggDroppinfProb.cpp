/*You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

For more description on this problem see wiki page

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation:
1. Drop the egg from floor 1. If it
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
Example 2:

Input:
N = 2, K = 10
Output: 4*/

#include <bits/stdc++.h>
using namespace std;
// Function to find minimum number of attempts needed in
// order to find the critical floor.
vector<vector<int>> dp;
// n-total number of eggs
// k-total number of floors
int rec(int eggs, int floors) //'eggs'...number of eggs...'floors' is number of floors..dp[n][k]
{
    if (floors == 1 || floors == 0 || eggs == 1) // only 1 floor left..1 trail needed or 0 floor left..no trial needed
        return dp[eggs][floors] = floors;

    if (dp[eggs][floors] != -1)
        return dp[eggs][floors];

    int ans = INT_MAX;

    for (int k = 1; k <= floors; k++) // drop egg from each floor till top floor
    {
        // two cases...egg breaks when thrown from floor 'k'
        // egg doesn't break when thrown from floor 'k'
        ans = min(max(rec(eggs - 1, k - 1), rec(eggs, floors - k)) + 1, ans); //+1 since checking for floor 'k'is also a step
    }
    return dp[eggs][floors] = ans;
}

int eggDrop(int n, int k)
{
    dp.clear();
    dp.resize(n + 1, vector<int>(k + 1, -1));
    return rec(n, k);
}
int main()
{
    return 0;
}