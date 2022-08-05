/**/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{ if(root==NULL) return ;
   
   findPreSuc(root->left,pre,suc,key);
   if(root->key<key)  pre=root;
   else if(suc==NULL and root->key>key) suc = root;
   findPreSuc(root->right,pre,suc,key);
   return ;
}
int main()
{
    return 0;
}