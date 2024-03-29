#include<bits/stdc++.h>>
using namespace std;

/*
Logic:
(1) Find the maximum element of input array and initialise start and end with zero.
(2) While traversing the array , do the following operations:
    - Decrement k : if current element is maximum element 
    - Contraction of window : while k is zero 
                              if start element of window is maximum element , increment k
                              increment start index of window
    - Add start index to ans showing all the elements before it would contribute to a window where max element would have occurred at least k times till considered window end.
(3) Return ans

Complexiy Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/
long long countSubarrays(vector<int>& nums, int k) 
{
    int max_elem=*max_element(nums.begin(),nums.end());
    int start=0,end=0;
    long long ans=0;
    while(end<nums.size())
    {
        if(nums[end]==max_elem)    k--;
        while(!k)
        {
            if(nums[start++]==max_elem)       k++;
        }    
        ans+=start;
        end++;
    }
    return ans;
        
}