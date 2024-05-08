#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Use a hashmap to store sum and the corresponding pointer to node which achieves it
(2) Initialise a dummy node to point to input list's head
(3) Traverse the input list and update the sum
    (a) If sum doesn't exist in map, store it .
    (b) else
        (i) Store the repated sum pointer location .
        (ii) Connect it to current node's next . (basically deleting the in-betwwen part as it contributes to a zero sum)
             AS you do so, also remove the sum entries of all these removed nodes from map 
(4) Return dummy's next
*/
class ListNode
{
    public:
        ListNode *next;
        int val;
        ListNode(int v,ListNode* nxt)
        {
            this->val=v;
            this->next = nxt;
        }
};

ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int,ListNode*> mp;
    ListNode* dummy=new ListNode(1001,head);
    mp[0]=dummy;
    int sum=0;
    while(head)
    {
        sum+=head->val;
        if(mp.find(sum)==mp.end())  mp[sum]=head,head=head->next;
        else
        {
            ListNode* tmp=mp[sum]->next;
            int v=sum;
            while(tmp!=head)
            {
                v+=tmp->val;
                mp.erase(v);
                tmp=tmp->next;
            }
            mp[sum]->next=head->next;
            head=head->next;
        }
    }
    return dummy->next;
}
