#include<bits/stdc++.h>
using namespace std;

/*
Logic: 
(1) Majority elment is the element that has a frequency greater than n/2 , (n=> size of array)
(2) Initialise a frequency count to 0, and answer to first element .
(3) As you traverse the input array, 
    (a) if ans doesn't match the current element, decrement the frequency count .if frequency count becomes 0, set answer to current element and frequency count to 1
    (b) else increment the frequency count.
(4) return the answer.

Complexity Analysis:
(1) TC: O(N), N=> size of input array
(2) SC: O(1)
*/
int majorityElement(vector<int>& nums) 
{
    int ans=nums[0];
    int frequency_count=1;
    for(int ind=1;ind<nums.size();ind++)
    {
        if(nums[ind]!=ans)
        {
            frequency_count--;
            if(frequency_count==0)
            { ans=nums[ind];frequency_count=1;}
            
        }
        else frequency_count++;
    }
    return ans;
    
}