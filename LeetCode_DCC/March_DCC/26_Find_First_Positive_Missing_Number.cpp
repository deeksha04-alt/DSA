#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Traverse the input array and try placing the elements with values in the range of [1,n] at their correct index. n=> size of input array .
(2) Retraverse the array , check for absence of element with value i+1 at index i.Return if such absence is found.
(3) Return n+1 

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/

int firstMissingPositive(vector<int>& nums) 
{
    for(int i=0;i<nums.size();i++)
    {
        while(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1])    swap(nums[i],nums[nums[i]-1]);
    }
    for(int i=0;i<nums.size();i++) 
    {
        if(nums[i]!=i+1)    return i+1;
    }
    return nums.size()+1;
}