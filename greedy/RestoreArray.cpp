/*There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.



Example 1:

Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
Example 2:

Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
Example 3:

Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]*/

#include <bits/stdc++.h>
using namespace std;
void dfs(int start_node, unordered_map<int, bool> &vis, unordered_map<int, vector<int>> &adj, vector<int> &ans)
{
    for (auto x : adj[start_node])
    {
        if (!vis[x])
        {
            vis[x] = true;
            ans.push_back(x);
            dfs(x, vis, adj, ans);
        }
    }
}
vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
{
    int n = adjacentPairs.size();
    vector<int> ans;
    if (n == 1)
    {
        ans.push_back(adjacentPairs[0][0]);
        ans.push_back(adjacentPairs[0][1]);
    }
    else
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++)
        {
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int start_node;
        unordered_map<int, bool> vis;
        for (auto i : adj)
        {
            if (i.second.size() == 1)
            {
                start_node = i.first;
                break;
            }
        }
        vis[start_node] = true;
        ans.push_back(start_node);
        dfs(start_node, vis, adj, ans);
    }
    return ans;
}
int main()
{
    return 0;
}