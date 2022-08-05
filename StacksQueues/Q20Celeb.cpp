/*A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.


Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0},
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.*/

#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (M[a][b] == 1)
        {
            s.push(b);
        }
        else if (M[b][a] == 1)
        {
            s.push(a);
        }
    }
    int ans = s.top();
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 1)
        {
            return -1;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 0)
        {
            count++;
        }
    }
    if (count == 1)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}
int main()
{
    return 0;
}