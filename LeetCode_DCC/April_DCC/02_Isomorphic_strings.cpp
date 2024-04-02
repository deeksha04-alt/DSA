#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Declare maps for string s and t.
(2) Store the order of distinct character occurrence in both string
(3) Run a loop till the size of input string
    if order position of current character in both is different return false
(4) Return True.

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
*/
bool isIsomorphic(string s, string t) 
{
    if(s.size()!=t.size())  return false;
    unordered_map<char,int> map_for_s,map_for_t;
    int count=0;
    for(auto e: s)
    {
        if(map_for_s.find(e)==map_for_s.end())      map_for_s[e]=count++;
    }
    count=0;
    for(auto e:t)
    {
        if(map_for_t.find(e)==map_for_t.end())      map_for_t[e]=count++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(map_for_s[s[i]]!=map_for_t[t[i]])    return false;
    }
    return true;
}