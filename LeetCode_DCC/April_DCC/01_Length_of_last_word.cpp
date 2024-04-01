#include<bits/stdc++.h>
using namespace std;

/*
Complexity Analysis:
(1) TC: O(N)
(2) TC: O(1)
*/

int lengthOfLastWord(string s) 
{
    int lenlastword=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]!=' ')   ++lenlastword;
        else if(lenlastword)    return lenlastword;
    }
    return lenlastword;
}