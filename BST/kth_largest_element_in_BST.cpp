/*
Logic:
We have implemented following recursive function
(1) Base condition - As we hit a NULL root or a situation where index counter becomes greater than K, we return.
(2) Perform inorder traversal in reverse manner ie;(Right, Node, Left) . Reverse inorder traversal is performed because the right child of a node is always greater than the node in a BST.
(3) As you return from the right child node call , increment the index to indicate visit of one more node.
(4) Thereby, check if (ind == K)
        Case :  True,it implies that KthLargest element has been found, set the value for kth largest element = root's data and return.
(5) Then, recursive calls for left child nodes is performed.


Complexity Analysis: 
(1) TC : O(N)           N- Number of Nodes.
(2) SC : O(H) or O(N)   H- Height of BST , in worst case may go upto O(N) , (This space is used in recursive call stack) 
*/

void solve(Node* root,int &ind,int K,int &val)
{
    if(!root || ind>K)  return;
    solve(root->right,ind,K,val);
    ind++;
    if(ind==K)
    {
        val=root->data;
        return;
    }
    solve(root->left,ind,K,val);
    return;
}
int KthLargestElement(Node *root, int K) {
    int val=-1;
    int ind=0;
    solve(root,ind,K,val);
    return val;
}

