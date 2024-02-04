/*
Logic: 
(1) use a recursive function- inorder to get inorder traversal of each BST
(2) Since the inorder traversal of BST gives a sorted list of elements, therfore ,
we can compare respective elemenets of inorder vectors to fill the elements in the answer vector 


Complexity Analysis: 
TC: O(N1+N2)+ O(N1)+O(N2) ,  Ni-number of nodes in BSTi , 
    
SC: O(N1+N2) + O(N1) + O(N2) , N1 and N2 are sizes of BST1 and BST2 respectively.
    space is utilised to store inorder traversals of each BST plus for the anser vector
    (Apart from it recursive stack space is also used in recursive inorder function)
*/

void inorder(Node* root,vector<int> &temp)
{
    if(!root)  return;
    inorder(root->left,temp);
    temp.push_back(root->data);
    inorder(root->right,temp);
}



vector<int> merge(Node *root1, Node *root2)
{
    vector<int> inorder_root1;
    vector<int> inorder_root2;
    inorder(root1,inorder_root1);
    inorder(root2,inorder_root2);

    vector<int> ans(inorder_root1.size()+inorder_root2.size(),0);
    int ans_ind=0;
    int ind1=0,ind2=0;
    while(ind1<inorder_root1.size() && ind2<inorder_root2.size())
    {
        if(inorder_root1[ind1]<inorder_root2[ind2])     ans[ans_ind++]=inorder_root1[ind1++];
        
        else    ans[ans_ind++]=inorder_root2[ind2++];
        
    }
    while(ind1<inorder_root1.size())  ans[ans_ind++]=inorder_root1[ind1++];
    while(ind2<inorder_root2.size())  ans[ans_ind++]=inorder_root2[ind2++];

    return ans;
}