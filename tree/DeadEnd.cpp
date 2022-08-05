/*Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Examples:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that 
              we cant insert any element.       

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at 
              node 9.  */

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
};
#include <bits/stdc++.h>
/*You are required to complete below method */
bool helper(Node *root, int l, int h)
{
    if (root == NULL)
    {
        return false;
    }
    if (l == h)
    {
        return true;
    }
    return helper(root->left, l, root->data - 1) || helper(root->right, root->data + 1, h);
}
bool isDeadEnd(Node *root)
{
    // Your code here
    if (root == NULL)
    {
        return false;
    }
    return helper(root, 1, INT_MAX);
}
int main()
{
    return 0;
}