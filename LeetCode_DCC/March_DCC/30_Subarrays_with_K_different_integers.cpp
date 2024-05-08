#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) To get count of subarrays with exact k unique elements => subarrays with atmost K unique elements - subarrays with atmost k-1 unique elements

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/
int k_most(vector<int> &nums,int k)
{
    int start=0,end=0,n=nums.size(),ans=0;
    unordered_map<int,int> mp;
    while(end<n)
    {
        mp[nums[end]]++;
        while(mp.size()>k)
        {
            mp[nums[start]]--;
            if(mp[nums[start]]==0)  mp.erase(nums[start]);
            start++;
        }

        ans+=end-start+1;
        end++;

    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) 
{
    return k_most(nums,k)-k_most(nums,k-1);
}