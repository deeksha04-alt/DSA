#include<bits/stdc++.h>
using namespace std;

/*
Problem Link: https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Logic:
(1)Create a frequency map to store count of distinct element
(2) First store the frequency of elements upto k-1 th index
(3) Append the size of map at this point into answer vector
(4) As you continue the traversal from k till the end of input array,
    reduce the frequency of element out of the k sized window ie; A[i-k] 
    if(freq of A[i-k] becomes zero) erase the element from map
    Increment the frequency of A[i] element
    append the size of map into answer


Complexity Analysis:
(1) TC: O(N) , N=> size of input array
(2) SC: O(N) , frequency map
*/
vector <int> countDistinct (int A[], int n, int k)
{
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++)    mp[A[i]]++;
    vector<int> ans;
    ans.push_back(mp.size());
    for(int i=k;i<n;i++)
    {
        mp[A[i-k]]--;
        if(mp[A[i-k]]==0)   mp.erase(A[i-k]);
        mp[A[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
}