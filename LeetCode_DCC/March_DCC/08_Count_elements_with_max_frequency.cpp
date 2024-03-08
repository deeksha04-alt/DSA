#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Use a map to track the frequency of elements in input array.
(2) find the maximum frequency achieved for an element and append the number of elements in array with frequency equal to max_frequency.

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
where N=> number of elements in input array.
*/

int maxFrequencyElements(vector<int>& nums) 
{
    unordered_map<int,int> freq;
    int max_freq=0;
    for(auto i:nums)
    {
        freq[i]++;
        max_freq=max(max_freq,freq[i]);
    }
    int ans=0;
    for(auto e:freq)
    {
        if(e.second==max_freq) ans+=e.second;
    }
    return ans;
    
}