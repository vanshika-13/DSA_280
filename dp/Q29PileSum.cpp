/*There are n piles of stones arranged in a row. The ith pile has stones[i] stones.

A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.

Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.



Example 1:

Input: stones = [3,2,4,1], k = 2
Output: 20
Explanation: We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.
Example 2:

Input: stones = [3,2,4,1], k = 3
Output: -1
Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
Example 3:

Input: stones = [3,5,1,2,6], k = 3
Output: 25
Explanation: We start with [3, 5, 1, 2, 6].
We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
We merge [3, 8, 6] for a cost of 17, and we are left with [17].
The total cost was 25, and this is the minimum possible.*/

#include <bits/stdc++.h>
using namespace std;
int dp[31][31];
vector<int> presum = {0};
int p;
int solve(int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 1e9;
    for (int k = i; k < j; k += p - 1)
        ans = min(ans, solve(i, k) + solve(k + 1, j));
    if ((j - i) % (p - 1) == 0)
        ans += presum[j + 1] - presum[i];
    return dp[i][j] = ans;
}
int mergeStones(vector<int> &stones, int p)
{
    for (int &x : stones)
        presum.push_back(presum.back() + x);
    int n = stones.size();
    this->p = p;
    memset(dp, -1, sizeof(dp));
    if ((n - 1) % (p - 1) != 0)
        return -1;
    return solve(0, n - 1);
}
int main()
{
    return 0;
}