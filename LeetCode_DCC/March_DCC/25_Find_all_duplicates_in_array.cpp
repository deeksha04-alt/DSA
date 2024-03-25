#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) During traversal , perform following operations :
    - Find the zero based index of current element .
    - Make the element at calculated index negative , indicating first visit.
    - append the current element in answer vector if the element at calculated index is positive .
    [Positive value indicates second visit ] 

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)

*/
vector<int> findDuplicates(vector<int>& nums) 
{
    vector<int> ans;
    for(int i=0;i<nums.size();i++)
    {
        int ind=abs(nums[i])-1;
        nums[ind]=nums[ind]*(-1);
        if(nums[ind]>0)   ans.push_back(abs(nums[i]));
    }
    return ans;
}