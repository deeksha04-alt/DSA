#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Store the equivalent numbers separated by '.' in temp vectors for both versions .
(2) Compare these values and accordingly predict the output.

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(N)
*/
int compareVersion(string version1, string version2) 
{
        vector<string> temp1,temp2;
        version1+='.',version2+='.';
        for(int i=0,j=0; j<version1.size();j++)
        {
            if(version1[j]=='.')     {  temp1.push_back(version1.substr(i,j-i)),i=j+1;}
        }
        for(int i=0,j=0; j<version2.size();j++)
        {
            if(version2[j]=='.')     { temp2.push_back(version2.substr(i,j-i)),i=j+1;}
        }

        int start_1 = 0, start_2 = 0;
        while(start_1<temp1.size() && start_2<temp2.size())
        {
            if(stoi(temp1[start_1])<stoi(temp2[start_2])) return -1;
            else if(stoi(temp1[start_1])>stoi(temp2[start_2]))    return 1;
            start_1++,start_2++;
        }
        while(start_1<temp1.size())   
        { 
            if(stoi(temp1[start_1++])>0)       return 1;         
        }
        while(start_2<temp2.size())
        {  
            if(stoi(temp2[start_2++])>0)      return -1;  
        }

        return 0;            
    }