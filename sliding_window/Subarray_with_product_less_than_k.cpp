#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Sliding window approach -
    - Initialise start, end and prod.
    - During array traversal incorporate the current element in product.
    - while product is greater than equal to k , reduce the window size by incrementing start index and altering the product
    - Update answer with current window size -1 with product less than k ,ie; end-start
    - Run a separate loop, and for each element lesser than k ,increment answer by 1

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/

int numSubarrayProductLessThanK(vector<int>& nums, int k) 
{
    int start=0,end=0,ans=0;
    int prod=1;
    while(end<nums.size())
    {
        prod*=nums[end];
        while(start<end && prod>=k)    prod/=nums[start++];
        ans+=(end-start+1);           
        end++;
    }
    return ans;
}