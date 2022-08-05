/*Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
set<vector<int>> s;
vector<int> temp;
void solve(vector<int> nums, int n, int i, set<vector<int>> &s, vector<int> &temp)
{
    if (i == n)
    {
        s.insert(temp);
        return;
    }
    temp.push_back(nums[i]);
    solve(nums, n, i + 1, s, temp);
    temp.pop_back();
    solve(nums, n, i + 1, s, temp);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    solve(nums, n, 0, s, temp);
    for (auto i : s)
    {
        ans.push_back(i);
    }
    return ans;
}
int main()
{
    return 0;
}