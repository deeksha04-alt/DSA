#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Make a palindrome check function, that returs true or false based upon the check
(2) Run a loop to traverse input string vector and on each element apply check_palindrome function

Complexity Analysis:
(1) TC: O(n^2)
(2) SC: O(1)
*/
bool check_palindrome(string &s)
{
    int i=0,j=s.size()-1;
    while(i<j)
    {
        if(s[i++]!=s[j--])  return false;
    }
    return true;
}
string firstPalindrome(vector<string>& words) 
{
    for(auto e:words)
    {
        if(check_palindrome(e))  return e;
    }
    return "";
}