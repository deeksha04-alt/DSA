#include<bits/stdc++.h>
using namespace std;

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

ListNode* reverseList(ListNode* head) 
{
    ListNode* prev=NULL;
    ListNode* cur=head;
    while(cur)
    {
        ListNode* f=cur->next;
        cur->next=prev;
        prev=cur;
        cur=f;
    }
    return prev;
}