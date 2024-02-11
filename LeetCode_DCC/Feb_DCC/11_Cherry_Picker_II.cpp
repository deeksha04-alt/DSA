#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Declare a 3D dp of dimensions nXmXm,
            where, dp[i1][i2][i3] denote position of robot-1 and robot-2 in row i1 at column i2 and i3 respectively .
(2) Base condition , if  robots reach last row of the grid ,
            check if both are in the same cell ie; rob1_col == rob2_col , and accordingly add the values of cell

(3) Valid position check , return 0 if any of the 2 robots go outside of the grid
(4) Explore all 9 combination moves 

Time Complexity : O(n^3)
Space Complexity : O(n^3)
*/
int solve(int row,int rob1_col,int rob2_col,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
{
    if(row>=grid.size() || rob1_col<0 || rob1_col>=grid[0].size() || rob2_col<0 || rob2_col>=grid[0].size() )    return 0;

    if(row==(grid.size()-1))
    {
        return rob1_col==rob2_col?grid[row][rob1_col]:grid[row][rob1_col]+grid[row][rob2_col];
    }
    if(dp[row][rob1_col][rob2_col]!=-1)  return dp[row][rob1_col][rob2_col];
    
    int v=grid[row][rob1_col];
    if(rob1_col!=rob2_col)  v+=grid[row][rob2_col];
    
    //all possible 9 combinations
    int dd=v+solve(row+1,rob1_col,rob2_col,grid,dp);                        //down-down
    int dddl=v+solve(row+1,rob1_col,rob2_col-1,grid,dp);                    //down - downleft
    int dddr=v+solve(row+1,rob1_col,rob2_col+1,grid,dp);                    //down - downright

    int dldd=v+solve(row+1,rob1_col-1,rob2_col,grid,dp);                    //downleft - down
    int dldl=v+solve(row+1,rob1_col-1,rob2_col-1,grid,dp);                  //downleft - downleft
    int dldr=v+solve(row+1,rob1_col-1,rob2_col+1,grid,dp);                  //downleft - downright

    int drdd=v+solve(row+1,rob1_col+1,rob2_col,grid,dp);                    //downright - down
    int drdl=v+solve(row+1,rob1_col+1,rob2_col-1,grid,dp);                  //downright - downleft
    int drdr=v+solve(row+1,rob1_col+1,rob2_col+1,grid,dp);                  //downright - downright

    return dp[row][rob1_col][rob2_col]=max({dd,dddl,dddr,dldd,dldl,dldr,drdd,drdl,drdr});
}

int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();int m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
    return solve(0,0,grid[0].size()-1,grid,dp);
}