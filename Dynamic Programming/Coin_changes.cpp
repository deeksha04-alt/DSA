#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://leetcode.com/problems/coin-change/description/
*/

int coinChange(vector<int>& coins, int amount) 
{
    int n=coins.size();
    vector<int> dp(amount + 1, (amount + 1));
    dp[0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            if(coins[i-1]<=j)   dp[j]=min(1+dp[j-coins[i-1]],dp[j]);
        }
    }
    return dp[amount]>amount?-1:dp[amount];
}