#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://www.geeksforgeeks.org/problems/word-break1352/1

Logic:
(1) We made use of partition dp concept, here we part the available string at different indexes, and if the parted substring is available
in the dictionary we explore the possible paths after that partition.
(2) A set is initialised with all the words in dictionary
(3) The base case of recursive function is => i (ie; index position of string s) is greater than or equal to size of string
(4) Through a loop make partitions, and explore the possible paths if the current substring is in the dictionary .


Time Complexity :
(1) TC: O(n^2), n: size of string s
(2) SC: O(N) ,  N : number of strings in dictionary  
*/
bool solve(int i,set<string> &dict,string &s)
{
    if(i>=s.size()) return true;
    
    for(int ind=i;ind<s.size();ind++)
    {
        string temp=s.substr(i,ind-i+1);
        if(dict.find(temp)!=dict.end())
        {
            if(solve(ind+1,dict,s)) return true;
        }
    }
    return false;
}
int wordBreak(int n, string s, vector<string> &dictionary) 
{
    set<string> dict;
    for(auto e:dictionary)  dict.insert(e);
    return solve(0,dict,s);
}