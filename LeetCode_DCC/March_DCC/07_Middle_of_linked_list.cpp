#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Two pointer slow-fast approach is implemented here.
(2) slow and fast pointers point to the head of the list. 
(3) Loop is run unitll fast pointer reaches the last node of linked list 
    fast pointer moves twice as fast as the slow pointer, ensuring that when fast reaches the end of the list, slow will be at the middle.
(4) Return slow pointer

Complexity Analysis:
(1) TC: O(N) , N=> number of nodes in linked list
(2) SC: o(1)
*/

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int v)
    {
        this->val=v;
        this->next = NULL;
    }
};

ListNode* middleNode(ListNode* head) 
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}