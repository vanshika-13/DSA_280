/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]*/

#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int> &nums, int n, vector<vector<int>> &ans)
{
    if (ind == n)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        swap(nums[ind], nums[i]);
        solve(ind + 1, nums, n, ans);
        swap(nums[ind], nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    solve(0, nums, n, ans);
    return ans;
}
int main()
{
    return 0;
}