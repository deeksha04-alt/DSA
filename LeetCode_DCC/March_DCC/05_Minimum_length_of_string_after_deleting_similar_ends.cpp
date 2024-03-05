#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) We have used a simple 2 pointer approach , where start and end are initialised with zero-th and last index
(2) Run a loop untill start and end characters match and start is less than end index.
(3) Run 2 separate loops,
    (a) to find maximum length of prefix of same strings.
    (b) to find maximum length of suffix of same strings.
(4) return the length of remaining substring after removals ie; end-start+1

Complexity Analysis:
(1) TC: O(N) , N => string length
(2) SC: O(1)
*/

int minimumLength(string s) 
{
    int start=0;int end=s.size()-1;
    while(start<end && s[start]==s[end])
    {
        while(s[start]==s[start+1] && start+1<end) start++;
        while(s[end]==s[end-1] && end-1>start) end--;
        start++;
        end--;
    }
    return end-start+1;
}