#include<bits/stdc++.h>
using namespace std;

/*
Logic: DFS
(1) Apply dfs from start node
(2) return visit value of destination node 
*/
bool dfs(int node,int destination,unordered_map<int,vector<int>> &mp,vector<bool> &vis)
    {
        vis[node]=true;
        if(node==destination)    return true;
        for(auto nbr:mp[node])
        {
            if(!vis[nbr]) 
            {
                if(dfs(nbr,destination,mp,vis))   return true;
            }  
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        unordered_map<int,vector<int>> mp;vector<bool> vis(n,false);
        for(auto e:edges)
        {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        return dfs(source,destination,mp,vis)  ;      
    }