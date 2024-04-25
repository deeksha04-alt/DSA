#include<bits/stdc++.h>
using namespace std;
/*
Logic: BFS
(1) At max 2 root nodes possible for min_height => depends on odd / even number of nodes
(2) Make an adjacency map and indegree list for all nodes
(3) Push the nodes with indegree 1 into queue => leaf nodes in this case
(4) AS you process each level of leaf nodes , perform following ops
        - Store all the nbr nodes in answer vector  
        - Keep reducing the indegree of adjacent nbr nodes , and push them into queue if indegree becomes 1
(5) AS you process each level of leaf nodes , clear the answer vector and refill it through current neighbours, this helps to finally have only the possible root nodes for min-height trees

*/
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int> ans;
        unordered_map<int,vector<int>> mp;
        vector<int> indeg(n,0);
        for(int i=0;i<n-1;i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            indeg[edges[i][0]]++;
            indeg[edges[i][1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==1) q.push(i);
        }

        while(!q.empty())
        {
            int size=q.size();
            ans.clear();
            while(size--)
            {
                auto f=q.front();q.pop();
                ans.push_back(f);
               
                for(auto nbr:mp[f])
                {
                    indeg[nbr]--;
                    if(indeg[nbr]==1)    q.push(nbr);
                }

            }            
        }
        if(n==1)    ans.push_back(0);
        return ans;
    }