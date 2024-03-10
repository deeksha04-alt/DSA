#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Create a map to track the presence of elements in nums1 vector.
(2) Traverse nums2 vector , 
    append the element if it has true value in map , and then update its map value as false
(3) Return ans vector

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N) 
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
    unordered_map<int,bool> mp;
    for(auto e: nums1)  mp[e]=true;

    vector<int> ans;
    for(auto e:nums2)
    {
        if(mp[e])   ans.push_back(e),mp[e]=false;
    }
    return ans;  
}