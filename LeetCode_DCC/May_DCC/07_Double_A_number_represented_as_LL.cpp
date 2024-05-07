#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Reverse the LL, the 2 numbers to be added are represented by reversed LL head.
(2) Initialise sum , rem with zero and keep answer pointers head and tail to be NULL.
(3) Run a loop as long as => any of pointers are NOT NULL or remainder is non 0
(4) Return Reverse LL obtained in answer head. 

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
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
ListNode* doubleIt(ListNode* head) 
{
    ListNode* reverse_head=reverse_LL(head);
    ListNode* num1=reverse_head,*num2=reverse_head;
    
    int sum=0,rem=0;
    ListNode* ans_head=NULL,*ans_tail=NULL;

    while((num1 && num2) || (rem))
    {
        int val1=0,val2=0;
        if(num1)            {   val1=num1->val;num1=num1->next;     }
        if(num2)            {   val2=num2->val;num2=num2->next;     }
        
        int dig=rem+val1+val2;
        rem=dig/10;
        
        ListNode* temp=new ListNode(dig%10);
        if(!ans_head)        {   ans_head=temp;ans_tail=temp;      }
        else                 {   ans_tail->next=temp;ans_tail=temp;}
        
    }
    return reverse_LL(ans_head);   
}