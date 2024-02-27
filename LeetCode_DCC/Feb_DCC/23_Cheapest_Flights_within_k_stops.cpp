#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Make an adjacency list representing a directed graph where each node has a list of neighboring nodes along with their corresponding prices.
(2) Initializes a vector dist to store the minimum cost to reach each node, initially set to INT_MAX (infinity).
(3) Initializes a queue q to perform BFS.Enqueues the source node 'src' with distance 0 into the queue.
(4) Performs BFS traversal with a limit on the number of stops ('k').
(5) At each iteration explore all the nodes in the queue at that time,
        dequeues a node from the queue and explores its neighbors.
        If the price of reaching a neighbor via the current node is lower than its current minimum cost, updates the minimum cost and enqueues the neighbor into the queue.
(6) Returns the minimum cost to reach the destination node 'dst' if it's reachable within 'k' stops, otherwise returns -1.

Complexity Analysis:
(1) TC: O(V+E*k) ,
E- Number of Flights
V- Number of Cities
k- Number of Stops 
(2) SC: O(V + E)
*/

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto& e : flights) {
        adj[e[0]].push_back({e[1], e[2]});
    }

    vector<int> dist(n, INT_MAX);
    queue<pair<int, int>> q;
    q.push({src, 0});
    dist[src] = 0;
    int stops = 0;

    while (stops <= k && !q.empty()) {
        int sz = q.size();

        while (sz--) {
            auto [node, distance] = q.front();
            q.pop();
            for (auto& [neighbour, price] : adj[node]) {
                if (distance!=INT_MAX && price + distance >= dist[neighbour]) continue;
                dist[neighbour] = price + distance;
                q.push({neighbour, dist[neighbour]});
            }
        }
        stops++;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
    
}
