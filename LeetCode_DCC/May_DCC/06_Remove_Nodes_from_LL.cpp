#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Reverse the LL.
(2) Initialise start to head of reversed LL , nbr to the next ptr of start.
(3) Run a loop as long as either start or start_nbr is not pointing to NULL
    a) run a loop and shift the nbr as long as nbr's value is less than start's value.
    b) update start->next to nbr.
    c) if nbr is not NULL , update start to nbr and nbr to nbr's next;
(4) Return reversed LL for reversed_head

Complexity Analysis:
(1) TC: O(N)
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

ListNode* reverse_LL(ListNode* h)
{
    ListNode* prev=NULL;
    ListNode* cur=h;
    while(cur)
    {
        ListNode* f=cur->next;
        cur->next=prev;
        prev=cur;
        cur=f;
    }
    return prev;
}
ListNode* removeNodes(ListNode* head) 
{
    ListNode* reverse_head=reverse_LL(head);
    ListNode* start=reverse_head;
    ListNode* nbr=start->next;

    while(start && nbr)
    {
        while(nbr && nbr->val<start->val)    nbr=nbr->next;
        start->next=nbr;
        if(nbr)        {   start=nbr;nbr=start->next;      }
    }
    return reverse_LL(reverse_head);
}