/*
Terms:
Inorder successor  : It is the node with the smallest value greater than the value of the given node.
Inorder predecessor: It is the node with the greatest value smaller than the value of the given node.


Logic:
We have implemented a recursive inorder function as follows:
(1) base condition :  if we hit a null root => return .
(2) Decision of exploration on the basis of root value

    Case-1 : root->data == key value
             if root's left child exist , set it as prev and then explore its rigit subtree to reach inorder predecessor
             if root's right cild exist , set it as suc  and then explore its left subtree to reach inorder successor
    Case-2 : root->data >  key
            set root as successor node
            make recursive call to left child of root
    Case-3 : root->data < key 
            set root as predecessor node
            make recursive call to right child of root


Complexity Analysis:
(1) TC: O(H) , H=> it is the height of tree
(2) SC: O(1) , (Apart from recursive call stack , no additional space is used)

*/

void inorder(Node* root,int key,Node* &pre,Node* &suc )
{
    if(!root)  return ;
    if(root->data==key)
    {
        if(root->left)
        {   pre=root->left;
            while(pre->right)   pre=pre->right;
        }
        if(root->right)
        {
            suc=root->right;
            while(suc->left)    suc=suc->left;
        }
        return;
        
    }
    else
    {
        if(root->data>key)  
        {
            suc=root;
            inorder(root->left,key,pre,suc);
        }
        else 
        {
            pre=root;
            inorder(root->right,key,pre,suc);
        }

    }
    return;  
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre=NULL;
    suc=NULL;
    inorder(root,key,pre,suc);
}