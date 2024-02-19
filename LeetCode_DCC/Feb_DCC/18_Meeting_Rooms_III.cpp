#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Sort the meetings array to get meetings list in increasing order of their occurrence
(2) Maintain a vector (track) of size n, where n =  number of rooms , and initialise it with 0, signifying all rooms are free
(3) Declare a set freeRoom, that has the room numbers which are free,
    Initially insert all the rooms from 0 to n into freeRoom set.
(4) Make a min-heap (inUse) of type pair<int,int> , where
    first value  => end time of meeting
    second value => room occupied
(5) Run a loop in meetings array, perform the following operations =>
    (i) get the start-time(a) and end-time (b)
    (ii) run an inner loop till  inUse is not empty and end-time of top element of inUse min-heap is smaller than current end-time(b)
        Perform following operations =>
            (1) insert the room number used by top element of inUse into freeRoom.
            (2) pop the top element from inUse min-heap.
    (iii) if freeRoom set is non empty ,perform following operations
            (1) increment the track vector for room of begining element in freeRoom set
            (2) push end time of current meeting and begining room of set into the inUse min-heap
            (3) erase the begining element of freeRoom set
    (iv) else 
            (1) increment the track vector for room of begining element in freeRoom set
            (2) since the room occupied by current meeting would be top elements's room in inUse
                and , end time of current would now be , time duration of current meeting ie;(b-a) plus top elments's end time .
            (3) Therefore, pop the top element from inUse min-heap , and push the above computed values

(6) To get the room with maximum meetings, run a loop and perform simple comparison  .

Complexity Analysis:
(1) TC: O(nlogn)
(2) SC: O(n)
*/


typedef pair<long long,int> p;
int mostBooked(int n, vector<vector<int>>& meetings) 
{
    sort(meetings.begin(),meetings.end());
    vector<int> track(n,0);
    priority_queue<p,vector<p>,greater<p>> inUse;
    set<int> freeRoom;
    for(int i=0;i<n;i++)    freeRoom.insert(i);
    

    for(auto e:meetings)
    {
        int a=e[0];
        int b=e[1];

        while(!inUse.empty() && inUse.top().first<=a)
        {
            int room=inUse.top().second;
            inUse.pop();
            freeRoom.insert(room);
        }

        if(!freeRoom.empty())
        {
            int availableRoom=*(freeRoom.begin());
            freeRoom.erase(availableRoom);
            inUse.push({b,availableRoom});
            track[availableRoom]++;
        }
        else
        {
            int availableTime=inUse.top().first;
            int availableRoom=inUse.top().second;
            inUse.pop();
            inUse.push({availableTime+b-a,availableRoom});
            track[availableRoom]++;
        }
    }

    int ans=0;
    int maxt=0;
    for(int i=0;i<n;i++)
    {
        if(track[i]>maxt)
        {
            maxt=track[i];
            ans=i;
        }
    }
    return ans;

    
}