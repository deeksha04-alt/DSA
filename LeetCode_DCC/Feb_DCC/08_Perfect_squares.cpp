#include<bits/stdc++.h>
using namespace std;

/*
Logic:
Following initialisations are made 
(1) target_number = sum of squared_num falling in the range of (1,k), 
    such that squared_num*squared_num <= target_number
(2) For each sqaured_number satisfying above condition , we have 2 choices
        (a) exclude it
        (b) include it if squared_num*squared_num < = target_number
(3) The base case would be if either
    (a) target number = 0
    (b) sqared_num =1  , if squared_num =1 , you will have to add 1 target_number times;
    Return target_number in both cases

(4) Thereby we have declared a 2D dp of size dp[n+1][k+1], 
 where k =square_root of n, because the numbers to be considered for generating a squared sum series would belong to 1 to k only. 



Complexity Analysis:
(1) TC: O(n^2)  , since we have memoized , in absence of memoization , it would be 2^n .
(2) SC: O(n^2)  , 2D dp vector used in memoization

*/

int solve(int target_num,int squared_num_series[],int i,vector<vector<int>> &dp)
{
    if(target_num==0)    return 0;
    if(i==1)    return target_num;
    if(dp[target_num][i]!=-1)    return dp[target_num][i];
    int exc=solve(target_num,squared_num_series,i-1,dp);
    int inc=INT_MAX;
    if(squared_num_series[i]*squared_num_series[i]<=target_num)    inc=1+solve(target_num-(squared_num_series[i]*squared_num_series[i]),squared_num_series,i,dp);

    return dp[target_num][i]=min(inc,exc);
    

}
int numSquares(int target_num) 
{
    int k=sqrt(target_num);

    int squared_num_series[k+1];
    for(int i=0;i<=k;i++) squared_num_series[i]=i;
    
    vector<vector<int>> dp(target_num+1,vector<int> (k+1,-1) );
    
    return solve(target_num,squared_num_series,k,dp);
    
}