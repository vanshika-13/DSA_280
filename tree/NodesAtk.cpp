/*Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []*/

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
vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
{
    unordered_map<TreeNode *, TreeNode *> parent_track; // node -> parent
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    { /*First BFS to get a track of parent nodes*/
        TreeNode *current = queue.front();
        queue.pop();
        if (current->left)
        {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if (current->right)
        {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
    queue.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (!queue.empty())
    { /*Second BFS to go upto K level from target node and using our hashtable info*/
        int size = queue.size();
        if (curr_level++ == K)
            break;
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = queue.front();
            queue.pop();
            if (current->left && !visited[current->left])
            {
                queue.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                queue.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]])
            {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while (!queue.empty())
    {
        TreeNode *current = queue.front();
        queue.pop();
        result.push_back(current->val);
    }
    return result;
}
int main()
{
    return 0;
}