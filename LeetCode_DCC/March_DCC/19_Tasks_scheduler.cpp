#include<bits/stdc++.h>>
using namespace std;

/*
Logic:
(1) Calculate the number of tasks with maximum frequency
(2) Every slot will have a minimum of (n+1) tasks to maintain the gap of atleast n tasks among similar tasks,
    therefore , 
            total positions available => (n+1)* (maximum frequency) 
            Unoccupied positions in last slot => (n+1) - (count of elements with max frequency)
    NOTE:  Few positions in the last slot may go empty as the different tasks of lower frequency may already have been completed before this slot, so
            

(3) so 2 options available with us are :
    opt1 :  total positions available - Unoccupied positions in last slot
    opt2 : tasks.size()

(4) Return the max of 2 options .

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1) 
*/

int leastInterval(vector<char>& tasks, int n) {
    vector<int> mp(26,0);
    int maxfreq=0;
    for(auto e:tasks)
    {
        mp[e-'A']++;
        if(maxfreq<mp[e-'A']) maxfreq=mp[e-'A'];
    }
    int count_max_freq=0;
    for(auto e:mp)  
    {
        if(e==maxfreq)    count_max_freq++;
    }
    int option1 = (n+1)*maxfreq - (n+1-count_max_freq);
    return tasks.size() > option1 ? tasks.size() : option1;
}