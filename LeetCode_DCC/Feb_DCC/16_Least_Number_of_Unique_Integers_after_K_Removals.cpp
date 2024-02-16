#include<bits/stdc++.h>
using namespace std;

/*
Logic:
Remove the elements in order of increasing frequnecy so as to get least number of distinct elements .

(1) Make a frequency map to store each element's frequency
(2) Use a min heap to store the pair of frequency and element in increasing order of their frequency count
(3) As you traverse the minheap , 
        check if top elment's frequency is less than k ==> pop the pair
        else break
(4) Return the size of priority queue

Complexity Analysis:
(1) TC: O(n) + O(nlogn) + O(klogk)
        nlogn => for storing pair of frequency and element in min-heap
        klogk => deletion pair from min heap 
(2) SC: O(n)
*/
typedef pair<int,int> p;
int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
{
    unordered_map<int,int> frequency_map;
    for(auto e:arr) frequency_map[e]++;

    priority_queue<p,vector<p>,greater<p>> pq;
    for(auto e:frequency_map)  pq.push({e.second,e.first});

    while(k)
    {
        if(pq.top().first<=k) 
        {      k-=pq.top().first;pq.pop();}
        else    break;            
    }
    return pq.size();
    
}