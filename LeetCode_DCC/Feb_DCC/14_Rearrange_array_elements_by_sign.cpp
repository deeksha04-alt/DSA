#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) The order of alternate positive and negative has to be maintained , so initialise positive_index with 0 and negative_index with 1 and an empty answer vector.
(2) Run a loop untill you reach the end of input array
    if element at index is greater than zero , set answer vector's postive_index as current input array index, and increment postive_index by 2.
    else set answer vector's negative_index as current input array index, and increment negative_index by 2.   
(3) Return the array.

Complexity Analysis:
(1) TC: O(n)
(2) SC: O(n)
*/

vector<int> rearrangeArray(vector<int>& nums) 
{
    int positive_ind=0,negative_ind=1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)   { ans[positive_ind]=nums[i];positive_ind+=2;   }   
            else            { ans[negative_ind]=nums[i];negative_ind+=2;   }
        }
        return ans;
}