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

void solve(TreeNode* root,string &ans,string temp)
{
    if(!root)  return;
    if(!root->left && !root->right)
    {
        temp+=(char)(97+root->val);
        reverse(temp.begin(),temp.end());
        if(ans=="" || ans.compare(temp)>0)
        {
            ans=temp;
            return;
        }
    }

    temp+=(char)(97+root->val);
    solve(root->left,ans,temp);
    solve(root->right,ans,temp);
}
string smallestFromLeaf(TreeNode* root) {
    string ans="",temp="";
    solve(root,ans,temp);
    return ans;
    
}