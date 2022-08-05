/*Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button. You are not allowed to press bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.

Example 1:

Input: 1
Output: 10
Explanation: Number of possible numbers 
would be 10 (0, 1, 2, 3, …., 9)  
Example 2:
Input: N = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11,
12, 14, 22, 21, 23, 25 and so on.
If we start with 0, valid numbers 
will be 00, 08 (count: 2)
If we start with 1, valid numbers 
will be 11, 12, 14 (count: 3)
If we start with 2, valid numbers 
will be 22, 21, 23,25 (count: 4)
If we start with 3, valid numbers 
will be 33, 32, 36 (count: 3)
If we start with 4, valid numbers 
will be 44,41,45,47 (count: 4)
If we start with 5, valid numbers 
will be 55,54,52,56,58 (count: 5) 
and so on..*/

#include <bits/stdc++.h>
using namespace std;
long long dp[26][10];
vector<vector<int>> moves{{0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6}, {1, 4, 5, 7}, {2, 4, 5, 8, 6}, {3, 5, 6, 9}, {4, 7, 8}, {5, 7, 8, 9, 0}, {6, 8, 9}};
long long count_no(int n, int x)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }
    long long n1 = 0;
    for (auto val : moves[x])
    {
        n1 += (count_no(n - 1, val));
        // n1 = n1%mod;
    }
    return dp[n][x] = n1;
}
long long getCount(int n)
{
    long long res = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 10; i++)
        res = (res + count_no(n - 1, i));
    return res;
}
int main()
{
    return 0;
}