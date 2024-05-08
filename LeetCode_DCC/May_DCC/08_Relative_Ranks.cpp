#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Store sorted score into another array.
(2) Map the score with positions.
(3) Using the map return their positions.

Complexity Analysis:
(1) TC: O(nlogn)
(2) SC: O(n)
*/

vector<string> findRelativeRanks(vector<int>& score) 
{
    vector<int> temp(score.begin(),score.end());
    sort(temp.begin(),temp.end());
    unordered_map<int,string> order;
    vector<string> ans;
    int n=temp.size();

    order[temp[n-1]]="Gold Medal";
    if(n>=2)    order[temp[n-2]]="Silver Medal";
    if(n>=3)    order[temp[n-3]]="Bronze Medal";
    for(int i=n-4,position=4;i>=0;i--,position++) order[temp[i]]=to_string(position);

    for(auto e:score)   ans.push_back(order[e]);
    return ans;

}