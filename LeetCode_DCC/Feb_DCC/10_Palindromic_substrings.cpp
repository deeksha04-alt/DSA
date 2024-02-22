#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Since , we have to consider the different palindromic substrings within a string, we have opted for dp approach.
(2) We have initialised a 2D dp of dimensions , nXn, n=> size of input string, a counter with 0
    dp[i][j] shows if substring that begins at index i and ends at index j is a palindrome
(3) The outer loop(start) begins from last index till 0th inex of input string,and inner loop(end) moves from outer loop index till last index of input string ,
    following cases are seen :
    (1) start == end , single sized substring , it is a palindrome so set it to 1
    (2) end = start+1 , length 2 sized palindrome, set it to 1 if both s[start]==s[end]
    (3) else , if s[start]=s[end], check for reduced substring part ie: substring that begins at start+1 and ends at end-1 , and accordingly update dp[start][end]
(4) add dp[start][end] to count.

Complexity Analysis:
(1) TC: O(n^2) , n=> size of input string
(2) SC: O(n^2) , n=> size of input string
*/
int countSubstrings(string s) 
{
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int count = 0;
    for(int start = s.size() - 1; start >= 0; --start) {
        for(int end = start; end < s.size(); ++end) 
        {
            if (start == end)                 dp[start][end] = 1;
            else if (start + 1 == end)        dp[start][end] = s[start] == s[end] ? 1 : 0;
            else                              dp[start][end] = s[start] == s[end] ? dp[start+1][end-1] : 0;
            
            count += dp[start][end];
        }
    }
    return count;
}