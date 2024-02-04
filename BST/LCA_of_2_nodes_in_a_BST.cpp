/*
Term :
LCA - Least Common Ancestor
LCA of 2 nodes in a BST : It is the shared ancestor for 2 nodes that is closest to the concerned 2 nodes.

Logic:
In case of BST , in order to find the LCA , we have used a recursive function explained below:
(1) base condition : if we hit a NULL state or a state where root's value either matches node-1's value or node-2's value ,then we return the root .
(2) Based upon the value comparison of node1 and node2 with root we select the subtree to be explored further -
    (a) If both node1 and node2 values are smaller than the current root node's value , then we explore left subtree to find the LCA .
    (b) If both node1 and node2 values are greater than the current root node's value , then we explore left subtree to find the LCA .
(3) Lastly we return the root .


Complexity Analysis:
(1) TC: O(H),  H=> Height of BST.
(2) SC: O(H) , H=> Height of the BST due to recursive call stack.
*/

Node* solve(Node* root , int node1_val, int node2_val)
{
    if(!root ||(root->data==node1_val || root->data==node2_val) )   return root;
    
    if(root->data>node1_val && root->data>node2_val) return solve(root->left,node1_val,node2_val);
    if(root->data<node1_val && root->data<node2_val)   return solve(root->right,node1_val,node2_val);

    return root;
}

Node* LCA(Node *root, int node1_val, int node2_val)
{
    return solve(root,node1_val,node2_val);
}