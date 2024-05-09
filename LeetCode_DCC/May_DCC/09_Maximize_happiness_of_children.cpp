#include<bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(), happiness.end(),greater<int> ());
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        long long temp = happiness[i] - i;
        if(temp<1)            break;
        ans += temp;
    }
    return ans;
}