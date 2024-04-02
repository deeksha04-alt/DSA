#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Make a predecessor and successor helper function , as the least absolute difference for a node will be with either its predecessor node or successor node.
(2) Implement a recursive function to check for difference possible at each node.

Complexity Analysis:
(1) TC: O(N) , N=> number of Nodes
*/

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int v)
    {
        this->data = v;
        this->left = NULL;
        this->right = NULL;
    }
};

int pred(Node* r)
{
    Node* pred=r->left;
    int ans=pred->data;
    while(pred->right)  pred=pred->right;
    return ans=pred->data;
}
int suc(Node* r)
{
    Node* suc=r->right;
    int  ans=suc->data;
    while(suc->left)  suc=suc->left;
    return ans=suc->data;
}
void solve(Node* r,int &ans)
{
    if(!r)  return;    
    if(r->left)
    {
        int val=r->data-pred(r);
        if(val<ans) ans=val;
        solve(r->left,ans);
        
    }
    if(r->right)
    {
        int val=suc(r)-r->data;
        if(val<ans) ans=val;
        solve(r->right,ans);
    }
}
int absolute_diff(Node *root)
{
    int ans=INT_MAX;
    solve(root,ans);
    return ans;
}