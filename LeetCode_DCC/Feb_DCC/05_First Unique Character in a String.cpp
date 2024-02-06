/*Practice Link:https://leetcode.com/problems/first-unique-character-in-a-string/?envType=daily-question&envId=2024-02-05
QUES:
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1

Frequency Map Creation:
Start by creating an empty map to store the frequency of characters.
Iterate through the given string, counting the occurrence of each character and updating the map.

Iteration through String (First Loop):
Begin a loop from index 0 to the size of the string.
For each character at the current index, move to the next step.

Secondary Loop for Frequency Check:
Start another loop, iterating from index 0 to the size of the string.
Inside this loop, check if the frequency of the current character (using the map) is equal to 1.

Return Unique Character Index:
If the frequency condition is met (character occurs only once), return the index of that character.
The function stops execution at this point.
Handling No Unique Character Case:

If no unique character is found in the entire string (no return happened in the previous step),
return -1 to indicate that there is no unique character.


TIME COMPLEXITY:  O(n)
we traverse the string from 0 to length of string.

SPACE COMPLEXITY : O(n)
we store the characters and their frequency in the unordered_map.


*/
CODE:
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp.insert({s[i],1});
            }else{
                mp[s[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1)return i;

        }
        return -1;
    }
};

