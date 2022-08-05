/*Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.



Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.*/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return NULL;
    }
    if (n == 1)
    {
        return new TreeNode(nums[0]);
    }
    int mid = n / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid + 1, nums.end());
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}
int main()
{
    return 0;
}