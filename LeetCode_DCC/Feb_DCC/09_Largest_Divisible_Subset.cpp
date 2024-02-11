#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Sort the given array to get the largest possible subset
(2) Declare a 2D dp where , 
            dp[end][start] = subset of elements begining at index start and end at index end 
            such that each pair in this range of subset satisfies nums[end]%nums[start]==0 || nums[start]%nums[end]==0
(3) For each subset range , update dp[end] with dp[start] if current dp size is lesser than dp[start] size
(4) At the end of inner loop , append the last element ie: dp[end] of considered subset. 
(5) update ans vector to current dp if current dp size is greater than ans vector size
Complexity Analysis:
(1) TC: O(n^2)
(2) SC: O(n^2) + O(n)
        O(n^2) => for dp
        O(n)   => for answer vector

*/

vector<int> largestDivisibleSubset(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<int> ans;
    vector<vector<int>> dp(n);
    for(int end=0;end<n;end++)
    {
        for(int start=0;start<end;start++)
        {
            if(nums[end]%nums[start]==0 || nums[start]%nums[end]==0)
            {
                dp[end]=dp[end].size()<dp[start].size()?dp[start]:dp[end];
            }
        }
        dp[end].push_back(nums[end]);
        if(ans.size()<dp[end].size()) ans=dp[end];
    }
    return ans;
}