/*
PRACTICE LINK: https://leetcode.com/problems/group-anagrams/description/

QUES:
49. Group Anagrams

Given an array of strings strs, group the anagrams together.
You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

EXPLANATION OF CODE:
1.unordered_map Initialization
Create an unordered map (`unordered_map`) named `mp` to store groups of anagrams. 
The key is the sorted version of each string, and the value is a vector of strings.

2. String Sorting and Grouping
Iterate through the input vector `strs`, create a sorted copy `s` for each string `c`, and use 
the sorted version as a key in the map to group anagrams.

3.Result Vector Initialization
Initialize a vector of vectors of strings named `ans` to store the grouped anagrams.

4.Populate Result Vector
Iterate through the map entries, and for each entry `i`,
push the corresponding vector of strings (representing anagrams) into the result vector `ans`.

5.Return Result Vector
The method returns the final vector of grouped anagrams.

Time complexity: O(m*nlogn))
nlogn -> for sorting every string present in the strs
we traverse the whole strs from 0  to size of strs , so total time complexity is O(m*nlogn))

*/

CODE:
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto c:strs){
            string s = c;
            sort(s.begin(),s.end());
            mp[s].push_back(c);
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
