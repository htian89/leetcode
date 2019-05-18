/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#define MAX(a, b) (a > b ? a : b)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[128] = {0};
        int longest = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            int offset = s[j];
            if (index[offset] != 0) {
                i = i > index[offset] ? i : index[offset];
            }
            index[offset] = j + 1;
            longest = MAX(longest, j - i + 1);
        }
        return longest;
    }
};

