#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Run a loop till left and right numbers converge to same representation.
(2) Keep a count of the shifts required for convergence of left and right numbers.
(3) Now, simply append the zero bits(left shift by bitshifts) to the convergence point signifying the uncommon bits after it.

Time Complexity:
(1) TC:O(logn) 
(2) SC:O(1)
*/

int rangeBitwiseAnd(int left, int right) 
{
    int bitshift=0;
    while(left!=right)
    {
        left>>=1;
        right>>=1;
        bitshift++;
    }
    return left<<bitshift;

}