#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v)
    {
        this->val = v;
        this->left = NULL;
        this->right = NULL;
    }
};

int solve(TreeNode* root,bool isLeft)
{
    if(!root)  return 0;
    if(!root->left && !root->right && isLeft)   return root->val;
    return solve(root->left,true)+solve(root->right,false);       
}
int sumOfLeftLeaves(TreeNode* root) 
{
    return solve(root,false);
}