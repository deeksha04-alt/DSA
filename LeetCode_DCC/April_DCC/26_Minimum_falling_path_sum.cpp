#include<bits/stdc++.h>
using namespace std;

//Memoization
int solve(int n,vector<vector<int>> &grid,int row,int prev_col,vector<vector<int>> &dp)
{
    if(row==n)  return    0;
    if(dp[row][prev_col]!=-1)   return dp[row][prev_col];
    int ans=INT_MAX;
    for(int cur_col=0;cur_col<n;cur_col++)
    {
        if(cur_col==prev_col)   continue;
        int temp=grid[row][cur_col]+solve(n,grid,row+1,cur_col,dp);
        ans=min(ans,temp);            
    }
    return dp[row][prev_col]=ans;         
}
int minFallingPathSum(vector<vector<int>>& grid) 
{
    int n = grid.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    return solve(n,grid,0,n,dp);
}

//Tabulation

int minFallingPathSum(vector<vector<int>>& grid) 
{
    int n=grid.size();
    vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
    for(int row=0;row<n;row++)    dp[0][row]=grid[0][row];

    for(int row=1;row<n;row++)
    {
        for(int prev_col=0;prev_col<n;prev_col++)
        {
            int temp=INT_MAX;
            for(int cur_col=0;cur_col<n;cur_col++)
            {
                if(cur_col!=prev_col && temp>dp[row-1][cur_col])    temp=dp[row-1][cur_col];

            }
            dp[row][prev_col]=grid[row][prev_col]+temp;
        }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}
