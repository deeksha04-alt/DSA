#include<bits/stdc++.h>
using namespace std;

/*
Logic:
3 ways - 
Solution 1 :  using prefix and suffix product array.
Solution 2 :  Counting number of zeroes , finding product of all elements , finding product of non zero elements
Solution 3 :  Optimising solution 1 by avoiding the use of prefix and suffix product array . 

Complexity Analysis:
(1) Code 1 -  TC: O(N) , SC: O(N) => prefix and suffix array . 
(2) Code 2 -  TC: O(N) , SC: O(1) 
(3) Code 3 -  TC: O(N) , SC: O(1) 
*/

//Code - (1)
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> pref(n,1),suf(n,1);
    for(int i=1;i<n;i++)    pref[i]=nums[i-1]*pref[i-1];
    for(int i=n-2;i>=0;i--) suf[i]=nums[i+1]*suf[i+1];
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)    ans[i]=pref[i]*suf[i];
    return ans;  
}

//Code - (2)
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans(n,0);
    int tot_prod=1,rem_prod=1,zero_count=0;
    for(int i=0;i<n;i++)
    {
        tot_prod*=nums[i];
        if(nums[i]==0)  zero_count++;
        else    rem_prod*=nums[i];
    }
    if(zero_count>1)    return ans;
    else if(zero_count==1)
    {
        for(int i=0;i<n;i++)    ans[i]=nums[i]==0?rem_prod:0;
    }
    else
    {
        for(int i=0;i<n;i++)    ans[i]=tot_prod/nums[i];
    }
    return ans;  
}

//code (3)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;
    for(int i=1; i<n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }
    int right = 1;
    for(int i=n-1; i>=0; i--){
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;  
}
