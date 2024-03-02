#include<bits/stdc++.h>
using namespace std;
/*
Logic:
(1) Find the negative elements in input array
(2) Intialise neg_ind to negcount-1 and pos_ind to neg_count.
(3) Fill the answer vector in a way similar to merging two sorted lists 
    (a) List 1 of negative numbers => that begins at neg_ind and goes till 0th index.
    (b) List 2 of positive numbers => begins at pos_ind and continues till the size of input array

Complexity Analysis:
(1) TC: O(n) , n=> number of elments in input array
(2) SC: O(n) , for storing answer vector 
*/

vector<int> sortedSquares(vector<int>& nums) 
{
    int neg_count=0;
    while(neg_count<nums.size() && nums[neg_count]<0)  neg_count++;

    int pos_ind=neg_count;
    int neg_ind=neg_count-1;
    vector<int> ans(nums.size());
    int ansind=0;

    while(neg_ind>=0 && pos_ind<nums.size())
    {
        if(nums[pos_ind]<=abs(nums[neg_ind]))  
        {ans[ansind++]=nums[pos_ind]*nums[pos_ind];pos_ind++;}
        else     
        {ans[ansind++]=nums[neg_ind]*nums[neg_ind];neg_ind--;}
    }
    while(neg_ind>=0)              {ans[ansind++]=nums[neg_ind]*nums[neg_ind];neg_ind--;}
    while(pos_ind<nums.size())     {ans[ansind++]=nums[pos_ind]*nums[pos_ind];pos_ind++;}
    
    return ans;
}