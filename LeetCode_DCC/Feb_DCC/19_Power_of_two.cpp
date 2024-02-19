#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Run a loop till the number is greater than zero and check for following conditions:
    (a) if number==1  ==> return true
    (b) if number is odd  ==> break 
    update number with number/2
(2) at the end of loop return false . (control reaches here if the number isn't power of 2)

Complexity Analysis
(1)TC: O(logn) 
(2)SC: O(1)
*/
bool isPowerOfTwo(int n) 
{
    while(n)
    {
        if(n==1)    return true;
        if(n%2) break;
        n/=2;
    }
    return false;
}