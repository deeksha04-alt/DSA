#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Run a loop till end of any of the input arrays is reached.
(2) return the element if nums1[index1]=nums2[index2]
(3) if array1's value is smaller than the value of other array , increment index1.
(4) else increment index2 .
(5) Return -1.

Complexity Analysis:
(1) TC: O(N) , N=> Number of elements in input array
(2) SC: O(1)
*/

int getCommon(vector<int>& nums1, vector<int>& nums2) 
{
    int index1=0,index2=0;
    while(index1<nums1.size() && index2<nums2.size())
    {
        if(nums1[index1]==nums2[index2])  return nums1[index1];
        else if(nums1[index1]<nums2[index2])  index1++;
        else    index2++;
    }
    return -1;
}