#include<bits/stdc++.h>
using namespace std;
/*
Logic:
(1) make a map that stores trust count on an individual .
(2) For every person -a trusting person-b , increment the trust count of b and decrement the trust count of a
(3) Iterate the track map, and find if for an individual the trust count is total individuals -1 , if so return that individual
(4) If no such individual could be found return -1;

Time Complexity:
(1) TC: O(N)
(2) SC: O(N)
N=> number of individuals
*/

int findJudge(int n, vector<vector<int>>& trust) 
{
    unordered_map<int,int> track;
    for(int i=0;i<trust.size();i++)
    {
        track[trust[i][1]]++;
        track[trust[i][0]]--;
    }

    for(int i=1;i<=n;i++)
    {
        if(track[i]==n-1) return i;
    }
    return -1;
}