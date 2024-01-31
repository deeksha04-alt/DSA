// Term used :
// Inorder successor Node: It is the node with the smallest value greater than the value of the given node.

/* 
Logic :
(1) We initialize the successor pointer initially to NULL .
(2) We perform traversal in reverse inorder (Right , Node, Left) manner.
(3) As we reach a NULL root state, we return to set the next pointer of our root node to the successor pointer,and 
then update the succssor pointer to current root node .
(4) We perform the call for the left subtree .

Complexity analysis
TC: O(N) , N==> Number of nodes in a BST 
SC: O(H) (Stack space used during recursive calls) , in worst case  it can go upto O(N).
*/
void solve(Node* r)
{
    static Node* suc=NULL;
    if(r)
    {
        solve(r->right);
        r->next=suc;
        suc=r;
        solve(r->left);
    }
    return;
    
}
void populateNext(Node *root)
{
    solve(root);
}