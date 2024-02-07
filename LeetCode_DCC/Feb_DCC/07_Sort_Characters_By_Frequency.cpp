#include<bits/stdc++.h>
using namespace std;
/*
Logic:
(1) Make a map to store frequency of each character of string
(2) Declare a priority queue of type <int,char> , this signifies a pair of  <frequency count,character>
(3) Since the priority queue is a max-heap by default, all the characters are sorted as per their frequencies
(4) As you traverse the priority queue, 
    get the top element and extract frequency and character from it 
    Run a loop to append the character frequency times into the answer string .  

Complexity Analysis:
(1) TC: O(nlogn) 
O(n) => To store character frequency into map
O(nlogn) => To insert each pair<freq,char> into priority queue and extract the pairs to
append into answer string 

(2) SC: O(n), used for frequency map and priority queue      
*/

//CODE
string frequencySort(string s)
{
    map<char, int> mp;
    for (auto i : s)
        mp[i]++;

    priority_queue<pair<int, char>> pq;
    for (auto i : mp)
        pq.push({i.second, i.first});

    string ans = "";
    while (!pq.empty())
    {
        auto i = pq.top();
        while (i.first--)
            ans += i.second;
        pq.pop();
    }

    return ans;
    
}