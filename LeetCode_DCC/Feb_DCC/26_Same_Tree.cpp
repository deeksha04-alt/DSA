#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) We have implementeda recursive solution as follows:
    (a) Base Case => return true if nodes of both tree are NULL
    (b) Condition check => return false for any of the cases
            (1) Any 1 of the tree nodes p or q is NULL.
            (2) value of node p isn't equal to node value of q
    (c) Take logical AND of recusive calls for left and right child respectively 
Complexity Analysis:
(1) TC: O(n), n=> number of nodes
(2) SC: O(n) , recursive stack space
*/

bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(!p && !q)    return true;
    if((!p || !q) || (p->val !=q->val))    return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}