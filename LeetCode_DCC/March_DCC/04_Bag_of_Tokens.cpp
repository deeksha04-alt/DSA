#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1)Sort the values , as it would be cheaper to score point through a source that consumes less battery and profitable to loose a score to gain  from a heavy battery device
(2) Initialise start and end , 
    here battery at start index would be used to increase the score with battery panelty.
    battery at end index would act as heavy battery source with score panelty. 
(3) Run the loop and check for 3 conditions

    (a) Break condition- if battery of start is greater than available power and (either score is less than 1 or both start and end coincide)

    (b) battery Addition score penalty - if score is greater than 0 and battery at start_index is greater than available power
                                        score--
                                        power+=tokens[end]
                                        end--
    (c) Score addition battery penalty - battery at start_index is lesser than available power
                                        score++
                                        power-=tokens[start]
                                        start++
(4) Return score

Complexity Analysis:
(1) TC: O(nlogn) + O(n) => sorting and 2 pointer approach
(2) SC: O(1)                                       
*/
int bagOfTokensScore(vector<int>& tokens, int power) 
{
    sort(tokens.begin(),tokens.end());
    int start=0;int end=tokens.size()-1;
    int score=0;
    while(start<=end)
    {
        if(tokens[start]>power && (score<1 || start==end) ) break;
        else if(power<tokens[start] && score>0)     
        {
            score--;
            power+=tokens[end];
            end--;
        }
        else
        {
            score++;
            power-=tokens[start];
            start++;
        }
    }
    return score;
}