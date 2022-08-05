/*iven n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9*/

#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> maxm_left(n), maxm_right(n);

    maxm_left[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        maxm_left[i] = max(maxm_left[i - 1], height[i]);
    }

    maxm_right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxm_right[i] = max(maxm_right[i + 1], height[i]);
    }

    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += (min(maxm_left[i], maxm_right[i]) - height[i]);
    }
    return water;
}
int main()
{
    return 0;
}