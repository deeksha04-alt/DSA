#include<bits/stdc++.h>
using namespace std;


/*
Logic: 
(1) We need to use create a comparator function to sort the characters in string s on the basis of occurrence of order string .
(2) return string s after sorting it using comparator function.

Complexity Analysis:
(1) TC: O(nlogn)
(2) SC: O(1) 
*/

string customSortString(string order, string s) 
{
    sort(s.begin(),s.end(),[order](char a,char b){return order.find(a)<order.find(b);});
    return s;
}