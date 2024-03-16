#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Create an unordered map to store cumulative sums and their corresponding indices.
(2) Loop through each element in nums and update sum based on the value of the current element. Check for following conditions: 
    a) If sum becomes 0, update ans with the current index plus 1. ( it means that the subarray from the beginning to the current index has equal count of 0s and 1s.)
    b) else if the current sum has been encountered before (i.e., it exists in the map), calculate the length of the subarray by subtracting the current index from the index where sum was first encountered and update ans if it's greater.
    c) else Update map with the current sum if it's not already present, storing the index of its first occurrence.

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N) 
where N=> number of elements in input array. 
*/

int findMaxLength(vector<int>& nums) 
{
    unordered_map<int,int> sum_index_track_map;
    int ans=0,sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i]==1?1:-1;
        if(sum==0)  ans=i+1;
        else if(sum_index_track_map.find(sum)!=sum_index_track_map.end()) ans=max(ans,i-sum_index_track_map[sum]);
        else sum_index_track_map[sum]=i;
    }
    return ans;
}