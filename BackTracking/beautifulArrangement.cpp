/*Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1*/

#include <bits/stdc++.h>
using namespace std;
void solve(int n, vector<bool> &vis, int i, int &count)
{
    if (i > n)
    {
        count++;
    }
    for (int j = 1; j <= n; ++j)
    {
        if (!vis[j] && (i % j == 0 || j % i == 0))
        {
            vis[j] = true;
            solve(n, vis, i + 1, count);
            vis[j] = false;
        }
    }
}
int countArrangement(int n)
{
    vector<bool> vis(n + 1, false);
    int count = 0;
    solve(n, vis, 1, count);
    return count;
}
int main()
{
    return 0;
}