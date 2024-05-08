#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Intialise a flag variable to true , this dislays whether new interval has been inserted or not
(2) While traversing input intervals , check for following
    (a) if new interval is smaller than first interval => insert new interval into answer and negate flag.
    (b) if flag is true and new interval begin point lies within current interval => insert an interval that covers both of them ie ;
                    {min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[i][1])}
    (c) else
            if current interval start point is ahead of end point of last inerted interval => insert current interval
            else    update the last inserted interval such that it contains both 
                    ans.back()[0]=min(ans.back()[0],intervals[i][0]);
                    ans.back()[1]=max(ans.back()[1],intervals[i][1]);                    
(3) Return ans.

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
*/

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
    vector<vector<int>> ans;
    bool flag=true;

    for(int i=0;i<intervals.size();i++)
    {
        if(flag && newInterval[0]<intervals[i][0])
        {
            ans.push_back(newInterval);flag=false;
        }

        if(flag && newInterval[0]>=intervals[i][0] && newInterval[0]<=intervals[i][1]  )  
        {
            ans.push_back({min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[i][1])});
            flag=false;
        }
        else
        {
            if(ans.size()==0 || intervals[i][0]>ans.back()[1])   ans.push_back(intervals[i]);
            else
            {    ans.back()[0]=min(ans.back()[0],intervals[i][0]);
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
    }
    if(flag)   ans.push_back(newInterval);
    return ans;
}