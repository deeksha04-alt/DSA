#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
*/

int maximumLengthSubstring(string s) 
{
    int ans=0,start=0,end=0;
    unordered_map<char,int> frq;
    while(end<s.size())
    {
        frq[s[end]]++;
        while(frq[s[end]]==3)     frq[s[start++]]--;
        ans = max(ans, end - start + 1);
        end++;
    }
    return ans;   
}