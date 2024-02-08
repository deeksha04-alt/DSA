// Term used :
// Inorder successor Node: It is the node with the smallest value greater than the value of the given node.

/* 
Logic :
(1) We initialize the successor pointer initially to NULL .
(2) We perform traversal in reverse inorder (Right , Node, Left) manner.
(3) As we reach a NULL root state, we return to set the next pointer of our root node to the successor pointer,and 
then update the succssor pointer to current root node .
(4) We perform the call for the left child .

Complexity analysis :
(1) TC: O(N) , N==> Number of nodes in a BST 
(2) SC: O(H) (Stack space used during recursive calls) , in worst case  it can go upto O(N).
*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node *next;

    Node(int v)
    {
        this->data = v;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};
void solve(Node* r,Node** successor)
{
    
    if(r)
    {
        solve(r->right,successor);
        r->next=*successor;
        *successor=r;
        solve(r->left,successor);
    }
    return;
    
}
void populateNext(Node *root)
{
    Node* successor=NULL;
    solve(root,&successor);
}