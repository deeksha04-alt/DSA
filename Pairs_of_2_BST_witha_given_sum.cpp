/*
Logic:
(1) Store the inorder traversal of both BST's
(2) set the start index to 0 for BST1, end index to last index of inorder_BST2 , countert to zero
(3) Run a loop, till start index is lesser than inorder_BST1.size() end index is greater than -1;
(4) As per the following condition check, proceed
        (a) Case 1: inorder_BST1[start] + inordered_BST2[end] == sum
                    increment the counter by 1 => counter + +
                    increment start index by 1 => start + +
                    decrement end index by 1   => end - -

        (b) Case 2: inorder_BST1[start] + inordered_BST2[end]  > sum
                    decrement end index by 1   => end - -
        
        (c) Case 3: inorder_BST1[start] + inordered_BST2[end] < sum
                    increment start index by 1 = start + +

Complexity Analysis
(1) TC: O(N) (due to inorder traversal) , N: number of Nodes of each BST + O(N) (@ pointer approach to find sum pair) ==> o(N)
(2) SC: O(N1 + N2) for inorder storage of each BST 

*/

void inord(Node* root,vector<int> &temp)
{
    if(!root)  return;
    
    inord(root->left,temp);
    temp.push_back(root->data);
    inord(root->right,temp);
}
int countPairs(Node* root1, Node* root2, int x)
{
    vector<int> inorder_BST1,inorder_BST2;
    inord(root1,inorder_BST1);
    inord(root2,inorder_BST2);

    int start=0, end=inorder_BST2.size()-1 , counter=0;

    while(start < inorder_BST1.size() && end>=0)
    {
        if(inorder_BST1[start]+inorder_BST2[end]==x)
        {
            counter++;
            start++;
            end--;
        }
        else
        {
            if(inorder_BST1[start]+inorder_BST2[end]>x)   end--;
            else    start++;
        }
        
    }
    return counter;

}