#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Count the number of 1s in input string
(2) Out of total 1 count, one 1 is fixed to be at zero-th position, to make the given string odd.
(3) Append the remaining 1s from the brgining followed by zero count.
(4) AT the end append last 1. 

Complexity Analysis:
(1) TC: O(N) , N=> number of elements in input string
(2) SC: O(1)
*/
string maximumOddBinaryNumber(string s) 
{
    int one_count=0;
    for(auto e:s)  
    {
        if(e=='1')  one_count++;
    }
    string ans="";
    for(int i=0;i<one_count-1;i++)  ans+='1';
    for(int i=0;i<s.size()-one_count;i++)  ans+='0';
    ans+='1';
    return ans;
  
}
