/*
Logic:
we have implemented the function as follows:
(1) if the root is NULL return {-1,-1}, indicating no minimum , no maximum .
(2) Initialize mint and maxt to root, they denote minimum and maximum value Node respectively .
(3) explore the left subtree of mint , to get the minimum value node of BST .
(4) explore the right subtree of maxt , to get the maximum value node of BST .
(5) return {mint->data, maxt->data}


Complexity Analysis:
(1) TC: O(N) , Number of Node in the BST
(2) SC: O(1) , No additonal space other the pointer refernces is used
*/


pair<int,int> minValue_maxValue(Node* root) {
    if(!root)   return {-1,-1};

    Node* mint = root;
    Node* maxt = root;

    while(mint && mint->left)    mint=mint->left;
    while(maxt && maxt->right)   maxt=maxt->right;
   
    return {mint->data,maxt->data};
}