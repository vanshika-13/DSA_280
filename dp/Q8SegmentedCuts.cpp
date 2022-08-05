/*Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Example 2:

Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.*/

#include <bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    if (dp[n])
        return dp[n];

    int ans1 = solve(n - x, x, y, z, dp);
    // cout<<ans1<<endl;
    int ans2 = solve(n - y, x, y, z, dp);
    // cout<<ans1<<endl;
    int ans3 = solve(n - z, x, y, z, dp);
    // cout<<ans1<<endl;
    dp[n] = 1 + max(max(ans1, ans2), ans3);
    return dp[n] = (dp[n] == 0) ? -1 : dp[n];
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    // Your code here
    vector<int> dp(n + 1, 0);
    int ans = solve(n, x, y, z, dp);
    return ans == -1 ? 0 : ans;
}
int main()
{
    return 0;
}