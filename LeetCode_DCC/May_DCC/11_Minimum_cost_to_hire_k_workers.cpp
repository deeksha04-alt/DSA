#include<bits/stdc++.h>
using namespace std;


/*
Logic:
(1) THe ratio pay should be such that cost evaluated thorugh it for a candidate -i must be greater than or equal to the expected wage by worker i
(2) Store the unit ratio pay as per each worker along with the quantity and sort it
(3) The first ratio pay would be according to kth worker in above sorted vector as it would help secure each worker a wage greater than or equal to their expected wage.
(4) Maintain a max heap to store the quantities of first k workers . 
(5) As we try to check for unit ratio pays after kth worker do following :
        Update the quanitysum by decreasing the top quantity till now and adding current worker quantity
        Remove the maxheap's top as only k workers are to be considered
        Add the current workers quantity to maxheap
        store min_sum by comparing min_sum and wages as per current ratio pay
                wage as per current ratio pay=> qty*ratio[i].first
(6) Return minsum

Complexity Analysis:
(1) TC: O(NlogN)
(2) SC: O(N)
*/
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) 
{
    int n=quality.size();
    vector<pair<double,int>> ratio(n);
    for(int i=0;i<n;i++)    
        ratio[i]={ (double)wage[i]/(double)quality[i],quality[i]};
    
    sort(ratio.begin(),ratio.end());

    int qty=0;
    priority_queue<int> pq;
    for(int i=0;i<k;i++)  
    { 
        qty+=ratio[i].second;
        pq.push(ratio[i].second);
    }
    double minsum=ratio[k-1].first*qty;
    for(int i=k;i<n;i++)
    {
        qty=qty-pq.top()+ratio[i].second;
        pq.pop();
        pq.push(ratio[i].second);
        minsum=min(minsum,(double)qty*ratio[i].first);
    }
    return minsum;
}