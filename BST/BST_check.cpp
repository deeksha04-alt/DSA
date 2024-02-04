/*
Logic:
- Implement a recursive function that checks the current value against the accepted range of values for its existence.
- Initially we have set the range to be [-1 ,100000] , this totally depends on the constraints provided in the question.

The steps are as follows:
(1) base condition : when root is NULL return true .
(2) value check    : if current root falls outside of range [mini,maxi] , return false . 
(3) Make recursive calls for leftchild and right child
(4) Return a logical AND of leftchild and rightchild call .

Complexity Analysis:
(1) TC :  
(2) SC :
*/

bool solve(Node* root,int mini,int maxi)
{
    if(!root)  return true;
    if(root->data<mini || root->data>maxi )   return false;
    
    bool left_child=solve(root->left,mini,root->data-1);
    
    bool right_child=solve(root->right,root->data+1,maxi);
    
    return left_child && right_child ;
}
bool isBST(Node* root) 
{
    return solve(root,-1,100001);
}