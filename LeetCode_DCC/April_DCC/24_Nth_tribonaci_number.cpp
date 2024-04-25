#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) intialise 3 variable with t0 t1 and t2 values
(2) Run a loop from 3 till n and perform following :
    store sum of a,b and c in ans
    update a with b, bwith c and c with ans
(3) Return ans

Complexity Analysis:
(1) TC:O(N)
(2) SC:O(1)
*/
int tribonacci(int n) 
{
    int a=0,b=1,c=1;
    if(n<3) return n==0?0:1;
    int ans=0;
    for(int i=3;i<=n;i++)
    {
        ans=a+b+c;
        a=b;
        b=c;
        c=ans;
    }
    return ans;
    
}