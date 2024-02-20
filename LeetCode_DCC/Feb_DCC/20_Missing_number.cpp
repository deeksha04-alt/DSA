#include<bits/stdc++.h>
using namespace std;
/*
Logic:
(1) Since the question description states , numbers in the input vector are distinct and fall in the range of 0 to n, both inclusive
(2) To find the missing number in given input, 
        substract the sum of input vector elements from sum of first n natural numbers.

Complexity Analysis:
(1) TC: O(n) , while traversing the loop
(2) SC: O(1)
*/


int missingNumber(vector<int>& nums) 
{
    int sum=0;
    int n=nums.size();
    for(auto e:nums)    sum+=e;
    return (n*(n+1))/2 - sum;
}