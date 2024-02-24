#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-ii/

Logic:
(1) Since the description of questions, suggests 3 possible ways ie; exploration of ways, we have opted for dynamic programming
(2) A 2D dp is intialised , where
    dp[i][j] => maximum number of operations that can be performed, such that all operations have the same score(temp) for array starting at index i and ending at index j.
(3) The recursive function is explained below:
    (a) Base condition : when start index passes or equals end index, return 0
    (b) Conditional check : if only 2 elements remaining in the considered part of array , return if sum of both elements is equal to temp.
    (c) return if dp[start][end] is not equal to -1 (memoized part)
    (d) explore 3 available operation moves , 
        1-sum of first and last element of array
        2-sum of first and second element of array
        3-sum of second-last and last element of array
    (e) store the max possible continuous chains from the 3 possible options into dp[start][end].

Complexity Analysis:
(1) TC: O(N^2) , n is the size of input array
(2) SC: O(N^2) , n is the size of input array

*/
int solve(int start,int end,vector<int> &nums,int temp,vector<vector<int>> &dp)
{
    if(start>=end)  return 0;
    if(end-start==1)    return temp==nums[end]+nums[start];
    if(dp[start][end]!=-1)  return dp[start][end];
    
    int start_end_option=nums[start]+nums[end]==temp?1+solve(start+1,end-1,nums,temp,dp):0;
    int first_2_option=nums[start]+nums[start+1]==temp?1+solve(start+2,end,nums,temp,dp):0;
    int last_2_option=nums[end]+nums[end-1]==temp?1+solve(start,end-2,nums,temp,dp):0;
    
    return dp[start][end]=max({start_end_option,first_2_option,last_2_option});
}
int maxOperations(vector<int>& nums) 
{
    int start=0;
    int end=nums.size()-1;
    vector<vector<int>> dp(nums.size(),vector<int> (nums.size(),-1));

    int start_end_option=solve(1,end-1,nums,nums[start]+nums[end],dp);
    int first_2_option=solve(2,end,nums,nums[start]+nums[start+1],dp);
    int last_2_option=solve(0,end-2,nums,nums[end]+nums[end-1],dp);
    return 1+max({start_end_option,first_2_option,last_2_option});
}