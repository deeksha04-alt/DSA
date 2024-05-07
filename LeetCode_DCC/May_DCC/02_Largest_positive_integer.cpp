#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Store the input vector into set
(2) Run a loop and check for :
    a) return -1 if current elem in set is +ve.
    b) if the positive of current negative element is present in set , return the positive val
    c) else erase the negative element 
(3) Return -1

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
*/
int findMaxK(vector<int>& nums) 
{
    set<int> temp(nums.begin(),nums.end());
    for(auto it:temp)
    {
        if(it>0)  return -1;
        if(temp.find(-1*it)!=temp.end())    return -1*it;
        else    temp.erase(it);
    }
    return -1;
    
}