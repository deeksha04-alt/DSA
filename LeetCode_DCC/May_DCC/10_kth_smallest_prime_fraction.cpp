#include<bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
{
    double low=0,high=1.0;
    int n=arr.size();
    while(low<high)
    {
        double mid=(low+high)/2;
        double mxval=0.0;
        int end=1;
        int tot=0;
        int num=0,den=0;
        for(int start=0;start<n-1;start++)
        {
            while(end<n && arr[start]>arr[end]*mid)   end++;
            tot+=n-end;
            if(end==n)  break;
            double frac=(double)arr[start]/(double)arr[end];
            
            if(frac > mxval)
            {
                mxval=frac;
                num=start;den=end;
            }
        }
        if(tot==k)
            return {arr[num],arr[den]};
        else
        {
            if(tot>k)   high=mid;
            else    low=mid;
        } 
        
    }
    return {};        
}
