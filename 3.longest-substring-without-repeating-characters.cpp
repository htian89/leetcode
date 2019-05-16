/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#define MAX(a, b) (a > b ? a : b)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char, int> index_map;
       int longest = 0;
       for (int i = -1, j = 0; j < s.length() ; ++j) {
         auto it = index_map.find(s[j]);
         if (it != index_map.end()) {
             i = it->second;
             it->second = j;
         } else {
             index_map[s[j]] = j;
         }
         longest = MAX(longest, j - i);
       } 
       return longest;
    }
};

