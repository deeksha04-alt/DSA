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
void solve(TreeNode* root,int &ans,int temp_sum)
{
    if(!root)  return;
    if(!root->left && !root->right)   
    {
        temp_sum=temp_sum*10+root->val;
        ans+=temp_sum;
        return;
    }

    temp_sum=temp_sum*10+root->val;
    solve(root->left,ans,temp_sum);
    solve(root->right,ans,temp_sum);
}
int sumNumbers(TreeNode* root) {
    int ans=0,temp_sum=0;
    solve(root,ans,temp_sum);
    return ans;
}