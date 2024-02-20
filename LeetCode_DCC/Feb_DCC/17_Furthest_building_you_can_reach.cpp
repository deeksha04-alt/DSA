#include<bits/stdc++.h>
using namespace std;

/*
Logic: Greedy Approach
(1) The idea is to use ladders for covering greater gaps and bricks for shorter gaps between adjacent buildings.
(2) Maintain a min-heap that stores the gap distances to be travelled through brick or ladder .
(3) Traverse the building vector and perform the following operations:
    (1) As the size of min-heap becomes greater than the number of available leaders , so we make use of bricks to cover the gaps ,
    therefore decrease the count of bricks by the top element of min-heap, and pop the element out of min-heap .
    (2) Return the index of buildings if count of bricks becomes less than 1.
(4) As you move out of loop, return building vector's size -1 , signifying that you could reach till the last building.

Complexity Analysis:
(1) TC: O(NlogL) [N- number of buildings , L- number of ladders] ==> traversing all the buildings and operations on min-heap elements
(2) SC: O(L)     [L -number of ladders]                          ==> min-heap of size equal to number of ladders is used.
*/

int furthestBuilding(vector<int>& buildings, int bricks, int ladders) 
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < buildings.size() - 1; ++i) {
        int diff = buildings[i + 1] - buildings[i];
        if (diff <= 0) continue;
        minHeap.push(diff);
        if (minHeap.size() > ladders) 
        {
            bricks -= minHeap.top(); 
            minHeap.pop();
        }
        if (bricks < 0) return i;
    }
    return buildings.size() - 1;
}