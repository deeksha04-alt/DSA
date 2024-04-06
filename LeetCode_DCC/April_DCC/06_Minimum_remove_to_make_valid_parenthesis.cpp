#include<bits/stdc++.h>
using namespace std;

/*
Logic: with extra space
(1) Use a stack to store the irrelavant brackets with their index ie: stack<pair<char,int>>
(2) As you process the string , mark the indexes in original string with a different symbol to ignore it while you reompute your answer string out of it

Complexity Analysis:
(1) TC:O(N)
(2) SC:O(N)
*/

string minRemoveToMakeValid(string input) 
{
    string ans="";
    stack<pair<char,int>> st;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='(')  st.push({'(',i});
        else if(input[i]==')')
        {
            if(!st.empty() && st.top().first=='(')    st.pop();
            else st.push({')',i});
        }
    }
    while(!st.empty())
    {
        input[st.top().second] = '*';
        st.pop();
    }
    for (auto e : input)
    {
        if (e != '*')     ans += e;
    }
    return ans;
    
}

/*
Logic: W/O extra space
(1) As you get an opening bracket increment its count.
(2) As you hit the close bracket
        if openbracket count is greater than zero => decrement open bracket count
        else mark that index with different symbol '#' to indicate position of symbol to be ignored.
(3) Retraverse the string
        if openbracket count > 0 and current char is ')' => mark with different symbol '#' and decrement openbracket count
(4) Recompute the answer string from input string by ignoring chars with '#'
*/
string minRemoveToMakeValid(string input) 
{
    int open_bracket=0;
    for(int i=0;i<input.size();i++)
    {

        if(input[i]=='(')  open_bracket++;
        else if(input[i]==')')
        {
            if(open_bracket==0)  input[i]='#';
            else    open_bracket--;
        }
    
    }
    
    for(int i=input.size()-1;i>=0;i--)
    {
        if(open_bracket>0 && input[i]=='(')
        {
            open_bracket--;
            input[i]='#';
        }
    }
    string ans="";
    for(auto e:input)   
    {
        if(e!='#')  ans+=e;
    }  
    return ans;      
}
