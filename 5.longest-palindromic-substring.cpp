/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
public:
    size_t lenOfPalindrome(const string& s, size_t pivot, int* left, int* right) const {
        size_t ret = pivot;
        while (ret < s.length() - 1 && s[ret + 1] == s[pivot]) {
            ++ret;
        }
        *right = pivot;
        *left = ret;
        while (*right + 1 < s.length() && *left - 1>= 0 && s[*left - 1] == s[*right + 1]) {
            ++(*right);
            --(*left);
        }
        return ret;
    }
    string longestPalindrome(const string& s) {
        if (s.empty()) return "";
        int pair[2] = {0};
        // Optimization: pivot为尾部时，长度肯定为1，不需要处理
        for (size_t i = 0; i < s.length() - 1; i++) {
            int right = 0, left = 0;
            i = lenOfPalindrome(s, i, &left, &right);
            if ((right - left) > pair[1] - pair[0]) {
                pair[0] = left;
                pair[1] = right;
            }
        }
        return s.substr(pair[0], pair[1] - pair[0] + 1);
    }
};

