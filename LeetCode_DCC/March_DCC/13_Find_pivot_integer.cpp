#include<bits/stdc++.h>
using namespace std;

/*
Logic:
Make use of sum of n natural numbers , and check for sum equality of left and right parts

Complexity Analysis:
(1) TC: O(N) , N: number of elements in array
(2) SC: O(1)
*/

int pivotInteger(int n) 
{
    for(int i=max(1,n/2);i<=n;i++)
    {
        int left_part_sum=i*(i+1)/2;
        int right_part_sum=n*(n+1)/2 - (i)*(i-1)/2;
        if(left_part_sum==right_part_sum)    return i;
    }
    return -1;
    
}