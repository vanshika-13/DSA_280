/*Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/

#include <bits/stdc++.h>
using namespace std;
// iterative ->

int maxProduct(vector<int> &nums)
{
    int maxP = INT_MIN;
    int n = nums.size(), prod = 1;
    for (int i = 0; i < n; i++)
    {
        prod *= nums[i];
        maxP = max(maxP, prod);
        if (prod == 0)
        {
            prod = 1;
        }
    }
    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prod *= nums[i];
        maxP = max(maxP, prod);
        if (prod == 0)
        {
            prod = 1;
        }
    }
    return maxP;
}

int maxProduct(vector<int> &nums)
{
    int res = *(max_element(nums.begin(), nums.end()));
    int n = nums.size();
    int curr_max = 1, curr_min = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            curr_max = 1;
            curr_min = 1;
        }
        int tmp = nums[i] * curr_max;
        curr_max = max({nums[i] * curr_max, nums[i] * curr_min, nums[i]});
        curr_min = max({tmp, nums[i] * curr_min, nums[i]});
        res = max(res, curr_max);
    }
    return res;
}
int main()
{
    return 0;
}