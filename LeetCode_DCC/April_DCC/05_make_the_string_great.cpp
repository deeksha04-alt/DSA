#include<bits/stdc++.h>
using namespace std;

/*
Complexity Analysis:
(1) TC: O(N)
(2) SC:O(N)
*/
string makeGood(string s) 
{
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty())  st.push(s[i]);
        else
        {
            if(abs(st.top()-s[i])==32)  st.pop();
            else    st.push(s[i]);
        }
    }
    string ans="";
    while(!st.empty())
    {
        ans+=st.top();st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

/*
Brute Approach :
(1) TC: O(N^2)
(2) SC: O(1)

string makeGood(string s) {
    int i=0;
    while(!s.empty() && i<s.size()-1)
    {
        if(abs(s[i]-s[i+1])==32)                                                    
        {
            s=s.substr(0,i)+s.substr(i+2);
            i=0;
        }
        else    i++;
    }
    return s;
}

*/