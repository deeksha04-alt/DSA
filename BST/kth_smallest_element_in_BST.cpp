/*
Logic:
We have implemented following recursive function
(1) Base condition - As we hit a NULL root or a situation where index counter becomes greater than K, we return.
(2) Perform inorder traversal ie;(Left, Node, Right) .Inorder traversal is performed because the left child of a node is always smaller than the node in a BST.
(3) As you return from the left child node call , increment the index to indicate visit of one more node.
(4) Thereby, check if (ind == K)
        Case :  True,it implies that KthSmallest element has been found, set the value for kth smallest element = root's data and return.
(5) Then, recursive calls for right child nodes is performed.


Complexity Analysis: 
(1) TC : O(N)           N- Number of Nodes.
(2) SC : O(H) or O(N)   H- Height of BST , in worst case may go upto O(N) , (This space is used in recursive call stack) 
*/

void solve(Node* root,int &ind,int K,int &val)
{
    if(!root || ind>K)  return;
    solve(root->left,ind,K,val);
    ind++;
    if(ind==K)
    {
        val=root->data;
        return;
    }
    solve(root->right,ind,K,val);
    return;
}
int KthSmallestElement(Node *root, int K) {
    int val=-1;
    int ind=0;
    solve(root,ind,K,val);
    return val;
}

