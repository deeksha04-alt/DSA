#include<bits/stdc++.h>
using namespace std;

//dfs approach
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool valid(int x,int y,vector<vector<bool>> &vis,vector<vector<char>> &grid)
{
    return !(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || vis[x][y] || grid[x][y]=='0');
}
void dfs(int x,int y,vector<vector<char>> &grid,vector<vector<bool>> &vis)
{
    vis[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(valid(nx,ny,vis,grid))     dfs(nx,ny,grid,vis);
    }
    }
    int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    int ans=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]=='1')
            {
                dfs(i,j,grid,vis);
                ans++;
            }
        }
    }
    return ans;

}

//bfs approach
// typedef pair<int, int> p;
// int numIslands(vector<vector<char>> &grid)
// {
//     int n = grid.size(), m = grid[0].size(), ans = 0;
//     queue<p> q;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(grid[i][j]=='1')
//             {
//                 grid[i][j]='0';
//                 q.push({i,j});
//                 while(!q.empty())
//                 {
//                     auto t=q.front();q.pop();
//                     for(int i=0;i<4;i++)
//                     {
//                         int nx=t.first+dx[i],ny=t.second+dy[i];
//                         if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1')
//                         {
//                             q.push({nx,ny});
//                             grid[nx][ny]='0';
//                         }
//                     }
//                 }
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }
