#include<bits/stdc++.h>>
using namespace std;

/*
Logic:
(1) Sort the intervals based on start points. If start points are equal,sort based on end points.  [increasing order]. 
(2) Merging the Overlapping Intervals - 
    (a) Overlap    : starting point of the current interval (points[i][0]) <= ending point of the previous interval (points[prev_slot][1]), 
        Updates the ending point of the previous interval to the minimum of its current ending point and the ending point of the current interval (points[i][1]).
    (b) No overlap : increments prev_slot and assign the current interval to points[prev_slot]
(3) Return prev_slot+1 => count of arrows.

Complexity Analysis:
(1) TC: O(nlogn)
(2) SC: O(1)
*/

bool static comp(vector<int> &a,vector<int> &b)
{
    if(a[0]==b[0])  return a[1]<=b[1];
    return a[0]<b[0];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(),points.end(),comp);
    int prev_slot=0;
    for(int i=1;i<points.size();i++)
    {
        if(points[i][0]<=points[prev_slot][1])     points[prev_slot][1]=min(points[prev_slot][1],points[i][1]);
        else                                       points[++prev_slot]=points[i];
    }
    return prev_slot+1;   
}