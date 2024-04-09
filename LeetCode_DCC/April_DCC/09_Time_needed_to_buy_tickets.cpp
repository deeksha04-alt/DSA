#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) All the indices lower than k will require time which is minimum of the tickets it needs and ticket kth person needs.
(2) For all the indices greater than k, time required would be minimum of ticket it needs and kth person's ticket requirement minus 1

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/
int timeRequiredToBuy(vector<int>& tickets, int k) 
{
    int ans=0;
    for(int i=0;i<tickets.size();i++)
    {
        ans+=i<=k?min(tickets[i],tickets[k]):min(tickets[i],tickets[k]-1);
    }
    return ans;

}