#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://www.geeksforgeeks.org/problems/distinct-occurrences/1

Logic:
(1) String pattern match suggests us to opt for dp approach
(2) Recursive function is explained below:
    (a) Base Case : string t has been matched completely, ie: t-index<0  => return 1
    (b) Condition Check : return 0 if string s index goes beyond 0 .
    (c) Exploring options :
        (1) if characters of both string index matches , 2 possiblilties are there
            (a) we accepted the character of s, and then call for recursive function for remaining part ,
                ie: s_index-1 and t_index-1
            (b) we rejected the current occurrence of character, and check for its presence in remaing part of string s,
                ie: s_index-1 and t_index
        (2) else ,recursive call is made to check for character in remaining part of string s,
                ie: s_index-1 and t_index 
    (d) return the sum of options matched through match and no_match explorations
(3) Memoization is performed through a 2D dp, dp[i][j] denotes the characters at index i and j of string s and t respectively

Complexity Analysis:
(1) TC: O(n*m)
(2) SC: O(n*m)
where, n=> length of string s, m=> length of string m
*/

int mod=1e9+7;
int solve(int s_index,int t_index,string &s,string &t,vector<vector<int>> &dp)
{
    if(t_index<0) return 1;
    if(s_index<0) return 0;
    if(dp[s_index][t_index]!=-1)    return dp[s_index][t_index];
    
    int match=0,nomatch=0;
    if(s[s_index]==t[t_index])  match=solve(s_index-1,t_index-1,s,t,dp)+solve(s_index-1,t_index,s,t,dp);
    else    nomatch=solve(s_index-1,t_index,s,t,dp);

    return dp[s_index][t_index]=(match+nomatch)%mod;
}
int subsequenceCount(string s, string t)
{
    vector<vector<int>> dp(s.size(),vector<int> (t.size(),-1));
    return solve(s.size()-1,t.size()-1,s,t,dp);
}