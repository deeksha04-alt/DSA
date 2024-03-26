#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Sort the input vector.
(2) Expand window size :  if nums[start]+k >= nums[end]-k
    ie; upon addition of k to start of window we can easily surpass (end of window -k) point .
(3) If above operation isn't possible, contract the window => increment start point of window .

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/

int maximumBeauty(vector<int>& nums, int k) 
{
    sort(nums.begin(),nums.end());
    int start=0,end=0,ans=0;
    while(end<nums.size())
    {
        if(nums[end]-nums[start]<=2*k) 
        {
            ans=max(ans,end-start+1);end++;
        }
        else    start++;
    }
    return ans;        
}