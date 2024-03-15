#include<bits/stdc++.h>
using namespace std;

/*
Logic:
An unordered map is used to keep track of the cumulative sums encountered so far and their frequencies.

(1) Initialize ans to 0 and track_map for sum 0 with frequency 1.
(2) Loop through each element in nums, adding it to the previous cumulative sum .
(3) Check if there exists a previous cumulative sum nums[j] such that nums[i] - nums[j] equals the goal. If so, update ans with the frequency of nums[j].
(4) Increment the frequency of the current cumulative sum nums[i] in the track_map.

Complexity Analysis:
(1) TC: O(N)  => N - number of elements in input array
(2) SC: O(N)  => for unordered_map
*/

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int ans=0;
    unordered_map<int,int> track_map;
    track_map[0]=1;
    for(int i=0;i<nums.size();i++)
    {
        if(i>0) nums[i]+=nums[i-1];
        if(track_map[nums[i]-goal])    ans+=track_map[nums[i]-goal];
        track_map[nums[i]]++;
    }
    return ans;
}