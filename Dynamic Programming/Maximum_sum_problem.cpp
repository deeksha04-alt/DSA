#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1

Logic:
(1) Since, we have to explore options for each divided part of number , we have opted for dp
(2) The recursive program is implemented as follows :
    (a) Base Case: when divided parts sum is lesser than or equal to the given number, return the number
    (b) recursively call the function for 3 divided parts => n/2 , n/3 , n/4
(3) we have memoized it using a 1D dp of size equal to number n. 

Complexity Analysis:
(1) TC: O(N), n=> input number
(2) SC: O(N), n=> input number
*/
int solve(int n,vector<int> &dp)
{
    if(n/2 + n/3+ n/4 <=n)  return n;
    if(dp[n]!=-1)   return dp[n];
    return solve(n/2,dp) +solve(n/3,dp) + solve(n/4,dp);
}
int maxSum(int n)
{  
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}