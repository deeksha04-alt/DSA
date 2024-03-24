#include<bits/stdc++.h>
using namespace std;

/*
Logic: 
[Cycle detection + Start point of Cycle]
(1) Implemented slow-fast Floyd Algorithm
(2) Initialise slow and fast to first element , and moving them by single and dpuble step untill both get same value.
(3) Then reintialise slow to begining and move slow and fast by single step untill bth have same value,
(4) Return slow.


Note :
(1) Loop 1 : detects the cycle by finding a position where both slow and fast have same value , not necessarily the duplicate element.
(2) Loop 2 : To detect the start point of cycle ie: duplicate element

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/

int findDuplicate(vector<int>& nums) 
{
    int slow = nums[0];
    int fast = nums[0];
    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)        break;
    }
    slow = nums[0];
    while (slow != fast) 
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;        
}