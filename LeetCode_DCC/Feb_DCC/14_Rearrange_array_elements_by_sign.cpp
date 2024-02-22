#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) The order of alternate positive and negative has to be maintained , so initialise positive_index with 0 and negative_index with 1.
(2) Run a loop untill both the indexes are less than size of input array
    if element at positiveindex is greater than zero , increment positve index with 2
    if element at negative index is less than zero , increment negative index by 2
    else swap the elements at positive and negative indexes.
(3) Return the array.

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/

vector<int> rearrangeArray(vector<int>& nums) 
{
    int positive_ind=0,negative_ind=1;
    while(positive_ind<nums.size() && negative_ind<nums.size())
    {
        if(nums[positive_ind]>0)   positive_ind+=2;
        else if(nums[negative_ind]<0)  negative_ind+=2;
        else swap(nums[positive_ind],nums[negative_ind]);
    }
    return nums;
    
}