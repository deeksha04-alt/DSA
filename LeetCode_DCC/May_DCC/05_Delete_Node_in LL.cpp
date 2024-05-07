#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Store the node immediate right to the given input node
(2) Copy its value into given input node and update input node's next pointer to the next of next_to_del_node.
(3) Delete next_to_del_node

Complexity Analysis:
(1) TC: O(1)
(2) SC: O(1)
*/
class ListNode
{
    public:
        ListNode *next;
        int val;
        ListNode()
        {
            this->val = 0;
            this->next = NULL;
        }
        ListNode(int v)
        {
            this->val = v;
            this->next = NULL;
        }
};

void deleteNode(ListNode* node) 
{
    ListNode* next_to_del_node=node->next;
    node->val=next_to_del_node->val;
    node->next=next_to_del_node->next;
    delete(next_to_del_node);
}