#include<bits/stdc++.h>>
using namespace std;

/*
Logic:
(1) Initialise start ,end and ans variabl with zero.
(2) As you traverse the loop , perform following operations:
    - increment current element frequency ie; freq[nums[end]]++;
    - while frequency of current element is greater than k , reduce the window size , by incrementing start index.
    - store maximum of ans and current window size in ans.

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
*/

int maxSubarrayLength(vector<int>& nums, int k) 
{
    unordered_map<int,int> freq;
    int start=0,end=0,ans=0;
    while(end<nums.size())
    {
        freq[nums[end]]++;
        while(start<end && freq[nums[end]]>k)      freq[nums[start++]]--;
        ans=max(ans,end-start+1);
        end++;
    }
    return ans;
    
}