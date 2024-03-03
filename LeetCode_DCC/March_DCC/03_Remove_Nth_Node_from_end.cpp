#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Using slow-fast pointer approach we proceed to find the nth node from end . Both slow and fast point to head node initially.
(2) We move the fast pointer by n steps from the begining .
(3) Till fast and fast's next aren't null, we move both slow and fast, thereby getting at the node previous to target node through slow pointer.
(4) If the fast pointer is NULL ==> indicating head node is to be removed , therefore we return head's next.
(5) else , link the slow pointer with target node's next and return head .

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode* fast=head;
    ListNode* slow=head;
    
    for(int i=0;i<n;i++)    fast=fast->next;
    while(fast && fast->next)
    {
        slow=slow->next;fast=fast->next;
    }
    if(!fast)  return head->next;
    else    slow->next=slow->next->next;
    return head;
    
}