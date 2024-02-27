#include<bits/stdc++.h>
using namespace std;
/*
Term: 
Diameter of Binary Tree : length of the longest path between any two nodes in a tree.

Logic:
(1)The recursive solve function is implemented as: 
    (a) It calculates the depth and diameter of the binary tree.
    (b) Base case: 
        If the current node is null, returns {0, 0}.
        If the current node has no children, returns {1, 0} (depth 1 and diameter 0).
    (c) Recursively calculates the depth and diameter of the left and right subtrees.
    (d) Return the pair of depth, diameter fr current node , it is calculated as :
        dept of current node = 1+ max of height of left subtree and right subtree
        diameter of current node = maximum of 2 options
            (a) Including root : sum of rightsub tree and leftsub tree heights
            (b) Excluding root : maximum of diameters of leftsub tree and rightsub tree



Complexity Analysis:
(1) TC: O(n), n=> number of nodes
(2) SC: O(n), n=> recursive stack space
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

pair<int,int> solve(Node* root)
{
    if(!root)  return {0,0};
    if(!root->right && !root->left)   return {1,0};

    pair<int,int> leftsub=solve(root->left);
    pair<int,int> rightsub=solve(root->right);

    return {max(leftsub.first,rightsub.first)+1,
            max(leftsub.first+rightsub.first,max(leftsub.second,rightsub.second))};
}
int diameterOfBinaryTree(Node* root) 
{
    return solve(root).second;
}