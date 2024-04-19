#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Contribution of an island cell to permimeter is 4 units, but if ithas adjacent island on its edges it needs to be reduced as we are only concerned with including edges on boundaries
(2) AS you explore surroundings of island cell, reduce its contribution if adjacent island cells are found

Complexity Analysis:
(1) TC: O(N^2)
(2) SC: O(1)
*/
int islandPerimeter(vector<vector<int>>& grid) 
{
    int res=0;
    for(int i=0;i<grid.size();i++) 
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]){ 
                int temp = 4; 
                if((i+1<grid.size() && grid[i+1][j])) temp--; 
                if(j+1<grid[0].size() && grid[i][j+1]) temp--;
                if(i-1>=0 && grid[i-1][j]) temp--; 
                if(j-1>=0 && grid[i][j-1]) temp--; 
                res+=temp;
            }
        }
    }
    return res;
}