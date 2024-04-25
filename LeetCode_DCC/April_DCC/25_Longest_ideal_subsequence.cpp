#include<bits/stdc++.h>
using namespace std;

/*
Logic: DP take-not take
(1) decalre a dp of size (n+1) X(126)
(2) dp[i][j] contains maximum length of subsequence till index i and last chosen character j
(3) For every index we have 2 choices : 
    - not take =>  call by incrementing index and choice remains same
    - take     => call by incrementing index and changing choice to current character
    (take is applicable only if absolute difference of current index and last choice is less than k)
(4) return max of take and not take in dp[index][choice]

Complexity Analysis:
(1) TC: O(N^2)
(2) SC: O(N^2)

 */
int solve(int index,int choice,string &s,int k,vector<vector<int>> &dp)
{
    if(index>=s.size()) return 0;
    if(dp[index][choice]!=-1)    return dp[index][choice];
    int not_take=solve(index+1,choice,s,k,dp);
    int take=0;
    if(choice==96 || abs(s[index]-(char)choice)<=k )  take=1+solve(index+1,s[index]-0,s,k,dp);
    return dp[index][choice]=max(take,not_take);
}
int longestIdealString(string s, int k) 
{
    int n=s.size();
    vector<vector<int>> dp(n+1,vector<int> (124,-1));
    return solve(0,96,s,k,dp);
}