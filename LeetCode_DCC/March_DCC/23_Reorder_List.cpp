#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Find the mid point of original list and store the reverse the list from mid into list2.
(2) Consider original list as 2 parts 
    list1 => head till midnode-1
    list2 => midnode till end .
(3) Manipulate the links to perform the required reordering.

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/
class ListNode
{
    public:
        int val;
        ListNode *next;

        ListNode(int v)
        {
            this->val = v;
            this->next = NULL;
        }
};

ListNode* getMid(ListNode* h)
{
    ListNode* fast=h;
    ListNode* slow=h;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* rev(ListNode* h)
{
    ListNode* cur=h;
    ListNode* prev=NULL;
    while(cur)
    {
        ListNode* f=cur->next;
        cur->next=prev;
        prev=cur;
        cur=f;
    }
    return prev;
}
void reorderList(ListNode* head) 
{
    if(!head || !head->next)    return ;
    ListNode* list1=head,*tail1=list1;
    ListNode* mid=getMid(head);
    ListNode* list2=rev(mid);
    while(tail1 && tail1->next!=mid)    tail1=tail1->next;
    tail1->next=NULL;

    while(list1 && list2)
    {
        ListNode* f1=list1->next;
        ListNode* f2=list2->next;
        list1->next=list2;
        if(f1)        list2->next=f1;
        list1=f1;
        list2=f2;
    }      
}