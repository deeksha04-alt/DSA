#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Traverse the input word, as the given char is encountered , reverse the substring from begining till current index and break out of loop
(2) Return the word

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/
string reversePrefix(string word, char ch) 
{
    for(int i=0;i<word.size();i++)
    {
        if(word[i]==ch)
        {
            reverse(word.begin(),word.begin()+i+1);
            break;
        }
    }
    return word;
    
}