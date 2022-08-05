/*Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.



Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 */

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
bool areEqual(TreeNode *s, TreeNode *t)
{
    if (s == nullptr || t == nullptr)
    {
        return s == t; // both null
    }
    return s->val == t->val && areEqual(s->left, t->left) && areEqual(s->right, t->right);
}

bool isSubtree(TreeNode *s, TreeNode *t)
{
    return areEqual(s, t) || (s->left && isSubtree(s->left, t)) || (s->right && isSubtree(s->right, t));
}
int main()
{
    return 0;
}