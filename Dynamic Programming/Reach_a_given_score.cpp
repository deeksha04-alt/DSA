#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

Logic:
(1) The question is similar to generation of distinct permutations for a given sum by exploring sum through 3 options, the availability of options to reach our sum suggests the use of dp
(2) Create a 1D dp of size N+1, intialise it with 0
(3) here , dp[i] => number of distinct ways to make sum i.
(4) so intialise dp[0] with 1 .
(5) since we have to get distinct ways to get sum i , we iterate over the 3 options separately, where 
        dp[i] = dp[i-option] , (ATQ options are 3, 5,and 10)
(6) Return dp[n] 

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
where N , is the input number
*/

long long int count(long long int n)
{
    vector<long long int> dp(n+1,0);
    dp[0]=1;
    for(int i=3;i<=n;i++)   dp[i]+=dp[i-3];
    for(int i=5;i<=n;i++)   dp[i]+=dp[i-5];
    for(int i=10;i<=n;i++)   dp[i]+=dp[i-10];
    return dp[n];
}