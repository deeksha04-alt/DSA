#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(TreeNode* root,int val,int depth)
{
    if(!root)  return;
    if(depth==1)  
    {
        
        TreeNode* lsub=root->left;TreeNode *rsub=root->right;
        root->left=new TreeNode(val);
        root->right=new TreeNode(val);
        root->left->left=lsub;root->right->right=rsub;
        return;
    }
    depth--;
    solve(root->left,val,depth);
    solve(root->right,val,depth);
}
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth==1)   
    { 
        TreeNode* root=new TreeNode(val);
        root->left=root;
        return root;
    }
    solve(root,val,depth-1);
    return root;        
}