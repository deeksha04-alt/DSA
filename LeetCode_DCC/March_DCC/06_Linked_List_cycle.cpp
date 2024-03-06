#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Cycle detection using Floyd's Tortoise and Hare algorithm ( slow and fast pointers ).
(2) Slow pointer's next is pointed to head, and fast pointer points at head.
(3) Run a loop till fast and fast->next are not null
    return True if slow and fast pointer are at same address.
    Move slow pointer by 1 step.
    Move fast pointer by 2 steps.
(4) Return false

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)  
*/

class ListNode
{
    public:
        int val;
        ListNode *next;

        ListNode(int x)
        {
            this->val = x;
            this->next = NULL;
        }
};

bool hasCycle(ListNode *head) 
{
    ListNode* slow=new ListNode(-1);
    slow->next=head;
    ListNode* fast=head;

    while(fast && fast->next)
    {
        if(slow==fast)  return true;
        slow=slow->next;
        fast=fast->next->next;        
    }
    return false;
}