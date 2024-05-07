#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Sort th input people vector.
(2) We can minimize the number o boats by letting the lightest and heaviest person sit together.
(3) If the sum of weight of person at start and end isn't greater than the limit, accomodate them in same boat and increment start and decrement end.
    else    decrement only end => only the person at end would sit in the boat 

    increase ans by 1
(4) Return ans

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/
int numRescueBoats(vector<int>& people, int limit) 
{
    sort(people.begin(),people.end());

    int ans=0,start=0,end=people.size()-1;
    while(start<=end)
    {
        if(people[start]+people[end]<=limit)
        {
            start++,end--;
        }
        else    end--;
        ans++;
    }
    return ans;
}