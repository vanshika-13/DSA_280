/*Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]*/

#include <bits/stdc++.h>
using namespace std;
void fn(int i, int k, int n, vector<int> &nums, vector<int> &v,
        vector<vector<int>> &ans)
{

    // base case
    if (i > n || k == 0)
    {
        if (k == 0)
            ans.push_back(v);
        return;
    }

    // pick up the element
    v.push_back(nums[i]);
    fn(i + 1, k - 1, n, nums, v, ans);
    v.pop_back();

    // dont pick up the element
    fn(i + 1, k, n, nums, v, ans);
}
vector<vector<int>> combine(int n, int k)
{
    vector<int> v, nums(n + 1, 0);
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        nums[i] = i;
    }
    fn(1, k, n, nums, v, ans);
    return ans;
}
int main()
{
    return 0;
}