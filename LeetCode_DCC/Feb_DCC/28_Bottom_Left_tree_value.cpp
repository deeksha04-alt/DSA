#include<bits/stdc++.h>
using namespace std;
/*
Term:
Bottom Left tree node : It is leftmost node of last level of binary tree
Logic:
(1) We get the height of given binary tree
(2) We perform simple BFS, and keep on decrementing height as we process each level.
    The steps followed are:
    (a) Initialise a queue to hold root of given tree
    (b) Process the queue unitll height is greater than 0
    (c) For each level, get the size of queue ,and perform following steps:
        (i)   Store and pop the front node.
        (ii)  If we reach the last level ie; height becomes 1, we return the stored element.
        (iii) else add stored element's left and right child nodes (if exist)
(3) Return 0;

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)

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
int getheight(Node* r)
{
    if(!r)  return 0;

    return max(getheight(r->left),getheight(r->right))+1;
}
int findBottomLeftValue(Node* root) 
{
    queue<Node*> q;
    q.push(root);
    int height=getheight(root);
    while(height>0)
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* f=q.front();
            q.pop();
            if(height==1)   return f->data;
            if(f->left) q.push(f->left);
            if(f->right)    q.push(f->right);
        }
        height--;
    }
    return 0;
    
}