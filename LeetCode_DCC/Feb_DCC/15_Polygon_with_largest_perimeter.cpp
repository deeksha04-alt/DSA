#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Sort the input array
(2) intialise a prefsum variable with sum of first 2 elements , 
    prefsum variable stores the sum of polygon sides befire the current edge consideration
(3) Traverse the array from index 2 til end, 
    if current element is smaller than the prefsum, update the answer with prefsum+nums[i]
    increment the prefsum with current side
(4) return answer

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/

long long largestPerimeter(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    int n=nums.size();
    long long prefsum=nums[0]+nums[1];
    long long ans=-1;

    for(int i=2;i<n;i++)
    {
        if(prefsum>nums[i])          ans=max(ans,prefsum+nums[i]);
        prefsum+=nums[i];
    }
    return ans;
}