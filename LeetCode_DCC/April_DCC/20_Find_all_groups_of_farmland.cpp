#include<bits/stdc++.h>
using namespace std;

/*
(1) For every cell with value 1 , explore land's boundaries
    - check for all the columns in row i [for columns greater than current column j] with cells value 1
    - check for all the rows in column j [for rows greater than current row i] with cell value 1
    - Thereby ,
        Farmland start point => i, j
        Farmland end point   => max(row-1,i),max(col-1,j)
    - Mark all the cells is above region to be zero .
    - store the start and end point coordinates of farmland into answer vector
(2) Return ans

Compelexity Analysis:
(1) TC: O(N^2)
(2) SC: O(1)
*/
vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size();
    int n = land[0].size();
    
    vector<vector<int>> result;
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) 
        {
            if(land[i][j] == 0) continue;

            int column = j,row=i;
            while(column < n && land[i][column] == 1) column++;
            while(row < m && land[row][j] == 1)     row++;
            
            column = column==0 ? column : column-1;
            row = row==0 ? row : row-1;

            result.push_back({i, j, row, column});
            
            for(int row_start = i; row_start<=row; row_start++) 
            {
                for(int col_start = j; col_start<=column; col_start++) 
                    land[row_start][col_start] = 0;

            }
        }
    }
    return result;
}