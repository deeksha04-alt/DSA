#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Find the node previous to ath node and next node to bth node in linked list 1.
(2) Attach the linked list 2 in between previous node and next node of ath and bth nodes of LL1.

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

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* prev=NULL;
    ListNode* ans_head=list1;
    int c=0;
    while(list1 && c<a)
    {
        prev=list1;
        list1=list1->next;
        c++;
    }
    while(list1 && c<=b)   list1=list1->next,c++;
    prev->next=list2;
    while(list2 && list2->next)    list2=list2->next;
    list2->next=list1;
    return ans_head; 
}