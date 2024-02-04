#include<bits/stdc++.h>
using namespace std;

/*
Logic:
We have implemented the sliding window technique to solve the question, the steps for the solution are illustrated below:
(1) Maintain a frequency map for every character in string t.
(2) Initialise a frequency map to track characters in string s .
(3) Initialise 2 indexes start_ind, end_ind and counter to zero

NOTE:   start_ind denotes begining and end_ind denotes ending index of subtring respectively.
        The counter helps check if we have found a window of size greater than or equal to string t length.
        To implement string minimisation we make use of begining index ie: start_ind;

(4) As we traverse string s,
        1)  a) increment the frequency of s[end_ind] in track map by 1 , if it is present in string t.
            b) increment the counter by 1, if frequency of s[end_ind] is less than its frequency in string t;

        2)Enter the substring minimisation loop if counter is equal to or greater than string t size;            
            a) Run a loop till following conditions are met :
                (1) if size of track map and temp map is same
                (2) either the current char ie: s[end_ind] is absent in string t
                                        or
                    frequency of s[end_ind] in track map is greater than its frequency in temp map

                if both conditions are passed , then make changes as directed below
                    (1) if character s[start_ind] is absent in string t :
                            increment start_ind by 1;
                    (2) if freq of s[start_ind] in track map greater than its frequeny in string t  :
                            reduce frequency of s[start_ind] by 1 in track map
                            increment start_ind by 1

            b) As you move out of loop , 
                update the ans string if either of the conditions are true
                (1) current substring length ie: (end_ind-start_ind+1) < ans string size 
                (2) ans string is empty

Complexity Analysis:
(1) TC: O(N) , N- size of string s
(2) SC: O(M) , M- size of string t , used for frequency maps
*/

string minWindow(string s, string t) 
{
        
    unordered_map<char,int> trackmp,temp;
    for(auto e:t) temp[e]++;

    int start_ind=0,end_ind=0,n=s.size(),counter=0;
    string ans="";
    while(end_ind<n)
    {
        if(temp.find(s[end_ind])!=temp.end())
        {
            trackmp[s[end_ind]]++;
            if(trackmp[s[end_ind]]<=temp[s[end_ind]]) counter++;
        }

        if(counter>=t.size())
        {
            while(start_ind<end_ind && (temp.find(s[start_ind])==temp.end() || trackmp[s[start_ind]]>temp[s[start_ind]] ) )
            {
                if(temp.find(s[start_ind])==temp.end())  start_ind++;
                else if(trackmp[s[start_ind]]>temp[s[start_ind]])
                {
                    trackmp[s[start_ind]]--;
                    start_ind++;
                }
            }
            if(ans=="" || (end_ind-start_ind+1)<ans.size())   ans=s.substr(start_ind,end_ind-start_ind+1);

        }
        end_ind++;
        }
        return ans;
}