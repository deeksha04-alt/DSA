#include<bits/stdc++.h>
using namespace std;

/*
Logic:
(1) Count the number of required square and circle sandwiches by the students
(2) Traverse the sandwich array and perform following checks:
    (a) square sandwich available when requirement of square is null => return count of circle sandwiches left as no student would be catered after this point
    (b) circle sandwich available when requirement of circle is null => return count of square sandwiches left as no student would be catered after this point
    (c) Reduce count of respective sandwich if available and required sandwich are of same type.
(3) Return 0

Complexity Analysis:
(1) TC: O(N)
(2) SC: O(1)
*/

int countStudents(vector<int>& students, vector<int>& sandwiches) 
{
    int circle=0,square=0;
    for(auto required_sandwich:students)    
    {
        if(required_sandwich==0)    circle++;
        else        square++;
    }

    for(auto available_sandwich:sandwiches)
    {
        if(available_sandwich==0 && circle==0)   return square;
        else if(available_sandwich==1 && square==0)  return circle;
        else if(available_sandwich==0)   circle--;
        else    square--;   
    }
    return 0;
}