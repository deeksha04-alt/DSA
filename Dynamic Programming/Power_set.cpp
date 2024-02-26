#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://www.geeksforgeeks.org/problems/power-set4302/1

Logic:
(1) Created a recursive function to generate the power set of a string 
    (a) base case => index moves out of string size , 
                     push the non-empty temp string into answer vector and return
    (b) every index has 2 options => to be included or excluded , therefore make both recursive calls respetcively.

Complexity Analysis:
(1) TC: O(n*2^n) 
The recursive function solve is called for each character of the input string s. Since there are n characters in s, the recursive function is called 2^n times in the worst case scenario. 
(2) SC: O(2^n)+O(n)+O(n)
O(2^n) => The maximum number of strings that can be stored in ans is 2^(length of s) => 2^n
O(n)   => String stored in temp variable at any time will have at max n length .
O(n)   => Recursive stack space
*/

void solve(string &s,int index,vector<string> &ans,string temp)
{
    if(index>=s.size())
    {
        if(temp.size())    ans.push_back(temp);
        return;
    }
    solve(s,index+1,ans,temp);
    solve(s,index+1,ans,temp+s[index]);
    return ;
}
vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    string temp="";
    solve(s,0,ans,temp);
    sort(ans.begin(),ans.end());
    return ans;
}